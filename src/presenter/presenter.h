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
        virtual bool setShipStartPosition(const std::pair<int, int>& position) override;
        virtual bool setShipEndPosition(const std::pair<int, int>& position) override;

        virtual bool setBarrier(const std::pair<int, int>& position) override;
        virtual bool removeBarrier(const std::pair<int, int>& position) override;

        virtual std::vector<std::tuple<int, int, bool>> getShipPath() override;

        // ModelObserver
        virtual void updatedCell(const std::pair<int, int>& position, bool hasBarrier) override;
        virtual void updatedShipStartPosition(const std::pair<int, int>& position) override;
        virtual void updatedShipEndPosition(const std::pair<int, int>& position) override;

    private:
        View _view;
        Model _model;
};

#endif

