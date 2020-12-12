#ifndef CHESS_PROJECT_MOVES_HPP
#define CHESS_PROJECT_MOVES_HPP

#include "Types.hpp"

#include <ostream>
#include <vector>

std::vector<Position> get_pawn_moves(const Position& position, const Board_state& board_state);

#endif // CHESS_PROJECT_MOVES_HPP
