#ifndef CHESS_PROJECT_TYPES_HPP
#define CHESS_PROJECT_TYPES_HPP

#include <array>
#include <utility>

enum class Piece_type
{
    pawn = 6,
    tower = 5,
    knight,
    bishop,
    queen,
    king
};

enum class Piece_color
{
    white,
    black
};

using Board_state = std::array<std::array<int, 8>, 8>;

class Position
{
public:
    Position() = default;

    Position(int row, int col) : row(row), col(col){};

    int row;
    int col;
};

#endif // CHESS_PROJECT_TYPES_HPP
