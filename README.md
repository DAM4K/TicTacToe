# TicTacToe-Cpp

## Descrierea proiectului / Reguli de joc
Acest proiect este o implementare în limbajul C++ a clasicului joc **Tic-Tac-Toe (X și O)** pentru consolă. Jocul folosește o arhitectură modulară, separând logica jocului, afișarea pe ecran și preluarea datelor de intrare de la utilizator.

**Reguli de joc:**
1. Jocul se desfășoară pe o tablă de $3 \times 3$ celule.
2. Participă 2 jucători (simbolurile **X** și **O**).
3. Jucătorii pun alternativ simbolul lor pe o celulă liberă.
4. Primul jucător care aliniează 3 simboluri identice (pe orizontală, verticală sau diagonală) câștigă.
5. Dacă toate celulele sunt completate fără un câștigător, jocul se încheie la egalitate (remiză).

## Structuri de date și descrierea lor
* `Symbol` (enum class): Reprezintă starea unei celule de pe tablă (`NONE`, `X`, `O`).
* `GameState` (enum class): Reprezintă starea curentă a jocului (`IN_PROGRESS`, `X_WON`, `O_WON`, `DRAW`).
* `Position` (struct): Reține coordonatele unei mutări pe tablă (`row` - rând, `col` - coloană).
* `Board` (std::vector<std::vector<Symbol>>): Matricea de $3 \times 3$ care salvează configurația tablei.
* `Listener` (interfață/clasa abstractă): Preluarea datelor de intrare de la utilizator.
* `Painter` (interfață/clasa abstractă): Afișarea stării jocului și a mesajelor pe ecran.
* `GameEngine` (clasa principală): Coordonează logica jocului, schimbă turele și verifică condițiile de victorie.
