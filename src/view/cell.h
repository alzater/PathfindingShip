// cell.h
#ifndef CELL_H
#define CELL_H

#include "oxygine-framework.h"

using namespace oxygine;

class Cell : public ColorRectSprite
{
    public:
        Cell();
        virtual ~Cell();

        void setRock();
        void removeRock();

        void shipArrived();
        void shipLeft();

        void setStartCell();
        void setEndCell();

    private:
        int _x, _y;
};

DECLARE_SMART(Cell, spCell);

#endif

