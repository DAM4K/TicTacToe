
#pragma once

#include <array>
#include <iosfwd>

namespace TicTacToe {

    enum class Player {
        None,
        X,
        O
    };

    using BoardRow = std::array<Player, 3>;
    using BoardCells = std::array<BoardRow, 3>;

    struct Board {
        BoardCells cells{};

        // Constructor implicit
        Board();

        // Constructor de copiere
        Board(const Board& other);

        // Constructor cu parametri
        Board(const BoardCells& initialCells);

        // Operator de atribuire
        Board& operator=(const Board& other);

        // Operatori de comparare
        bool operator==(const Board& other) const;
        bool operator!=(const Board& other) const;
        bool operator<(const Board& other) const;
        bool operator>(const Board& other) const;
        bool operator<=(const Board& other) const;
        bool operator>=(const Board& other) const;

        // Operatori de intrare si iesire
        friend std::ostream& operator<<(std::ostream& out,
            const Board& board);

        friend std::istream& operator>>(std::istream& in, Board& board);

        void reset();
        bool isCellEmpty(int r, int c) const;

    private:
        void copyCells(const BoardCells& source);
    };

}
