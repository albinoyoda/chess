#include "Moves.hpp"
#include "Tree_search.hpp"

#include "gtest/gtest.h"
#include <Test_functions.hpp>

TEST(TestSuite, test_tree_search_weird)
{
    Board_state board_state{"00000000bK000000"
                            "0000000000000000"
                            "0000000000000000"
                            "00000000000000bQ"
                            "0000000000000000"
                            "bT00000000000000"
                            "0000000000000000"
                            "0000wK0000000000"};

    //    Chess_board chess_board{};
    //    chess_board.board_state_ = board_state;
    //    chess_board.draw_board(0, true);

    Tree_search_config config{};
    config.search_depth = 6;
    //    config.debug_best_action = true;
    //    config.debug_n_actions = 10;

    Tree_search tree_search{config, board_state, Piece_color::black};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();

    ASSERT_TRUE(best_action.first.row != 0);
}

TEST(TestSuite, test_tree_search_king_mate)
{
    Board_state board_state{"00bQ0000bK0000bB"
                            "0000000000000000"
                            "0000000000000000"
                            "00000000000000wB"
                            "0000000000000000"
                            "bT00000000000000"
                            "0000000000000000"
                            "0000wK0000000000"};

    Chess_board chess_board{};
    chess_board.board_state_ = board_state;
    chess_board.draw_board(0, true);

    Tree_search_config config{};
    config.search_depth = 6;
    config.prune = true;
    config.debug_best_action = true;
    config.debug_n_actions = 10;

    Tree_search tree_search{config, board_state, Piece_color::black};
    tree_search.find_best_action();
    Action best_action = tree_search.get_best_action();

    ASSERT_EQ(best_action.first.row, 0);
    ASSERT_EQ(best_action.first.col, 4);
}

TEST(TestSuite, test_king_mate_castling_bishop)
{
    Board_state board_state{"bT000000bK0000bT"
                            "0000000000000000"
                            "0000wB0000000000"
                            "00wK000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};

    auto all_moves = get_king_moves({0, 4}, board_state);

    ASSERT_EQ(concatenate_vectors(all_moves).size(), 5);
}

TEST(TestSuite, test_king_mate_castling_tower)
{
    Board_state board_state{"bT000000bK0000bT"
                            "0000000000000000"
                            "00000000wT000000"
                            "00wK000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};

    get_all_actions(board_state, Piece_color::white);
    auto all_moves = get_king_moves({0, 4}, board_state);

    ASSERT_EQ(concatenate_vectors(all_moves).size(), 5);
}

TEST(TestSuite, test_king_mate_castling_pawn)
{
    Board_state board_state{"bT000000000000bT"
                            "0000000000000000"
                            "00000000000000bK"
                            "00wK00000000wP00"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};

    get_all_actions(board_state, Piece_color::white);
    auto all_moves = get_king_moves({0, 4}, board_state);

    ASSERT_EQ(concatenate_vectors(all_moves).size(), 5);
}

TEST(TestSuite, test_king_mate_castling_queen)
{
    Board_state board_state{"bT000000bK0000bT"
                            "0000000000000000"
                            "00000000wQ000000"
                            "00wK000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};

    get_all_actions(board_state, Piece_color::white);
    auto all_moves = get_king_moves({0, 4}, board_state);

    ASSERT_EQ(concatenate_vectors(all_moves).size(), 5);
}

TEST(TestSuite, test_king_mate_castling_horse)
{
    Board_state board_state{"bT000000bK0000bT"
                            "0000000000000000"
                            "000000wH00000000"
                            "00wK000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};

    get_all_actions(board_state, Piece_color::white);
    auto all_moves = get_king_moves({0, 4}, board_state);

    ASSERT_EQ(concatenate_vectors(all_moves).size(), 5);
}