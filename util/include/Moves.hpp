#ifndef CHESS_PROJECT_MOVES_HPP
#define CHESS_PROJECT_MOVES_HPP

#include "Types.hpp"

#include <ostream>
#include <vector>

constexpr bool is_white(int val)
{
    return val > 0;
}

constexpr bool is_black(int val)
{
    return val < 0;
}

constexpr bool is_free(int val)
{
    return val == 0;
}

constexpr bool is_inside_board(const Position& pos)
{
    return pos.col >= 0 && pos.col <= 7 && pos.row >= 0 && pos.row <= 7;
}

std::vector<Position> get_pawn_moves(const Position& position, const Board_state& board_state);

std::vector<Position> get_tower_moves(const Position& position, const Board_state& board_state);

std::vector<Position> get_horse_moves(const Position& position, const Board_state& board_state);

std::vector<Position> get_bishop_moves(const Position& position, const Board_state& board_state);

std::vector<Position> get_queen_moves(const Position& position, const Board_state& board_state);

std::vector<Position> get_king_moves(const Position& position, const Board_state& board_state);

std::vector<Action> get_actions_on_square(const Position& position, const Board_state& board_state);

std::vector<Action> get_all_actions(const Board_state& board_state, Piece_color color);

#endif // CHESS_PROJECT_MOVES_HPP
