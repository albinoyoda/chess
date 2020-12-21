#include "Test_functions.hpp"

bool is_move_in_vector(const Position& pos, const std::vector<Position>& moves)
{
    for (const auto& move : moves)
    {
        if (move == pos)
        {
            return true;
        }
    }
    return false;
}

bool is_move_in_vector(const Position& pos, const std::vector<std::vector<Position>>& all_moves)
{
    for (const auto& moves : all_moves)
    {
        for (const auto& move : moves)
        {
            if (move == pos)
            {
                return true;
            }
        }
    }
    return false;
}

bool is_action_in_vector(const Action& action, const std::vector<Action>& actions)
{
    for (const auto& move : actions)
    {
        if ((move.first == action.first) && (move.second == action.second))
        {
            return true;
        }
    }
    return false;
}

bool is_action_in_vector_and_pop(const Action& action, std::vector<Action>& actions)
{
    for (auto it = actions.begin(); it < actions.end(); it++)
    {
        if ((it->first == action.first) && (it->second == action.second))
        {
            actions.erase(it);
            return true;
        }
    }
    return false;
}