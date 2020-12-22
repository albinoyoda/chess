#include <Board_state.hpp>
#include <iostream>
#include <map>

namespace
{
std::map<int, std::string> print_piece{{0, "[  ]"},  {1, "[wT]"},  {2, "[wH]"},  {3, "[wB]"},  {4, "[wQ]"},
                                       {5, "[wK]"},  {6, "[wP]"},  {-1, "[bT]"}, {-2, "[bH]"}, {-3, "[bB]"},
                                       {-4, "[bQ]"}, {-5, "[bK]"}, {-6, "[bP]"}};

std::map<std::string, int> string_to_piece{{"00", 0},  {"wT", 1},  {"wH", 2},  {"wB", 3},  {"wQ", 4},
                                           {"wK", 5},  {"wP", 6},  {"bT", -1}, {"bH", -2}, {"bB", -3},
                                           {"bQ", -4}, {"bK", -5}, {"bP", -6}};

} // namespace

Board_state::Board_state()
{
    state_ = {std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
              {-6, -6, -6, -6, -6, -6, -6, -6},
              {0, 0, 0, 0, 0, 0, 0, 0},
              {0, 0, 0, 0, 0, 0, 0, 0},
              {0, 0, 0, 0, 0, 0, 0, 0},
              {0, 0, 0, 0, 0, 0, 0, 0},
              {6, 6, 6, 6, 6, 6, 6, 6},
              {1, 2, 3, 4, 5, 3, 2, 1}};
}

Board_state::Board_state(const std::array<std::array<int, 8>, 8>& configuration) : state_{configuration}
{
}

Board_state::Board_state(const std::string& configuration)
{
    assert(configuration.size() == 128);
    for (size_t row = 0; row < 8; ++row)
    {
        for (size_t col = 0; col < 8; ++col)
        {
            size_t index = row * 16 + col * 2;
            std::string substring = configuration.substr(index, 2);
            state_[row][col] = string_to_piece[substring];
        }
    }
    white_checked = is_checked(*this, Piece_color::white);
    black_checked = is_checked(*this, Piece_color::black);
}

int& Board_state::operator()(const Position& pos)
{
    if (!is_inside_board(pos))
    {
        assert(false);
    }
    return state_[pos.row][pos.col];
}

int Board_state::operator()(const Position& pos) const
{
    if (!is_inside_board(pos))
    {
        assert(false);
    }
    return state_[pos.row][pos.col];
}

void Board_state::move(const Position& prev, const Position& next)
{
    // Castling
    if ((state_[prev.row][prev.col] == 5) && (std::abs(next.col - prev.col) == 2))
    {
        if (next.col > prev.col)
        {
            state_[next.row][next.col] = state_[prev.row][prev.col];
            state_[prev.row][prev.col] = 0;
            state_[prev.row][prev.col + 1] = 1;
            state_[next.row][next.col + 1] = 0;
        }
        else
        {
            state_[next.row][next.col] = state_[prev.row][prev.col];
            state_[prev.row][prev.col] = 0;
            state_[prev.row][prev.col - 1] = 1;
            state_[next.row][next.col - 2] = 0;
        }
    }
    else if ((state_[prev.row][prev.col] == -5) && (std::abs(next.col - prev.col) == 2))
    {
        if (next.col > prev.col)
        {
            state_[next.row][next.col] = state_[prev.row][prev.col];
            state_[prev.row][prev.col] = 0;
            state_[prev.row][prev.col + 1] = -1;
            state_[next.row][next.col + 1] = 0;
        }
        else
        {
            state_[next.row][next.col] = state_[prev.row][prev.col];
            state_[prev.row][prev.col] = 0;
            state_[prev.row][prev.col - 1] = -1;
            state_[next.row][next.col - 2] = 0;
        }
    }
    else
    {
        state_[next.row][next.col] = state_[prev.row][prev.col];
        state_[prev.row][prev.col] = 0;
    }
    // Promotion
    if ((state_[next.row][next.col] == 6) && (next.row == 0))
    {
        state_[next.row][next.col] = 4;
    }
    else if ((state_[next.row][next.col] == -6) && (next.row == 7))
    {
        state_[next.row][next.col] = -4;
    }
}

int Board_state::value_of_state(Piece_color color) const
{
    int white_value = 0;
    int black_value = 0;
    for (const auto& row : state_)
    {
        for (const auto& sq : row)
        {
            if (sq == 0)
            {
                continue;
            }
            switch (sq)
            {
            case Piece_type::white_tower:
                white_value += RookValueMg;
                break;
            case Piece_type::white_knight:
                white_value += KnightValueMg;
                break;
            case Piece_type::white_bishop:
                white_value += BishopValueMg;
                break;
            case Piece_type::white_queen:
                white_value += QueenValueMg;
                break;
            case Piece_type::white_king:
                white_value += KingValueMg;
                break;
            case Piece_type::white_pawn:
                white_value += PawnValueMg;
                break;
            case Piece_type::black_tower:
                black_value += RookValueMg;
                break;
            case Piece_type::black_knight:
                black_value += KnightValueMg;
                break;
            case Piece_type::black_bishop:
                black_value += BishopValueMg;
                break;
            case Piece_type::black_queen:
                black_value += QueenValueMg;
                break;
            case Piece_type::black_king:
                black_value += KingValueMg;
                break;
            case Piece_type::black_pawn:
                black_value += PawnValueMg;
                break;
            default:
                break;
            }
        }
    }
    if (color == Piece_color::white)
    {
        return white_value - black_value;
    }
    return black_value - white_value;
}

Position Board_state::find_white_king() const
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (state_[row][col] == 5)
            {
                return Position{row, col};
            }
        }
    }
    return {-1, -1};
}

Position Board_state::find_black_king() const
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (state_[row][col] == -5)
            {
                return Position{row, col};
            }
        }
    }
    return {-1, -1};
}

void Board_state::draw_board() const
{
    std::string row_labels = "87654321";
    std::string col_labels = "abcdefgh";
    size_t index = 0;
    for (const auto& row : state_)
    {
        std::cout << row_labels[index++];
        std::cout << " ";
        for (const auto& piece : row)
        {
            std::cout << print_piece[piece];
        }
        std::cout << "\n";
    }
    for (const auto& label : col_labels)
    {
        std::cout << "   ";
        std::cout << label;
    }
    std::cout << "\n";
}
