/**
 * @file GameStorage.hpp
 * @brief Declarația componentei de persistare a rezultatelor folosind SQLite.
 * Proiect: Tic-Tac-Toe
 * @author Papanaga Damian
 * @date 2026
 */
#pragma once

#include <memory>
#include <string>
#include <sqlite3.h>

namespace TicTacToe {

    /**
     * @class GameStorage
     * @brief Gestionează conexiunea SQLite și salvarea rezultatelor partidelor.
     *
     * Obiectul deține conexiunea la baza de date printr-un pointer inteligent.
     * Copierea obiectelor GameStorage este dezactivată.
     */
    class GameStorage {
    public:
        /**
         * @brief Deschide baza de date indicată.
         * @param databasePath Calea către fișierul bazei de date SQLite.
         */
        explicit GameStorage(const std::string& databasePath);

        /** @brief Închide automat conexiunea SQLite deținută de obiect. */
        ~GameStorage();

        /**
         * @brief Dezactivează constructorul de copiere.
         * @details O conexiune SQLite deținută nu poate fi copiată prin această clasă.
         */
        GameStorage(const GameStorage&) = delete;

        /**
         * @brief Dezactivează operatorul de atribuire prin copiere.
         * @return Nu există valoare returnată; operația este interzisă la compilare.
         */
        GameStorage& operator=(const GameStorage&) = delete;

        /**
         * @brief Verifică disponibilitatea conexiunii la baza de date.
         * @return true dacă obiectul este pregătit să folosească baza de date.
         */
        bool isOpen() const;

        /**
         * @brief Salvează rezultatul unei partide.
         * @param result Textul care descrie rezultatul (de exemplu, câștigător sau remiză).
         * @return true dacă rezultatul a fost salvat cu succes; altfel false.
         */
        bool saveResult(const std::string& result) const;

    private:
        /** @brief Tip de pointer inteligent care închide conexiunea SQLite la distrugere. */
        using DatabasePtr =
            std::unique_ptr<sqlite3, decltype(&sqlite3_close)>;

        /** @brief Conexiunea SQLite deținută de obiect. */
        DatabasePtr database_;
        /** @brief Indică dacă inițializarea bazei de date a reușit. */
        bool ready_;
    };

}
