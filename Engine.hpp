#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Painter.hpp"
#include "Listener.hpp"

class Engine {
private:
    Board board;
    Symbol currentTurn;
    GameState state;
    Painter& painter;
    Listener& listener;

    bool checkLine(Symbol a, Symbol b, Symbol c) const {
        return (a != Symbol::NONE) && (a == b) && (b == c);
    }

    void updateGameState() {
        for (int i = 0; i < 3; ++i) {
            if (checkLine(board[i][0], board[i][1], board[i][2])) {
                state = (board[i][0] == Symbol::X) ? GameState::X_WON : GameState::O_WON;
                return;
            }
            if (checkLine(board[0][i], board[1][i], board[2][i])) {
                state = (board[0][i] == Symbol::X) ? GameState::X_WON : GameState::O_WON;
                return;
            }
        }

        if (checkLine(board[0][0], board[1][1], board[2][2])) {
            state = (board[0][0] == Symbol::X) ? GameState::X_WON : GameState::O_WON;
            return;
        }
        if (checkLine(board[0][2], board[1][1], board[2][0])) {
            state = (board[0][2] == Symbol::X) ? GameState::X_WON : GameState::O_WON;
            return;
        }

        bool full = true;
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board[r][c] == Symbol::NONE) {
                    full = false;
                    break;
                }
            }
        }

        if (full) {
            state = GameState::DRAW;
        }
    }

public:
    Engine(Painter& p, Listener& l)
        : painter(p), listener(l), currentTurn(Symbol::X), state(GameState::IN_PROGRESS) {
        board = std::vector<std::vector<Symbol>>(3, std::vector<Symbol>(3, Symbol::NONE));
    }

    void run() {
        while (state == GameState::IN_PROGRESS) {
            painter.drawBoard(board);
            painter.drawTurn(currentTurn);

            Position pos = listener.getNextMove();

            if (pos.row < 0 || pos.row >= 3 || pos.col < 0 || pos.col >= 3) {
                painter.drawErrorMessage("Pozitie invalida! Introduceti numere intre 0 si 2.");
                continue;
            }

            if (board[pos.row][pos.col] != Symbol::NONE) {
                painter.drawErrorMessage("Celula deja ocupata! Alege alta.");
                continue;
            }

            board[pos.row][pos.col] = currentTurn;
            updateGameState();

            if (state == GameState::IN_PROGRESS) {
                currentTurn = (currentTurn == Symbol::X) ? Symbol::O : Symbol::X;
            }
        }

        painter.drawBoard(board);
        painter.drawEndGame(state);
    }
};

#endif // ENGINE_HPP