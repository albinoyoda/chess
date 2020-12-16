#include "Moves.hpp"

namespace
{
std::vector<Action> convert_to_actions(const Position& pos, const std::vector<Position>& moves)
{
    std::vector<Action> actions{};
    actions.reserve(moves.size());
    for (const auto& move : moves)
    {
        actions.emplace_back(pos, move);
    }
    return actions;
}
} // namespace

std::vector<Position> get_pawn_moves(const Position& position, const Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(2);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(2);
    if (is_white(board_state(position)))
    {
        if (position.row > 0)
        {
            if (is_free(board_state(position + Position::north())))
            {
                moves.emplace_back(position + Position::north());
            }
            if (position.col > 0)
            {
                if (is_black(board_state(position + Position::north_west())))
                {
                    taking_moves.emplace_back(position + Position::north_west());
                }
            }
            if (position.col < 7)
            {
                if (is_black(board_state(position + Position::north_east())))
                {
                    taking_moves.emplace_back(position + Position::north_east());
                }
            }
        }
        if (position.row == 6)
        {
            if (is_free(board_state(position + Position::north() + Position::north())))
            {
                moves.emplace_back(position + Position::north() + Position::north());
            }
        }
    }
    else
    {
        if (position.row < 7)
        {
            if (is_free(board_state(position + Position::south())))
            {
                moves.emplace_back(position + Position::south());
            }
            if (position.col > 0)
            {
                if (is_white(board_state(position + Position::south_west())))
                {
                    taking_moves.emplace_back(position + Position::south_west());
                }
            }
            if (position.col < 7)
            {
                if (is_white(board_state(position + Position::south_east())))
                {
                    taking_moves.emplace_back(position + Position::south_east());
                }
            }
        }
        if (position.row == 1)
        {
            if (is_free(board_state(position + Position::south() + Position::south())))
            {
                moves.emplace_back(position + Position::south() + Position::south());
            }
        }
    }
    taking_moves.insert(taking_moves.end(), moves.begin(), moves.end());
    return taking_moves;
}

std::vector<Position> get_tower_moves(const Position& position, const Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(16);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(16);
    bool color = is_white(board_state(position));
    auto possible_position = position;
    while (possible_position.col > 0)
    {
        possible_position = possible_position + Position::west();
        if (is_free(board_state(possible_position)))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(board_state(possible_position)))
        {
            taking_moves.emplace_back(possible_position);
            break;
        }
        else
        {
            break;
        }
    }
    possible_position = position;
    while (possible_position.col < 7)
    {
        possible_position = possible_position + Position::east();
        if (is_free(board_state(possible_position)))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(board_state(possible_position)))
        {
            taking_moves.emplace_back(possible_position);
            break;
        }
        else
        {
            break;
        }
    }
    possible_position = position;
    while (possible_position.row > 0)
    {
        possible_position = possible_position + Position::north();
        if (is_free(board_state(possible_position)))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(board_state(possible_position)))
        {
            taking_moves.emplace_back(possible_position);
            break;
        }
        else
        {
            break;
        }
    }
    possible_position = position;
    while (possible_position.row < 7)
    {
        possible_position = possible_position + Position::south();
        if (is_free(board_state(possible_position)))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(board_state(possible_position)))
        {
            taking_moves.emplace_back(possible_position);
            break;
        }
        else
        {
            break;
        }
    }
    taking_moves.insert(taking_moves.end(), moves.begin(), moves.end());
    return taking_moves;
}

std::vector<Position> get_horse_moves(const Position& position, const Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(8);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(8);
    std::vector<Position> possible_moves{};
    possible_moves.reserve(8);
    bool color = is_white(board_state(position));
    possible_moves.emplace_back(position + Position::east() + Position::north_east());
    possible_moves.emplace_back(position + Position::east() + Position::south_east());
    possible_moves.emplace_back(position + Position::north() + Position::north_east());
    possible_moves.emplace_back(position + Position::north() + Position::north_west());
    possible_moves.emplace_back(position + Position::south() + Position::south_east());
    possible_moves.emplace_back(position + Position::south() + Position::south_west());
    possible_moves.emplace_back(position + Position::west() + Position::north_west());
    possible_moves.emplace_back(position + Position::west() + Position::south_west());
    for (const auto& move : possible_moves)
    {
        if (is_inside_board(move))
        {
            if (is_free(board_state(move)))
            {
                moves.emplace_back(move);
            }
            else if (color != is_white(board_state(move)))
            {
                taking_moves.emplace_back(move);
            }
        }
    }
    taking_moves.insert(taking_moves.end(), moves.begin(), moves.end());
    return taking_moves;
}

std::vector<Position> get_bishop_moves(const Position& position, const Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(8);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(8);
    bool color = is_white(board_state(position));
    auto possible_position = position;
    while (possible_position.col > 0 && possible_position.row > 0)
    {
        possible_position = possible_position + Position::north_west();
        if (is_free(board_state(possible_position)))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(board_state(possible_position)))
        {
            taking_moves.emplace_back(possible_position);
            break;
        }
        else
        {
            break;
        }
    }
    possible_position = position;
    while (possible_position.col > 0 && possible_position.row < 7)
    {
        possible_position = possible_position + Position::south_west();
        if (is_free(board_state(possible_position)))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(board_state(possible_position)))
        {
            taking_moves.emplace_back(possible_position);
            break;
        }
        else
        {
            break;
        }
    }
    possible_position = position;
    while (possible_position.col < 7 && possible_position.row > 0)
    {
        possible_position = possible_position + Position::north_east();
        if (is_free(board_state(possible_position)))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(board_state(possible_position)))
        {
            taking_moves.emplace_back(possible_position);
            break;
        }
        else
        {
            break;
        }
    }
    possible_position = position;
    while (possible_position.col < 7 && possible_position.row < 7)
    {
        possible_position = possible_position + Position::south_east();
        if (is_free(board_state(possible_position)))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(board_state(possible_position)))
        {
            taking_moves.emplace_back(possible_position);
            break;
        }
        else
        {
            break;
        }
    }
    taking_moves.insert(taking_moves.end(), moves.begin(), moves.end());
    return taking_moves;
}

