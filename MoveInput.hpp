/**
 * @file MoveInput.hpp
 * @brief Declarația structurii care păstrează datele unei mutări.
 * Proiect: Tic-Tac-Toe
 * @author Papanaga Damian
 * @date 2026
 */
#pragma once

#include <iosfwd>

namespace TicTacToe {

    /**
     * @struct MoveInput
     * @brief Reprezintă datele citite pentru o mutare sau o solicitare de ieșire.
     */
    struct MoveInput {
        /** @brief Indexul rândului selectat (în mod obișnuit 0-2). */
        int row;
        /** @brief Indexul coloanei selectate (în mod obișnuit 0-2). */
        int col;
        /** @brief Indică dacă poziția introdusă a fost validată. */
        bool isValid;
        /** @brief Indică dacă utilizatorul a solicitat ieșirea din joc. */
        bool isQuitRequested;

        /** @brief Construiește o intrare implicită, nevalidă, fără solicitare de ieșire. */
        MoveInput();

        /**
         * @brief Construiește o copie a unei intrări existente.
         * @param other Intrarea-sursă.
         */
        MoveInput(const MoveInput& other);

        /**
         * @brief Construiește o intrare cu valorile specificate.
         * @param row Indexul rândului.
         * @param col Indexul coloanei.
         * @param isValid Starea de validare a mutării.
         * @param isQuitRequested Starea solicitării de ieșire.
         */
        MoveInput(int row, int col, bool isValid, bool isQuitRequested);

        /**
         * @brief Copiază valorile unei alte intrări.
         * @param other Intrarea-sursă.
         * @return Referință la obiectul curent.
         */
        MoveInput& operator=(const MoveInput& other);

        /**
         * @brief Compară toate câmpurile a două intrări.
         * @param other Intrarea cu care se face comparația.
         * @return true dacă toate câmpurile coincid.
         */
        bool operator==(const MoveInput& other) const;

        /**
         * @brief Verifică dacă două intrări sunt diferite.
         * @param other Intrarea cu care se face comparația.
         * @return true dacă cel puțin un câmp diferă.
         */
        bool operator!=(const MoveInput& other) const;

        /**
         * @brief Compară lexicografic câmpurile intrărilor: row, col, isValid, isQuitRequested.
         * @param other Intrarea din partea dreaptă a comparației.
         * @return true dacă intrarea curentă este mai mică lexicografic.
         */
        bool operator<(const MoveInput& other) const;

        /**
         * @brief Verifică dacă intrarea curentă este mai mare lexicografic.
         * @param other Intrarea cu care se face comparația.
         * @return true dacă intrarea curentă este mai mare lexicografic.
         */
        bool operator>(const MoveInput& other) const;

        /**
         * @brief Verifică dacă intrarea curentă este mai mică sau egală.
         * @param other Intrarea cu care se face comparația.
         * @return true dacă intrarea curentă nu este mai mare lexicografic.
         */
        bool operator<=(const MoveInput& other) const;

        /**
         * @brief Verifică dacă intrarea curentă este mai mare sau egală.
         * @param other Intrarea cu care se face comparația.
         * @return true dacă intrarea curentă nu este mai mică lexicografic.
         */
        bool operator>=(const MoveInput& other) const;

        /**
         * @brief Scrie câmpurile intrării într-un flux de ieșire.
         * @param out Fluxul de ieșire.
         * @param input Intrarea care va fi scrisă.
         * @return Referință la fluxul de ieșire.
         */
        friend std::ostream& operator<<(std::ostream& out, const MoveInput& input);

        /**
         * @brief Citește câmpurile intrării dintr-un flux.
         * @param in Fluxul de intrare.
         * @param input Obiectul care va primi valorile citite.
         * @return Referință la fluxul de intrare.
         */
        friend std::istream& operator>>(std::istream& in, MoveInput& input);

        /**
         * @brief Verifică dacă utilizatorul a solicitat ieșirea.
         * @return true dacă isQuitRequested este true.
         */
        bool shouldQuit() const;

        /**
         * @brief Verifică dacă mutarea poate fi procesată.
         * @return true dacă intrarea este validă și nu s-a solicitat ieșirea.
         */
        bool canProcessMove() const;
    };

}
