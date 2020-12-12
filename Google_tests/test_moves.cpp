#include "Moves.hpp"

#include "gtest/gtest.h"

bool is_move_in_vector(const Position& pos, const std::vector<Position>& moves)
{
    for (const auto& move : moves)
    {
        if (move.row == pos.row && move.col == pos.col)
        {
            return true;
        }
    }
    return false;
}

TEST(TestSuite, test_black_pawn_opening)
{
    Board_state board_state{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                            {-6, -6, -6, -6, -6, -6, -6, -6},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {6, 6, 6, 6, 6, 6, 6, 6},
                            {1, 2, 3, 4, 5, 3, 2, 1}};

    auto possible_moves = get_pawn_moves(Position{1, 0}, board_state);

    ASSERT_EQ(possible_moves.size(), 2);
    ASSERT_TRUE(is_move_in_vector(Position{2, 0}, possible_moves));
    ASSERT_TRUE(is_move_in_vector(Position{3, 0}, possible_moves));
}

TEST(TestSuite, test_black_pawn_take_border)
{
    Board_state board_state{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                            {0, -6, -6, -6, -6, -6, -6, -6},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {-6, 0, 0, 0, 0, 0, 0, 0},
                            {6, 6, 6, 6, 6, 6, 6, 6},
                            {1, 2, 3, 4, 5, 3, 2, 1}};

    auto possible_moves = get_pawn_moves(Position{5, 0}, board_state);

    ASSERT_EQ(possible_moves.size(), 1);
    ASSERT_TRUE(is_move_in_vector(Position{6, 1}, possible_moves));
}

TEST(TestSuite, test_black_pawn_take_border_right)
{
    Board_state board_state{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                            {0, -6, -6, -6, -6, -6, -6, -6},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, -6},
                            {6, 6, 6, 6, 6, 6, 6, 6},
                            {1, 2, 3, 4, 5, 3, 2, 1}};

    auto possible_moves = get_pawn_moves(Position{5, 7}, board_state);

    ASSERT_EQ(possible_moves.size(), 1);
    ASSERT_TRUE(is_move_in_vector(Position{6, 6}, possible_moves));
}

TEST(TestSuite, test_white_pawn_opening)
{
    Board_state board_state{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                            {-6, -6, -6, -6, -6, -6, -6, -6},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {6, 6, 6, 6, 6, 6, 6, 6},
                            {1, 2, 3, 4, 5, 3, 2, 1}};

    auto possible_moves = get_pawn_moves(Position{6, 0}, board_state);

    ASSERT_EQ(possible_moves.size(), 2);
    ASSERT_TRUE(is_move_in_vector(Position{5, 0}, possible_moves));
    ASSERT_TRUE(is_move_in_vector(Position{4, 0}, possible_moves));
}

TEST(TestSuite, test_white_pawn_opening_blocked)
{
    Board_state board_state{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                            {-6, -6, -6, -6, -6, -6, -6, -6},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 2, 0, 0, 0, 0, 0},
                            {6, 6, 6, 6, 6, 6, 6, 6},
                            {1, 0, 3, 4, 5, 3, 2, 1}};

    auto possible_moves = get_pawn_moves(Position{6, 2}, board_state);

    ASSERT_EQ(possible_moves.size(), 1);
    ASSERT_TRUE(is_move_in_vector(Position{4, 2}, possible_moves));
}

TEST(TestSuite, test_white_pawn_take)
{
    Board_state board_state{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                            {-6, -6, -6, -6, -6, -6, -6, -6},
                            {0, 6, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {6, 0, 6, 6, 6, 6, 6, 6},
                            {1, 2, 3, 4, 5, 3, 2, 1}};

    auto possible_moves = get_pawn_moves(Position{2, 1}, board_state);

    ASSERT_EQ(possible_moves.size(), 2);
    ASSERT_TRUE(is_move_in_vector(Position{1, 0}, possible_moves));
    ASSERT_TRUE(is_move_in_vector(Position{1, 2}, possible_moves));
}

TEST(TestSuite, test_white_pawn_take_border)
{
    Board_state board_state{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                            {-6, -6, -6, -6, -6, -6, -6, -6},
                            {6, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {6, 0, 6, 6, 6, 6, 6, 6},
                            {1, 2, 3, 4, 5, 3, 2, 1}};

    auto possible_moves = get_pawn_moves(Position{2, 0}, board_state);

    ASSERT_EQ(possible_moves.size(), 1);
    ASSERT_TRUE(is_move_in_vector(Position{1, 1}, possible_moves));
}

TEST(TestSuite, test_white_pawn_take_border_right)
{
    Board_state board_state{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                            {-6, -6, -6, -6, -6, -6, -6, -6},
                            {0, 0, 0, 0, 0, 0, 0, 6},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0},
                            {6, 0, 6, 6, 6, 6, 6, 6},
                            {1, 2, 3, 4, 5, 3, 2, 1}};

    auto possible_moves = get_pawn_moves(Position{2, 7}, board_state);

    ASSERT_EQ(possible_moves.size(), 1);
    ASSERT_TRUE(is_move_in_vector(Position{1, 6}, possible_moves));
}