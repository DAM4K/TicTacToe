
#pragma once

#include "MoveInput.hpp"

namespace TicTacToe {

    class Listener {
    public:
        Listener();
        ~Listener();

        MoveInput listenForMove() const;
        bool askForRestart() const;
    };

}
