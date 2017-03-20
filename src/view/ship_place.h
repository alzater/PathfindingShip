// ship.h
#ifndef SHIP_PLACE_H
#define SHIP_PLACE_H

#include "oxygine-framework.h"

using namespace oxygine;

class ShipPlace : public ColorRectSprite
{
    public:
        ShipPlace(float cellSize, const Color& color);
        virtual ~ShipPlace();
};

DECLARE_SMART(ShipPlace, spShipPlace);

#endif

