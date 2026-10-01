#include "Painter.hpp"
#include <iostream>
#include <cstdlib>

namespace TicTacToe {

    Painter::Painter() {}
    Painter::~Painter() {}

    void Painter::clearScreen() const {
#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
    }

    void Painter::drawHeader() const {
        std::cout << "===========================\n";
        std::cout << "      TIC-TAC-TOE (X&O)    \n";
        std::cout << "===========================\n\n";
    }

    void Painter::drawBoard(const Board& board) const {
        std::cout << "    0   1   2\n";
        std::cout << "  -------------\n";
        for (int r = 0; r < 3; ++r) {
            std::cout << r << " | ";
            for (int c = 0; c < 3; ++c) {
                char symbol = ' ';
                if (board.cells[r][c] == Player::X) symbol = 'X';
                else if (board.cells[r][c] == Player::O) symbol = 'O';

                std::cout << symbol << " | ";
            }
            std::cout << "\n  -------------\n";
        }
        std::cout << "\n";
    }

    void Painter::drawStatus(Player currentPlayer, GameState state) const {
        if (state == GameState::InProgress) {
            char p = (currentPlayer == Player::X) ? 'X' : 'O';
            std::cout << "Rândul jucătorului: " << p << "\n";
        }
        else if (state == GameState::PlayerXWins) {
            std::cout << ">>> FELICITĂRI! Jucătorul X a câștigat! <<<\n";
        }
        else if (state == GameState::PlayerOWins) {
            std::cout << ">>> FELICITĂRI! Jucătorul O a câștigat! <<<\n";
        }
        else if (state == GameState::Draw) {
            std::cout << ">>> REMIZĂ! Tabla este plină. <<<\n";
        }
    }

    void Painter::drawMessage(const std::string& message) const {
        std::cout << message << "\n";
    }

    void Painter::drawHelp() const {
        std::cout << "Instrucțiuni: Introduceți două numere separate prin spațiu (de ex: 1 1).\n";
    }

}