# Prompts pentru lab1

```prompt

Sarcina C++
Realizeaza joaca tic-tac-toe (X și O)
Adăugați în repozitoriu fișier README.md cu descrierea proiectului Denumirea proiectului
Descrierea proiectului / reguli de joc
Structuri de date si descrierea lor
Creați fișiere hpp cu definirea structurilor de bază necesitate pentru proiect. Fisiere obligatorii:motor de joaca (de exemplu, GameEngine.hpp sau Engine.hpp)
desenator (de exemplu Painter.hpp, Presenter.hpp sau Renderer.hpp)
ascultator (de exemplu Listener.hpp)
```
Rezultat:

Iată o structură modulară și curată în C++ pentru jocul Tic-Tac-Toe, separată conform cerințelor în **Motor de joc**, **Desenator** și **Ascultator**, alături de conținutul pentru fișierul `README.md`.

---

### Fișierul `README.md`

```markdown
# Tic-Tac-Toe C++ (X și O)

## Descrierea proiectului și reguli de joc
Acest proiect este o implementare în C++ a clasicului joc **Tic-Tac-Toe (X și O)** pentru consolă. Jocul este conceput modular, separând logica de starea jocului, afișarea (renderizarea) și citirea input-ului de la utilizator.

**Reguli de joc:**
1. Jocul se joacă pe o tablă de $3 \times 3$ celule.
2. Participă 2 jucători: unul folosește simbolul **X**, iar celălalt simbolul **O**.
3. Jucătorii pun alternativ simbolul lor pe o celulă liberă.
4. Primul jucător care reușește să alinieze 3 simboluri identice pe orizontală, verticală sau diagonală câștigă.
5. Dacă toate cele 9 celule sunt ocupate și niciun jucător nu a aliniat 3 simboluri, jocul se termină la egalitate (remiză).

---

## Structuri de date și descrierea lor

* `enum class Symbol`: Definește conținutul unei celule pe tablă (`NONE` / Gol, `X`, `O`).
* `enum class GameState`: Reprezintă starea curentă a jocului (`IN_PROGRESS`, `X_WON`, `O_WON`, `DRAW`).
* `struct Position`: Reține coordonatele unei mutări pe tablă (`row`, `col`).
* `Board`: Matrice $3 \times 3$ de tip `Symbol` care reține configurația curentă a jocului.
* `Listener`: Interfață / clasă abstractă responsabilă de preluarea input-ului (de la tastatură).
* `Painter`: Interfață / clasă abstractă responsabilă de afișarea reprezentării grafice/textuale a jocului.
* `GameEngine`: Clasa principală care orchestrează fluxul jocului, validează mutările și verifică condițiile de victorie.

```

---

### 1. `Listener.hpp`

Preluarea datelor de intrare (mutările jucătorilor).

```cpp
#ifndef LISTENER_HPP
#define LISTENER_HPP

struct Position {
    int row;
    int col;
};

class Listener {
public:
    virtual ~Listener() = default;

    // Citește și returnează poziția aleasă de jucător
    virtual Position getNextMove() = 0;
};

#endif // LISTENER_HPP

```

---

### 2. `Painter.hpp`

Afișarea în consolă a stării jocului și a mesajelor.

```cpp
#ifndef PAINTER_HPP
#define PAINTER_HPP

#include <vector>

enum class Symbol { NONE, X, O };
enum class GameState { IN_PROGRESS, X_WON, O_WON, DRAW };

using Board = std::vector<std::vector<Symbol>>;

class Painter {
public:
    virtual ~Painter() = default;

    // Afișează tabla de joc curentă
    virtual void drawBoard(const Board& board) = 0;

    // Afișează mesajul de final
    virtual void drawEndGame(GameState state) = 0;

    // Afișează mesaje de eroare sau informații despre tura curentă
    virtual void drawTurn(Symbol currentTurn) = 0;
    virtual void drawErrorMessage(const std::string& message) = 0;
};

#endif // PAINTER_HPP

```

---

### 3. `GameEngine.hpp`

Logica principală a jocului: starea tablei, comutarea turelor și condițiile de oprire.

```cpp
#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "Painter.hpp"
#include "Listener.hpp"

class GameEngine {
private:
    Board board;
    Symbol currentTurn;
    GameState state;
    Painter& painter;
    Listener& listener;

    bool checkLine(Symbol a, Symbol b, Symbol c) const {
        return (a != Symbol::NONE) && (a == b) && (b == c);
    }

    void updateGameState() {
        // Verificare linii și coloane
        for (int i = 0; i < 3; ++i) {
            if (checkLine(board[i][0], board[i][1], board[i][2])) {
                state = (board[i][0] == Symbol::X) ? GameState::X_WON : GameState::O_WON;
                return;
            }
            if (checkLine(board[0][i], board[1][i], board[2][i])) {
                state = (board[0][i] == Symbol::X) ? GameState::X_WON : GameState::O_WON;
                return;
            }
        }

        // Verificare diagonale
        if (checkLine(board[0][0], board[1][1], board[2][2])) {
            state = (board[0][0] == Symbol::X) ? GameState::X_WON : GameState::O_WON;
            return;
        }
        if (checkLine(board[0][2], board[1][1], board[2][0])) {
            state = (board[0][2] == Symbol::X) ? GameState::X_WON : GameState::O_WON;
            return;
        }

        // Verificare remiză
        bool full = true;
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board[r][c] == Symbol::NONE) {
                    full = false;
                    break;
                }
            }
        }

        if (full) {
            state = GameState::DRAW;
        }
    }

public:
    GameEngine(Painter& p, Listener& l) 
        : painter(p), listener(l), currentTurn(Symbol::X), state(GameState::IN_PROGRESS) {
        board = std::vector<std::vector<Symbol>>(3, std::vector<Symbol>(3, Symbol::NONE));
    }

    void run() {
        while (state == GameState::IN_PROGRESS) {
            painter.drawBoard(board);
            painter.drawTurn(currentTurn);

            Position pos = listener.getNextMove();

            // Validare mutare
            if (pos.row < 0 || pos.row >= 3 || pos.col < 0 || pos.col >= 3) {
                painter.drawErrorMessage("Poziție invalidă! Alegeți valori între 0 și 2.");
                continue;
            }

            if (board[pos.row][pos.col] != Symbol::NONE) {
                painter.drawErrorMessage("Celulă deja ocupată! Alegeți alta.");
                continue;
            }

            // Aplicare mutare
            board[pos.row][pos.col] = currentTurn;
            updateGameState();

            // Schimbare tură
            if (state == GameState::IN_PROGRESS) {
                currentTurn = (currentTurn == Symbol::X) ? Symbol::O : Symbol::X;
            }
        }

        painter.drawBoard(board);
        painter.drawEndGame(state);
    }
};

#endif // GAMEENGINE_HPP

```

Doriți să adaug și o implementare de exemplu pentru clasele derivate din `Listener` și `Painter` în fișierul `main.cpp` pentru a putea rula jocul direct?

```
