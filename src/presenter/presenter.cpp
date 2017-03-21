// presenter.cpp
#include "presenter.h"

Presenter::Presenter(spActor scene, std::pair<int, int> fieldSize)
    : _model()
    , _view(this)
{
    _model.setObserver(this);
    _model.nextField();

    scene->addChild(&_view);
}

Presenter::~Presenter()
{
    _view.detach();
    _model.removeObserver(this);
}

bool Presenter::setShipStartPosition(int x, int y)
{
    return _model.setShipStartPosition(x, y);
}

bool Presenter::setShipEndPosition(int x, int y)
{
    return _model.setShipEndPosition(x, y);
}

bool Presenter::setBarrier(int x, int y)
{
    return _model.setBarrier(x, y);
}

bool Presenter::removeBarrier(int x, int y)
{
    return _model.removeBarrier(x, y);
}

std::vector<ShipMove> Presenter::getShipPath()
{
    const auto path = _model.getShipPath();
    std::vector<ShipMove> result;
    if( path.empty() )
        return result;

    auto startPosition = _model.getShipStartPosition();
    ShipMove firstMove;
    if( std::get<2>(startPosition) )
        firstMove.type = ShipMove::Type::MOVE;
    else
        firstMove.type = ShipMove::Type::ROTATE_RIGHT;
    int xPos = firstMove.x = std::get<0>(startPosition);
    int yPos = firstMove.y = std::get<1>(startPosition);

    result.push_back(firstMove);

    for( const auto& move : path )
    {
        ShipMove shipMove;
        if( move == ShipManager::MOVEMENT::ROTATE_LEFT )
            shipMove.type = ShipMove::Type::ROTATE_LEFT;
        else if( move == ShipManager::MOVEMENT::ROTATE_RIGHT )
            shipMove.type = ShipMove::Type::ROTATE_RIGHT;
        else
        {
            switch( move )
            {
                case ShipManager::MOVEMENT::UP    : yPos -= 1; break;
                case ShipManager::MOVEMENT::DOWN  : yPos += 1; break;
                case ShipManager::MOVEMENT::RIGHT : xPos += 1; break;
                case ShipManager::MOVEMENT::LEFT  : xPos -= 1; break;
            }
            shipMove.type = ShipMove::Type::MOVE;
        }
        shipMove.x = xPos;
        shipMove.y = yPos;

        result.push_back(shipMove);
    }

    return result;
}

void Presenter::nextMap()
{
    _model.nextField();
}

void Presenter::updatedCell(int x, int y, bool hasBarrier)
{
    _view.setCell(x, y, hasBarrier);
}

void Presenter::updatedShipStartPosition(int x, int y, bool isVertical)
{
    _view.setShipStartPosition(x, y, isVertical);
}

void Presenter::updatedShipEndPosition(int x, int y, bool isVertical)
{
    _view.setShipEndPosition(x, y, isVertical);
}

void Presenter::updatedField(int x, int y)
{
    _view.initField(x, y);
}