std::vector<Position> get_queen_moves(const Position& position, const Board_state& board_state)
{
    std::vector<Position> tower_moves = get_tower_moves(position, board_state);
    std::vector<Position> bishop_moves = get_bishop_moves(position, board_state);
    tower_moves.insert(tower_moves.end(), bishop_moves.begin(), bishop_moves.end());
    return tower_moves;
}

std::vector<Position> get_king_moves(const Position& position, const Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(9);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(9);
    std::vector<Position> possible_moves{};
    possible_moves.reserve(9);
    bool color = is_white(board_state(position));
    possible_moves.emplace_back(position + Position::north_east());
    possible_moves.emplace_back(position + Position::north());
    possible_moves.emplace_back(position + Position::north_west());
    possible_moves.emplace_back(position + Position::south_east());
    possible_moves.emplace_back(position + Position::south());
    possible_moves.emplace_back(position + Position::south_west());
    possible_moves.emplace_back(position + Position::west());
    possible_moves.emplace_back(position + Position::east());

    // Check castling
    if (position == Position{7, 4})
    {
        if (board_state(Position{7, 5}) == 0 && board_state(Position{7, 6}) == 0 && board_state(Position{7, 7}) == 1)
        {
            possible_moves.emplace_back(Position{7, 6});
        }
        if (board_state(Position{7, 0}) == 1 && board_state(Position{7, 1}) == 0 && board_state(Position{7, 2}) == 0 &&
            board_state(Position{7, 3}) == 0)
        {
            possible_moves.emplace_back(Position{7, 2});
        }
    }
    else if (position == Position{0, 4})
    {
        if (board_state(Position{0, 5}) == 0 && board_state(Position{0, 6}) == 0 && board_state(Position{0, 7}) == -1)
        {
            possible_moves.emplace_back(Position{0, 6});
        }
        if (board_state(Position{0, 0}) == -1 && board_state(Position{0, 1}) == 0 && board_state(Position{0, 2}) == 0 &&
            board_state(Position{0, 3}) == 0)
        {
            possible_moves.emplace_back(Position{0, 2});
        }
    }

    for (const auto& move : possible_moves)
    {
        if (is_inside_board(move))
        {
            if (is_free(board_state(move)))
            {
                moves.emplace_back(move);
            }
            else if (color != is_white(board_state(move)))
            {
                taking_moves.emplace_back(move);
            }
        }
    }
    taking_moves.insert(taking_moves.end(), moves.begin(), moves.end());
    return taking_moves;
}

std::vector<Action> get_all_actions(const Board_state& board_state, Piece_color color)
{
    std::vector<Action> all_actions;
    all_actions.reserve(50);
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            auto pos = Position{row, col};
            if ((board_state(pos) == 0) || (color == Piece_color::white && (board_state(pos) < 0)) ||
                (color == Piece_color::black && (board_state(pos) > 0)))
            {
                continue;
            }
            auto actions = get_actions_on_square(pos, board_state);
            all_actions.insert(all_actions.end(), actions.begin(), actions.end());
        }
    }
    return all_actions;
}

std::vector<Action> get_actions_on_square(const Position& position, const Board_state& board_state)
{
    std::vector<Action> all_actions;
    int sq = board_state(position);
    switch (sq)
    {
    case Piece_type::white_tower:
    case Piece_type::black_tower: {
        auto moves = get_tower_moves(position, board_state);
        auto actions = convert_to_actions(position, moves);
        all_actions.insert(all_actions.end(), actions.begin(), actions.end());
        break;
    }
    case Piece_type::white_knight:
    case Piece_type::black_knight: {
        auto moves = get_horse_moves(position, board_state);
        auto actions = convert_to_actions(position, moves);
        all_actions.insert(all_actions.end(), actions.begin(), actions.end());
        break;
    }
    case Piece_type::white_bishop:
    case Piece_type::black_bishop: {
        auto moves = get_bishop_moves(position, board_state);
        auto actions = convert_to_actions(position, moves);
        all_actions.insert(all_actions.end(), actions.begin(), actions.end());
        break;
    }
    case Piece_type::white_queen:
    case Piece_type::black_queen: {
        auto moves = get_queen_moves(position, board_state);
        auto actions = convert_to_actions(position, moves);
        all_actions.insert(all_actions.end(), actions.begin(), actions.end());
        break;
    }
    case Piece_type::white_king:
    case Piece_type::black_king: {
        auto moves = get_king_moves(position, board_state);
        auto actions = convert_to_actions(position, moves);
        all_actions.insert(all_actions.end(), actions.begin(), actions.end());
        break;
    }
    case Piece_type::white_pawn:
    case Piece_type::black_pawn: {
        auto moves = get_pawn_moves(position, board_state);
        auto actions = convert_to_actions(position, moves);
        all_actions.insert(all_actions.end(), actions.begin(), actions.end());
        break;
    }
    default:
        break;
    }
    return all_actions;
}
