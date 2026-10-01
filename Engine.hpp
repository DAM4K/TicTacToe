#pragma once

#include <vector>

namespace TicTacToe {

    enum class Player {
        None,
        X,
        O
    };

    enum class GameState {
        InProgress,
        PlayerXWins,
        PlayerOWins,
        Draw
    };

    struct Board {
        Player cells[3][3];

        void reset() {
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    cells[r][c] = Player::None;
                }
            }
        }

        bool isCellEmpty(int r, int c) const {
            if (r >= 0 && r < 3 && c >= 0 && c < 3) {
                return cells[r][c] == Player::None;
            }
            return false;
        }
    };

    class Engine {
    public:
        Engine();
        ~Engine();

        void initialize();
        bool makeMove(int row, int col);

        Board getBoard() const;
        Player getCurrentPlayer() const;
        GameState getGameState() const;

        bool isGameOver() const;

    private:
        Board board;
        Player currentPlayer;
        GameState gameState;

        void checkGameState();
        bool checkWin(Player player) const;
        bool isBoardFull() const;
    };

}