#ifndef board_H
#define board_H

#include <iostream>
#include <string>
using namespace std;
//This class represents a 3x3 tic-tac-toe board
class Board {
    public:
        int board[3][3];
        bool isFilled;

        //board constructor
        Board() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = 2;
                }
            }
            isFilled = false;
        }

        //checks if the board is filled with xs and os
        bool check_filled() {
            int a = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 0 || board[i][j] == 1) {
                        ++a;
                    }
                }
            }
            if (a == 9) {
                isFilled = true;
            }
            return isFilled;
        }

        //prints out the board
        void print_board() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        //clears the board
        void clear_board() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = 2;
                }
                cout << endl;
            }
        }

        //edits the board
        //REQUIRES: a and b are between 0 and 2, c is a valid character
        void edit_board(int a, int b, int c) {
            board[a][b] = c;
        }

        //checks if a move is valid
        bool is_valid_move(int a, int b) {
            if (board[a][b] != 0 && board[a][b] != 1) {
                return true;
            }
            return false;
        }

        bool check_winner() {
            if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) {
                return true;
            }
            if (board[0][0] == 0 && board[1][0] == 0 && board[2][0] == 0) {
                return true;
            }
            if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) {
                return true;
            }
            if (board[0][1] == 0 && board[1][1] == 0 && board[2][1] == 0) {
                return true;
            }
            if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) {
                return true;
            }
            if (board[0][2] == 0 && board[1][2] == 0 && board[2][2] == 0) {
                return true;
            }
            if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) {
                return true;
            }
            if (board[0][0] == 0 && board[0][1] == 0 && board[0][2] == 0) {
                return true;
            }
            if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) {
                return true;
            }
            if (board[1][0] == 0 && board[1][1] == 0 && board[1][2] == 0) {
                return true;
            }
            if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) {
                return true;
            }
            if (board[2][0] == 0 && board[2][1] == 0 && board[2][2] == 0) {
                return true;
            }
            if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
                return true;
            }
            if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0) {
                return true;
            }
            if (board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1) {
                return true;
            }
            if (board[2][0] == 0 && board[1][1] == 0 && board[0][2] == 0) {
                return true;
            }
            return false;
        }
};

#endif