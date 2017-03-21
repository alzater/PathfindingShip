// ship.h
#ifndef SHIP_H
#define SHIP_H

#include "ship_manager.h"

class Ship
{
    public:
        Ship(const ShipManager& shipManager);

        bool setStartPosition(const ShipManager::Position& startPosition);
        bool setEndPosition(const ShipManager::Position& endPosition);

        const ShipManager::Position& getStartPosition() const;
        const ShipManager::Position& getEndPosition() const;

        bool updateStartPosition();
        bool updateEndPosition();

        bool checkStartPosition() const;
        bool checkEndPosition() const;

        void clear();

    private:
        const ShipManager& _shipManager;

        ShipManager::Position _startPosition;
        ShipManager::Position _endPosition;
};

#endif

