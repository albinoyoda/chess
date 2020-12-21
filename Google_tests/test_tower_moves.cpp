#include "Moves.hpp"

#include "gtest/gtest.h"
#include <Test_functions.hpp>

TEST(TestSuite, test_black_tower_opening1)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_tower_moves(Position{0, 0}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 0);
}

TEST(TestSuite, test_black_tower_opening2)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_tower_moves(Position{0, 7}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 0);
}

TEST(TestSuite, test_black_tower_open_area)
{
    Board_state board_state{"00bHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "00bT000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_tower_moves(Position{3, 1}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 11);
}

TEST(TestSuite, test_white_tower_open_area)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000wT0000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "00wHwBwQwKwBwHwT"};

    auto possible_moves = get_tower_moves(Position{4, 2}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 11);
}

TEST(TestSuite, test_white_tower_opening1)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_tower_moves(Position{7, 0}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 0);
}

TEST(TestSuite, test_white_tower_opening2)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_tower_moves(Position{7, 7}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 0);
}