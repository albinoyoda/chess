#include <Types.hpp>
#include <iostream>
#include <map>

namespace
{
std::map<int, std::string> print_piece{{0, "[  ]"},  {1, "[wT]"},  {2, "[wH]"},  {3, "[wB]"},  {4, "[wQ]"},
                                       {5, "[wK]"},  {6, "[wP]"},  {-1, "[bT]"}, {-2, "[bH]"}, {-3, "[bB]"},
                                       {-4, "[bQ]"}, {-5, "[bK]"}, {-6, "[bP]"}};

std::map<std::string, int> string_to_piece{{"00", 0},  {"wT", 1},  {"wH", 2},  {"wB", 3},  {"wQ", 4},
                                           {"wK", 5},  {"wP", 6},  {"bT", -1}, {"bH", -2}, {"bB", -3},
                                           {"bQ", -4}, {"bK", -5}, {"bP", -6}};

} // namespace

std::ostream& operator<<(std::ostream& os, const Piece_type& piece)
{
    std::string white{"white "};
    std::string black{"black "};
    switch (piece)
    {
    case Piece_type::white_tower:
        os << white + "tower";
        break;
    case Piece_type::black_tower:
        os << black + "tower";
        break;
    case Piece_type::white_knight:
        os << white + "knight";
        break;
    case Piece_type::black_knight:
        os << black + "knight";
        break;
    case Piece_type::white_bishop:
        os << white + "bishop";
        break;
    case Piece_type::black_bishop:
        os << black + "bishop";
        break;
    case Piece_type::white_queen:
        os << white + "queen";
        break;
    case Piece_type::black_queen:
        os << black + "queen";
        break;
    case Piece_type::white_king:
        os << white + "king";
        break;
    case Piece_type::black_king:
        os << black + "king";
        break;
    case Piece_type::white_pawn:
        os << white + "pawn";
        break;
    case Piece_type::black_pawn:
        os << black + "pawn";
        break;
    default:
        os << "unknown piece";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Piece_color& piece)
{
    if (piece == Piece_color::white)
    {
        os << "White";
    }
    else
    {
        os << "Black";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Action& action)
{
    std::string row_labels = "87654321";
    std::string col_labels = "abcdefgh";
    os << "Action: (" << col_labels[action.first.col] << ", " << row_labels[action.first.row] << ") -> ("
       << col_labels[action.second.col] << ", " << row_labels[action.second.row] << ") | (" << action.first.row << ", "
       << action.first.col << ") -> (" << action.second.row << ", " << action.second.col << ")" << std::endl;
    return os;
}

int distance(const Position& pos1, const Position& pos2)
{
    return std::abs(pos1.row - pos2.row) + std::abs(pos1.col - pos2.col);
}

bool is_square_white(const Position& pos1)
{
    return (pos1.row + pos1.col) % 2;
}

bool same_color_square(const Position& pos1, const Position& pos2)
{
    return is_square_white(pos1) == is_square_white(pos2);
}