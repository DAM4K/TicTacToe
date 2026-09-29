#pragma once

#include "Engine.hpp"
#include <string>

namespace TicTacToe {

    class Painter {
    public:
        Painter();
        ~Painter();

        void clearScreen() const;
        void drawHeader() const;
        void drawBoard(const Board& board) const;
        void drawStatus(Player currentPlayer, GameState state) const;
        void drawMessage(const std::string& message) const;
        void drawHelp() const;
    };

}