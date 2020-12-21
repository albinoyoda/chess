#ifndef CHESS_PROJECT_TREE_SEARCH_HPP
#define CHESS_PROJECT_TREE_SEARCH_HPP

#include "Chess_board.hpp"

#include <iostream>
#include <memory>
#include <vector>
struct Tree_search_config
{
    int search_depth{2};
    bool prune{true};
    bool debug{false};
    bool debug_best_action{false};
    int debug_n_actions{25};
};

class Node
{
public:
    Node() = default;

    explicit Node(const Board_state& state, Action action, Piece_color color, bool king_dead);

    Board_state state;
    Action this_action;
    Piece_color color{};
    std::vector<Action> actions{};
    int value{};
    bool is_root{false};

    Node traverse(const Action& action, bool debug, int depth, Piece_color maximizing_color);
};

using Action_value_pair = std::pair<Action, int>;

class Tree_search
{
public:
    Tree_search() = delete;
    explicit Tree_search(const Tree_search_config& config, Board_state board_state, Piece_color color)
        : config_{config}, color{color}, root_node{board_state, Action{}, color, false}
    {
        root_node.is_root = true;
    };

    void find_best_action();

    Action get_best_action();

    Tree_search_config config_;
    Piece_color color;
    Node root_node;
    std::vector<Action_value_pair> root_child_values;
    int queries = 0;

private:
    int search(Node& node, int depth, int alpha, int beta, bool maximising_player);
};

#endif // CHESS_PROJECT_TREE_SEARCH_HPP
