#pragma once
#include <iostream>
#include <vector>

using namespace std;

class GameBoard {
    public:
        void update(int location, char playerToken) {
            int x = (location - 1) / 3;
            int y = (location - 1) % 3;
            board[x][y] = playerToken;
        }
        char getContentsOfLocation(int location) {
            int x = (location - 1) / 3;
            int y = (location - 1) % 3;
            return board[x][y];
        }
        void print() {
            system("cls");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << board[i][j];
                }
                cout << endl;
            }

            cout << endl;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << optionBoard[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }
        vector<vector<char>> getGameBoard() {
            return board;
        }
private:
    vector<vector<char>> board{
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
    };
    vector<vector<char>> optionBoard{
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
};
