#include "Chess_board.hpp"

#include <iostream>

namespace
{
std::string get_indicator_bar(int value)
{
    std::string standing{"|---<---<---<---+--->--->--->---|"};
    int indicator_pos = int(double(value) / 100.0);
    if (std::abs(value) > 400)
    {
        int subtract_value = (value > 0) ? 400 : -400;
        value -= subtract_value;
        indicator_pos = int(double(subtract_value) / 100.0);
        indicator_pos += int(double(value) / 500.0);
    }
    indicator_pos = std::min(std::max(16 + indicator_pos, 0), 32);
    standing[indicator_pos] = '|';
    return "B" + standing + "W";
}
} // namespace

Position Chess_board::coordinate_from_command(char col_char, char row_char)
{
    int col = int(col_char) - 97;
    int row = int(row_char) - 49;
    row = 7 - row;
    return {row, col};
}

bool Chess_board::is_valid_move(std::string in_string) const
{
    if (in_string.empty())
    {
        return false;
    }
    if (in_string.size() == 4)
    {
        int col1 = int(in_string[0]) - 97;
        int col2 = int(in_string[2]) - 97;
        int row1 = int(in_string[1]) - 49;
        int row2 = int(in_string[3]) - 49;
        row1 = 7 - row1;
        row2 = 7 - row2;
        bool bool1 = (col1 >= 0) && (col1 <= 7);
        bool bool2 = (col2 >= 0) && (col2 <= 7);
        bool bool3 = (row1 >= 0) && (row1 <= 7);
        bool bool4 = (row2 >= 0) && (row2 <= 7);
        if (bool1 && bool2 && bool3 && bool4)
        {
            Position pos1 = {row1, col1};
            Position pos2 = {row2, col2};
            auto actions = get_actions_on_square(pos1, board_state_);
            Action commanded_action = Action{pos1, pos2};
            if (is_action_in_vector(commanded_action, actions))
            {
                return true;
            }
        }
    }
    std::cout << "Not valid move: " << in_string << std::endl;
    return false;
}

void Chess_board::draw_board(int value_of_computer) const
{
    std::string row_labels = "87654321";
    std::string col_labels = "abcdefgh";
    size_t index = 0;
    int white_value = board_state_.value_of_state(Piece_color::white);
    std::cout << get_indicator_bar(white_value) << " Board value\n";
    std::cout << get_indicator_bar(value_of_computer) << " Computer's estimate\n";
    for (const auto& row : board_state_.state_)
    {
        std::cout << row_labels[index++];
        std::cout << " ";
        for (const auto& piece : row)
        {
            std::cout << print_piece.at(piece);
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
    board_state_.move(current_pos, new_pos);
}

// void Chess_board::move(const Position& prev, const Position& next)
//{
//    board_state_.move(prev, next);
//    state_[next.row][next.col] = state_[prev.row][prev.col];
//    state_[prev.row][prev.col] = 0;
//}

bool Chess_board::find_white_king()
{
    for (const auto& row : board_state_.state_)
    {
        for (const auto& piece : row)
        {
            if (piece == 5)
            {
                return true;
            }
        }
    }
    return false;
}

bool Chess_board::find_black_king()
{
    for (const auto& row : board_state_.state_)
    {
        for (const auto& piece : row)
        {
            if (piece == -5)
            {
                return true;
            }
        }
    }
    return false;
}

bool Chess_board::find_kings()
{
    return find_white_king() && find_black_king();
}
