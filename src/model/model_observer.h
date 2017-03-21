// model_observer.h
#ifndef MODEL_OBSERVER_H
#define MODEL_OBSERVER_H

class ModelObserver
{
    public:
        virtual void updatedCell(int x, int y, bool hasBarrier) = 0;
        virtual void updatedShipStartPosition(int x, int y, bool isVertical) = 0;
        virtual void updatedShipEndPosition(int x, int y, bool isVertical) = 0;
        virtual void updatedField(int x, int y) = 0;
};

#endif

