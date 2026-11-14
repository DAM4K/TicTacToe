
#pragma once

#include <memory>
#include <string>
#include <sqlite3.h>

namespace TicTacToe {

    class GameStorage {
    public:
        explicit GameStorage(const std::string& databasePath);
        ~GameStorage();

        GameStorage(const GameStorage&) = delete;
        GameStorage& operator=(const GameStorage&) = delete;

        bool isOpen() const;
        bool saveResult(const std::string& result) const;

    private:
        using DatabasePtr =
            std::unique_ptr<sqlite3, decltype(&sqlite3_close)>;

        DatabasePtr database_;
        bool ready_;
    };

}
