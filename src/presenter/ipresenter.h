// ipresenter.h

#include <vector>

class IPresenter
{
    public:
        virtual bool setStartShipPosition(const std::pair<int, int>& position);
        virtual bool setEndShipPosition(const std::pair<int, int>& position);

        virtual bool setBarrier(const std::pair<int, int>& position);
        virtual bool removeBarrier(const std::pair<int, int>& position);

        virtual std::vector<std::tuple<int, int, bool>> getShipPath();

        virtual void nextMap();

    private:
        virtual ~IPresenter();
};
