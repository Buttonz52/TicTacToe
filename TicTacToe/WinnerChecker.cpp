#pragma once
#include <iostream>
#include <vector>

using namespace std;

class WinnerChecker {
public:
	static bool hasPlayerWon(char playerToken, vector<vector<char>> gameBoard) {
        char tokenInCell;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tokenInCell = gameBoard[i][j];
                if (tokenInCell != playerToken) {
                    continue;
                }

                if (checkWinHorizontal(i, j, tokenInCell, gameBoard) ||
                    checkWinVertial(i, j, tokenInCell, gameBoard) ||
                    checkWinRightDiagonal(i, j, tokenInCell, gameBoard) ||
                    checkWinLeftDiagonal(i, j, tokenInCell, gameBoard)) {
                    return true;
                }
            }
        }
        return false;
	}
    static bool checkCatsGame(vector<vector<char>> gameBoard) {
        char playerInCell;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                playerInCell = gameBoard[i][j];
                if (playerInCell == '-') {
                    return false;
                }
            }
        }
        return true;
    }
private:
    static bool checkWinHorizontal(int x, int y, char player, vector<vector<char>> gameBoard) {
        if (x != 0) {
            return false;
        }
        return gameBoard[x + 1][y] == player && gameBoard[x + 2][y] == player;
    }

    static bool checkWinVertial(int x, int y, char player, vector<vector<char>> gameBoard) {
        if (y != 0) {
            return false;
        }
        return gameBoard[x][y + 1] == player && gameBoard[x][y + 2] == player;
    }

    static bool checkWinRightDiagonal(int x, int y, char player, vector<vector<char>> gameBoard) {
        if (x != 0 || y != 0) {
            return false;
        }
        return gameBoard[x + 1][y + 1] == player && gameBoard[x + 2][y + 2] == player;
    }
    static bool checkWinLeftDiagonal(int x, int y, char player, vector<vector<char>> gameBoard) {
        if (x != 2 || y != 0) {
            return false;
        }
        return gameBoard[x - 1][y + 1] == player && gameBoard[x - 2][y + 2] == player;
    }
};