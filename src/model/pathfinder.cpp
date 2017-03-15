// pathfinder.cpp
#include "pathfinder.h"

#include "ship_manager.h"

#include <set>
#include <map>
#include <queue>
#include <algorithm>

Pathfinder::Pathfinder(const ShipManager& shipManager, const Ship& ship)
    : _shipManager(shipManager)
    , _ship(ship)
{}

std::vector<ShipManager::MOVEMENT> Pathfinder::getPath( bool& error )
{
    error = true;
    if( !_ship.checkStartPosition() || !_ship.checkEndPosition() )
        return {};

    std::set<ShipManager::Position> visitedPositions;
    std::queue<ShipManager::Position> positionsQueue;
    std::map<ShipManager::Position, std::pair<ShipManager::Position, ShipManager::MOVEMENT>> parents;

    positionsQueue.push(_ship.getStartPosition());
    visitedPositions.insert(_ship.getStartPosition());

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

            if( newPosition == _ship.getEndPosition() )
                gained = true;
        }

        if(gained)
            break;
    }

    if( !gained )
        return {};

    std::vector<ShipManager::MOVEMENT> result;
    auto position = _ship.getEndPosition();
    while( !(position == _ship.getStartPosition()) )
    {
        auto state = parents[position];
        position = state.first;
        result.push_back(state.second);
    }
    std::reverse(result.begin(), result.end());

    error = false;
    return result;
}

