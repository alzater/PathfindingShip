// view.cpp
#include "view.h"

#include <cmath>

View::View()
{
    initField(columns, rows);
}

View::~View()
{}

void View::initField()
{
    _cellSize = std::max((float)_colomns / MAX_WIDTH, (float)_rows / MAX_WIDTH);

    _field.resize(_columns);
    for( int i = 0; i < _columns; ++i )
    {
        _field[i].resize(_rows);
        for( int j = 0; j < _rows; j++ )
        {
            _field[i][j] = Cell(i, j, cellClickLeft, cellClickRight);
            _field[i][j]->setSize(_cellSize, _cellSize);
            _field[i][j]->setPosition(_cellSize * i, _cellSize * j);
        }
    }
}

