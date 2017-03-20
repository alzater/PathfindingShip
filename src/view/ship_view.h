// ship.h
#ifndef SHIP_VIEW_H
#define SHIP_VIEW_H

#include "oxygine-framework.h"

using namespace oxygine;

class ShipView : public Sprite
{
    public:
        ShipView(float cellSize);
        virtual ~ShipView();
};

DECLARE_SMART(ShipView, spShipView);

#endif

