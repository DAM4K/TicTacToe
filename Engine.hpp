#pragma once

#include <iostream>
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

        // Constructor implicit
        Board() {
            reset();
        }

        // Constructor de copiere
        Board(const Board& other) {
            copyCells(other.cells);
        }

        // Constructor cu parametri
        Board(const Player initialCells[3][3]) {
            copyCells(initialCells);
        }

        // Operator de atribuire
        Board& operator=(const Board& other) {
            if (this != &other) {
                copyCells(other.cells);
            }
            return *this;
        }

        // Operatori de comparare
        bool operator==(const Board& other) const {
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    if (cells[r][c] != other.cells[r][c]) {
                        return false;
                    }
                }
            }
            return true;
        }

        bool operator!=(const Board& other) const {
            return !(*this == other);
        }

        bool operator<(const Board& other) const {
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    if (cells[r][c] != other.cells[r][c]) {
                        return cells[r][c] < other.cells[r][c];
                    }
                }
            }
            return false;
        }

        bool operator>(const Board& other) const {
            return other < *this;
        }

        bool operator<=(const Board& other) const {
            return !(other < *this);
        }

        bool operator>=(const Board& other) const {
            return !(*this < other);
        }

        // Operator de iesire
        friend std::ostream& operator<<(std::ostream& out,
            const Board& board) {
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    if (board.cells[r][c] == Player::X) {
                        out << 'X';
                    }
                    else if (board.cells[r][c] == Player::O) {
                        out << 'O';
                    }
                    else {
                        out << '-';
                    }

                    if (c < 2) {
                        out << ' ';
                    }
                }

                if (r < 2) {
                    out << '\n';
                }
            }
            return out;
        }

        // Operator de intrare
        friend std::istream& operator>>(std::istream& in, Board& board) {
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    char symbol;

                    if (!(in >> symbol)) {
                        return in;
                    }

                    if (symbol == 'X' || symbol == 'x') {
                        board.cells[r][c] = Player::X;
                    }
                    else if (symbol == 'O' || symbol == 'o') {
                        board.cells[r][c] = Player::O;
                    }
                    else if (symbol == '-') {
                        board.cells[r][c] = Player::None;
                    }
                    else {
                        in.setstate(std::ios::failbit);
                        return in;
                    }
                }
            }
            return in;
        }

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

    private:
        void copyCells(const Player source[3][3]) {
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    cells[r][c] = source[r][c];
                }
            }
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