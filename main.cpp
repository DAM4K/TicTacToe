#include "ConsolePainter.hpp"
#include "ConsoleListener.hpp"
#include "Engine.hpp"

int main() {
    ConsolePainter painter;
    ConsoleListener listener;

    Engine game(painter, listener);
    game.run();

    return 0;
}