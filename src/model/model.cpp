// model.cpp
#include "model.h"

Model::Model(int x, int y)
    : _field(x, y)
    , _shipManager(_field)
    , _pathfinder(_shipManager)
{
}

void Model::setObserver(ModelObserver& observer)
{
}

void Model::removeObserver(ModelObserver& observer)
{
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
    return false;
}

bool Model::removeBarrier(int x, int y)
{
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
