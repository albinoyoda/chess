#include "../include/Chess_board.hpp"


Chess_board::Chess_board()
{
    board_state_ =
            {-1, -2, -3, -4, -5, -3, -2, -1,
             -6, -6, -6, -6, -6, -6, -6, -6,
             0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0,
             6, 6, 6, 6, 6, 6, 6, 6,
             1, 2, 3, 4, 5, 3, 2, 1};
}

Chess_board::Chess_board(std::array<std::array<int, 8>, 8> board_state_)
{
    board_state_ = board_state_;
}