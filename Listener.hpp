#pragma once

namespace TicTacToe {

    struct MoveInput {
        int row;
        int col;
        bool isValid;
        bool isQuitRequested;
    };

    class Listener {
    public:
        Listener();
        ~Listener();

        MoveInput listenForMove() const;
        bool askForRestart() const;
    };

}