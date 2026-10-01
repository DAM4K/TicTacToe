CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = TicTacToe.cpp Engine.cpp Listener.cpp Painter.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = TicTacToe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)