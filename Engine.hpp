
#pragma once

#include <iostream>
#include <array>
#include <algorithm>
#include <cstddef>

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

    using BoardRow = std::array<Player, 3>;
    using BoardCells = std::array<BoardRow, 3>;

    struct Board {
        BoardCells cells{};

        // Constructor implicit
        Board() {
            reset();
        }

        // Constructor de copiere
        Board(const Board& other) {
            copyCells(other.cells);
        }

        // Constructor cu parametri
        Board(const BoardCells& initialCells) {
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
            return std::equal(
                cells.begin(), cells.end(),
                other.cells.begin()
            );
        }

        bool operator!=(const Board& other) const {
            return !(*this == other);
        }

        bool operator<(const Board& other) const {
            return std::lexicographical_compare(
                cells.begin(), cells.end(),
                other.cells.begin(), other.cells.end()
            );
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
            for (const auto& row : board.cells) {
                std::size_t c = 0;

                for (const auto& cell : row) {
                    if (cell == Player::X) {
                        out << 'X';
                    }
                    else if (cell == Player::O) {
                        out << 'O';
                    }
                    else {
                        out << '-';
                    }

                    if (++c < row.size()) {
                        out << ' ';
                    }
                }

                if (&row != &board.cells.back()) {
                    out << '\n';
                }
            }

            return out;
        }

        // Operator de intrare
        friend std::istream& operator>>(std::istream& in, Board& board) {
            for (auto& row : board.cells) {
                for (auto& cell : row) {
                    char symbol;

                    if (!(in >> symbol)) {
                        return in;
                    }

                    if (symbol == 'X' || symbol == 'x') {
                        cell = Player::X;
                    }
                    else if (symbol == 'O' || symbol == 'o') {
                        cell = Player::O;
                    }
                    else if (symbol == '-') {
                        cell = Player::None;
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
            for (auto& row : cells) {
                std::fill(row.begin(), row.end(), Player::None);
            }
        }

        bool isCellEmpty(int r, int c) const {
            if (r >= 0 && r < 3 && c >= 0 && c < 3) {
                return cells[r][c] == Player::None;
            }

            return false;
        }

    private:
        void copyCells(const BoardCells& source) {
            std::copy(source.begin(), source.end(), cells.begin());
        }
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
