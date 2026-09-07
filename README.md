# TicTacToe-Cpp
Lab.1
## Descrierea proiectului și Regulile de joc
Acest proiect este o implementare în C++ a jocului **Tic-Tac-Toe (X și O)** pentru consolă, structurat pe o arhitectură modulară bazată pe interfețe abstracte.

**Reguli de joc:**
1. Jocul se desfășoară pe o tablă de 3x3 celule.
2. Participă 2 jucători (simbolurile X și O).
3. Jucătorii introduc pe rând coordonatele (rând și coloană de la 0 la 2) pentru a plasa simbolul.
4. Primul jucător care aliniează 3 simboluri identice pe orizontală, verticală sau diagonală câștigă.
5. Dacă toate celulele sunt ocupate și nu există un câștigător, jocul se încheie la egalitate (remiză).

## Structuri de date și descrierea lor
* `Symbol` (enum class): Reprezintă starea unei celule de pe tablă (`NONE`, `X`, `O`).
* `GameState` (enum class): Reprezintă starea curentă a jocului (`IN_PROGRESS`, `X_WON`, `O_WON`, `DRAW`).
* `Position` (struct): Reține coordonatele unei mutări pe tablă (`row`, `col`).
* `Board` (alias `std::vector<std::vector<Symbol>>`): Matricea 3x3 a stării jocului.
* `Listener` (interfață abstractă): Interfață pentru preluarea mutărilor de la utilizator.
* `ConsoleListener`: Implementare a interfeței `Listener` pentru citirea datelor din consolă (`std::cin`).
* `Painter` (interfață abstractă): Interfață pentru afișarea interfeței de joc.
* `ConsolePainter`: Implementare a interfeței `Painter` pentru desenarea tablei și mesajelor în consolă (`std::cout`).
* `Engine`: Clasa principală ce conține logica jocului, aplică regulile și verifică condițiile de victorie sau remiză.

## Autor
* Damian