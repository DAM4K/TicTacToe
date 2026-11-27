/**
 * @file Board.hpp
 * @brief Declarațiile pentru tabla de joc Tic-Tac-Toe.
 * Proiect: Tic-Tac-Toe
 * @author Papanaga Damian
 * @date 2026
 */
#pragma once

#include <array>
#include <iosfwd>

/** @namespace TicTacToe Conține tipurile și clasele jocului Tic-Tac-Toe. */
namespace TicTacToe {

    /** @brief Simbolul care ocupă o celulă a tablei. */
    enum class Player {
        None, /**< Celulă liberă. */
        X,    /**< Simbolul jucătorului X. */
        O     /**< Simbolul jucătorului O. */
    };

    /** @brief Un rând al tablei, format din trei celule. */
    using BoardRow = std::array<Player, 3>;

    /** @brief Tabla completă, formată din trei rânduri. */
    using BoardCells = std::array<BoardRow, 3>;

    /**
     * @struct Board
     * @brief Reprezintă tabla de joc 3x3.
     *
     * Clasa păstrează simbolurile jucătorilor și oferă operații de inițializare,
     * copiere, comparare și citire/scriere prin fluxuri.
     */
    struct Board {
        /** @brief Celulele tablei de joc. */
        BoardCells cells{};

        /**
         * @brief Construiește o tablă goală.
         * @post Toate celulele conțin Player::None.
         */
        Board();

        /**
         * @brief Construiește o copie a unei table existente.
         * @param other Tabla-sursă.
         */
        Board(const Board& other);

        /**
         * @brief Construiește tabla dintr-un set de celule.
         * @param initialCells Valorile inițiale ale celor nouă celule.
         */
        Board(const BoardCells& initialCells);

        /**
         * @brief Copiază conținutul unei alte table în obiectul curent.
         * @param other Tabla-sursă.
         * @return Referință la obiectul curent.
         */
        Board& operator=(const Board& other);

        /**
         * @brief Verifică egalitatea a două table.
         * @param other Tabla cu care se face comparația.
         * @return true dacă toate celulele coincid.
         */
        bool operator==(const Board& other) const;

        /**
         * @brief Verifică dacă două table sunt diferite.
         * @param other Tabla cu care se face comparația.
         * @return true dacă cel puțin o celulă diferă.
         */
        bool operator!=(const Board& other) const;

        /**
         * @brief Compară lexicografic două table.
         * @param other Tabla din partea dreaptă a comparației.
         * @return true dacă tabla curentă este mai mică lexicografic.
         */
        bool operator<(const Board& other) const;

        /**
         * @brief Verifică dacă tabla curentă este mai mare lexicografic.
         * @param other Tabla cu care se face comparația.
         * @return true dacă tabla curentă este mai mare lexicografic.
         */
        bool operator>(const Board& other) const;

        /**
         * @brief Verifică dacă tabla curentă este mai mică sau egală.
         * @param other Tabla cu care se face comparația.
         * @return true dacă tabla curentă nu este mai mare lexicografic.
         */
        bool operator<=(const Board& other) const;

        /**
         * @brief Verifică dacă tabla curentă este mai mare sau egală.
         * @param other Tabla cu care se face comparația.
         * @return true dacă tabla curentă nu este mai mică lexicografic.
         */
        bool operator>=(const Board& other) const;

        /**
         * @brief Scrie tabla într-un flux de ieșire.
         * @param out Fluxul de ieșire.
         * @param board Tabla care va fi afișată.
         * @return Referință la fluxul de ieșire.
         * @details Celulele sunt reprezentate prin X, O și -, separate prin spații.
         */
        friend std::ostream& operator<<(std::ostream& out, const Board& board);

        /**
         * @brief Citește valorile tablei dintr-un flux de intrare.
         * @param in Fluxul de intrare.
         * @param board Tabla care va fi actualizată.
         * @return Referință la fluxul de intrare.
         * @details Acceptă X/x, O/o și - pentru cele nouă celule.
         */
        friend std::istream& operator>>(std::istream& in, Board& board);

        /**
         * @brief Golește tabla de joc.
         * @post Toate celulele conțin Player::None.
         */
        void reset();

        /**
         * @brief Verifică dacă o celulă se află în interiorul tablei și este liberă.
         * @param r Indexul rândului (0-2).
         * @param c Indexul coloanei (0-2).
         * @return true dacă poziția este validă și celula este liberă; altfel false.
         */
        bool isCellEmpty(int r, int c) const;

    private:
        /**
         * @brief Copiază valorile celulelor dintr-o tablă-sursă.
         * @param source Matricea-sursă.
         */
        void copyCells(const BoardCells& source);
    };

}
