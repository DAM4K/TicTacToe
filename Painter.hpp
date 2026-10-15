
#pragma once

#include "Engine.hpp"
#include <string>

namespace TicTacToe {

    class AbstractPainter {
    public:
        virtual ~AbstractPainter() = default;

        virtual void clearScreen() const = 0;
        virtual void drawHeader() const = 0;
        virtual void drawBoard(const Board& board) const = 0;
        virtual void drawStatus(Player currentPlayer, GameState state) const = 0;
        virtual void drawMessage(const std::string& message) const = 0;
        virtual void drawHelp() const = 0;
    };

    class Painter : public AbstractPainter {
    public:
        Painter();
        ~Painter() override;

        void clearScreen() const override;
        void drawHeader() const override;
        void drawBoard(const Board& board) const override;
        void drawStatus(Player currentPlayer, GameState state) const override;
        void drawMessage(const std::string& message) const override;
        void drawHelp() const override;
    };

}
