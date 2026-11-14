
#include "Board.hpp"

#include <algorithm>
#include <istream>
#include <ostream>

namespace TicTacToe {

    Board::Board() {
        reset();
    }

    Board::Board(const Board& other) : cells{} {
        copyCells(other.cells);
    }

    Board::Board(const BoardCells& initialCells) : cells{} {
        copyCells(initialCells);
    }

    Board& Board::operator=(const Board& other) {
        if (this != &other) {
            copyCells(other.cells);
        }
        return *this;
    }

    bool Board::operator==(const Board& other) const {
        return std::equal(
            cells.begin(), cells.end(),
            other.cells.begin()
        );
    }

    bool Board::operator!=(const Board& other) const {
        return !(*this == other);
    }

    bool Board::operator<(const Board& other) const {
        return std::lexicographical_compare(
            cells.begin(), cells.end(),
            other.cells.begin(), other.cells.end()
        );
    }

    bool Board::operator>(const Board& other) const {
        return other < *this;
    }

    bool Board::operator<=(const Board& other) const {
        return !(other < *this);
    }

    bool Board::operator>=(const Board& other) const {
        return !(*this < other);
    }

    std::ostream& operator<<(std::ostream& out, const Board& board) {
        for (std::size_t r = 0; r < board.cells.size(); ++r) {
            for (std::size_t c = 0; c < board.cells[r].size(); ++c) {
                if (board.cells[r][c] == Player::X) {
                    out << 'X';
                }
                else if (board.cells[r][c] == Player::O) {
                    out << 'O';
                }
                else {
                    out << '-';
                }

                if (c < 2) out << ' ';
            }

            if (r < 2) out << '\n';
        }

        return out;
    }

    std::istream& operator>>(std::istream& in, Board& board) {
        for (auto& row : board.cells) {
            for (auto& cell : row) {
                char symbol;

                if (!(in >> symbol)) return in;

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

    void Board::reset() {
        for (auto& row : cells) {
            std::fill(row.begin(), row.end(), Player::None);
        }
    }

    bool Board::isCellEmpty(int r, int c) const {
        if (r >= 0 && r < 3 && c >= 0 && c < 3) {
            return cells[r][c] == Player::None;
        }

        return false;
    }

    void Board::copyCells(const BoardCells& source) {
        std::copy(source.begin(), source.end(), cells.begin());
    }

}
