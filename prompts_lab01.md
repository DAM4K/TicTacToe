# Prompts pentru lab1

```prompt

După executarea acestei lucrării de laborator student va face cunoștința cu sistem de control codului sursă GIT și va primi cunoștințe de bază necesare pentru organizarea proiectului.

Sarcina
Selectați pentru realizarea o joacă din specificate:joc de cărți "Durak"
tic-tac-toe (X și O)
Snake
Minesweeper
Pacman
Dame
Story Tale (text adventure)
Visual Novel
Rogue-like
etc.
Înregistrați-vă pe GitHub.
Creați un repozitoriu nou.
Clonați repozitoriu pe calculator personal
Adăugați în repozitoriu fișier README.md cu descrierea proiectului
Adăugați în repozitoriu fișier README.md cu descrierea proiectuluiDenumirea proiectului
Descrierea proiectului / reguli de joc
Structuri de date si descrierea lor
Creați fișiere hpp cu definirea structurilor de bază necesitate pentru proiect. Fisiere obligatorii:motor de joaca (de exemplu, GameEngine.hpp sau Engine.hpp)
desenator (de exemplu Painter.hpp, Presenter.hpp sau Renderer.hpp)
ascultator (de exemplu Listener.hpp)
Plasați cod pe GitHub
Dacă se utilizează LLM, atunci, repozitoruil trebuie să conțină fișier prompts_lab01.md cu prompturi și descrierea rezultatului / fixării greșelilor.
```
Rezultat:

Acest ghid vă oferă pas cu pas tot ce este necesar pentru a completa lucrarea de laborator, de la configurarea Git și GitHub până la structurarea codului C++ și a fișierelor de documentație.

---

## 1. Ghid de executare (Comenzi Git)

După ce v-ați creat cont pe [GitHub](https://github.com) și ați creat un repozitoriu nou (de exemplu, numit `snake-game`), executați următoarele comenzi în terminalul de pe calculatorul personal:

```bash
# Clonați repozitoriul pe calculator (înlocuiți cu URL-ul repozitoriului dvs.)
git clone https://github.com/utilizator/snake-game.git
cd snake-game

# Creați fișierele necesare
touch README.md Engine.hpp Renderer.hpp Listener.hpp prompts_lab01.md

# Verificați starea fișierelor
git status

# Adăugați fișierele în zona de staging
git add .

# Salvati modificările local (commit)
git commit -m "Initial commit: Adaugat structura de baza a proiectului si fisierul README"

# Trimiteți codul pe GitHub
git push origin main

```

---

## 2. Model de fișier `README.md`

Copiați conținutul de mai jos în fișierul `README.md` și adaptați-l dacă doriți:

```markdown
# Jocul Snake (Șarpele)

## Descrierea proiectului și regulile de joc
Acest proiect reprezintă o implementare clasică a jocului **Snake** în limbajul C++.

### Reguli de joc:
1. Jucătorul controlează un șarpe pe o grilă bidimensională.
2. Șarpele se mișcă continuu în direcția selectată (Sus, Jos, Stânga, Dreapta).
3. Jucătorul trebuie să adune mâncare pentru a acumula puncte și a mări lungimea șarpelui.
4. Jocul se termină (*Game Over*) dacă șarpele lovește pereții suprafeței de joc sau își mușcă propria coadă.

---

## Structuri de date și descrierea lor

* `Point`: Structură simplă pentru stocarea coordonatelor pe grilă `(x, y)`.
* `Direction`: Enumerație pentru starea direcției de deplasare (`UP`, `DOWN`, `LEFT`, `RIGHT`).
* `SnakeNode`: Element constitutiv al șarpelui (conține poziția și un pointer către următorul segment).
* `GameState`: Structură ce menține starea globală a jocului (scorul, starea `isGameOver`, poziția mâncării și corpul șarpelui).

```

---

## 3. Fișierele header (`.hpp`)

### `Engine.hpp` (Motorul de joc)

```cpp
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Point {
    int x;
    int y;
};

struct GameState {
    std::vector<Point> snakeBody;
    Point foodPosition;
    Direction currentDirection;
    int score;
    bool isGameOver;
};

class Engine {
public:
    Engine(int width, int height);
    ~Engine() = default;

    void update();
    void changeDirection(Direction newDirection);
    GameState getState() const;

private:
    int width;
    int height;
    GameState state;

    void spawnFood();
    bool checkCollision();
};

#endif // ENGINE_HPP

```

### `Renderer.hpp` (Desenatorul)

```cpp
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Engine.hpp"

class Renderer {
public:
    Renderer() = default;
    ~Renderer() = default;

    // Afișează starea curentă a jocului
    void render(const GameState& state);
    void clearScreen();
};

#endif // RENDERER_HPP

```

### `Listener.hpp` (Ascultătorul de evenimente / tastatură)

```cpp
#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "Engine.hpp"

class Listener {
public:
    Listener() = default;
    ~Listener() = default;

    // Așteaptă și procesează introducerea de la tastatură
    Direction pollInput();
};

#endif // LISTENER_HPP

```

---

## 4. Model de fișier `prompts_lab01.md`

Dacă ați folosit un Asistent AI (LLM) pentru realizarea lucrării, creați fișierul `prompts_lab01.md` în rădăcina repozitoriului:

```markdown
# Registru Prompt-uri AI (Lucrarea de Laborator 01)

## Prompt 1: Generare structură de fișiere
* **Prompt:** "Generează structura de bază în C++ pentru un joc Snake, împărțită în Engine.hpp, Renderer.hpp și Listener.hpp."
* **Rezultat primite:** Am primit clasele de bază și enumerațiile necesare.
* **Corecții/Fixări:** Am adăugat manual `GameState` ca structură separată pentru a facilita transmiterea datelor către desenator.

## Prompt 2: Creare README.md
* **Prompt:** "Creează un fișier README.md cu descrierea și regulile jocului Snake, plus secțiunea de structuri de date."
* **Rezultat primite:** Textul generat a fost inclus direct în fișierul `README.md`.

```
