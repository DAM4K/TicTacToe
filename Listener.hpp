/**
 * @file Listener.hpp
 * @brief Declarația componentei de citire a comenzilor utilizatorului.
 * Proiect: Tic-Tac-Toe
 * @author Papanaga Damian
 * @date 2026
 */
#pragma once

#include "MoveInput.hpp"

namespace TicTacToe {

    /**
     * @class Listener
     * @brief Citește mutările și comenzile utilizatorului din consolă.
     */
    class Listener {
    public:
        /** @brief Construiește un listener pentru comenzile utilizatorului. */
        Listener();

        /** @brief Destructorul listener-ului. */
        ~Listener();

        /**
         * @brief Citește și returnează datele unei mutări.
         * @return Obiect MoveInput cu coordonatele și starea comenzii.
         */
        MoveInput listenForMove() const;

        /**
         * @brief Întreabă utilizatorul dacă dorește să înceapă o partidă nouă.
         * @return true dacă utilizatorul confirmă reluarea jocului.
         */
        bool askForRestart() const;
    };

}
