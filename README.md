# Tic-Tac-Toe (X și O)

## Descrierea Proiectului & Reguli de Joc
Un joc clasic de **Tic-Tac-Toe** dezvoltat în C++ pentru consolă. Jocul se desfășoară pe o tablă de 3x3 între doi jucători (`X` și `O`).

### Reguli:
1. Jocul începe cu jucătorul `X`.
2. Jucătorii introduc pe rând coordonatele unei celule libere (linie și coloană, de la 0 la 2).
3. Primul jucător care reușește să plaseze 3 simboluri identice pe orizontală, verticală sau diagonală câștigă.
4. Dacă toate cele 9 celule sunt completate fără un câștigător, jocul se încheie cu remiză.

---

## Structuri de Date și Metode

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
* `cells[3][3]`: Matrice 3x3 de tip `Player`.
* **Metode:**
  * `reset()`: Resetează toate celulele la starea `Player::None`.
  * `isCellEmpty(int r, int c)`: Verifică dacă o celulă este liberă.

### 4. `struct MoveInput`
Păstrează datele de intrare citite de la utilizator:
* `row`, `col`: Coordonatele alese.
* `isValid`: `true` dacă valorile introduse sunt valide.
* `isQuitRequested`: `true` dacă jucătorul a cerut ieșirea.
* **Metode:**
  * `shouldQuit()`: Returnează dacă s-a solicitat părăsirea jocului.
  * `canProcessMove()`: Verifică dacă mutarea poate fi procesată.

---

## Construcția Proiectului (Build)

Proiectul poate fi construit manual din linia de comandă în două moduri:

### Varianta 1: Utilizând Makefile (Recomandat)
Pentru compilare și creare executabil:
> make

Pentru ștergerea fișierelor obiect și executabilului:
> make clean

### Varianta 2: Compilare manuală directă cu g++
Compilarea unui fișier obiect individual:
> g++ -std=c++17 -c Engine.cpp -o Engine.o

Compilarea întregului proiect într-un singur executabil:
> g++ -std=c++17 Tictactoe.cpp Engine.cpp Listener.cpp Painter.cpp -o Tictactoe

Rularea proiectului:
> ./Tictactoe