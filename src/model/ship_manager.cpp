// ship_manager.cpp
#include "ship_manager.h"

#include "field.h"

#include "assert.h"

ShipManager::ShipManager(const Field& field)
    : _field(field)
{}

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
    if( position.isVertical )
        return Position::illegal();

    if( position.x >= _field.getWidth() - 2 )
        return Position::illegal();

    if( _field.hasBarrier( position.x + 2, position.y ) )
        return Position::illegal();

    return {position.x + 1, position.y, false, true};
}

ShipManager::Position ShipManager::moveLeft(const ShipManager::Position& position) const
{
    if( position.isVertical )
        return Position::illegal();

    if( position.x <= 1 )
        return Position::illegal();

    if( _field.hasBarrier( position.x - 2, position.y ) )
        return Position::illegal();

    return {position.x - 1, position.y, false, true};
}

ShipManager::Position ShipManager::moveUp(const ShipManager::Position& position) const
{
    if( !position.isVertical )
        return Position::illegal();

    if( position.y <= 1 )
        return Position::illegal();

    if( _field.hasBarrier( position.x, position.y - 2 ) )
        return Position::illegal();

    return {position.x, position.y - 1, true, true};
}

ShipManager::Position ShipManager::moveDown(const Position& position) const
{
    if( !position.isVertical )
        return Position::illegal();

    if( position.y >= _field.getWidth() - 2 )
        return Position::illegal();

    if( _field.hasBarrier( position.x, position.y + 2 ) )
        return Position::illegal();

    return {position.x, position.y + 1, true, true};
}

ShipManager::Position ShipManager::moveRotateRight(const Position& position) const
{
    if( position.isVertical )
    {
        if( mainDiagonalRotationCheck(position) )
            return {position.x, position.y, false, true};
        else
            return Position::illegal();
    }
    else
    {
        if( sideDiagonalRotationCheck(position) )
            return {position.x, position.y, false, true};
        else
            return Position::illegal();
    }
}

ShipManager::Position ShipManager::moveRotateLeft(const Position& position) const
{
    if( position.isVertical )
    {
        if( sideDiagonalRotationCheck(position) )
            return {position.x, position.y, false, true};
        else
            return Position::illegal();
    }
    else
    {
        if( mainDiagonalRotationCheck(position) )
            return {position.x, position.y, false, true};
        else
            return Position::illegal();
    }
}

bool ShipManager::mainDiagonalRotationCheck(const ShipManager::Position& position) const
{
    if( _field.hasBarrier( position.x, position.y + 1) ||
        _field.hasBarrier( position.x + 1, position.y + 1) ||
        _field.hasBarrier( position.x + 1, position.y) ||
        _field.hasBarrier( position.x - 1, position.y) ||
        _field.hasBarrier( position.x - 1, position.y - 1) ||
        _field.hasBarrier( position.x, position.y - 1) )
        return false;

    return true;
}

bool ShipManager::sideDiagonalRotationCheck(const ShipManager::Position& position) const
{
    if( _field.hasBarrier( position.x, position.y + 1) ||
        _field.hasBarrier( position.x - 1, position.y + 1) ||
        _field.hasBarrier( position.x + 1, position.y) ||
        _field.hasBarrier( position.x - 1, position.y) ||
        _field.hasBarrier( position.x + 1, position.y - 1) ||
        _field.hasBarrier( position.x, position.y - 1) )
        return false;

    return true;
}

