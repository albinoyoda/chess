#include "Chess_board.hpp"

#include <iostream>

std::map<int, std::string> print_piece{{0, "[  ]"},  {1, "[wT]"},  {2, "[wH]"},  {3, "[wB]"},  {4, "[wQ]"},
                                       {5, "[wK]"},  {6, "[wP]"},  {-1, "[bT]"}, {-2, "[bH]"}, {-3, "[bB]"},
                                       {-4, "[bQ]"}, {-5, "[bK]"}, {-6, "[bP]"}};

std::string Chess_board::toChessNote(Position p)
{
    std::string s = "";
    s += char(p.row + 97);
    s += char(7 - p.col + 49);
    return s;
}

Position Chess_board::coordinate_from_command(char row_char, char col_char)
{
    int row = int(row_char) - 97;
    row = 7 - row;
    int col = int(col_char) - 49;
    return {row, col};
}

Chess_board::Chess_board()
    : board_state_{std::array<int, 8>{-1, -2, -3, -4, -5, -3, -2, -1},
                   {-6, -6, -6, -6, -6, -6, -6, -6},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {6, 6, 6, 6, 6, 6, 6, 6},
                   {1, 2, 3, 4, 5, 3, 2, 1}}
{
}

Chess_board::Chess_board(Board_state custom_state) : board_state_{custom_state}
{
}

void Chess_board::draw_board() const
{
    std::string row_labels = "hgfedcba";
    std::string col_labels = "12345678";
    size_t index = 0;
    for (const auto& row : board_state_)
    {
        std::cout << row_labels[index++];
        std::cout << " ";
        for (const auto& piece : row)
        {
            std::cout << print_piece[piece];
        }
        std::cout << "\n";
    }
    for (const auto& label : col_labels)
    {
        std::cout << "   ";
        std::cout << label;
    }
    std::cout << "\n";
}

void Chess_board::move(std::string command)
{
    std::cout << "Moving: " + command + "\n";
    auto current_pos = coordinate_from_command(command[0], command[1]);
    auto new_pos = coordinate_from_command(command[2], command[3]);
    board_state_[new_pos.row][new_pos.col] = board_state_[current_pos.row][current_pos.col];
    board_state_[current_pos.row][current_pos.col] = 0;
}