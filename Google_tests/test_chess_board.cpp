#include "Chess_board.hpp"

#include "gtest/gtest.h"

TEST(TestSuite, test_coordinates_to_command)
{
    Chess_board chess_board{};
    auto coord1 = chess_board.coordinate_from_command("a"[0], "1"[0]);
    auto coord2 = chess_board.coordinate_from_command("a"[0], "8"[0]);
    auto coord3 = chess_board.coordinate_from_command("h"[0], "8"[0]);
    auto coord4 = chess_board.coordinate_from_command("h"[0], "1"[0]);

    ASSERT_EQ(coord1.row, 7);
    ASSERT_EQ(coord1.col, 0);

    ASSERT_EQ(coord2.row, 7);
    ASSERT_EQ(coord2.col, 7);

    ASSERT_EQ(coord3.row, 0);
    ASSERT_EQ(coord3.col, 7);

    ASSERT_EQ(coord4.row, 0);
    ASSERT_EQ(coord4.col, 0);
}

TEST(TestSuite, test_move_piece)
{
    Chess_board chess_board{};
    chess_board.move("b4d4");
    auto prev_coordinate = chess_board.coordinate_from_command("b"[0], "4"[0]);
    auto new_coordinate = chess_board.coordinate_from_command("d"[0], "4"[0]);

    ASSERT_EQ(chess_board.board_state_[prev_coordinate.row][prev_coordinate.col], 0);
    ASSERT_EQ(chess_board.board_state_[new_coordinate.row][new_coordinate.col], 6);
}
