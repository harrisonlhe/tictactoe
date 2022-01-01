#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <utility>
#include "board.h"
using namespace std;

//helper functions
template<class T>
bool check_range(T value, T min, T max) {
    return (value >= min) && (value <= max);
}

//checks if character is equal to x or o
bool is_valid_input(int c) {
    return (c == 0 || c == 1);
}

class Player {
    public:
        string name;
        Player(string name_in) :
            name(name_in) {}
};

class HumanPlayer : public Player {
    public:
        HumanPlayer(string name_in) :
            Player(name_in) {}
        
        //make a move
        //REQUIRES: xcor and ycor inputs are valid integers between 0 and 2 (inclusive)
        //EFFECTS: returns the pair (xcor, ycor), the coordinates of the move
        pair<int, int> make_move(Board &b) {
            int xcor;
            int ycor;
            cout << "Enter row of move (0 is left side, 2 is right side)" << endl;
            cin >> xcor;
            while (!check_range(xcor, 0, 2)) {
                cout << "Enter a valid row between 0 and 2" << endl;
                cin >> xcor;
            }
            cout << "Enter column of move (0 is top, 2 is bottom)" << endl;
            cin >> ycor;
            while (!check_range(ycor, 0, 2)) {
                cout << "Enter a valid column between 0 and 2" << endl;
                cin >> ycor;
            }
            pair<int, int> p (xcor, ycor);
            return p;
        }
};