/**
 * @file Painter.hpp
 * @brief Declarațiile interfeței și implementării pentru afișarea jocului.
 * Proiect: Tic-Tac-Toe
 * @author Papanaga Damian
 * @date 2026
 */
#pragma once

#include "Engine.hpp"
#include <string>

namespace TicTacToe {

    /**
     * @class AbstractPainter
     * @brief Interfață abstractă pentru afișarea elementelor jocului.
     *
     * Metodele virtuale pure trebuie implementate de clasele derivate.
     */
    class AbstractPainter {
    public:
        /** @brief Destructor virtual pentru distrugerea corectă prin pointer la bază. */
        virtual ~AbstractPainter() = default;

        /** @brief Curăță ecranul consolei. */
        virtual void clearScreen() const = 0;
        /** @brief Afișează antetul jocului. */
        virtual void drawHeader() const = 0;

        /**
         * @brief Afișează tabla de joc.
         * @param board Tabla care trebuie afișată.
         */
        virtual void drawBoard(const Board& board) const = 0;

        /**
         * @brief Afișează jucătorul curent și starea partidei.
         * @param currentPlayer Jucătorul care urmează să mute.
         * @param state Starea curentă a jocului.
         */
        virtual void drawStatus(Player currentPlayer, GameState state) const = 0;

        /**
         * @brief Afișează un mesaj în consolă.
         * @param message Textul mesajului.
         */
        virtual void drawMessage(const std::string& message) const = 0;

        /** @brief Afișează instrucțiunile de utilizare. */
        virtual void drawHelp() const = 0;
    };

    /**
     * @class Painter
     * @brief Implementează afișarea jocului în consolă.
     * @details Implementează toate operațiile definite de AbstractPainter.
     */
    class Painter : public AbstractPainter {
    public:
        /** @brief Construiește componenta de afișare. */
        Painter();

        /** @brief Destructor virtual suprascris. */
        ~Painter() override;

        /** @brief Curăță ecranul consolei. */
        void clearScreen() const override;
        /** @brief Afișează antetul jocului. */
        void drawHeader() const override;

        /**
         * @brief Afișează tabla de joc.
         * @param board Tabla care trebuie afișată.
         */
        void drawBoard(const Board& board) const override;

        /**
         * @brief Afișează jucătorul curent și starea partidei.
         * @param currentPlayer Jucătorul care urmează să mute.
         * @param state Starea curentă a jocului.
         */
        void drawStatus(Player currentPlayer, GameState state) const override;

        /**
         * @brief Afișează un mesaj în consolă.
         * @param message Textul mesajului.
         */
        void drawMessage(const std::string& message) const override;

        /** @brief Afișează instrucțiunile de utilizare. */
        void drawHelp() const override;
    };

}
