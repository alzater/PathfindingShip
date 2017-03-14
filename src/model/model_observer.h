// model_observer.h

class ModelObserver
{
    public:
        virtual void updatedCell(const std::pair<int, int>& position, bool hasBarrier) = 0;
        virtual void updatedShipStartPosition(const std::pair<int, int>& position) = 0;
        virtual void updatedShipEndPosition(const std::pair<int, int>& position) = 0;

        virtual ~ModelObserver = 0;
};

