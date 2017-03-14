// ipresenter.h
#ifndef I_PRESENTER_H
#define I_PRESENTER_H

#include <vector>

class IPresenter
{
    public:
        virtual bool setShipStartPosition(int x, int y) = 0;
        virtual bool setShipEndPosition(int x, int y) = 0;

        virtual bool setBarrier(int x, int y) = 0;
        virtual bool removeBarrier(int x, int y) = 0;

        virtual std::vector<std::tuple<int, int, bool>> getShipPath() = 0;
};

#endif

