// model.cpp
#include "model.h"

#include <iostream>

Model::Model()
    : _field(1, 1)
    , _shipManager(_field)
    , _ship(_shipManager)
    , _pathfinder(_shipManager, _ship)
{}

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

std::vector<ShipManager::MOVEMENT> Model::getShipPath()
{
    bool error = true;
    auto path = _pathfinder.getPath(error);
    if( error )
        return {};

printPath(path);
    return path;
}

std::tuple<int, int, bool> Model::getShipStartPosition()
{
    const auto pos = _ship.getStartPosition();

    return std::make_tuple(pos.x, pos.y, (bool)pos.isVertical);
}

std::pair<int, int> Model::getFieldSize()
{
}

bool Model::hasBarrier(int x, int y)
{
}

void Model::updateShip()
{
    if( _ship.updateStartPosition() && _observer != nullptr )
    {
        const auto pos = _ship.getStartPosition();
        _observer->updatedShipStartPosition(pos.x, pos.y, pos.isVertical);
    }

    if( _ship.updateEndPosition() && _observer != nullptr )
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


void Model::nextField()
{
    _ship.clear();

    auto newField = _fieldLoader.getNextField();
    _field = std::get<0>(newField);
    auto start = std::get<1>(newField);
    auto end = std::get<2>(newField);
    ShipManager::Position shipStartPosition = {std::get<0>(start), std::get<1>(start), std::get<2>(start), true};
    ShipManager::Position shipEndPosition = {std::get<0>(end), std::get<1>(end), std::get<2>(end), true};

    _observer->updatedField( _field.getWidth(), _field.getHeight() );
    for( int i = 0; i < _field.getWidth(); ++i )
        for( int j = 0; j < _field.getHeight(); ++j )
            _observer->updatedCell(i, j, _field.hasBarrier(i, j));

    _ship.setStartPosition(shipStartPosition);
    _ship.setEndPosition(shipEndPosition);
    updateShip();
}

