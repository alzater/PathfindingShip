// field.cpp
#include "field.h"
#include "assert.h"

Field::Field()
{
    init(1, 1);
}

Field::Field(int width, int height)
{
    init(width, height);
}

void Field::setSize(int width, int height)
{
    init(width, height);
}

int Field::getWidth() const
{
    return _barriers.size();
}

int Field::getHeight() const
{
    if( _barriers.empty() )
        return 0;

    return _barriers[0].size();
}

void Field::setBarrier(int x, int y)
{
    assert(x >= 0 && x < _barriers.size());
    assert(!_barriers.empty() && y >= 0 && y < _barriers[0].size());

    _barriers[x][y] = true;
}

void Field::removeBarrier(int x, int y)
{
    assert(x >= 0 && x < _barriers.size());
    assert(!_barriers.empty() && y >= 0 && y < _barriers[0].size());

    _barriers[x][y] = false;
}

bool Field::hasBarrier(int x, int y) const
{
    assert(x >= 0 && x < _barriers.size());
    assert(!_barriers.empty() && y >= 0 && y < _barriers[0].size());

    return _barriers[x][y];
}

void Field::init(int width, int height)
{
    assert(width > 0);
    assert(height > 0);

    _barriers.resize(width);
    for (auto& barriersCol : _barriers)
    {
        barriersCol.resize(height);
        for (auto& barrier : barriersCol)
            barrier = false;
    }
}
