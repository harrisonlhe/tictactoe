#include <iostream>
#include <string>
#include <utility>
#include "board.h"
#include "player.cpp"
using namespace std;

int main() {
    bool validity = false;
    bool didp1win = false;
    pair<int, int> move;
    Board gameboard;
    gameboard.print_board();
    HumanPlayer p1("p1");
    HumanPlayer p2("p2");
    while (!gameboard.check_winner()) {
        cout << "p1's turn to move" << endl;
        move = p1.make_move(gameboard);
        validity = gameboard.is_valid_move(move.first, move.second);
        while (!validity) {
            cout << "Invalid move, try again" << endl;
            move = p1.make_move(gameboard);
            validity = gameboard.is_valid_move(move.first, move.second);
        }
        gameboard.edit_board(move.first, move.second, 1);
        gameboard.print_board();
        if (gameboard.check_winner()) {
            didp1win = true;
            cout << "p1 wins" << endl;
            break;
        }
        cout << "p2's turn to move" << endl;
        move = p2.make_move(gameboard);
        validity = gameboard.is_valid_move(move.first, move.second);
        while (!validity) {
            cout << "Invalid move, try again" << endl;
            move = p2.make_move(gameboard);
            validity = gameboard.is_valid_move(move.first, move.second);
        }
        gameboard.edit_board(move.first, move.second, 0);
        gameboard.print_board();
    }
    if (gameboard.check_winner() && !didp1win) {
        cout << "p2 wins" << endl;
    }
    else if (!didp1win) {
        cout << "tie" << endl;
    }
    else {
        cout << "";
    }
} 