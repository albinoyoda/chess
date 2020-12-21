#include "Chess_board.hpp"

#include <iostream>

namespace
{
std::string get_indicator_bar(int value)
{
    std::string skip = "               ";
    std::string standing{"|---<---<---<---<---<---<---<------->--->--->--->--->--->--->---|"};
    int indicator_pos = int(double(value) / 100.0);
    if (std::abs(value) > 800)
    {
        int subtract_value = (value > 0) ? 800 : -800;
        value -= subtract_value;
        indicator_pos = int(double(subtract_value) / 100.0);
        indicator_pos += int(double(value) / 500.0);
    }
    indicator_pos = std::min(std::max(32 + indicator_pos, 0), 64);
    standing[indicator_pos] = 'X';
    return skip + "Black " + standing + " White";
}
} // namespace

Position Chess_board::coordinate_from_command(char col_char, char row_char)
{
    int col = int(col_char) - 97;
    int row = int(row_char) - 49;
    row = 7 - row;
    return {row, col};
}

bool Chess_board::is_valid_move(std::string in_string)
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
            if (board_state_(pos1) != 0)
            {
                auto actions = get_actions_on_square(pos1, board_state_);
                Action commanded_action = Action{pos1, pos2};
                if (is_action_in_vector(commanded_action, actions[0]) ||
                    is_action_in_vector(commanded_action, actions[1]))
                {
                    return true;
                }
            }
        }
    }
    std::cout << "Not valid move: " << in_string << std::endl;
    return false;
}

void Chess_board::draw_board(int value_of_computer, bool fancy_art) const
{
    std::string row_labels = "87654321";
    std::string col_labels = "abcdefgh";
    size_t index = 0;
    int white_value = board_state_.value_of_state(Piece_color::white);
    std::cout << get_indicator_bar(white_value) << " <- Board value\n";
    std::cout << get_indicator_bar(value_of_computer) << " <- Computer's estimate\n";

    int square_width = 15;
    int square_height = 6;

    int board_width = square_width * 9 + 1;

    if (fancy_art)
    {
        std::string board{};
        std::string filled{};
        std::string empty{};

        for (int i = 0; i < square_width; i++)
        {
            filled.push_back(':');
            empty.push_back(' ');
        }

        for (int row = 0; row < 8 * square_height + 3; row++)
        {
            board += empty;
            for (int col = 0; col < 8; col++)
            {
                if (row >= 8 * square_height)
                {
                    board += empty;
                }
                else
                {
                    if ((row / square_height + col) % 2)
                    {
                        board += filled;
                    }
                    else
                    {
                        board += empty;
                    }
                }
            }
            board += '\n';
        }

        for (int row = 0; row < 8; row++)
        {
            auto shape = number_shapes.at(8 - row);
            int shape_height = shape.size();
            int shape_width = shape[0].size();
            int start_row = row * square_height + square_height / (shape_height + 1);
            int start_col = (square_width - shape_width) / 2;
            int start_index = start_row * board_width + start_col;
            for (const auto& shape_row : shape)
            {
                int paint_index = start_index;
                for (const auto& ascii_symbol : shape_row)
                {
                    board[paint_index] = ascii_symbol;

                    paint_index++;
                }
                start_index += board_width;
            }
        }

        for (int col = 1; col < 9; col++)
        {
            auto shape = letter_shapes.at(col);
            int shape_width = shape[0].size();
            int start_row = 8 * square_height;
            int start_col = col * square_width + (square_width - shape_width) / 2;
            int start_index = start_row * board_width + start_col;
            for (const auto& shape_row : shape)
            {
                int paint_index = start_index;
                for (const auto& ascii_symbol : shape_row)
                {
                    board[paint_index] = ascii_symbol;

                    paint_index++;
                }
                start_index += board_width;
            }
        }

        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                if (board_state_({row, col}) != 0)
                {
                    auto shape = figure_shapes.at(board_state_({row, col}));
                    int shape_height = shape.size();
                    int shape_width = shape[0].size();
                    int start_row = row * square_height + square_height / (shape_height + 1);
                    int start_col = (col + 1) * square_width + (square_width - shape_width) / 2;
                    int start_index = start_row * board_width + start_col;
                    for (const auto& shape_row : shape)
                    {
                        int paint_index = start_index;
                        for (const auto& ascii_symbol : shape_row)
                        {
                            if (ascii_symbol != ' ')
                            {
                                if (ascii_symbol == '.')
                                {
                                    board[paint_index] = ' ';
                                }
                                else
                                {
                                    board[paint_index] = ascii_symbol;
                                }
                            }
                            paint_index++;
                        }
                        start_index += board_width;
                    }
                }
            }
        }
        std::cout << board << std::endl;
    }
    else
    {
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
