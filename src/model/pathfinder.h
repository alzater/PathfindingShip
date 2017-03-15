// pathfinder.h

#include "ship.h"
#include "ship_manager.h"

#include <vector>

class Pathfinder
{
    public:
        Pathfinder(const ShipManager& shipManager, const Ship& ship);

        std::vector<ShipManager::MOVEMENT> getPath(bool& error);

    private:
        const ShipManager& _shipManager;
        const Ship& _ship;
};

