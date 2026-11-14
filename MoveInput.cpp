
#include "MoveInput.hpp"

#include <istream>
#include <ostream>

namespace TicTacToe {

    MoveInput::MoveInput()
        : row(0), col(0), isValid(false), isQuitRequested(false) {
    }

    MoveInput::MoveInput(const MoveInput& other)
        : row(other.row),
        col(other.col),
        isValid(other.isValid),
        isQuitRequested(other.isQuitRequested) {
    }

    MoveInput::MoveInput(int row, int col, bool isValid,
        bool isQuitRequested)
        : row(row),
        col(col),
        isValid(isValid),
        isQuitRequested(isQuitRequested) {
    }

    MoveInput& MoveInput::operator=(const MoveInput& other) {
        if (this != &other) {
            row = other.row;
            col = other.col;
            isValid = other.isValid;
            isQuitRequested = other.isQuitRequested;
        }
        return *this;
    }

    bool MoveInput::operator==(const MoveInput& other) const {
        return row == other.row &&
            col == other.col &&
            isValid == other.isValid &&
            isQuitRequested == other.isQuitRequested;
    }

    bool MoveInput::operator!=(const MoveInput& other) const {
        return !(*this == other);
    }

    bool MoveInput::operator<(const MoveInput& other) const {
        if (row != other.row) return row < other.row;
        if (col != other.col) return col < other.col;
        if (isValid != other.isValid) return isValid < other.isValid;

        return isQuitRequested < other.isQuitRequested;
    }

    bool MoveInput::operator>(const MoveInput& other) const {
        return other < *this;
    }

    bool MoveInput::operator<=(const MoveInput& other) const {
        return !(other < *this);
    }

    bool MoveInput::operator>=(const MoveInput& other) const {
        return !(*this < other);
    }

    std::ostream& operator<<(std::ostream& out, const MoveInput& input) {
        out << input.row << ' '
            << input.col << ' '
            << input.isValid << ' '
            << input.isQuitRequested;

        return out;
    }

    std::istream& operator>>(std::istream& in, MoveInput& input) {
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

    bool MoveInput::shouldQuit() const {
        return isQuitRequested;
    }

    bool MoveInput::canProcessMove() const {
        return isValid && !isQuitRequested;
    }

}
