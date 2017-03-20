// cell.h
#ifndef CELL_H
#define CELL_H

#include "oxygine-framework.h"

using namespace oxygine;

class Cell : public ColorRectSprite
{
    public:
        Cell(float size);
        virtual ~Cell();

        void setRock();
        void removeRock();

    private:
        spSprite rock;
};

DECLARE_SMART(Cell, spCell);

#endif

