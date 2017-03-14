// presenter.cpp
#include "presenter.cpp"

Presenter::Presenter(spActor scene, std::pair<int, int> fieldSize)
    : _model(fieldSize.first, fieldSize.second)
{
    _model.setObserver(*this);

    scene->addChild(_view);
    _view.initField(fieldSize.first, fieldSize.second);
}

Presenter::~Presenter()
{
    _view->detach();
    _model->removeObserver(*this);
}

bool Preseneter::setShipStartPosition(const std::pair<int, int>& position)
{
    return _model->setShipStartPosition(position);
}

bool Preseneter::setShipEndPosition(const std::pair<int, int>& position)
{
    return _model->setShipEndPosition(position);
}

bool Preseneter::setBarrier(const std::pair<int, int>& position)
{
    return _model->setBarrier(position);
}

bool Preseneter::removeBarrier(const std::pair<int, int>& position)
{
    return _model->removeBarrier(position);
}

std::vector<std::tuple<int, int, bool>> getShipPath()
{
    return _model->getShipPath();
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

