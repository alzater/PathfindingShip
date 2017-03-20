// view.cpp
#include "view.h"

#include <cmath>

#include <iostream>

extern Resources gameResources;

View::View(IPresenter* presenter, int columns, int rows)
    : _presenter(presenter)
    , _columns(columns)
    , _rows(rows)
{
    initField();
    initShips();
    initButtons();
}

View::~View()
{}

void View::setCell(int x, int y, bool hasBarrier)
{
    if( hasBarrier )
        _field[x][y]->setRock();
    else
        _field[x][y]->removeRock();
}

void View::setShipStartPosition(int x, int y, bool isVertical)
{
    setShip(_startShipPosition, x, y, isVertical);
}

void View::setShipEndPosition(int x, int y, bool isVertical)
{
    setShip(_endShipPosition, x, y, isVertical);
}

void View::initField()
{
    _cellSize = std::max((float)MAX_WIDTH / _columns, (float)MAX_WIDTH / _rows);

    _field.resize(_columns);
    for( int i = 0; i < _columns; ++i )
    {
        _field[i].resize(_rows);
        for( int j = 0; j < _rows; j++ )
        {
            _field[i][j] = new Cell(_cellSize);
            _field[i][j]->setPosition(_cellSize * i, _cellSize * j);
            _field[i][j]->addEventListener(TouchEvent::CLICK, [this, i, j](Event* e){ cellClick(e, i, j); });
            addChild(_field[i][j]);
        }
    }
}

void View::initShips()
{
    _startShipPosition = new ShipPlace(_cellSize, Color(255, 255, 0));
    _startShipPosition->setVisible(false);
    addChild(_startShipPosition);

    _endShipPosition = new ShipPlace(_cellSize, Color(0, 255, 255));
    _endShipPosition->setVisible(false);
    addChild(_endShipPosition);

    _mainShip = new ShipView(_cellSize);
    _mainShip->setVisible(false);
    addChild(_mainShip);
}

void View::cellClick(Event* e, int column, int row)
{
    TouchEvent* event = dynamic_cast<TouchEvent*>(e);
    if( event == nullptr )
        return;

    bool result = false;
    if( event->mouseButton == MouseButton_Left )
        result = cellClickLeft(column, row);
    else if( event->mouseButton == MouseButton_Right )
        result = cellClickRight(column, row);

    if( !result )
        _field[column][row]->addTween(ColorRectSprite::TweenColor(Color(255, 0, 0)), 400, 1, true, Tween:: ease_outQuart);
}

bool View::cellClickLeft(int column, int row)
{
    if( _modifyMode )
        return _presenter->setBarrier(column, row);
    else
        return _presenter->setShipStartPosition(column, row);
}

bool View::cellClickRight(int column, int row)
{
    if( _modifyMode )
        return _presenter->removeBarrier(column, row);
    else
        return _presenter->setShipEndPosition(column, row);
}

void View::setShip(spActor ship, int column, int row, bool isVertical)
{
    if( column < 0 || row < 0 )
    {
        ship->setVisible(false);
        return;
    }

    ship->setVisible(true);
    ship->setPosition( _cellSize * ( (float)column + 0.5f ), _cellSize * ( (float)row + 0.5f ) );

    if( isVertical )
        ship->setRotation(0);
    else
        ship->setRotation(M_PI / 2);
}

void View::initButtons()
{
    ResFont *fnt = gameResources.getResFont("main");

    spButton modeButton = new Button();
    modeButton->setSize(200, 60);
    modeButton->setPosition(600, 10);
    modeButton->addEventListener(TouchEvent::CLICK, [this](Event*){changeMode();});
    addChild(modeButton);

    _modeButtonText = new TextField();
    modeButton->addChild(_modeButtonText);
    _modeButtonText->setText("Modify");
    _modeButtonText->setSize(200, 55);
    _modeButtonText->setFont(fnt);
    _modeButtonText->setAlign(TextStyle::VALIGN_MIDDLE, TextStyle::HALIGN_MIDDLE);
    _modeButtonText->setTouchEnabled(false);

    _pathfindButton = new Button();
    _pathfindButton->setSize(200, 60);
    _pathfindButton->setPosition(600, 80);
    _pathfindButton->addEventListener(TouchEvent::CLICK, [this](Event*){pathfinding();});
    if( !_modifyMode )
        _pathfindButton->setVisible(true);
    else
        _pathfindButton->setVisible(false);
    addChild(_pathfindButton);

    spTextField pathfindButtonText = new TextField();
    _pathfindButton->addChild(pathfindButtonText);
    pathfindButtonText->setText("Find path");
    pathfindButtonText->setSize(200, 55);
    pathfindButtonText->setFont(fnt);
    pathfindButtonText->setAlign(TextStyle::VALIGN_MIDDLE, TextStyle::HALIGN_MIDDLE);
    pathfindButtonText->setTouchEnabled(false);
}

void View::changeMode()
{
    _modifyMode = !_modifyMode;

    if( _modifyMode )
    {
        _modeButtonText->setText("Apply modify");
        _pathfindButton->setVisible(false);
    }
    else
    {
        _modeButtonText->setText("Modify");
        _pathfindButton->setVisible(true);
    }
}

void View::pathfinding()
{
    const auto path = _presenter->getShipPath();
    if( path.empty() )
        return;

    spTweenQueue tween = new TweenQueue;
    float angle = 0;
    int duration = 10;

    for(const auto& move : path)
    {
        if( move.type == ShipMove::Type::MOVE )
        {
            tween->add(Actor::TweenPosition( Vector2(_cellSize*((float)move.x+0.5f), _cellSize*((float)move.y+0.5f))), duration );
        }
        else
        {
            if( move.type == ShipMove::Type::ROTATE_LEFT )
                angle -= M_PI/2;
            else
                angle += M_PI/2;

            tween->add(Actor::TweenRotation(angle), duration);

            std::cout << angle << std::endl;
        }

        duration = 500;
    }

    tween->add(TweenDummy(), 2000);
    tween->setDoneCallback([this](Event*){pathfinding();});

    _mainShip->removeTweens();
    _mainShip->setVisible(true);
    _mainShip->setRotation(0);
    _mainShip->setPosition( Vector2(_cellSize*((float)path[0].x+0.5f), _cellSize*((float)path[0].y+0.5f)));
    _mainShip->addTween(tween);
}
