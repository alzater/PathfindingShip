// ship.cpp
#include "ship.h"


Ship::Ship(const ShipManager& shipManager)
    : _shipManager(shipManager)
    , _startPosition(ShipManager::Position::illegal())
    , _endPosition(ShipManager::Position::illegal())
{}

bool Ship::setStartPosition(const ShipManager::Position& startPosition)
{
    if( !_shipManager.goodPosition(startPosition) || startPosition == _endPosition )
        return false;

    _startPosition = startPosition;

    return true;
}

bool Ship::setEndPosition(const ShipManager::Position& endPosition)
{
    if( !_shipManager.goodPosition(endPosition) || endPosition == _startPosition)
        return false;

    _endPosition = endPosition;

    return true;
}

const ShipManager::Position& Ship::getStartPosition() const
{
    return _startPosition;
}

const ShipManager::Position& Ship::getEndPosition() const
{
    return _endPosition;
}

bool Ship::checkStartPosition()
{
    if( !_shipManager.goodPosition(_startPosition) )
    {
        _startPosition = ShipManager::Position::illegal();
        return false;
    }
    else
        return true;
}

bool Ship::checkEndPosition()
{
    if( !_shipManager.goodPosition(_endPosition) )
    {
        _endPosition = ShipManager::Position::illegal();
        return false;
    }
    else
        return true;
}

bool Ship::checkStartPosition() const
{
    if( !_shipManager.goodPosition(_startPosition) )
        return false;
    else
        return true;
}

bool Ship::checkEndPosition() const
{
    if( !_shipManager.goodPosition(_endPosition) )
        return false;
    else
        return true;
}
