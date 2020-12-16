#include "Tree_search.hpp"

#include "Moves.hpp"

#include <algorithm>
#include <iostream>
#include <limits>

Node::Node(const Board_state& state, Action action, Piece_color color)
    : state{state}, this_action{std::move(action)}, color{color}, children()
{
    actions = get_all_actions(this->state, color);
}

void Node::add_child(const Action& action, bool debug, int depth, Piece_color maximizing_color)
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
    Piece_color other_color = (color == Piece_color::white) ? Piece_color::black : Piece_color::white;
    Board_state new_state = state;
    new_state.move(action.first, action.second);
    int val = new_state.value_of_state(maximizing_color);
    if (debug)
    {
        new_state.draw_board();
        std::cout << "Move value: " << val << std::endl;
    }
    children.push_back(std::make_unique<Node>(new_state, action, other_color));
}

int Tree_search::search(std::unique_ptr<Node>& node, int depth, int alpha, int beta, bool maximizing_player)
{
    queries++;
    if (depth == config_.search_depth)
    {
        int value = node->state.value_of_state(color);
        if (config_.debug)
        {
            std::cout << "\nDepth: " << depth << ". Reached leaf node. Value: " << value << std::endl;
        }
        node->value = value;
        return value;
    }
    if (maximizing_player)
    {
        int best_value = std::numeric_limits<int>::min();
        node->children.reserve(node->actions.size());
        for (const auto& action : node->actions)
        {
            node->add_child(action, config_.debug, depth, root_node->color);
            int value = search(node->children.back(), depth + 1, alpha, beta, !maximizing_player);
            best_value = std::max(value, best_value);
            alpha = std::max(alpha, best_value);
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
                    // TODO check what to do here
                    best_value -= 1;
                    break;
                }
            }
        }
        if (config_.debug)
        {
            std::cout << "Node value: " << best_value << std::endl;
        }
        node->value = best_value;
        return best_value;
    }
    else
    {
        int best_value = std::numeric_limits<int>::max();
        node->children.reserve(node->actions.size());
        for (const auto& action : node->actions)
        {
            node->add_child(action, config_.debug, depth, root_node->color);
            int value = search(node->children.back(), depth + 1, alpha, beta, !maximizing_player);
            best_value = std::min(value, best_value);
            beta = std::min(beta, best_value);
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
                    // TODO check what to do here
                    best_value -= 1;
                    break;
                }
            }
        }
        if (config_.debug)
        {
            std::cout << "Node value: " << best_value << std::endl;
        }
        node->value = best_value;
        return best_value;
    }
}

Action Tree_search::get_best_action()
{
    if (config_.debug_best_action)
    {
        std::cout << "\n\n\nRetreiving best actions" << std::endl;
        std::cout << "Queries done: " << queries << std::endl;
        root_node->state.draw_board();
    }
    std::sort(
        root_node->children.begin(), root_node->children.end(),
        [](const std::unique_ptr<Node>& a, const std::unique_ptr<Node>& b) -> bool { return a->value > b->value; });
    int i = 0;
    int value = root_node->state.value_of_state(color);
    for (const auto& node : root_node->children)
    {
        ++i;
        if (i > config_.debug_n_actions)
        {
            break;
        }
        if (config_.debug_best_action)
        {
            std::cout << node->this_action;
            std::cout << "Value: " << value << " -> " << node->value << "\n\n";
        }
    }
    return root_node->children[0]->this_action;
}
