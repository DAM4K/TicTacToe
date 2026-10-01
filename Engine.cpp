#include "Engine.hpp"

namespace TicTacToe {

    Engine::Engine() {
        initialize();
    }

    Engine::~Engine() {}

    void Engine::initialize() {
        board.reset(); 
        currentPlayer = Player::X;
        gameState = GameState::InProgress;
    }

    bool Engine::makeMove(int row, int col) {
        if (gameState != GameState::InProgress) return false;
        if (!board.isCellEmpty(row, col)) return false;

        board.cells[row][col] = currentPlayer;
        checkGameState();

        if (gameState == GameState::InProgress) {
            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
        }

        return true;
    }

    Board Engine::getBoard() const { return board; }
    Player Engine::getCurrentPlayer() const { return currentPlayer; }
    GameState Engine::getGameState() const { return gameState; }

    bool Engine::isGameOver() const {
        return gameState != GameState::InProgress;
    }

    void Engine::checkGameState() {
        if (checkWin(Player::X)) {
            gameState = GameState::PlayerXWins;
        }
        else if (checkWin(Player::O)) {
            gameState = GameState::PlayerOWins;
        }
        else if (isBoardFull()) {
            gameState = GameState::Draw;
        }
    }

    bool Engine::checkWin(Player p) const {
        for (int i = 0; i < 3; ++i) {
            if (board.cells[i][0] == p && board.cells[i][1] == p && board.cells[i][2] == p) return true;
            if (board.cells[0][i] == p && board.cells[1][i] == p && board.cells[2][i] == p) return true;
        }
        if (board.cells[0][0] == p && board.cells[1][1] == p && board.cells[2][2] == p) return true;
        if (board.cells[0][2] == p && board.cells[1][1] == p && board.cells[2][0] == p) return true;

        return false;
    }

    bool Engine::isBoardFull() const {
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board.cells[r][c] == Player::None) return false;
            }
        }
        return true;
    }

}