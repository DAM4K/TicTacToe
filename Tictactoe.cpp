
#include "Engine.hpp"
#include "Listener.hpp"
#include "Painter.hpp"
#include "GameStorage.hpp"

#include <string>

int main() {
    TicTacToe::Engine engine;
    TicTacToe::Listener listener;
    TicTacToe::Painter painter;

    TicTacToe::GameStorage storage("tictactoe.db");

    bool keepPlaying = true;

    while (keepPlaying) {
        engine.initialize();

        while (!engine.isGameOver()) {
            painter.clearScreen();
            painter.drawHeader();
            painter.drawBoard(engine.getBoard());
            painter.drawStatus(
                engine.getCurrentPlayer(),
                engine.getGameState()
            );

            TicTacToe::MoveInput input = listener.listenForMove();

            if (input.shouldQuit()) {
                keepPlaying = false;
                break;
            }

            if (input.canProcessMove()) {
                if (!engine.makeMove(input.row, input.col)) {
                    painter.drawMessage(
                        "Mutare invalida! Celula este deja ocupata."
                    );
                }
            }
            else {
                painter.drawMessage(
                    "Coordonate invalide! Alegeti numere intre 0 si 2."
                );
            }
        }

        if (!keepPlaying) {
            break;
        }

        painter.clearScreen();
        painter.drawHeader();
        painter.drawBoard(engine.getBoard());
        painter.drawStatus(
            engine.getCurrentPlayer(),
            engine.getGameState()
        );

        // Determinam rezultatul jocului
        std::string result;

        switch (engine.getGameState()) {
        case TicTacToe::GameState::PlayerXWins:
            result = "Player X wins";
            break;

        case TicTacToe::GameState::PlayerOWins:
            result = "Player O wins";
            break;

        case TicTacToe::GameState::Draw:
            result = "Draw";
            break;

        case TicTacToe::GameState::InProgress:
            break;
        }

        // Salvam rezultatul in baza de date
        if (!result.empty()) {
            if (!storage.saveResult(result)) {
                painter.drawMessage(
                    "Nu s-a putut salva rezultatul in baza de date."
                );
            }
        }

        keepPlaying = listener.askForRestart();
    }

    painter.drawMessage("Va multumim pentru joc!");

    return 0;
}
