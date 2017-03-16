// ship_move.h
#ifndef SHIP_MOVE_H
#define SHIP_MOVE_H

struct ShipMove
{
    enum class Type {MOVE, ROTATE_LEFT, ROTATE_RIGHT};

    Type type;
    int x, y;
};

#endif
