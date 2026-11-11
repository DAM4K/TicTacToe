
#include "Listener.hpp"
#include <iostream>
#include <string>

namespace TicTacToe {

    Listener::Listener() = default;
    Listener::~Listener() = default;

    MoveInput Listener::listenForMove() const {
        MoveInput input{ -1, -1, false, false };

        std::cout << "Introduceti linia si coloana (0-2) sau -1 pentru iesire: ";

        int row, col;

        if (!(std::cin >> row)) {
            if (!std::cin.eof()) {
                std::cin.clear();
                std::string invalidInput;
                std::cin >> invalidInput;
            }
            return input;
        }

        if (row == -1) {
            input.isQuitRequested = true;
            return input;
        }

        if (!(std::cin >> col)) {
            if (!std::cin.eof()) {
                std::cin.clear();
                std::string invalidInput;
                std::cin >> invalidInput;
            }
            return input;
        }

        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            input.row = row;
            input.col = col;
            input.isValid = true;
        }

        return input;
    }

    bool Listener::askForRestart() const {
        std::cout << "Doriti sa jucati din nou? (y/n): ";

        std::string answer;

        if (!(std::cin >> answer)) {
            return false;
        }

        return !answer.empty() &&
            (answer[0] == 'y' || answer[0] == 'Y');
    }

}
