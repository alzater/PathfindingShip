// ship_place.cpp
#include "ship_place.h"


ShipPlace::ShipPlace(float cellSize, const Color& color)
{
    setSize(cellSize, cellSize * 3);
    setAnchor(0.5, 0.5);
    setTouchEnabled(false);
    setColor(color);
}

ShipPlace::~ShipPlace()
{}
