#ifndef CHESS_PROJECT_TYPES_HPP
#define CHESS_PROJECT_TYPES_HPP

#include <array>
#include <cassert>
#include <utility>

enum Piece_type : int8_t
{
    unknown = 0,
    white_tower = 1,
    white_knight = 2,
    white_bishop = 3,
    white_queen = 4,
    white_king = 5,
    white_pawn = 6,
    black_tower = -1,
    black_knight = -2,
    black_bishop = -3,
    black_queen = -4,
    black_king = -5,
    black_pawn = -6,
};

std::ostream& operator<<(std::ostream& os, const Piece_type& action);

enum Piece_color : bool
{
    white = true,
    black = false,
};

std::ostream& operator<<(std::ostream& os, const Piece_color& action);

static constexpr int PawnValueMg = 126, PawnValueEg = 208, KnightValueMg = 781, KnightValueEg = 854,
                     BishopValueMg = 825, BishopValueEg = 915, RookValueMg = 1276, RookValueEg = 1380,
                     QueenValueMg = 2538, QueenValueEg = 2682, KingValueMg = 253800, KingValueEg = 268200;

class Position
{
public:
    constexpr Position() = default;

    constexpr Position(int row, int col) : row(row), col(col){};

    static constexpr Position north() { return Position{-1, 0}; }
    static constexpr Position south() { return Position{1, 0}; }
    static constexpr Position east() { return Position{0, 1}; }
    static constexpr Position west() { return Position{0, -1}; }

    static constexpr Position north_east() { return Position{-1, 1}; }
    static constexpr Position north_west() { return Position{-1, -1}; }
    static constexpr Position south_east() { return Position{1, 1}; }
    static constexpr Position south_west() { return Position{1, -1}; }

    Position operator+(const Position& other_pos) const
    {
        return Position{this->row + other_pos.row, this->col + other_pos.col};
    };

    bool operator==(const Position& other_pos) const
    {
        return this->row == other_pos.row && this->col == other_pos.col;
    };

    int row{};
    int col{};
};

using Action = std::pair<Position, Position>;

std::ostream& operator<<(std::ostream& os, const Action& action);

constexpr bool is_inside_board(const Position& pos)
{
    return pos.col >= 0 && pos.col <= 7 && pos.row >= 0 && pos.row <= 7;
}

int distance(const Position& pos1, const Position& pos2);

bool is_square_white(const Position& pos1);

bool same_color_square(const Position& pos1, const Position& pos2);

#endif // CHESS_PROJECT_TYPES_HPP
