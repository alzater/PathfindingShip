// model_observer.h
#ifndef MODEL_OBSERVER_H
#define MODEL_OBSERVER_H

#include <functional>

class ModelObserver
{
    public:
        virtual void updatedCell(const std::pair<int, int>& position, bool hasBarrier) = 0;
        virtual void updatedShipStartPosition(const std::pair<int, int>& position) = 0;
        virtual void updatedShipEndPosition(const std::pair<int, int>& position) = 0;
};

#endif

