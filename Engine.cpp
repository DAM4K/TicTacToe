
#include "Engine.hpp"
#include <algorithm>
#include <array>

namespace TicTacToe {

    Engine::Engine() {
        initialize();
    }

    Engine::~Engine() = default;

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
            currentPlayer = (currentPlayer == Player::X)
                ? Player::O
                : Player::X;
        }

        return true;
    }

    const Board& Engine::getBoard() const {
        return board;
    }

    Player Engine::getCurrentPlayer() const {
        return currentPlayer;
    }

    GameState Engine::getGameState() const {
        return gameState;
    }

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

    bool Engine::checkWin(Player player) const {
        // Verifica daca toate elementele unei linii sunt egale
        const auto isWinningLine = [player](std::array<Player, 3> line) {
            std::sort(line.begin(), line.end());

            return line.front() == player &&
                line.back() == player;
            };

        for (std::size_t i = 0; i < 3; ++i) {

            // Verificam liniile
            if (isWinningLine(board.cells[i])) {
                return true;
            }

            // Verificam coloanele
            std::array<Player, 3> column = {
                board.cells[0][i],
                board.cells[1][i],
                board.cells[2][i]
            };

            if (isWinningLine(column)) {
                return true;
            }
        }

        // Verificam diagonala principala
        std::array<Player, 3> mainDiagonal = {
            board.cells[0][0],
            board.cells[1][1],
            board.cells[2][2]
        };

        if (isWinningLine(mainDiagonal)) {
            return true;
        }

        // Verificam diagonala secundara
        std::array<Player, 3> secondaryDiagonal = {
            board.cells[0][2],
            board.cells[1][1],
            board.cells[2][0]
        };

        return isWinningLine(secondaryDiagonal);
    }

    bool Engine::isBoardFull() const {
        return std::all_of(
            board.cells.begin(),
            board.cells.end(),
            [](const BoardRow& row) {
                return std::find(
                    row.begin(),
                    row.end(),
                    Player::None
                ) == row.end();
            }
        );
    }

}
