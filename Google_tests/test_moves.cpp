#include "Moves.hpp"
#include "Test_functions.hpp"

#include "gtest/gtest.h"

TEST(TestSuite, test_moves)
{
    Board_state board_state{"bT0000bQbK000000"
                            "bPbB000000000000"
                            "00bH000000000000"
                            "0000wB0000wQwP00"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wTwH0000wK000000"};
    auto black_actions = get_all_actions(board_state, Piece_color::black);
    // TODO castling
    // tower
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 0}, {0, 1}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 0}, {0, 2}}, black_actions));

    // queen
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {0, 1}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {0, 2}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {1, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {1, 2}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {1, 4}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {2, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {2, 5}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {3, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {4, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {5, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {6, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {7, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 3}, {3, 6}}, black_actions));

    // king
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 4}, {1, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 4}, {1, 4}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 4}, {1, 5}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{0, 4}, {0, 5}}, black_actions));

    // pawn
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 0}, {2, 0}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 0}, {3, 0}}, black_actions));

    // bishop
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 1}, {0, 2}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 1}, {2, 0}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 1}, {2, 2}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 1}, {3, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 1}, {4, 4}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 1}, {5, 5}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 1}, {6, 6}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{1, 1}, {7, 7}}, black_actions));

    // horse
    EXPECT_TRUE(is_action_in_vector_and_pop({{2, 1}, {0, 2}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{2, 1}, {1, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{2, 1}, {3, 3}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{2, 1}, {4, 2}}, black_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{2, 1}, {4, 0}}, black_actions));

    EXPECT_TRUE(black_actions.empty());
    for (const auto& action : black_actions)
    {
        std::cout << action;
    }

    auto white_actions = get_all_actions(board_state, Piece_color::white);

    // bishop
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {2, 1}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {4, 1}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {5, 0}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {4, 3}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {5, 4}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {6, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {2, 3}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {1, 4}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {0, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 2}, {7, 6}}, white_actions));

    // queen
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {3, 4}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {3, 3}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {2, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {1, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {0, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {4, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {5, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {6, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {7, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {2, 4}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {1, 3}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {0, 2}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {4, 4}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {5, 3}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {6, 2}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {2, 6}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {1, 7}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {4, 6}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 5}, {5, 7}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{3, 6}, {2, 6}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 0}, {1, 0}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 0}, {6, 0}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 0}, {5, 0}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 0}, {4, 0}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 0}, {3, 0}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 0}, {2, 0}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 1}, {6, 3}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 1}, {5, 2}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 1}, {5, 0}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 4}, {6, 5}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 4}, {6, 4}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 4}, {6, 3}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 4}, {7, 3}}, white_actions));
    EXPECT_TRUE(is_action_in_vector_and_pop({{7, 4}, {7, 5}}, white_actions));

    EXPECT_TRUE(white_actions.empty());
    for (const auto& action : white_actions)
    {
        std::cout << action;
    }
}

TEST(TestSuite, test_castling_black1)
{
    Board_state board_state{"bT000000bK000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};
    auto black_actions = get_all_actions(board_state, Piece_color::black);
    EXPECT_TRUE(is_action_in_vector({{0, 4}, {0, 2}}, black_actions));
    board_state.move({0, 4}, {0, 2});
    EXPECT_TRUE(board_state({0, 3}) == -1);
    EXPECT_TRUE(board_state({0, 2}) == -5);
}

TEST(TestSuite, test_castling_black2)
{
    Board_state board_state{"00000000bK0000bT"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"};
    auto black_actions = get_all_actions(board_state, Piece_color::black);
    EXPECT_TRUE(is_action_in_vector({{0, 4}, {0, 6}}, black_actions));
    board_state.move({0, 4}, {0, 6});
    EXPECT_TRUE(board_state({0, 5}) == -1);
    EXPECT_TRUE(board_state({0, 6}) == -5);
}

TEST(TestSuite, test_castling_white1)
{
    Board_state board_state{"0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wT000000wK000000"};
    auto black_actions = get_all_actions(board_state, Piece_color::white);
    EXPECT_TRUE(is_action_in_vector({{7, 4}, {7, 2}}, black_actions));
    board_state.move({7, 4}, {7, 2});
    EXPECT_TRUE(board_state({7, 3}) == 1);
    EXPECT_TRUE(board_state({7, 2}) == 5);
}

TEST(TestSuite, test_castling_white2)
{
    Board_state board_state{"00000000bK0000bT"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "00000000wK0000wT"};
    auto black_actions = get_all_actions(board_state, Piece_color::white);
    EXPECT_TRUE(is_action_in_vector({{7, 4}, {7, 6}}, black_actions));
    board_state.move({7, 4}, {7, 6});
    EXPECT_TRUE(board_state({7, 5}) == 1);
    EXPECT_TRUE(board_state({7, 6}) == 5);
}

TEST(TestSuite, test_promotion_white)
{
    Board_state board_state{"00000000bK0000bT"
                            "00wP000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "00000000wK0000wT"};
    board_state.move({1, 1}, {0, 1});
    EXPECT_TRUE(board_state({0, 1}) == 4);
}

TEST(TestSuite, test_promotion_black)
{
    Board_state board_state{"00000000bK0000bT"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000bP0000000000"
                            "00000000wK0000wT"};
    board_state.move({6, 2}, {7, 2});
    EXPECT_TRUE(board_state({7, 2}) == -4);
}