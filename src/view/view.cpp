// view.cpp
#include "view.h"

#include <cmath>

#include <iostream>

View::View(int columns, int rows)
    : _columns(columns)
    , _rows(rows)
{
    initField();
}

View::~View()
{}

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

    _field[2][5]->setRock();
    _field[3][2]->setRock();
    _field[3][6]->setRock();
    _field[8][2]->setRock();
}

void View::cellClick(Event* e, int column, int row)
{
    std::cout << "click " << column << ' ' << row << std::endl;
}

bool View::cellClickLeft(int column, int row)
{
}

bool View::cellClickRight(int column, int row)
{
}

