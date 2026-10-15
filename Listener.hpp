#pragma once

#include <iostream>

namespace TicTacToe {

    struct MoveInput {
        int row;
        int col;
        bool isValid;
        bool isQuitRequested;

        // Constructor implicit
        MoveInput()
            : row(0), col(0), isValid(false), isQuitRequested(false) {
        }

        // Constructor de copiere
        MoveInput(const MoveInput& other)
            : row(other.row),
            col(other.col),
            isValid(other.isValid),
            isQuitRequested(other.isQuitRequested) {
        }

        // Constructor cu parametri
        MoveInput(int row, int col, bool isValid, bool isQuitRequested)
            : row(row),
            col(col),
            isValid(isValid),
            isQuitRequested(isQuitRequested) {
        }

        // Operator de atribuire
        MoveInput& operator=(const MoveInput& other) {
            if (this != &other) {
                row = other.row;
                col = other.col;
                isValid = other.isValid;
                isQuitRequested = other.isQuitRequested;
            }
            return *this;
        }

        // Operatori de comparare
        bool operator==(const MoveInput& other) const {
            return row == other.row &&
                col == other.col &&
                isValid == other.isValid &&
                isQuitRequested == other.isQuitRequested;
        }

        bool operator!=(const MoveInput& other) const {
            return !(*this == other);
        }

        bool operator<(const MoveInput& other) const {
            if (row != other.row) return row < other.row;
            if (col != other.col) return col < other.col;
            if (isValid != other.isValid) return isValid < other.isValid;
            return isQuitRequested < other.isQuitRequested;
        }

        bool operator>(const MoveInput& other) const {
            return other < *this;
        }

        bool operator<=(const MoveInput& other) const {
            return !(other < *this);
        }

        bool operator>=(const MoveInput& other) const {
            return !(*this < other);
        }

        // Operator de iesire
        friend std::ostream& operator<<(std::ostream& out,
            const MoveInput& input) {
            out << input.row << ' '
                << input.col << ' '
                << input.isValid << ' '
                << input.isQuitRequested;
            return out;
        }

        // Operator de intrare
        friend std::istream& operator>>(std::istream& in, MoveInput& input) {
            int row, col;
            bool isValid, isQuitRequested;

            if (in >> row >> col >> isValid >> isQuitRequested) {
                input.row = row;
                input.col = col;
                input.isValid = isValid;
                input.isQuitRequested = isQuitRequested;
            }

            return in;
        }

        bool shouldQuit() const {
            return isQuitRequested;
        }

        bool canProcessMove() const {
            return isValid && !isQuitRequested;
        }
    };
    class Listener {
    public:
        Listener();
        ~Listener();

        MoveInput listenForMove() const;
        bool askForRestart() const;
    };

}