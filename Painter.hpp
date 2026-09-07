#ifndef PAINTER_HPP
#define PAINTER_HPP

#include <vector>
#include <string>

enum class Symbol { NONE, X, O };
enum class GameState { IN_PROGRESS, X_WON, O_WON, DRAW };

using Board = std::vector<std::vector<Symbol>>;

class Painter {
public:
    virtual ~Painter() = default;
    virtual void drawBoard(const Board& board) = 0;
    virtual void drawEndGame(GameState state) = 0;
    virtual void drawTurn(Symbol currentTurn) = 0;
    virtual void drawErrorMessage(const std::string& message) = 0;
};

#endif // PAINTER_HPP