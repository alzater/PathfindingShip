// model.cpp
#include "model.h"

Model::Model(int x, int y)
    : _field(x, y)
    , _shipManager(_field)
    , _ship(_shipManager)
    , _pathfinder(_shipManager, _ship)
{
}

void Model::setObserver(ModelObserver* observer)
{
    _observer = observer;
}

void Model::removeObserver(ModelObserver* observer)
{
    _observer = nullptr;
}

bool Model::setShipStartPosition(int x, int y)
{
    return false;
}

bool Model::setShipEndPosition(int x, int y)
{
    return false;
}

bool Model::setBarrier(int x, int y)
{
    if( !_field.hasBarrier(x, y) )
    {
        _field.setBarrier(x, y);

        if( _observer != nullptr )
            _observer->updatedCell(x, y, true);

        return true;
    }
    else
        return false;
}

bool Model::removeBarrier(int x, int y)
{
    if( _field.hasBarrier(x, y) )
    {
        _field.removeBarrier(x, y);

        if( _observer != nullptr )
            _observer->updatedCell(x, y, false);

        return true;
    }
    else
        return false;
}

std::vector<std::tuple<int, int, bool>> Model::getShipPath()
{
}

std::pair<int, int> Model::getFieldSize()
{
}

bool Model::hasBarrier(int x, int y)
{
}
