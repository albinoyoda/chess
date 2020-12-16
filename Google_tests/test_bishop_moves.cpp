#include "Moves.hpp"

#include "gtest/gtest.h"
#include <Test_functions.hpp>

TEST(TestSuite, test_black_bishop_opening1)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_bishop_moves(Position{0, 2}, board_state);
    ASSERT_EQ(possible_moves.size(), 0);
}

TEST(TestSuite, test_black_bishop_opening2)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_bishop_moves(Position{0, 5}, board_state);
    ASSERT_EQ(possible_moves.size(), 0);
}

TEST(TestSuite, test_black_bishop_open_area)
{
    Board_state board_state{"00bHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "00bB000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_bishop_moves(Position{3, 1}, board_state);
    ASSERT_EQ(possible_moves.size(), 6);
}

TEST(TestSuite, test_white_bishop_open_area)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000wB0000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "00wHwBwQwKwBwHwT"};

    auto possible_moves = get_bishop_moves(Position{4, 2}, board_state);
    ASSERT_EQ(possible_moves.size(), 7);
}

TEST(TestSuite, test_white_bishop_opening1)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_bishop_moves(Position{7, 2}, board_state);
    ASSERT_EQ(possible_moves.size(), 0);
}

TEST(TestSuite, test_white_bishop_opening2)
{
    Board_state board_state{"bTbHbBbQbKbBbHbT"
                            "bPbPbPbPbPbPbPbP"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "0000000000000000"
                            "wPwPwPwPwPwPwPwP"
                            "wTwHwBwQwKwBwHwT"};

    auto possible_moves = get_bishop_moves(Position{7, 5}, board_state);
    ASSERT_EQ(possible_moves.size(), 0);
}