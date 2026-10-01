#include "Engine.hpp"
#include "Listener.hpp"
#include "Painter.hpp"

int main() {
    TicTacToe::Engine engine;
    TicTacToe::Listener listener;
    TicTacToe::Painter painter;

    bool keepPlaying = true;

    while (keepPlaying) {
        engine.initialize();

        while (!engine.isGameOver()) {
            painter.clearScreen();
            painter.drawHeader();
            painter.drawBoard(engine.getBoard());
            painter.drawStatus(engine.getCurrentPlayer(), engine.getGameState());

            TicTacToe::MoveInput input = listener.listenForMove();

            if (input.shouldQuit()) {
                keepPlaying = false;
                break;
            }

            if (input.canProcessMove()) {
                if (!engine.makeMove(input.row, input.col)) {
                    painter.drawMessage("Mutare invalidă! Celula este deja ocupată.");
                }
            }
            else {
                painter.drawMessage("Coordonate invalide! Alegeți numere între 0 și 2.");
            }
        }

        if (!keepPlaying) break;

        painter.clearScreen();
        painter.drawHeader();
        painter.drawBoard(engine.getBoard());
        painter.drawStatus(engine.getCurrentPlayer(), engine.getGameState());

        keepPlaying = listener.askForRestart();
    }

    painter.drawMessage("Vă mulțumim pentru joc!");
    return 0;
}