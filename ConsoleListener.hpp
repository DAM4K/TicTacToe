#ifndef CONSOLELISTENER_HPP
#define CONSOLELISTENER_HPP

#include "Listener.hpp"
#include <iostream>

class ConsoleListener : public Listener {
public:
    Position getNextMove() override {
        Position pos;
        std::cout << "Introdu randul (0-2) si coloana (0-2) separate prin spatiu: ";
        std::cin >> pos.row >> pos.col;
        return pos;
    }
};

#endif // CONSOLELISTENER_HPP