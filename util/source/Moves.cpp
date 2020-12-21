#include "Moves.hpp"

namespace
{
std::vector<std::vector<Action>> convert_to_actions(const Position& pos,
                                                    const std::vector<std::vector<Position>>& moves)
{
    std::vector<Action> taking_actions{};
    taking_actions.reserve(moves[0].size());
    for (const auto& move : moves[0])
    {
        taking_actions.emplace_back(pos, move);
    }
    std::vector<Action> moving_actions{};
    moving_actions.reserve(moves[1].size());
    for (const auto& move : moves[1])
    {
        moving_actions.emplace_back(pos, move);
    }
    return {taking_actions, moving_actions};
}
} // namespace

std::vector<std::vector<Position>> get_pawn_moves(const Position& position, Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(2);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(2);
    bool white = is_white(board_state(position));
    if (white)
    {
        if (position.row > 0)
        {
            //            auto pos = ;
            if (is_free(board_state(position + Position::north())))
            {
                moves.emplace_back(position + Position::north());
            }
            if (position.col > 0)
            {
                if (is_black(board_state(position + Position::north_west())))
                {
                    taking_moves.emplace_back(position + Position::north_west());
                    if (board_state(position + Position::north_west()) == -5)
                    {
                        board_state.black_checked = true;
                    }
                }
            }
            if (position.col < 7)
            {
                if (is_black(board_state(position + Position::north_east())))
                {
                    taking_moves.emplace_back(position + Position::north_east());
                    if (board_state(position + Position::north_east()) == -5)
                    {
                        board_state.black_checked = true;
                    }
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
                    if (board_state(position + Position::south_west()) == 5)
                    {
                        board_state.white_checked = true;
                    }
                }
            }
            if (position.col < 7)
            {
                if (is_white(board_state(position + Position::south_east())))
                {
                    taking_moves.emplace_back(position + Position::south_east());
                    if (board_state(position + Position::south_east()) == 5)
                    {
                        board_state.white_checked = true;
                    }
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
    return {std::move(taking_moves), std::move(moves)};
}

std::vector<std::vector<Position>> get_tower_moves(const Position& position, Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(16);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(4);
    bool color = is_white(board_state(position));
    auto possible_position = position;
    while (possible_position.col > 0)
    {
        possible_position = possible_position + Position::west();
        int sq = board_state(possible_position);
        if (is_free(sq))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(sq))
        {
            taking_moves.emplace_back(possible_position);
            if (std::abs(sq) == 5)
            {
                color ? board_state.black_checked = true : board_state.white_checked = true;
            }
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
        int sq = board_state(possible_position);
        if (is_free(sq))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(sq))
        {
            taking_moves.emplace_back(possible_position);
            if (std::abs(sq) == 5)
            {
                color ? board_state.black_checked = true : board_state.white_checked = true;
            }
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
        int sq = board_state(possible_position);
        if (is_free(sq))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(sq))
        {
            taking_moves.emplace_back(possible_position);
            if (std::abs(sq) == 5)
            {
                color ? board_state.black_checked = true : board_state.white_checked = true;
            }
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
        int sq = board_state(possible_position);
        if (is_free(sq))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(sq))
        {
            taking_moves.emplace_back(possible_position);
            if (std::abs(sq) == 5)
            {
                color ? board_state.black_checked = true : board_state.white_checked = true;
            }
            break;
        }
        else
        {
            break;
        }
    }
    return {std::move(taking_moves), std::move(moves)};
}

std::vector<std::vector<Position>> get_horse_moves(const Position& position, Board_state& board_state)
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
            int sq = board_state(move);
            if (is_free(sq))
            {
                moves.emplace_back(move);
            }
            else if (color != is_white(sq))
            {
                taking_moves.emplace_back(move);
                if (std::abs(sq) == 5)
                {
                    color ? board_state.black_checked = true : board_state.white_checked = true;
                }
            }
        }
    }
    return {std::move(taking_moves), std::move(moves)};
}

std::vector<std::vector<Position>> get_bishop_moves(const Position& position, Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(8);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(4);
    bool color = is_white(board_state(position));
    auto possible_position = position;
    while (possible_position.col > 0 && possible_position.row > 0)
    {
        possible_position = possible_position + Position::north_west();
        int sq = board_state(possible_position);
        if (is_free(sq))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(sq))
        {
            taking_moves.emplace_back(possible_position);
            if (std::abs(sq) == 5)
            {
                color ? board_state.black_checked = true : board_state.white_checked = true;
            }
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
        int sq = board_state(possible_position);
        if (is_free(sq))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(sq))
        {
            taking_moves.emplace_back(possible_position);
            if (std::abs(sq) == 5)
            {
                color ? board_state.black_checked = true : board_state.white_checked = true;
            }
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
        int sq = board_state(possible_position);
        if (is_free(sq))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(sq))
        {
            taking_moves.emplace_back(possible_position);
            if (std::abs(sq) == 5)
            {
                color ? board_state.black_checked = true : board_state.white_checked = true;
            }
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
        int sq = board_state(possible_position);
        if (is_free(sq))
        {
            moves.emplace_back(possible_position);
        }
        else if (color != is_white(sq))
        {
            taking_moves.emplace_back(possible_position);
            if (std::abs(sq) == 5)
            {
                color ? board_state.black_checked = true : board_state.white_checked = true;
            }
            break;
        }
        else
        {
            break;
        }
    }
    return {std::move(taking_moves), std::move(moves)};
}

