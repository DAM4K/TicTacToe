
#pragma once

#include <iosfwd>

namespace TicTacToe {

    struct MoveInput {
        int row;
        int col;
        bool isValid;
        bool isQuitRequested;

        // Constructor implicit
        MoveInput();

        // Constructor de copiere
        MoveInput(const MoveInput& other);

        // Constructor cu parametri
        MoveInput(int row, int col, bool isValid, bool isQuitRequested);

        // Operator de atribuire
        MoveInput& operator=(const MoveInput& other);

        // Operatori de comparare
        bool operator==(const MoveInput& other) const;
        bool operator!=(const MoveInput& other) const;
        bool operator<(const MoveInput& other) const;
        bool operator>(const MoveInput& other) const;
        bool operator<=(const MoveInput& other) const;
        bool operator>=(const MoveInput& other) const;

        // Operatori de intrare si iesire
        friend std::ostream& operator<<(std::ostream& out,
            const MoveInput& input);

        friend std::istream& operator>>(std::istream& in,
            MoveInput& input);

        bool shouldQuit() const;
        bool canProcessMove() const;
    };

}
