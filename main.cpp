#include "Moves.hpp"
#include "Tree_search.hpp"
#include "util/include/Chess_board.hpp"

#include <iostream>
#include <limits>
#include <string>

Piece_color get_color(std::string in_string)
{
    if (in_string[0] == 'w' || in_string[0] == 'W')
    {
        std::cout << "You selected white!\n";
        return Piece_color::white;
    }
    std::cout << "You selected black!\n";
    return Piece_color::black;
}

int main()
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Welcome to PepeChess.\n";
    std::cout << "Do you want to play white or black?\n[w/b]";
    std::string color{"w"};
    std::cin >> color;
    Piece_color player1_color = get_color(color);
    Piece_color player2_color = (player1_color == Piece_color::white) ? Piece_color::black : Piece_color::white;
    bool player1_turn = player1_color == Piece_color::white;

    //    std::cout << "Select difficulty: \n[3]Head (easy)\n[4]Head (medium)\n[5]Head (hard)\n";
    //    std::string difficulty{"4"};
    //    std::cin >> difficulty;
    //    int ai_level = get_color(difficulty);

    Tree_search_config config_1{};
    config_1.search_depth = 4;
    config_1.prune = true;
    config_1.debug = false;
    config_1.debug_best_action = false;
    config_1.debug_n_actions = 5;

    Tree_search_config config_2{};
    config_2.search_depth = 6;
    config_2.prune = true;
    config_2.debug = false;
    config_2.debug_best_action = false;
    config_2.debug_n_actions = 5;

    Chess_board chess_board{};
    std::cout << "Game started! Current board state:\n";
    chess_board.draw_board();
    int value_of_computer_move{};
    while (chess_board.find_kings())
    {
        Action best_action{};
        Piece_type moved_piece{};
        int captured_piece{};
        int n_searches = 0;
        if (player1_turn)
        {
            std::string move{};
            std::cout << "Enter your move (a-h)(1-8) -> (a-h)(1-8). (Example 'b2b4')\n";
            while (!chess_board.is_valid_move(move))
            {
                std::cin >> move;
            }
            chess_board.move(move);

            //            Tree_search tree_search{config_1, chess_board.board_state_, player1_color};
            //            tree_search.search(tree_search.root_node, 0, std::numeric_limits<int>::min(),
            //                               std::numeric_limits<int>::max(), true);
            //            Action best_action = tree_search.get_best_action();
            //            chess_board.board_state_.move(best_action.first, best_action.second);
        }
        else
        {
            Tree_search tree_search{config_2, chess_board.board_state_, player2_color};
            tree_search.search(tree_search.root_node, 0, std::numeric_limits<int>::min(),
                               std::numeric_limits<int>::max(), true);
            best_action = tree_search.get_best_action();
            value_of_computer_move = tree_search.root_child_values[0].second;
            moved_piece = Piece_type(chess_board.board_state_(best_action.first));
            captured_piece = Piece_type(chess_board.board_state_(best_action.second));
            chess_board.board_state_.move(best_action.first, best_action.second);
            n_searches = tree_search.queries;
        }
        player1_turn = !player1_turn;
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        if (player1_turn)
        {
            std::cout << best_action;
            if (n_searches > 2000000)
            {
                std::cout << "Evaluated " << n_searches << " board states (weird flex)\n";
            }
            if (captured_piece != 0)
            {
                std::cout << "The computer captures " << Piece_type(captured_piece) << " with " << moved_piece << "!\n";
            }
            else
            {
                std::cout << "The computer moves: " << moved_piece << "\n";
            }
            std::cout << "Computer estimates its move to have the value: " << value_of_computer_move << "\n";
            std::cout << "Players turn:\n";
        }
        else
        {
            std::cout << "Computers turn...\n";
        }
        chess_board.draw_board(-value_of_computer_move);
    }
    if (chess_board.find_black_king())
    {
        std::cout << "Black player won!";
    }
    std::cout << "White player won!";
    return 0;
}
