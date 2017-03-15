// view.cpp
#include "view.h"

#include <cmath>

#include <iostream>

View::View(IPresenter* presenter, int columns, int rows)
    : _presenter(presenter)
    , _columns(columns)
    , _rows(rows)
{
    initField();
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

void View::initField()
{
    _cellSize = std::max((float)MAX_WIDTH / _columns, (float)MAX_WIDTH / _rows);

    _field.resize(_columns);
    for( int i = 0; i < _columns; ++i )
    {
        _field[i].resize(_rows);
        for( int j = 0; j < _rows; j++ )
        {
            _field[i][j] = new Cell();
            _field[i][j]->setSize(_cellSize, _cellSize);
            _field[i][j]->setPosition(_cellSize * i, _cellSize * j);
            _field[i][j]->addEventListener(TouchEvent::CLICK, [this, i, j](Event* e){ cellClick(e, i, j); });
            addChild(_field[i][j]);
        }
    }
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
        _field[column][row]->addTween(ColorRectSprite::TweenColor(Color(255, 0, 0)), 1000, 1, true, Tween:: ease_inOutQuad);
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



