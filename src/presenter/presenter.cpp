// presenter.cpp
#include "presenter.h"

Presenter::Presenter(spActor scene, std::pair<int, int> fieldSize)
    : _model(fieldSize.first, fieldSize.second)
    , _view(this, fieldSize.first, fieldSize.second)
{
    _model.setObserver(*this);

    scene->addChild(&_view);
}

Presenter::~Presenter()
{
    _view.detach();
    _model.removeObserver(*this);
}

bool Presenter::setShipStartPosition(int x, int y)
{
    return _model.setShipStartPosition(x, y);
}

bool Presenter::setShipEndPosition(int x, int y)
{
    return _model.setShipEndPosition(x, y);
}

bool Presenter::setBarrier(int x, int y)
{
    return _model.setBarrier(x, y);
}

bool Presenter::removeBarrier(int x, int y)
{
    return _model.removeBarrier(x, y);
}

std::vector<std::tuple<int, int, bool>> Presenter::getShipPath()
{
    return _model.getShipPath();
}

void Presenter::updatedCell(int x, int y, bool hasBarrier)
{
    // TODO
}

void Presenter::updatedShipStartPosition(int x, int y, bool isVertical)
{
    // TODO
}

void Presenter::updatedShipEndPosition(int x, int y, bool isVertical)
{
    // TODO
}

