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

bool Model::setShipStartPosition(const std::pair<int, int>& position)
{
}

bool Model::setShipEndPosition(const std::pair<int, int>& position)
{
}

bool Model::setBarrier(const std::pair<int, int>& position)
{
}

bool Model::removeBarrier(const std::pair<int, int>& position)
{
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
