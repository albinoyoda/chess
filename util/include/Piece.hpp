#ifndef CHESS_PROJECT_PIECE_HPP
#define CHESS_PROJECT_PIECE_HPP

#include "Types.hpp"

#include <ostream>
#include <vector>

class Piece
{
public:
    Piece() = default;

    virtual ~Piece() = default;

    virtual std::vector<Position> get_moves(const Position& position, const Board_state& board_state) const = 0;

    bool has_moved{false};
    Piece_color color{};
};

class Pawn : public Piece
{
public:
    Pawn() = default;

    ~Pawn() override = default;

    std::vector<Position> get_moves(const Position& position, const Board_state& board_state) const override;
};

std::ostream& operator<<(std::ostream& os, const Piece& special_stats);

#endif // CHESS_PROJECT_PIECE_HPP
