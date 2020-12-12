#include "Moves.hpp"

std::vector<Position> get_pawn_moves(const Position& position, const Board_state& board_state)
{
    std::vector<Position> moves{};
    moves.reserve(4);
    if (board_state[position.row][position.col] > 0)
    {
        if (position.row > 0)
        {
            if (board_state[position.row - 1][position.col] == 0)
            {
                moves.emplace_back(position.row - 1, position.col);
            }
            if (position.col > 0)
            {
                if (board_state[position.row - 1][position.col - 1] < 0)
                {
                    moves.emplace_back(position.row - 1, position.col - 1);
                }
            }
            if (position.col < 7)
            {
                if (board_state[position.row - 1][position.col + 1] < 0)
                {
                    moves.emplace_back(position.row - 1, position.col + 1);
                }
            }
        }
        if (position.row == 6)
        {
            moves.emplace_back(position.row - 2, position.col);
        }
    }
    else
    {
        if (position.row < 7)
        {
            if (board_state[position.row + 1][position.col] == 0)
            {
                moves.emplace_back(position.row + 1, position.col);
            }
            if (position.col > 0)
            {
                if (board_state[position.row + 1][position.col - 1] > 0)
                {
                    moves.emplace_back(position.row + 1, position.col - 1);
                }
            }
            if (position.col < 7)
            {
                if (board_state[position.row + 1][position.col + 1] > 0)
                {
                    moves.emplace_back(position.row + 1, position.col + 1);
                }
            }
        }
        if (position.row == 1)
        {
            moves.emplace_back(position.row + 2, position.col);
        }
    }
    return moves;
}