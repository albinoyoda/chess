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
    init_state_values();
}

Board_state::Board_state(const std::array<std::array<int, 8>, 8>& configuration) : state_{configuration}
{
    init_state_values();
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
    init_state_values();
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
    // Check if the value should be recomputed
    recompute_piece_values(state_[next.row][next.col], next.row);
    recompute_position_values(state_[prev.row][prev.col], prev.row - next.row);

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
        // White
        state_[next.row][next.col] = 4;
        white_position_value -= 6;
        white_piece_value += QueenValueMg - PawnValueMg;
    }
    else if ((state_[next.row][next.col] == -6) && (next.row == 7))
    {
        // Black
        state_[next.row][next.col] = -4;
        black_position_value -= 6;
        black_piece_value += QueenValueMg - PawnValueMg;
    }
}

int Board_state::value_of_state(Piece_color color) const
{
    if (color == Piece_color::white)
    {
        return white_piece_value + white_position_value - (black_piece_value + black_position_value);
    }
    return black_piece_value + black_position_value - (white_piece_value + white_position_value);
}

void Board_state::init_state_values()
{
    int row_idx = -1;
    for (const auto& row : state_)
    {
        row_idx++;
        for (const auto& sq : row)
        {
            if (sq == 0)
            {
                continue;
            }
            switch (sq)
            {
            case Piece_type::white_tower:
                white_piece_value += RookValueMg;
                break;
            case Piece_type::white_knight:
                white_piece_value += KnightValueMg;
                break;
            case Piece_type::white_bishop:
                white_piece_value += BishopValueMg;
                break;
            case Piece_type::white_queen:
                white_piece_value += QueenValueMg;
                break;
            case Piece_type::white_king:
                white_piece_value += KingValueMg;
                break;
            case Piece_type::white_pawn:
                white_piece_value += PawnValueMg;
                white_position_value += (6 - row_idx);
                break;
            case Piece_type::black_tower:
                black_piece_value += RookValueMg;
                break;
            case Piece_type::black_knight:
                black_piece_value += KnightValueMg;
                break;
            case Piece_type::black_bishop:
                black_piece_value += BishopValueMg;
                break;
            case Piece_type::black_queen:
                black_piece_value += QueenValueMg;
                break;
            case Piece_type::black_king:
                black_piece_value += KingValueMg;
                break;
            case Piece_type::black_pawn:
                black_piece_value += PawnValueMg;
                black_position_value += (row_idx - 1);
                break;
            default:
                break;
            }
        }
    }
}

void Board_state::recompute_piece_values(int taken_piece, int row)
{
    switch (taken_piece)
    {
    case Piece_type::white_tower:
        white_piece_value -= RookValueMg;
        break;
    case Piece_type::white_knight:
        white_piece_value -= KnightValueMg;
        break;
    case Piece_type::white_bishop:
        white_piece_value -= BishopValueMg;
        break;
    case Piece_type::white_queen:
        white_piece_value -= QueenValueMg;
        break;
    case Piece_type::white_king:
        white_piece_value -= KingValueMg;
        break;
    case Piece_type::white_pawn:
        white_piece_value -= PawnValueMg;
        white_position_value -= (6 - row);
        break;
    case Piece_type::black_tower:
        black_piece_value -= RookValueMg;
        break;
    case Piece_type::black_knight:
        black_piece_value -= KnightValueMg;
        break;
    case Piece_type::black_bishop:
        black_piece_value -= BishopValueMg;
        break;
    case Piece_type::black_queen:
        black_piece_value -= QueenValueMg;
        break;
    case Piece_type::black_king:
        black_piece_value -= KingValueMg;
        break;
    case Piece_type::black_pawn:
        black_piece_value -= PawnValueMg;
        white_position_value -= (row - 1);
        break;
    default:
        // Check promotion
        break;
    }
}

void Board_state::recompute_position_values(int moved_piece, int steps)
{
    if (moved_piece == 6)
    {
        white_position_value += steps;
    }
    else if (moved_piece == -6)
    {
        black_position_value -= steps;
    }
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
