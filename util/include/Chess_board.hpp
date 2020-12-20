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

    void draw_board(int value_of_computer = 0, bool fancy_art = false) const;

    void move(std::string command);

    static Position coordinate_from_command(char a, char b);

    Board_state board_state_;

    bool find_white_king();

    bool find_black_king();

    bool find_kings();

    const std::map<int, std::string> print_piece{{0, "[  ]"},  {1, "[wT]"},  {2, "[wH]"},  {3, "[wB]"},  {4, "[wQ]"},
                                                 {5, "[wK]"},  {6, "[wP]"},  {-1, "[bT]"}, {-2, "[bH]"}, {-3, "[bB]"},
                                                 {-4, "[bQ]"}, {-5, "[bK]"}, {-6, "[bP]"}};

    std::vector<std::string> letter_a = {
        {"  _  "},
        {" /_\\ "},
        {"/   \\"},
    };

    std::vector<std::string> letter_b = {
        {" _ "},
        {"|_)"},
        {"|_)"},
    };

    std::vector<std::string> letter_c = {
        {" _"},
        {"/ "},
        {"\\_"},
    };

    std::vector<std::string> letter_d = {
        {" _ "},
        {"| \\"},
        {"|_/"},
    };

    std::vector<std::string> letter_e = {
        {" __"},
        {"|_ "},
        {"|__"},
    };

    std::vector<std::string> letter_f = {
        {" __"},
        {"|_ "},
        {"|  "},
    };

    std::vector<std::string> letter_g = {
        {" _ "},
        {"/ _"},
        {"\\_/"},
    };

    std::vector<std::string> letter_h = {
        {". ."},
        {"|_|"},
        {"| |"},
    };

    std::vector<std::string> letter_1 = {
        {" ."},
        {"/|"},
        {" |"},
    };

    std::vector<std::string> letter_2 = {
        {"_ "},
        {" )"},
        {"/_"},
    };

    std::vector<std::string> letter_3 = {
        {"_ "},
        {"_)"},
        {"_)"},
    };

    std::vector<std::string> letter_4 = {
        {"  ."},
        {" /|"},
        {"'-|"},
    };

    std::vector<std::string> letter_5 = {
        {" _ "},
        {"|_ "},
        {" _)"},
    };

    std::vector<std::string> letter_6 = {
        {" / "},
        {"(_)"},
    };

    std::vector<std::string> letter_7 = {
        {"__"},
        {" /"},
        {"/ "},
    };

    std::vector<std::string> letter_8 = {
        {" _ "},
        {"(_)"},
        {"(_)"},
    };

    std::vector<std::string> white_pawn_shape = {{"  (@)  "}, {"  )@(  "}, {" (@@@) "}, {"[@@@@@]"}};
    std::vector<std::string> black_pawn_shape = {{"  (.)  "}, {"  ).(  "}, {" (...) "}, {"[_____]"}};

    std::vector<std::string> white_knight_shape{{"   _/)  "}, {"  /,@|= "}, {" /_)@|= "}, {"  (@@@) "}, {" [@@@@@]"}};
    std::vector<std::string> black_knight_shape{{"   _/)  "}, {"  /,.|= "}, {" /_).|= "}, {"  (...) "}, {" [_____]"}};

    std::vector<std::string> white_bishop_shape{{"   ^   "}, {"  /@\\  "}, {"  )@(  "}, {" (@@@) "}, {"[@@@@@]"}};
    std::vector<std::string> black_bishop_shape{{"   ^   "}, {"  /.\\  "}, {"  ).(  "}, {" (...) "}, {"[_____]"}};

    std::vector<std::string> white_tower_shape{{" ||||| "}, {" )@@@( "}, {" (@@@) "}, {" )@@@( "}, {"[@@@@@]"}};
    std::vector<std::string> black_tower_shape{{" ||||| "}, {" )...( "}, {" (...) "}, {" )...( "}, {"[_____]"}};

    std::vector<std::string> black_king_shape{
        {"   M   "}, {"  (.)  "}, {" (...) "}, {"  ).(  "}, {" (...) "}, {"[_____]"},
    };

    std::vector<std::string> white_king_shape{
        {"   M   "}, {"  (@)  "}, {" (@@@) "}, {"  )@(  "}, {" (@@@) "}, {"[@@@@@]"},
    };

    std::vector<std::string> black_queen_shape{
        {"   o   "}, {"  (.)  "}, {" (...) "}, {"  ).(  "}, {" (...) "}, {"[_____]"},
    };

    std::vector<std::string> white_queen_shape{
        {"   o   "}, {"  (@)  "}, {" (@@@) "}, {"  )@(  "}, {" (@@@) "}, {"[@@@@@]"},
    };

    std::map<int, std::vector<std::string>> figure_shapes{
        {Piece_type::black_pawn, black_pawn_shape},     {Piece_type::white_pawn, white_pawn_shape},
        {Piece_type::black_knight, black_knight_shape}, {Piece_type::white_knight, white_knight_shape},
        {Piece_type::black_bishop, black_bishop_shape}, {Piece_type::white_bishop, white_bishop_shape},
        {Piece_type::black_tower, black_tower_shape},   {Piece_type::white_tower, white_tower_shape},
        {Piece_type::black_queen, black_queen_shape},   {Piece_type::white_queen, white_queen_shape},
        {Piece_type::black_king, black_king_shape},     {Piece_type::white_king, white_king_shape},
    };

    std::map<int, std::vector<std::string>> number_shapes{
        {8, letter_8}, {7, letter_7}, {6, letter_6}, {5, letter_5},
        {4, letter_4}, {3, letter_3}, {2, letter_2}, {1, letter_1},
    };

    std::map<int, std::vector<std::string>> letter_shapes{
        {8, letter_h}, {7, letter_g}, {6, letter_f}, {5, letter_e},
        {4, letter_d}, {3, letter_c}, {2, letter_b}, {1, letter_a},
    };
};

#endif // CHESS_CHESS_BOARD_HPP
