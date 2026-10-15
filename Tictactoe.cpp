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
                    painter.drawMessage("Mutare invalida! Celula este deja ocupata.");
                }
            }
            else {
                painter.drawMessage("Coordonate invalide! Alegeti numere intre 0 si 2.");
            }
        }

        if (!keepPlaying) break;

        painter.clearScreen();
        painter.drawHeader();
        painter.drawBoard(engine.getBoard());
        painter.drawStatus(engine.getCurrentPlayer(), engine.getGameState());

        keepPlaying = listener.askForRestart();
    }

    painter.drawMessage("Va multumim pentru joc!");
    return 0;
}