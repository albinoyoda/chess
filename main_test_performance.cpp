#include "Moves.hpp"
#include "Tree_search.hpp"

#include <ctime>
#include <iostream>

int main()
{
    // compute values when piece is taken
    // create a check-if-mate function
    for (int i = 0; i < 20; i++)
    {
        clock_t clock1 = clock();
        Board_state board_state{"bT0000bQbK0000bT"
                                "bPbB00000000bPbP"
                                "00bH0000wPbB0000"
                                "0000wB0000wQ0000"
                                "bP00bP0000000000"
                                "0000wP0000000000"
                                "0000wB0000wPwPwP"
                                "wTwH0000wT00wK00"};

        Tree_search_config config{};
        config.search_depth = 4;

        Tree_search tree_search{config, board_state, Piece_color::black};
        tree_search.find_best_action();
        Action best_action = tree_search.get_best_action();
        double time_taken = (double)(clock() - clock1) / CLOCKS_PER_SEC;
        std::cout << "Measured time: " << time_taken << ", nodes/second = " << tree_search.queries / time_taken
                  << std::endl;
    }
    return 0;
}
