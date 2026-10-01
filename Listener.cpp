#include "Listener.hpp"
#include <iostream>

namespace TicTacToe {

    Listener::Listener() {}
    Listener::~Listener() {}

    MoveInput Listener::listenForMove() const {
        MoveInput input{ -1, -1, false, false };
        std::cout << "Introduceti linia si coloana (0-2) sau -1 pentru ieșire: ";

        int r, c;
        if (std::cin >> r) {
            if (r == -1) {
                input.isQuitRequested = true;
                return input;
            }
            if (std::cin >> c) {
                if (r >= 0 && r < 3 && c >= 0 && c < 3) {
                    input.row = r;
                    input.col = c;
                    input.isValid = true;
                }
            }
        }
        else {
            std::cin.clear();
            std::string dummy;
            std::cin >> dummy;
        }

        return input;
    }

    bool Listener::askForRestart() const {
        std::cout << "Doriți să jucați din nou? (y/n): ";
        char answer;
        std::cin >> answer;
        return (answer == 'y' || answer == 'Y');
    }

}