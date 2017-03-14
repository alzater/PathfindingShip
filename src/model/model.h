// model.h

#include "model_observer.h"

class Model
{
    public:
        Model(int x, int y);

        void setObserver(ModelObserver& observer);
        void removeObserver(ModelObserver& observer);

        bool setShipStartPosition(const std::pair<int, int>& position);
        bool setShipEndPosition(const std::pair<int, int>& position);

        bool setBarrier(const std::pair<int, int>& position);
        bool removeBarrier(const std::pair<int, int>& position);

        std::vector<std::tuple<int, int, bool>> getShipPath();

        std::pair<int, int> getFieldSize();
        bool hasBarrier(int x, int y);

    private:
        Field _field;
        ShipManager _shipManager;
        Pathfinder _pathfinder;
};

