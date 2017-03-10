// pathfinder.h

#include "ship_manager.h"

#include <vector>

class Pathfinder
{
    public:
        Pathfinder(const ShipManager& shipManager);

        bool setStartPosition(const ShipManager::Position& startPosition);
        bool setEndPosition(const ShipManager::Position& endPosition);

        std::vector<ShipManager::MOVEMENT> getPath(bool& error);

        //static int positionToInt(const ShipManager::Position& position);
        //static ShipManager::Position& intToPosition(int intPosition);

    private:
        const ShipManager& _shipManager;

        ShipManager::Position _startPosition;
        ShipManager::Position _endPosition;

        //std::set<int> _visitedPositions;
};
