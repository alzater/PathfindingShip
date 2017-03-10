// ship_manager.cpp
#include "ship_manager.h"

#include "field.h"

#include "assert.h"

ShipManager::ShipManager(const Field& field)
    : _field(field)
{}

bool ShipManager::goodPosition(const ShipManager::Position& position) const
{
    if( !position.isLegal )
        return false;

    if( position.isVertical )
    {
        if( _field.hasBarrier(position.x, position.y) ||
            _field.hasBarrier(position.x, position.y + 1) ||
            _field.hasBarrier(position.x, position.y - 1)
          )
            return false;
        else
            return true;
    }
    else
    {
        if( _field.hasBarrier(position.x, position.y) ||
            _field.hasBarrier(position.x - 1, position.y) ||
            _field.hasBarrier(position.x + 1, position.y)
          )
            return false;
        else
            return true;
    }
}

ShipManager::Position ShipManager::getNewPosition(const ShipManager::Position& position, ShipManager::MOVEMENT movement) const
{
    assert( position.isLegal );

    switch( movement )
    {
        case MOVEMENT::RIGHT:        return moveRight(position);
        case MOVEMENT::LEFT:         return moveLeft(position);
        case MOVEMENT::UP:           return moveUp(position);
        case MOVEMENT::DOWN:         return moveDown(position);
        case MOVEMENT::ROTATE_RIGHT: return moveRotateRight(position);
        case MOVEMENT::ROTATE_LEFT:  return moveRotateLeft(position);
        default:
                                     assert(!"KNOWN MOVEMENT TYPE");
                                     return Position::illegal();
    }
}

ShipManager::Position ShipManager::moveRight(const ShipManager::Position& position) const
{
    Position newPosition = position;
    newPosition.x += 1;

    if( position.isVertical || !goodPosition(position) || !goodPosition(newPosition) )
        return Position::illegal();

    return newPosition;
}

ShipManager::Position ShipManager::moveLeft(const ShipManager::Position& position) const
{
    Position newPosition = position;
    newPosition.x -= 1;

    if( position.isVertical || !goodPosition(position) || !goodPosition(newPosition) )
        return Position::illegal();

    return newPosition;
}

ShipManager::Position ShipManager::moveUp(const ShipManager::Position& position) const
{
    Position newPosition = position;
    newPosition.y -= 1;

    if( !position.isVertical || !goodPosition(position) || !goodPosition(newPosition) )
        return Position::illegal();

    return newPosition;
}

ShipManager::Position ShipManager::moveDown(const Position& position) const
{
    Position newPosition = position;
    newPosition.y += 1;

    if( !position.isVertical || !goodPosition(position) || !goodPosition(newPosition) )
        return Position::illegal();

    return newPosition;
}

ShipManager::Position ShipManager::moveRotateRight(const Position& position) const
{
    if( !goodPosition(position) )
        return Position::illegal();

    Position newPosition = position;
    newPosition.isVertical = !position.isVertical;

    if( !goodPosition(newPosition) )
        return Position::illegal();

    if( position.isVertical )
    {
        if( sideDiagonalRotationCheck(position) )
            return newPosition;
        else
            return Position::illegal();
    }
    else
    {
        if( mainDiagonalRotationCheck(position) )
            return newPosition;
        else
            return Position::illegal();
    }
}

ShipManager::Position ShipManager::moveRotateLeft(const Position& position) const
{
    if( !goodPosition(position) )
        return Position::illegal();

    Position newPosition = position;
    newPosition.isVertical = !position.isVertical;

    if( !goodPosition(newPosition) )
        return Position::illegal();

    if( position.isVertical )
    {
        if( mainDiagonalRotationCheck(position) )
            return newPosition;
        else
            return Position::illegal();
    }
    else
    {
        if( sideDiagonalRotationCheck(position) )
            return newPosition;
        else
            return Position::illegal();
    }
}

bool ShipManager::mainDiagonalRotationCheck(const ShipManager::Position& position) const
{
    if( _field.hasBarrier( position.x + 1, position.y + 1) ||
        _field.hasBarrier( position.x - 1, position.y - 1)
      )
        return false;

    return true;
}

bool ShipManager::sideDiagonalRotationCheck(const ShipManager::Position& position) const
{
    if( _field.hasBarrier( position.x - 1, position.y + 1) ||
        _field.hasBarrier( position.x + 1, position.y - 1)
      )
        return false;

    return true;
}

std::pair<int, int> ShipManager::getFieldSize() const
{
    std::pair<int, int> size;

    size.first = _field.getWidth();
    size.second = _field.getHeight();

    return size;
}

