
# Tic-Tac-Toe (X si O)

## Descrierea proiectului

Un joc clasic Tic-Tac-Toe dezvoltat in C++ pentru consola. Jocul se desfasoara pe o tabla de 3x3 intre doi jucatori (`X` si `O`).

### Reguli
1. Jocul incepe cu jucatorul `X`.
2. Jucatorii introduc pe rand coordonatele unei celule libere (linie si coloana, de la 0 la 2).
3. Primul jucator care plaseaza 3 simboluri identice pe orizontala, verticala sau diagonala castiga.
4. Daca toate cele 9 celule sunt completate fara un castigator, jocul se incheie cu remiza.

---

## Structura proiectului

### 1. Board

Reprezinta tabla de joc si starea celulelor.

- `Board.hpp` - declaratia structurii Board.
- `Board.cpp` - implementarea constructorilor si operatorilor.
- Utilizeaza `std::array` pentru reprezentarea tablei de joc.

### 2. MoveInput

Pastreaza datele de intrare citite de la utilizator.

- `MoveInput.hpp` - declaratia structurii MoveInput.
- `MoveInput.cpp` - implementarea constructorilor si operatorilor.

### 3. Engine

Gestioneaza logica jocului:

- Initializarea tablei.
- Procesarea mutarilor.
- Verificarea castigatorului.
- Verificarea remizei.

### 4. Listener

Citeste coordonatele introduse de utilizator si gestioneaza solicitarile de reluare a jocului.

### 5. Painter

Afiseaza tabla, mesajele si starea jocului in consola. Utilizeaza clasa abstracta `AbstractPainter`.

### 6. GameStorage

Gestioneaza salvarea rezultatelor jocurilor folosind biblioteca externa SQLite.

Rezultatele sunt salvate in baza de date `tictactoe.db`, in tabelul `games`.

Pentru fiecare partida terminata se salveaza:
- ID-ul partidei;
- rezultatul (`Player X wins`, `Player O wins` sau `Draw`);
- data si ora inregistrarii.

---

## Biblioteci utilizate

### Biblioteci proprii

Proiectul utilizeaza doua biblioteci statice:

- `libBoard.a` - contine implementarea structurii `Board`.
- `libMoveInput.a` - contine implementarea structurii `MoveInput`.

Aceste biblioteci sunt construite automat de Makefile si sunt legate de aplicatia principala.

### Biblioteca externa

Proiectul utilizeaza SQLite3 pentru pastrarea rezultatelor jocurilor.

### Biblioteca standard C++

Sunt utilizate:
- `std::array` - pentru reprezentarea tablei de joc;
- `std::string` - pentru siruri de caractere;
- `std::unique_ptr` - pentru gestionarea automata a resurselor SQLite;
- `std::copy`, `std::fill`, `std::find`, `std::sort`;
- `std::equal`, `std::all_of`, `std::lexicographical_compare`;
- fluxurile `std::cin`, `std::cout`, `std::istream` si `std::ostream`.

---

## Construirea proiectului (Build)

### Cerinte preliminare

Pentru construirea proiectului pe Windows este utilizat mediul MSYS2 UCRT64.

Sunt necesare:
- GCC (g++);
- GNU Make;
- GNU Archiver (ar);
- SQLite3.

Instalarea bibliotecilor si instrumentelor necesare prin MSYS2:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-sqlite3
```

### Construirea aplicatiei

Din terminalul MSYS2 UCRT64, in folderul proiectului, executati:

```bash
mingw32-make clean
mingw32-make
```

Makefile construieste automat:
1. Biblioteca statica `libBoard.a`.
2. Biblioteca statica `libMoveInput.a`.
3. Fisierele obiect ale aplicatiei.
4. Executabilul `TicTacToe.exe`, legat cu bibliotecile proprii si SQLite3.

### Rularea jocului

```bash
./TicTacToe.exe
```

### Curatarea fisierelor generate

```bash
mingw32-make clean
```

Comanda elimina fisierele obiect, bibliotecile statice generate si executabilul.

Baza de date `tictactoe.db` este pastrata separat si nu este eliminata de comanda clean.

---

## Organizarea branch-urilor

Fiecare lucrare de laborator este dezvoltata intr-un branch separat al repository-ului GitHub.

Pentru laboratorul 5 se utilizeaza branch-ul `lab05`.
