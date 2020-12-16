#ifndef CHESS_PROJECT_TEST_FUNCTIONS_HPP
#define CHESS_PROJECT_TEST_FUNCTIONS_HPP

#include "Types.hpp"

#include <map>
#include <vector>

bool is_move_in_vector(const Position& pos, const std::vector<Position>& moves);

bool is_action_in_vector(const Action& action, const std::vector<Action>& actions);

bool is_action_in_vector_and_pop(const Action& action, std::vector<Action>& actions);

#endif // CHESS_PROJECT_TEST_FUNCTIONS_HPP
