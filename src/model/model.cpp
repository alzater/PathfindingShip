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
    bool res = _ship.setStartPosition( calcNewShipPosition(x, y) );
    if( res && _observer != nullptr )
    {
        const auto& pos = _ship.getStartPosition();
        _observer->updatedShipStartPosition(pos.x, pos.y, pos.isVertical);
    }

    return res;
}

bool Model::setShipEndPosition(int x, int y)
{
    bool res = _ship.setEndPosition( calcNewShipPosition(x, y) );
    if( res && _observer != nullptr )
    {
        const auto& pos = _ship.getEndPosition();
        _observer->updatedShipEndPosition(pos.x, pos.y, pos.isVertical);
    }

    return res;
}

bool Model::setBarrier(int x, int y)
{
    if( !_field.hasBarrier(x, y) )
    {
        _field.setBarrier(x, y);

        if( _observer != nullptr )
            _observer->updatedCell(x, y, true);

        updateShip();

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

        updateShip();

        return true;
    }
    else
        return false;
}

void printPath(const std::vector<ShipManager::MOVEMENT>& path)
{
    std::cout << std::endl;

    std::string res;
    for( auto movement : path )
    {
        switch( movement )
        {
            case ShipManager::MOVEMENT::RIGHT: res = "right"; break;
            case ShipManager::MOVEMENT::LEFT: res = "left"; break;
            case ShipManager::MOVEMENT::UP: res = "up"; break;
            case ShipManager::MOVEMENT::DOWN: res = "down"; break;
            case ShipManager::MOVEMENT::ROTATE_RIGHT: res = "rotate_right"; break;
            case ShipManager::MOVEMENT::ROTATE_LEFT: res = "rotate_left"; break;
        }
        std::cout << res << " ";
    }
    std::cout << std::endl;
}

std::vector<std::tuple<int, int, bool>> Model::getShipPath()
{
    bool error = true;
    auto path = _pathfinder.getPath(error);
    printPath(path);

    return {};
}

std::pair<int, int> Model::getFieldSize()
{
}

bool Model::hasBarrier(int x, int y)
{
}

void Model::updateShip()
{
    if( !_ship.updateStartPosition() && _observer != nullptr )
    {
        const auto pos = _ship.getStartPosition();
        _observer->updatedShipStartPosition(pos.x, pos.y, pos.isVertical);
    }

    if( !_ship.updateEndPosition() && _observer != nullptr )
    {
        const auto pos = _ship.getEndPosition();
        _observer->updatedShipEndPosition(pos.x, pos.y, pos.isVertical);
    }
}

ShipManager::Position Model::calcNewShipPosition(int x, int y)
{
    const ShipManager::Position verticalPosition = {x, y, true, true};
    if( _shipManager.goodPosition(verticalPosition) &&
            verticalPosition != _ship.getStartPosition() &&
            verticalPosition != _ship.getEndPosition()
      )
        return verticalPosition;

    const ShipManager::Position horisontalPosition = {x, y, false, true};
    if( _shipManager.goodPosition(horisontalPosition) &&
            horisontalPosition != _ship.getStartPosition() &&
            horisontalPosition != _ship.getEndPosition()
      )
        return horisontalPosition;

    return ShipManager::Position::illegal();
}