std::vector<std::vector<Position>> get_queen_moves(const Position& position, Board_state& board_state)
{
    auto tower_moves = get_tower_moves(position, board_state);
    auto bishop_moves = get_bishop_moves(position, board_state);
    tower_moves[0].insert(tower_moves[0].end(), bishop_moves[0].begin(), bishop_moves[0].end());
    tower_moves[1].insert(tower_moves[1].end(), bishop_moves[1].begin(), bishop_moves[1].end());
    return {std::move(tower_moves[0]), std::move(tower_moves[1])};
}

std::vector<std::vector<Position>> get_king_moves(const Position& position, Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(8);
    std::vector<Position> taking_moves{};
    taking_moves.reserve(10);
    std::vector<Position> possible_moves{};
    possible_moves.reserve(10);
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
    if ((color && !board_state.white_checked) || (!color && !board_state.black_checked))
    {
        if (position == Position{7, 4})
        {
            if (board_state(Position{7, 5}) == 0 && board_state(Position{7, 6}) == 0 &&
                board_state(Position{7, 7}) == 1)
            {
                possible_moves.emplace_back(Position{7, 6});
            }
            if (board_state(Position{7, 0}) == 1 && board_state(Position{7, 1}) == 0 &&
                board_state(Position{7, 2}) == 0 && board_state(Position{7, 3}) == 0)
            {
                possible_moves.emplace_back(Position{7, 2});
            }
        }
        else if (position == Position{0, 4})
        {
            if (board_state(Position{0, 5}) == 0 && board_state(Position{0, 6}) == 0 &&
                board_state(Position{0, 7}) == -1)
            {
                possible_moves.emplace_back(Position{0, 6});
            }
            if (board_state(Position{0, 0}) == -1 && board_state(Position{0, 1}) == 0 &&
                board_state(Position{0, 2}) == 0 && board_state(Position{0, 3}) == 0)
            {
                possible_moves.emplace_back(Position{0, 2});
            }
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
    return {std::move(taking_moves), std::move(moves)};
}

std::vector<Action> get_all_actions(Board_state& board_state, Piece_color color)
{
    std::vector<Action> taking_actions;
    taking_actions.reserve(10);
    std::vector<Action> moving_actions;
    moving_actions.reserve(40);
    if (color == Piece_color::white)
    {
        board_state.black_checked = false;
    }
    else
    {
        board_state.white_checked = false;
    }
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
            taking_actions.insert(taking_actions.end(), actions[0].begin(), actions[0].end());
            moving_actions.insert(moving_actions.end(), actions[1].begin(), actions[1].end());
        }
    }
    taking_actions.insert(taking_actions.end(), moving_actions.begin(), moving_actions.end());
    return taking_actions;
}

std::vector<std::vector<Action>> get_actions_on_square(const Position& position, Board_state& board_state)
{
    int sq = board_state(position);
    switch (sq)
    {
    case Piece_type::white_tower:
    case Piece_type::black_tower: {
        auto moves = get_tower_moves(position, board_state);
        return convert_to_actions(position, moves);
    }
    case Piece_type::white_knight:
    case Piece_type::black_knight: {
        auto moves = get_horse_moves(position, board_state);
        return convert_to_actions(position, moves);
    }
    case Piece_type::white_bishop:
    case Piece_type::black_bishop: {
        auto moves = get_bishop_moves(position, board_state);
        return convert_to_actions(position, moves);
    }
    case Piece_type::white_queen:
    case Piece_type::black_queen: {
        auto moves = get_queen_moves(position, board_state);
        return convert_to_actions(position, moves);
    }
    case Piece_type::white_king:
    case Piece_type::black_king: {
        auto moves = get_king_moves(position, board_state);
        return convert_to_actions(position, moves);
    }
    case Piece_type::white_pawn:
    case Piece_type::black_pawn: {
        auto moves = get_pawn_moves(position, board_state);
        return convert_to_actions(position, moves);
    }
    default:
        return {};
    }
}
