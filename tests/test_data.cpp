#include "Board.hpp"
#include "MoveInput.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace TicTacToe;

namespace {
    int testsRun = 0;
    int testsFailed = 0;

    void expect(bool condition, const std::string& description) {
        ++testsRun;
        if (condition) {
            std::cout << "[PASS] " << description << '\n';
        } else {
            ++testsFailed;
            std::cerr << "[FAIL] " << description << '\n';
        }
    }

    void testBoardConstructionAndCells() {
        Board board;
        bool allEmpty = true;
        for (const auto& row : board.cells) {
            for (Player cell : row) {
                allEmpty = allEmpty && (cell == Player::None);
            }
        }
        expect(allEmpty, "Board: constructorul implicit creeaza o tabla goala");
        expect(board.isCellEmpty(0, 0), "Board: celula libera este detectata");
        expect(board.isCellEmpty(2, 2), "Board: ultima celula valida este detectata");
        expect(!board.isCellEmpty(-1, 0), "Board: indexul negativ de rand este respins");
        expect(!board.isCellEmpty(0, 3), "Board: indexul de coloana 3 este respins");

        BoardCells initial{};
        initial[0][0] = Player::X;
        initial[1][1] = Player::O;
        Board fromCells(initial);
        expect(fromCells.cells == initial, "Board: constructorul cu parametri copiaza celulele");
        expect(!fromCells.isCellEmpty(0, 0), "Board: celula ocupata nu este libera");
    }

    void testBoardCopyAssignmentAndReset() {
        Board original;
        original.cells[0][1] = Player::X;
        original.cells[2][2] = Player::O;

        Board copied(original);
        expect(copied == original, "Board: constructorul de copiere copiaza tabla");

        Board assigned;
        assigned = original;
        expect(assigned == original, "Board: operatorul de atribuire copiaza tabla");
        assigned = assigned;
        expect(assigned == original, "Board: atribuirea catre acelasi obiect este sigura");

        assigned.reset();
        expect(assigned != original, "Board: reset modifica tabla fata de original");
        expect(assigned.isCellEmpty(0, 1) && assigned.isCellEmpty(2, 2),
               "Board: reset elibereaza toate celulele");
    }

    void testBoardComparisonsAndStreams() {
        Board empty;
        Board withX;
        withX.cells[0][0] = Player::X;
        Board sameAsX(withX);

        expect(withX == sameAsX, "Board: operator==");
        expect(withX != empty, "Board: operator!=");
        expect(empty < withX, "Board: operator< foloseste ordinea lexicografica");
        expect(withX > empty, "Board: operator>");
        expect(empty <= withX, "Board: operator<=");
        expect(withX >= empty, "Board: operator>=");
        expect(withX <= sameAsX && withX >= sameAsX, "Board: compararea <= si >= pentru table egale");

        std::ostringstream output;
        output << empty;
        expect(output.str() == "- - -\n- - -\n- - -", "Board: operator<< formateaza tabla goala");

        Board parsed;
        std::istringstream input("X O - x o - - - -");
        input >> parsed;
        expect(static_cast<bool>(input), "Board: operator>> accepta simbolurile valide");
        expect(parsed.cells[0][0] == Player::X && parsed.cells[0][1] == Player::O &&
               parsed.cells[1][0] == Player::X && parsed.cells[1][1] == Player::O,
               "Board: operator>> recunoaste simbolurile mari si mici");

        Board invalid;
        std::istringstream invalidInput("X O ? - - - - - -");
        invalidInput >> invalid;
        expect(invalidInput.fail(), "Board: operator>> respinge un simbol necunoscut");
    }

    void testMoveInputConstructionAndMethods() {
        MoveInput empty;
        expect(empty.row == 0 && empty.col == 0 && !empty.isValid && !empty.isQuitRequested,
               "MoveInput: constructorul implicit initializeaza toate campurile");

        MoveInput move(1, 2, true, false);
        expect(move.row == 1 && move.col == 2 && move.isValid && !move.isQuitRequested,
               "MoveInput: constructorul cu parametri seteaza campurile");
        expect(!move.shouldQuit(), "MoveInput: shouldQuit este false pentru o mutare obisnuita");
        expect(move.canProcessMove(), "MoveInput: o mutare valida poate fi procesata");

        MoveInput quit(0, 0, true, true);
        expect(quit.shouldQuit(), "MoveInput: shouldQuit detecteaza solicitarea de iesire");
        expect(!quit.canProcessMove(), "MoveInput: solicitarea de iesire nu este procesata ca mutare");

        MoveInput invalid(0, 0, false, false);
        expect(!invalid.canProcessMove(), "MoveInput: o mutare invalida nu poate fi procesata");
    }

    void testMoveInputCopyComparisonsAndStreams() {
        MoveInput original(1, 2, true, false);
        MoveInput copied(original);
        expect(copied == original, "MoveInput: constructorul de copiere");

        MoveInput assigned;
        assigned = original;
        expect(assigned == original, "MoveInput: operatorul de atribuire");
        assigned = assigned;
        expect(assigned == original, "MoveInput: auto-atribuirea este sigura");

        MoveInput smaller(0, 2, true, false);
        expect(smaller < original, "MoveInput: operator< compara lexicografic");
        expect(original > smaller, "MoveInput: operator>");
        expect(smaller <= original, "MoveInput: operator<=");
        expect(original >= smaller, "MoveInput: operator>=");
        expect(original != smaller, "MoveInput: operator!=");
        expect(original <= copied && original >= copied, "MoveInput: compararea <= si >= pentru intrari egale");

        std::ostringstream output;
        output << original;
        expect(output.str() == "1 2 1 0", "MoveInput: operator<< scrie campurile in ordinea corecta");

        MoveInput parsed;
        std::istringstream input("2 1 1 0");
        input >> parsed;
        expect(static_cast<bool>(input), "MoveInput: operator>> citeste date valide");
        expect(parsed == MoveInput(2, 1, true, false), "MoveInput: operator>> seteaza toate campurile");

        MoveInput unchanged(4, 5, true, false);
        std::istringstream invalidInput("8 9 1 invalid");
        invalidInput >> unchanged;
        expect(invalidInput.fail(), "MoveInput: operator>> marcheaza datele invalide");
        expect(unchanged == MoveInput(4, 5, true, false),
               "MoveInput: datele existente raman neschimbate la citire incompleta");
    }
}

int main() {
    std::cout << "=== Teste pentru clasele de date Tic-Tac-Toe ===\n";

    testBoardConstructionAndCells();
    testBoardCopyAssignmentAndReset();
    testBoardComparisonsAndStreams();
    testMoveInputConstructionAndMethods();
    testMoveInputCopyComparisonsAndStreams();

    std::cout << "\nTeste executate: " << testsRun
              << ", esuate: " << testsFailed << '\n';

    return testsFailed == 0 ? 0 : 1;
}
