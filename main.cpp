#include <string>
#include "util/include/Chess_board.hpp"

int main()
{
    Chess_board chess_board{};
    chess_board.draw_board();
    chess_board.move("b4d4");
    chess_board.draw_board();
    return 0;
}
