#pragma once
#include <iostream>
#include <vector>
#include "GameBoard.cpp"
#include "Player.cpp"
#include "WinnerChecker.cpp"

using namespace std;

int selectGameType() {
    int option;

    cout << "Welcome to Tic Tac Toe!\n" << endl;
    cout << "Select option:" << "\n" <<
        "1: Player vs Player" << "\n" <<
        "2: Player vs AI" << "\n" << 
        "3: AI vs AI" << "\n" << endl;

    cin >> option;

    if (option == 1) {
        return 1;
    }
    else if (option == 2) {
        return 2;
    }
    else if (option == 3) {
        return 3;
    }
    else {
        cout << "Invalid selection, try again!" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        return selectGameType();
    }
}

void setupPlayers(Player* playerOne, Player* playerTwo, int gameType) {
    if (gameType == 1) {
        playerOne->setHumanPlayer(true);
        playerTwo->setHumanPlayer(true);
    } else if (gameType == 2) {
        playerOne->setHumanPlayer(true);
        playerTwo->setHumanPlayer(false);
    }
    else if (gameType == 3) {
        playerOne->setHumanPlayer(false);
        playerTwo->setHumanPlayer(false);
    }
}

int main() {
    GameBoard gameBoard;
    Player playerOne('X');
    Player playerTwo('O');
    bool isGameOver = false;

    setupPlayers(&playerOne, &playerTwo, selectGameType());

    while (!isGameOver) {
        isGameOver = playerOne.doTurn(&gameBoard);
        if (isGameOver) {
            break;
        }
        isGameOver = playerTwo.doTurn(&gameBoard);
    }
}