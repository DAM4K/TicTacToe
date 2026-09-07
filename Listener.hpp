#ifndef LISTENER_HPP
#define LISTENER_HPP

struct Position {
    int row;
    int col;
};

class Listener {
public:
    virtual ~Listener() = default;
    virtual Position getNextMove() = 0;
};

#endif // LISTENER_HPP