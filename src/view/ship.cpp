// ship.cpp
#include "ship.h"


ShipView::ShipView(float cellSize, const Color& color)
{
    setSize(cellSize, cellSize * 3);
    setColor(color);
    setAnchor(0.5, 0.5);
    setTouchEnabled(false);
}

ShipView::~ShipView()
{}
