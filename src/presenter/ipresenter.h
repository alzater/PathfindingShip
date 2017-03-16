// ipresenter.h
#ifndef I_PRESENTER_H
#define I_PRESENTER_H

#include "ship_move.h"

#include <vector>

class IPresenter
{
    public:
        virtual bool setShipStartPosition(int x, int y) = 0;
        virtual bool setShipEndPosition(int x, int y) = 0;

        virtual bool setBarrier(int x, int y) = 0;
        virtual bool removeBarrier(int x, int y) = 0;

        virtual std::vector<ShipMove> getShipPath() = 0;
};

#endif

