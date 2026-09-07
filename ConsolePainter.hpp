#ifndef CONSOLEPAINTER_HPP
#define CONSOLEPAINTER_HPP

#include "Painter.hpp"
#include <iostream>

class ConsolePainter : public Painter {
private:
    char symbolToChar(Symbol s) const {
        switch (s) {
        case Symbol::X: return 'X';
        case Symbol::O: return 'O';
        default: return ' ';
        }
    }

public:
    void drawBoard(const Board& board) override {
        std::cout << "\n-------------\n";
        for (int r = 0; r < 3; ++r) {
            std::cout << "| ";
            for (int c = 0; c < 3; ++c) {
                std::cout << symbolToChar(board[r][c]) << " | ";
            }
            std::cout << "\n-------------\n";
        }
    }

    void drawTurn(Symbol currentTurn) override {
        std::cout << "Este randul jucatorului: " << symbolToChar(currentTurn) << "\n";
    }

    void drawErrorMessage(const std::string& message) override {
        std::cout << "[EROARE]: " << message << "\n";
    }

    void drawEndGame(GameState state) override {
        std::cout << "\n==============================\n";
        if (state == GameState::X_WON) {
            std::cout << "     JUCATORUL X A CASTIGAT!   \n";
        }
        else if (state == GameState::O_WON) {
            std::cout << "     JUCATORUL O A CASTIGAT!   \n";
        }
        else if (state == GameState::DRAW) {
            std::cout << "     EGALITATE (REMIZA)!       \n";
        }
        std::cout << "==============================\n";
    }
};

#endif // CONSOLEPAINTER_HPP