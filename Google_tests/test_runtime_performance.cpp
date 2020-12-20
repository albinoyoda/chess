#include "Moves.hpp"
#include "Tree_search.hpp"

#include "gtest/gtest.h"
#include <Test_functions.hpp>
#include <ctime>

TEST(TestSuite, test_tree_search_performance)
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
    config.search_depth = 5;

    Tree_search tree_search{config, board_state, Piece_color::black};
    tree_search.search(tree_search.root_node, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(),
                       true);
    Action best_action = tree_search.get_best_action();

    std::cout << "n searches " << tree_search.queries << ", Measured time "
              << (double)(clock() - clock1) / CLOCKS_PER_SEC << " " << std::endl;
    ;
}
