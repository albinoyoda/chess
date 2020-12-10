#ifndef CHESS_CHESS_BOARD_HPP
#define CHESS_CHESS_BOARD_HPP

#include <array>


class Chess_board
{
public:
    Chess_board();

    Chess_board(std::array<std::array<int, 8>, 8> board_state_);

    std::array<std::array<int, 8>, 8> board_state_;
};


#endif //CHESS_CHESS_BOARD_HPP
