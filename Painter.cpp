#include "Painter.hpp"
#include <iostream>
#include <cstdlib>

namespace TicTacToe {

    Painter::Painter() {}
    Painter::~Painter() {}


    void Painter::clearScreen() const {
        std::cout << "\x1B[2J\x1B[H" << std::flush;
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
            std::cout << "Randul jucatorului: " << p << "\n";
        }
        else if (state == GameState::PlayerXWins) {
            std::cout << ">>> FELICITARI! Jucatorul X a castigat! <<<\n";
        }
        else if (state == GameState::PlayerOWins) {
            std::cout << ">>> FELICITARI! Jucatorul O a castigat! <<<\n";
        }
        else if (state == GameState::Draw) {
            std::cout << ">>> REMIZA! Tabla este plina. <<<\n";
        }
    }

    void Painter::drawMessage(const std::string& message) const {
        std::cout << message << "\n";
    }

    void Painter::drawHelp() const {
        std::cout << "Instructiuni: Introduceti doua numere separate prin spatiu (de ex: 1 1).\n";
    }

}