// pathfinder.cpp
#include "pathfinder.h"

#include "ship_manager.h"

#include <set>
#include <map>
#include <queue>
#include <algorithm>

Pathfinder::Pathfinder(const ShipManager& shipManager)
    : _shipManager(shipManager)
{
    _startPosition = ShipManager::Position::illegal();
    _endPosition = ShipManager::Position::illegal();
}

bool Pathfinder::setStartPosition(const ShipManager::Position& startPosition)
{
    if( !_shipManager.goodPosition(startPosition) || startPosition == _endPosition )
        return false;

    _startPosition = startPosition;

    return true;
}

bool Pathfinder::setEndPosition(const ShipManager::Position& endPosition)
{
    if( !_shipManager.goodPosition(endPosition) || endPosition == _startPosition)
        return false;

    _endPosition = endPosition;

    return true;
}

std::vector<ShipManager::MOVEMENT> Pathfinder::getPath( bool& error )
{
    error = true;
    if( !_shipManager.goodPosition(_startPosition) || !_shipManager.goodPosition(_endPosition) )
        return {};

    std::set<ShipManager::Position> visitedPositions;
    std::queue<ShipManager::Position> positionsQueue;
    std::map<ShipManager::Position, std::pair<ShipManager::Position, ShipManager::MOVEMENT>> parents;

    positionsQueue.push(_startPosition);
    visitedPositions.insert(_startPosition);

    bool gained = false;
    while( !positionsQueue.empty() )
    {
        const auto position = positionsQueue.front();
        positionsQueue.pop();

        for( auto movement : ShipManager::MOVEMENT() )
        {
            const auto newPosition = _shipManager.getNewPosition(position, movement);
            if( !_shipManager.goodPosition(newPosition) )
                continue;

            if( visitedPositions.find(newPosition) != visitedPositions.end() )
                continue;

            positionsQueue.push(newPosition);
            visitedPositions.insert(newPosition);
            parents.insert( std::make_pair( newPosition, std::make_pair(position, movement) ) );

            if( newPosition == _endPosition )
                gained = true;
        }

        if(gained)
            break;
    }

    if( !gained )
        return {};

    std::vector<ShipManager::MOVEMENT> result;
    auto position = _endPosition;
    while( !(position == _startPosition) )
    {
        auto state = parents[position];
        position = state.first;
        result.push_back(state.second);
    }
    std::reverse(result.begin(), result.end());

    error = false;
    return result;
}

