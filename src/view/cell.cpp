// cell.cpp
#include "cell.h"

Cell::Cell()
{
    setColor( Color(0, 0, 240) );
}

Cell::~Cell()
{}

void Cell::setRock()
{
    setColor( Color(200, 80, 80) );
}

void Cell::removeRock()
{
    setColor( Color(0, 0, 240) );
}

void Cell::shipArrived()
{
}

void Cell::shipLeft()
{
}

void Cell::setStartCell()
{
    setColor( Color(160, 250, 0) );
}

void Cell::setEndCell()
{
    setColor( Color(0, 250, 160) );
}
