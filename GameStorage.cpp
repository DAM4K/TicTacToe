
#include "GameStorage.hpp"

namespace TicTacToe {

    GameStorage::GameStorage(const std::string& databasePath)
        : database_(nullptr, &sqlite3_close), ready_(false) {

        sqlite3* rawDatabase = nullptr;

        if (sqlite3_open(databasePath.c_str(), &rawDatabase) != SQLITE_OK) {
            if (rawDatabase != nullptr) {
                sqlite3_close(rawDatabase);
            }
            return;
        }

        database_.reset(rawDatabase);

        const char* createTable =
            "CREATE TABLE IF NOT EXISTS games ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "result TEXT NOT NULL,"
            "played_at TEXT NOT NULL "
            "DEFAULT (datetime('now','localtime'))"
            ");";

        ready_ = sqlite3_exec(
            database_.get(),
            createTable,
            nullptr,
            nullptr,
            nullptr
        ) == SQLITE_OK;
    }

    GameStorage::~GameStorage() = default;

    bool GameStorage::isOpen() const {
        return ready_ && database_ != nullptr;
    }

    bool GameStorage::saveResult(const std::string& result) const {
        if (!isOpen()) {
            return false;
        }

        const char* insertSql =
            "INSERT INTO games (result) VALUES (?);";

        sqlite3_stmt* rawStatement = nullptr;

        int rc = sqlite3_prepare_v2(
            database_.get(),
            insertSql,
            -1,
            &rawStatement,
            nullptr
        );

        std::unique_ptr<sqlite3_stmt, decltype(&sqlite3_finalize)>
            statement(rawStatement, &sqlite3_finalize);

        if (rc != SQLITE_OK || !statement) {
            return false;
        }

        if (sqlite3_bind_text(
            statement.get(),
            1,
            result.c_str(),
            -1,
            SQLITE_TRANSIENT
        ) != SQLITE_OK) {
            return false;
        }

        return sqlite3_step(statement.get()) == SQLITE_DONE;
    }

}
