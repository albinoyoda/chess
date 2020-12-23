#ifndef CHESS_PROJECT_BOARD_STATE_HPP
#define CHESS_PROJECT_BOARD_STATE_HPP

#include <Types.hpp>
#include <Moves.hpp>
#include <array>
#include <cassert>
#include <utility>

class Board_state
{
public:
    Board_state();

    explicit Board_state(const std::string& configuration);

    explicit Board_state(const std::array<std::array<int, 8>, 8>& configuration);

    void move(const Position& prev, const Position& next);

    [[nodiscard]] int value_of_state(Piece_color piece_color) const;

    void init_state_values();

    void recompute_piece_values(int taken_piece, int row);

    void recompute_position_values(int moved_piece, int steps);

//    [[nodiscard]] void compute_move_values();

    Position find_white_king() const;

    Position find_black_king() const;

    void draw_board() const;

    int& operator()(const Position& pos);
    int operator()(const Position& pos) const;

    std::array<std::array<int, 8>, 8> state_{};
    bool white_checked{false};
    bool black_checked{false};
    int white_piece_value{};
    int black_piece_value{};
    int white_position_value{};
    int black_position_value{};
};

#endif // CHESS_PROJECT_BOARD_STATE_HPP
