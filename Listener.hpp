#pragma once

namespace TicTacToe {

    struct MoveInput {
        int row;
        int col;
        bool isValid;
        bool isQuitRequested;

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