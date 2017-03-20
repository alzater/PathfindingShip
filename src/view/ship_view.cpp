// ship.cpp
#include "ship_view.h"

extern Resources gameResources;

ShipView::ShipView(float cellSize)
{
    setResAnim( gameResources.getResAnim("ship") );
    setSize(cellSize, cellSize * 3);
    setAnchor(0.5, 0.5);
    setTouchEnabled(false);
}

ShipView::~ShipView()
{}
