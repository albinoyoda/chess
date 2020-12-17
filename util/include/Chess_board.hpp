#ifndef CHESS_CHESS_BOARD_HPP
#define CHESS_CHESS_BOARD_HPP

#include "Test_functions.hpp"
#include "Types.hpp"

#include <Moves.hpp>
#include <map>

class Chess_board
{
public:
    Chess_board() = default;

    bool is_valid_move(std::string in_string) const;

    void draw_board(int value_of_computer = 0) const;

    void move(std::string command);

    static Position coordinate_from_command(char a, char b);

    Board_state board_state_;

    bool find_white_king();

    bool find_black_king();

    bool find_kings();

    const std::map<int, std::string> print_piece{{0, "[  ]"},  {1, "[wT]"},  {2, "[wH]"},  {3, "[wB]"},  {4, "[wQ]"},
                                                 {5, "[wK]"},  {6, "[wP]"},  {-1, "[bT]"}, {-2, "[bH]"}, {-3, "[bB]"},
                                                 {-4, "[bQ]"}, {-5, "[bK]"}, {-6, "[bP]"}};
};

#endif // CHESS_CHESS_BOARD_HPP
