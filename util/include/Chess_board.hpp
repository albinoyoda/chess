#ifndef CHESS_CHESS_BOARD_HPP
#define CHESS_CHESS_BOARD_HPP

#include "Types.hpp"

#include <map>

class Chess_board
{
public:
    Chess_board();

    explicit Chess_board(Board_state custom_state);

    void draw_board() const;

    void move(std::string command);

    std::string toChessNote(Position p);

    Position coordinate_from_command(char a, char b);

    Board_state board_state_;
};

#endif // CHESS_CHESS_BOARD_HPP
