
#pragma once

#include "Board.hpp"

namespace TicTacToe {

    enum class GameState {
        InProgress,
        PlayerXWins,
        PlayerOWins,
        Draw
    };

    class Engine {
    public:
        Engine();
        ~Engine();

        void initialize();
        bool makeMove(int row, int col);

        const Board& getBoard() const;
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
