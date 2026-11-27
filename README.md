# Tic-Tac-Toe (X și O)

## Descrierea proiectului

Tic-Tac-Toe este un joc pentru consolă, dezvoltat în C++17. Partida se desfășoară pe o tablă de 3x3, între doi jucători: `X` și `O`. Aplicația gestionează mutările, verifică rezultatul partidei și poate salva rezultatele folosind SQLite3.

## Regulile jocului

1. Jocul începe cu jucătorul `X`.
2. Jucătorii introduc pe rând coordonatele unei celule libere (linie și coloană, cu indici de la 0 la 2).
3. Primul jucător care plasează trei simboluri identice pe aceeași linie, coloană sau diagonală câștigă.
4. Dacă toate cele nouă celule sunt completate fără un câștigător, partida se încheie la egalitate.

## Structura proiectului

- `Board.hpp/.cpp` — reprezintă tabla de joc și operațiile asupra celulelor.
- `MoveInput.hpp/.cpp` — păstrează coordonatele și starea unei comenzi introduse de utilizator.
- `Engine.hpp/.cpp` — gestionează logica jocului și verificarea rezultatului.
- `Listener.hpp/.cpp` — citește mutările și solicitările de reluare.
- `Painter.hpp/.cpp` — afișează tabla, starea jocului și mesajele în consolă.
- `GameStorage.hpp/.cpp` — salvează rezultatele partidelor într-o bază de date SQLite.
- `tests/test_data.cpp` — teste pentru clasele de date `Board` și `MoveInput`.

## Dependențe

- Sistem de operare: Windows (prin MSYS2 UCRT64).
- Standard de limbaj: C++17.
- Compilator: GCC (`g++`).
- Instrument de construire: GNU Make (`mingw32-make`).
- Arhivator: GNU `ar`, utilizat pentru bibliotecile statice.
- Bibliotecă externă: SQLite3.
- Documentarea codului: Doxygen (pentru generarea documentației HTML).
- Testele pentru `Board` și `MoveInput` folosesc biblioteca standard C++, fără un framework extern.

În MSYS2 UCRT64, compilatorul, Make și SQLite3 pot fi instalate cu:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-sqlite3
```

Doxygen trebuie să fie disponibil în mediul de lucru pentru comanda de generare a documentației (`doxygen --version`).

## Construirea aplicației

Din terminalul MSYS2 UCRT64, în directorul proiectului:

```bash
mingw32-make clean
mingw32-make
```

Makefile construiește bibliotecile statice `libBoard.a` și `libMoveInput.a`, compilează sursele aplicației și creează executabilul `TicTacToe.exe`, legat cu SQLite3.

Pentru a porni jocul:

```bash
./TicTacToe.exe
```

## Rularea testelor

Pentru a compila și rula testele claselor `Board` și `MoveInput`:

```bash
mingw32-make test
```

Comanda construiește bibliotecile statice necesare, compilează `tests/test_data.cpp` și rulează executabilul de test. Codul de ieșire este `0` dacă toate testele trec și `1` dacă există teste eșuate.

## Generarea documentației

Comentariile din fișierele antet folosesc formatul Doxygen. După instalarea Doxygen, documentația HTML se generează cu:

```bash
mingw32-make docs
```

Pagina principală va fi disponibilă în `docs/api/html/index.html`.

## Curățarea fișierelor generate

```bash
mingw32-make clean
```

Comanda elimină fișierele obiect, bibliotecile statice generate, executabilele și documentația HTML generată. Baza de date `tictactoe.db` nu este ștearsă.

## Organizarea branch-urilor

Fiecare lucrare de laborator este dezvoltată într-un branch separat al repository-ului GitHub. Pentru această etapă se utilizează branch-ul `lab06`.
