#pragma once
#include <iostream>
#include <windows.h>   
#include <chrono>
#include <thread>
#include <cstdlib>
#include "GameBoard.cpp"
#include "WinnerChecker.cpp"

using namespace std;

class Player {
    public:
        Player(char token) {
            this->token = token;
        }
        bool doTurn(GameBoard* gameBoard) {
            gameBoard->print();
            if (this->isHumanPlayer()) {
                doHumanTurn(gameBoard);
            }
            else {
                doAiTurn(gameBoard);
            }
            if (WinnerChecker::hasPlayerWon(this->getToken(), gameBoard->getGameBoard())) {
                gameBoard->print();
                cout << token << " has Won!" << endl;
                return true;
            }
            if (WinnerChecker::checkCatsGame(gameBoard->getGameBoard())) {
                gameBoard->print();
                cout << "Cat's game! No Winner!" << endl;
                return true;
            }
            return false;
        }
        char getToken() {
            return token;
        }
        void setHumanPlayer(bool isHuman) {
            this->isHuman = isHuman;
        }
        bool isHumanPlayer() {
            return isHuman;
        }
    private:
        void doHumanTurn(GameBoard* gameboard) {
            int location;
            cout << "Player " << token << " turn. Select location via numbers 1-9: ";
            cin >> location;

            if (location < 1 || location > 9) {
                cout << "Invalid location.\n" << endl;
                cin.clear();
                cin.ignore(123, '\n');
                doHumanTurn(gameboard);
            }
            else {
                if (gameboard->getContentsOfLocation(location) == '-') {
                    gameboard->update(location, token);
                }
                else {
                    cout << "Invalid location. Please choose an unoccupied location.\n" << endl;
                    doHumanTurn(gameboard);
                }
            }
        }
        void doAiTurn(GameBoard* gameboard) {
            int location = randomAI(gameboard);
            gameboard->update(location, token);
            cout << "AI " << token << " selects: " << location << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }
        int randomAI(GameBoard* gameboard) {
            int location;
            srand((unsigned)time(NULL));
            do {
                location = rand() % 9 + 1;
            } while (gameboard->getContentsOfLocation(location) != '-');
            return location;
        }
        char token;
        bool isHuman;
};