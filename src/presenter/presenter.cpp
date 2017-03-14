// presenter.cpp
#include "presenter.h"

Presenter::Presenter(spActor scene, std::pair<int, int> fieldSize)
    : _model(fieldSize.first, fieldSize.second)
    , _view(fieldSize.first, fieldSize.second)
{
    _model.setObserver(*this);

    scene->addChild(&_view);
}

Presenter::~Presenter()
{
    _view.detach();
    _model.removeObserver(*this);
}

bool Presenter::setShipStartPosition(const std::pair<int, int>& position)
{
    return _model.setShipStartPosition(position);
}

bool Presenter::setShipEndPosition(const std::pair<int, int>& position)
{
    return _model.setShipEndPosition(position);
}

bool Presenter::setBarrier(const std::pair<int, int>& position)
{
    return _model.setBarrier(position);
}

bool Presenter::removeBarrier(const std::pair<int, int>& position)
{
    return _model.removeBarrier(position);
}

std::vector<std::tuple<int, int, bool>> Presenter::getShipPath()
{
    return _model.getShipPath();
}

void Presenter::updatedCell(const std::pair<int, int>& position, bool hasBarrier)
{
    // TODO
}

void Presenter::updatedShipStartPosition(const std::pair<int, int>& position)
{
    // TODO
}

void Presenter::updatedShipEndPosition(const std::pair<int, int>& position)
{
    // TODO
}

