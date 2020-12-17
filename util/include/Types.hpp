#ifndef CHESS_PROJECT_TYPES_HPP
#define CHESS_PROJECT_TYPES_HPP

#include <array>
#include <cassert>
#include <utility>

enum Piece_type
{
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

enum class Piece_color
{
    white,
    black
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

class Board_state
{
public:
    Board_state();

    explicit Board_state(const std::string& configuration);

    explicit Board_state(const std::array<std::array<int, 8>, 8>& configuration);

    void move(const Position& prev, const Position& next);

    [[nodiscard]] int value_of_state(Piece_color piece_color) const;

    void draw_board() const;

    int& operator()(const Position& pos);
    int operator()(const Position& pos) const;

    std::array<std::array<int, 8>, 8> state_{};
};

#endif // CHESS_PROJECT_TYPES_HPP
