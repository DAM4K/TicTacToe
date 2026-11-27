/**
 * @file Engine.hpp
 * @brief Declarațiile pentru starea și logica principală a jocului.
 * Proiect: Tic-Tac-Toe
 * @author Papanaga Damian
 * @date 2026
 */
#pragma once

#include "Board.hpp"

namespace TicTacToe {

    /** @brief Enumeră rezultatele posibile ale unei partide. */
    enum class GameState {
        InProgress,  /**< Partida este în desfășurare. */
        PlayerXWins, /**< Jucătorul X a câștigat. */
        PlayerOWins, /**< Jucătorul O a câștigat. */
        Draw         /**< Partida s-a încheiat la egalitate. */
    };

    /**
     * @class Engine
     * @brief Gestionează tabla, jucătorul curent și regulile jocului.
     */
    class Engine {
    public:
        /** @brief Construiește motorul jocului și inițializează starea inițială. */
        Engine();

        /** @brief Destructorul motorului jocului. */
        ~Engine();

        /**
         * @brief Resetează tabla și pregătește o partidă nouă.
         * @post Jocul revine în starea InProgress, cu jucătorul X la mutare.
         */
        void initialize();

        /**
         * @brief Încearcă să execute mutarea jucătorului curent.
         * @param row Indexul rândului (0-2).
         * @param col Indexul coloanei (0-2).
         * @return true dacă mutarea a fost acceptată; altfel false.
         */
        bool makeMove(int row, int col);

        /**
         * @brief Oferă acces constant la tabla curentă.
         * @return Referință constantă la tabla de joc.
         */
        const Board& getBoard() const;

        /**
         * @brief Returnează jucătorul care urmează să mute.
         * @return Player::X sau Player::O.
         */
        Player getCurrentPlayer() const;

        /**
         * @brief Returnează rezultatul/starea curentă a partidei.
         * @return Valoarea curentă din GameState.
         */
        GameState getGameState() const;

        /**
         * @brief Verifică dacă partida s-a terminat.
         * @return true dacă există un câștigător sau tabla este plină.
         */
        bool isGameOver() const;

    private:
        /** @brief Tabla curentă de joc. */
        Board board;
        /** @brief Jucătorul care urmează să mute. */
        Player currentPlayer;
        /** @brief Starea curentă a partidei. */
        GameState gameState;

        /** @brief Actualizează starea jocului după o mutare. */
        void checkGameState();

        /**
         * @brief Verifică dacă jucătorul indicat are trei simboluri aliniate.
         * @param player Jucătorul verificat.
         * @return true dacă jucătorul a câștigat.
         */
        bool checkWin(Player player) const;

        /**
         * @brief Verifică dacă toate celulele tablei sunt ocupate.
         * @return true dacă tabla este plină.
         */
        bool isBoardFull() const;
    };

}
