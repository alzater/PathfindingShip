// ship.h
#ifndef SHIP_VIEW_H
#define SHIP_VIEW_H

#include "oxygine-framework.h"

using namespace oxygine;

class ShipView : public ColorRectSprite
{
    public:
        ShipView(float cellSize, const Color& color);
        virtual ~ShipView();
};

DECLARE_SMART(ShipView, spShipView);

#endif

