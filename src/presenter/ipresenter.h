// ipresenter.h

#include <vector>

class IPresenter
{
    public:
        virtual bool setShipStartPosition(const std::pair<int, int>& position) = 0;
        virtual bool setShipEndPosition(const std::pair<int, int>& position) = 0;

        virtual bool setBarrier(const std::pair<int, int>& position) = 0;
        virtual bool removeBarrier(const std::pair<int, int>& position) = 0;

        virtual std::vector<std::tuple<int, int, bool>> getShipPath() = 0;
};
