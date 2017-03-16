// model.h
#include "model_observer.h"

#include "field.h"
#include "ship_manager.h"
#include "ship.h"
#include "pathfinder.h"

class Model
{
    public:
        Model(int x, int y);

        void setObserver(ModelObserver* observer);
        void removeObserver(ModelObserver* observer);

        bool setShipStartPosition(int x, int y);
        bool setShipEndPosition(int x, int y);

        bool setBarrier(int x, int y);
        bool removeBarrier(int x, int y);

        std::vector<ShipManager::MOVEMENT> getShipPath();
        std::tuple<int, int, bool> getShipStartPosition();

        std::pair<int, int> getFieldSize();
        bool hasBarrier(int x, int y);

    private:
        void updateShip();

        ShipManager::Position calcNewShipPosition(int x, int y);

    private:
        ModelObserver* _observer = nullptr;

        Field _field;
        ShipManager _shipManager;
        Ship _ship;
        Pathfinder _pathfinder;
};

