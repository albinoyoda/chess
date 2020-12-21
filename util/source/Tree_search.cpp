#include "Tree_search.hpp"

#include "Moves.hpp"

#include <algorithm>
#include <iostream>
#include <limits>

Node::Node(const Board_state& state, Action action, Piece_color color, bool king_dead)
    : state(state), this_action{std::move(action)}, color{color}
{
    if (!king_dead)
    {
        // Check if there is a mate
        color == Piece_color::white ? get_all_actions(this->state, Piece_color::black) :
                                      get_all_actions(this->state, Piece_color::white);
        actions = get_all_actions(this->state, color);
    }
}

Node Node::traverse(const Action& action, bool debug, int depth, Piece_color maximizing_color)
{
    if (debug)
    {
        std::cout << "\n\nDepth: " << depth << std::endl;
        if (color == Piece_color::white)
        {
            std::cout << "White turn to move:" << std::endl;
        }
        else
        {
            std::cout << "Black turn to move:" << std::endl;
        }
        std::cout << "Performing move: " << action;
        state.draw_board();
    }
    Board_state new_state = state;
    bool king_dead = std::abs(new_state(action.second)) == 5;
    new_state.move(action.first, action.second);
    if (debug)
    {
        int val = new_state.value_of_state(maximizing_color);
        new_state.draw_board();
        std::cout << "Move value: " << val << std::endl;
    }
    Piece_color new_color;
    if (depth % 2)
    {
        new_color = maximizing_color;
    }
    else
    {
        new_color = maximizing_color == Piece_color::white ? Piece_color::black : Piece_color::white;
    }
    return Node{new_state, action, new_color, king_dead};
}

int Tree_search::search(Node& node, int depth, int alpha, int beta, bool maximizing_player)
{
    queries++;
    if (depth == config_.search_depth)
    {
        int value = node.state.value_of_state(color);
        if (config_.debug)
        {
            std::cout << "\nDepth: " << depth << ". Reached leaf node. Value: " << value << std::endl;
        }
        return value;
    }
    if (maximizing_player)
    {
        int best_value = std::numeric_limits<int>::min() + 1000;
        for (const auto& action : node.actions)
        {
            Node child = node.traverse(action, config_.debug, depth, root_node.color);
            int value = search(child, depth + 1, alpha, beta, !maximizing_player);
            best_value = std::max(value, best_value);
            bool set_alpha = false;
            if (alpha < best_value)
            {
                set_alpha = true;
                alpha = std::max(alpha, best_value);
            }
            if (node.is_root)
            {
                root_child_values.emplace_back(action, value);
            }
            if (config_.debug)
            {
                std::cout << "Depth: " << depth << ", alpha = " << alpha << ", beta = " << beta << std::endl;
            }
            if (config_.prune)
            {
                if (alpha >= beta)
                {
                    if (config_.debug)
                    {
                        std::cout << "Pruning Tree!" << std::endl;
                    }
                    if (!set_alpha)
                    {
                        best_value -= 1;
                    }
                    break;
                }
            }
        }
        if (config_.debug)
        {
            std::cout << "Node value: " << best_value << std::endl;
        }
        return best_value;
    }
    else
    {
        int best_value = std::numeric_limits<int>::max() - 1000;
        for (const auto& action : node.actions)
        {
            Node child = node.traverse(action, config_.debug, depth, root_node.color);
            int value = search(child, depth + 1, alpha, beta, !maximizing_player);
            best_value = std::min(value, best_value);
            beta = std::min(beta, best_value);
            bool set_beta = false;
            if (beta < best_value)
            {
                set_beta = true;
                beta = std::min(beta, best_value);
            }
            if (config_.debug)
            {
                std::cout << "Depth: " << depth << ", alpha = " << alpha << ", beta = " << beta << std::endl;
            }
            if (config_.prune)
            {
                if (alpha >= beta)
                {
                    if (config_.debug)
                    {
                        std::cout << "Pruning Tree" << std::endl;
                    }
                    if (!set_beta)
                    {
                        best_value -= 1;
                    }
                    break;
                }
            }
        }
        if (config_.debug)
        {
            std::cout << "Node value: " << best_value << std::endl;
        }
        return best_value;
    }
}

Action Tree_search::get_best_action()
{
    if (config_.debug_best_action)
    {
        std::cout << "\n\n\nRetreiving best actions" << std::endl;
        std::cout << "Queries done: " << queries << std::endl;
        root_node.state.draw_board();
    }
    std::sort(root_child_values.begin(), root_child_values.end(),
              [](const Action_value_pair& a, const Action_value_pair& b) -> bool { return a.second > b.second; });
    int i = 0;
    int value = root_node.state.value_of_state(color);
    for (const auto& action_value_pair : root_child_values)
    {
        ++i;
        if (i > config_.debug_n_actions)
        {
            break;
        }
        if (config_.debug_best_action)
        {
            std::cout << action_value_pair.first;
            std::cout << "Value: " << value << " -> " << action_value_pair.second << "\n\n";
        }
    }
    return root_child_values[0].first;
}
void Tree_search::find_best_action()
{
    search(root_node, 0, std::numeric_limits<int>::min() + 1000, std::numeric_limits<int>::max() - 1000, true);
}
