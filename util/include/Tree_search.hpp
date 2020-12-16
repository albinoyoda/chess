#ifndef CHESS_PROJECT_TREE_SEARCH_HPP
#define CHESS_PROJECT_TREE_SEARCH_HPP

#include "Chess_board.hpp"

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

    explicit Node(const Board_state& state, Action action, Piece_color color);

    Board_state state;
    Action this_action;
    Piece_color color{};
    std::vector<Action> actions;
    std::vector<std::unique_ptr<Node>> children;
    int value{};

    void add_child(const Action& action, bool debug, int depth, Piece_color maximizing_color);
};

class Tree_search
{
public:
    Tree_search() = delete;
    explicit Tree_search(const Tree_search_config& config, Board_state board_state, Piece_color color)
        : config_{config}, color{color}
    {
        root_node = std::make_unique<Node>(board_state, Action{}, color);
    };

    int search(std::unique_ptr<Node>& node, int depth, int alpha, int beta, bool maximising_player);

    Action get_best_action();

    Tree_search_config config_;
    Piece_color color;
    std::unique_ptr<Node> root_node;
    int queries = 0;
};

#endif // CHESS_PROJECT_TREE_SEARCH_HPP
