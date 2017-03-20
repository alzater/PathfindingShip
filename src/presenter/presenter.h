// presenter.h
#ifndef PRESENTER_H
#define PRESENTER_H

#include "ipresenter.h"
#include "../model/model_observer.h"
#include "../model/model.h"
#include "../view/view.h"

#include "oxygine-framework.h"

#include <vector>

class Presenter : public IPresenter, public ModelObserver
{
    public:
        Presenter(spActor scene, std::pair<int, int> fieldSize);
        virtual ~Presenter();

    private:
        // IPresenter
        virtual bool setShipStartPosition(int x, int y) override;
        virtual bool setShipEndPosition(int x, int y) override;

        virtual bool setBarrier(int x, int y) override;
        virtual bool removeBarrier(int x, int y) override;

        virtual std::vector<ShipMove> getShipPath() override;

        virtual void nextMap() override;

        // ModelObserver
        virtual void updatedCell(int x, int y, bool hasBarrier) override;
        virtual void updatedShipStartPosition(int x, int y, bool isVertical) override;
        virtual void updatedShipEndPosition(int x, int y, bool isVertical) override;

    private:
        View _view;
        Model _model;
};

#endif

