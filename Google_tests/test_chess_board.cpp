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

    ASSERT_EQ(coord2.row, 0);
    ASSERT_EQ(coord2.col, 0);

    ASSERT_EQ(coord3.row, 0);
    ASSERT_EQ(coord3.col, 7);

    ASSERT_EQ(coord4.row, 7);
    ASSERT_EQ(coord4.col, 7);
}

TEST(TestSuite, test_move_piece)
{
    Chess_board chess_board{};
    std::string command{"d2d4"};
    chess_board.move(command);
    auto prev_coordinate = Chess_board::coordinate_from_command(command[0], command[1]);
    auto new_coordinate = Chess_board::coordinate_from_command(command[2], command[3]);

    ASSERT_EQ(chess_board.board_state_(prev_coordinate), 0);
    ASSERT_EQ(chess_board.board_state_(new_coordinate), 6);
}
