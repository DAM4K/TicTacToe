CXX = g++
AR = ar
ARFLAGS = rcs
DOXYGEN = doxygen

CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
LDLIBS = -lsqlite3

EXEC = TicTacToe.exe
TEST_EXEC = tests/test_data.exe

APP_SRC = Tictactoe.cpp Engine.cpp Listener.cpp Painter.cpp GameStorage.cpp
APP_OBJ = $(APP_SRC:.cpp=.o)
TEST_OBJ = tests/test_data.o

BOARD_LIB = libBoard.a
MOVEINPUT_LIB = libMoveInput.a

all: $(EXEC)

$(EXEC): $(APP_OBJ) $(BOARD_LIB) $(MOVEINPUT_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(APP_OBJ) -L. -lBoard -lMoveInput $(LDLIBS)

$(BOARD_LIB): Board.o
	$(AR) $(ARFLAGS) $@ $^

$(MOVEINPUT_LIB): MoveInput.o
	$(AR) $(ARFLAGS) $@ $^

Tictactoe.o: Tictactoe.cpp Engine.hpp Listener.hpp Painter.hpp Board.hpp MoveInput.hpp GameStorage.hpp
Engine.o: Engine.cpp Engine.hpp Board.hpp
Listener.o: Listener.cpp Listener.hpp MoveInput.hpp
Painter.o: Painter.cpp Painter.hpp Engine.hpp Board.hpp
GameStorage.o: GameStorage.cpp GameStorage.hpp
Board.o: Board.cpp Board.hpp
MoveInput.o: MoveInput.cpp MoveInput.hpp

tests/test_data.o: tests/test_data.cpp Board.hpp MoveInput.hpp

$(TEST_EXEC): $(TEST_OBJ) $(BOARD_LIB) $(MOVEINPUT_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJ) -L. -lBoard -lMoveInput

test: $(TEST_EXEC)
	./$(TEST_EXEC)

docs:
	mkdir -p docs/api
	doxygen Doxyfile

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	rm -f $(APP_OBJ) Board.o MoveInput.o $(BOARD_LIB) $(MOVEINPUT_LIB) $(EXEC) tests/test_data.o tests/test_data.exe
	rm -rf docs/api

.PHONY: all clean test docs
