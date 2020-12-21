#include "Moves.hpp"
#include "Tree_search.hpp"

#include "gtest/gtest.h"
#include <Test_functions.hpp>

TEST(TestSuite, test_tree_search_pawn_depth_1)
{
    Board_state board_state{"00bP000000000000"
                            "wT00wP0000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};

    Tree_search_config config{};
    config.search_depth = 1;

    Tree_search tree_search{config, board_state, Piece_color::black};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();
    ASSERT_EQ(best_action.second.row, 1);
    ASSERT_EQ(best_action.second.col, 0);
}

TEST(TestSuite, test_tree_search_tower_depth_1)
{
    Board_state board_state{"bT000000000000wT"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wP00000000000000"};

    Tree_search_config config{};
    config.search_depth = 1;

    Tree_search tree_search{config, board_state, Piece_color::black};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();

    ASSERT_EQ(best_action.second.row, 0);
    ASSERT_EQ(best_action.second.col, 7);
}

TEST(TestSuite, test_tree_search_depth_2_simple)
{
    Board_state board_state{"0000000000000000"
                            "0000000000000000"
                            "000000bP0000bP00"
                            "0000000000000000"
                            "0000wP0000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};

    Tree_search_config config{};
    config.search_depth = 3;
    //    config.debug_best_action = true;

    Tree_search tree_search{config, board_state, Piece_color::black};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();

    ASSERT_EQ(best_action.second.row, 3);
    ASSERT_EQ(best_action.second.col, 6);
}

TEST(TestSuite, test_tree_search_depth_2)
{
    Board_state board_state{"0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "00bP00bP00000000"
                            "wP00wP0000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};

    Tree_search_config config{};
    config.search_depth = 3;
    config.prune = true;
    //    config.debug = true;
    //    config.debug_best_action = true;

    Tree_search tree_search{config, board_state, Piece_color::black};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();

    ASSERT_EQ(best_action.second.row, 4);
    ASSERT_EQ(best_action.second.col, 2);
}

TEST(TestSuite, test_tree_search_mate_in_2_puzzle)
{
    Board_state board_state{"bT0000bQbK0000bT"
                            "bPbB00000000bPbP"
                            "00bH0000wPbB0000"
                            "0000wB0000wQ0000"
                            "bP00bP0000000000"
                            "0000wP0000000000"
                            "0000wB0000wPwPwP"
                            "wTwH0000wT00wK00"};

    get_all_actions(board_state, Piece_color::black);

    Chess_board chess_board{};
    chess_board.board_state_ = board_state;
    chess_board.draw_board(0, true);

    Tree_search_config config{};
    config.search_depth = 6;
    config.prune = true;
    config.debug = false;
    config.debug_best_action = true;
    config.debug_n_actions = 100;

    Tree_search tree_search{config, board_state, Piece_color::white};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();

    //    ASSERT_EQ(best_action.second.row, 1);
    //    ASSERT_EQ(best_action.second.col, 2);
}

TEST(TestSuite, test_tree_search_mate_in_2_puzzle_reduced)
{
    Board_state board_state{"000000bPbK0000bT"
                            "0000000000000000"
                            "00000000wP00bP00"
                            "0000wB0000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000wB0000000000"
                            "000000000000wK00"};

    get_all_actions(board_state, Piece_color::black);

    Chess_board chess_board{};
    chess_board.board_state_ = board_state;
    chess_board.draw_board(0, true);

    Tree_search_config config{};
    config.search_depth = 4;
    config.prune = true;
    config.debug = false;
    config.debug_best_action = true;
    config.debug_n_actions = 100;

    Tree_search tree_search{config, board_state, Piece_color::white};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();

    //    ASSERT_EQ(best_action.second.row, 1);
    //    ASSERT_EQ(best_action.second.col, 2);
}

TEST(TestSuite, test_tree_search_test_expansion)
{
    Board_state board_state{"00000000bK000000"
                            "0000000000wP0000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000wK0000000000"};

    Tree_search_config config{};
    config.search_depth = 6;
    config.prune = true;
    config.debug = true;
    config.debug_best_action = true;
    config.debug_n_actions = 100;

    Tree_search tree_search{config, board_state, Piece_color::white};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();

    ASSERT_EQ(tree_search.queries, 2);
}

// mate in 4 config
//    Board_state board_state{"00000000000000wT"
//                            "0000bP00bQ00bPbP"
//                            "000000bK00bP0000"
//                            "00bP00bH00wQ0000"
//                            "000000wH00wP0000"
//                            "00000000wT000000"
//                            "00wPwP0000000000"
//                            "000000000000wK00"};

// siegbert-tarrash-vs-max-kurschner
