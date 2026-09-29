# Tic-Tac-Toe (X și O)

## Descrierea Proiectului & Reguli de Joc
Un joc clasic de **Tic-Tac-Toe** dezvoltat în C++ pentru consolă. Jocul se desfășoară pe o tablă de 3x3 între doi jucători (`X` și `O`).

### Reguli:
1. Jocul începe cu jucătorul `X`.
2. Jucătorii introduc pe rând coordonatele unei celule libere (linie și coloană, de la 0 la 2).
3. Primul jucător care reușește să plaseze 3 simboluri identice pe orizontală, verticală sau diagonală câștigă.
4. Dacă toate cele 9 celule sunt completate fără un câștigător, jocul se încheie cu remiză.

---

## Structuri de Date și Descrierea Lor

### 1. `enum class Player`
Reprezintă starea unei celule sau jucătorul curent:
* `None`: Celulă goală.
* `X`: Simbolul jucătorului X.
* `O`: Simbolul jucătorului O.

### 2. `enum class GameState`
Starea curentă a partidei:
* `InProgress`: Jocul este în desfășurare.
* `PlayerXWins`: Jucătorul X a câștigat.
* `PlayerOWins`: Jucătorul O a câștigat.
* `Draw`: Remiză.

### 3. `struct Board`
Conține starea grilei de joc:
* `cells[3][3]`: Matrice 3x3 de tip `Player` ce păstrează starea fiecărei celule.

### 4. `struct MoveInput`
Păstrează datele de intrare citite de la utilizator:
* `row`: Linia selectată (0-2).
* `col`: Coloana selectată (0-2).
* `isValid`: `true` dacă valorile introduse sunt în limitele valide.
* `isQuitRequested`: `true` dacă jucătorul a solicitat părăsirea jocului.