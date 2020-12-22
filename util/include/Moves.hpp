#ifndef CHESS_PROJECT_MOVES_HPP
#define CHESS_PROJECT_MOVES_HPP

#include "Board_state.hpp"
#include "Types.hpp"

#include <ostream>
#include <vector>

class Board_state;

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

std::vector<std::vector<Position>> get_pawn_moves(const Position& position, const Board_state& board_state);

std::vector<std::vector<Position>> get_tower_moves(const Position& position, const Board_state& board_state);

std::vector<std::vector<Position>> get_horse_moves(const Position& position, const Board_state& board_state);

std::vector<std::vector<Position>> get_bishop_moves(const Position& position, const Board_state& board_state);

std::vector<std::vector<Position>> get_queen_moves(const Position& position, const Board_state& board_state);

std::vector<std::vector<Position>> get_king_moves(const Position& position, const Board_state& board_state);

std::vector<std::vector<Action>> get_actions_on_square(const Position& position, const Board_state& board_state);

std::vector<Action> get_all_actions(const Board_state& board_state, Piece_color color);

bool is_checked(const Board_state& board_state, Piece_color color);

#endif // CHESS_PROJECT_MOVES_HPP
