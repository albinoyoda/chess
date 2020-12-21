#include "Moves.hpp"

#include "gtest/gtest.h"
#include <Test_functions.hpp>

TEST(TestSuite, test_black_horse_opening1)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_horse_moves(Position{0, 1}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 2);
}

TEST(TestSuite, test_black_horse_opening2)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_horse_moves(Position{0, 6}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 2);
}

TEST(TestSuite, test_black_horse_open_area)
{
    Board_state board_state{"00bHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "00bH000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_horse_moves(Position{3, 1}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 4);
}

TEST(TestSuite, test_white_horse_take)
{
    Board_state board_state{"00bHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "00wH000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_horse_moves(Position{3, 1}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 6);
}

TEST(TestSuite, test_white_horse_open_area)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000wH0000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "00wHwBwQwKwBwHwT"};

    auto possible_moves = get_horse_moves(Position{4, 2}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 6);
}

TEST(TestSuite, test_black_horse_take)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000bH0000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "00wHwBwQwKwBwHwT"};

    auto possible_moves = get_horse_moves(Position{4, 2}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 8);
}

TEST(TestSuite, test_white_horse_opening1)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_horse_moves(Position{7, 1}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 2);
}

TEST(TestSuite, test_white_horse_opening2)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_horse_moves(Position{7, 6}, board_state);
    ASSERT_EQ(concatenate_vectors(possible_moves).size(), 2);
}