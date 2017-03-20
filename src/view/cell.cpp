// cell.cpp
#include "cell.h"

extern Resources gameResources;

Cell::Cell(float size)
{
    setSize(size, size);
    setColor( Color(0, 0, 240) );

    spSprite sea = new Sprite;
    sea->setResAnim( gameResources.getResAnim("sea") );
    sea->setSize( getSize() * 0.9 );
    sea->setAnchor(-0.05, -0.05);
    addChild(sea);
}

Cell::~Cell()
{}

void Cell::setRock()
{
    if( !rock )
    {
        rock = new Sprite;
        rock->setResAnim( gameResources.getResAnim("rock") );
        rock->setColumn( rand() % 8 );
        rock->setRow( rand() % 8 );
        rock->setSize( getSize() * 1.2 );
        rock->setAnchor(0.1, 0.1);
        addChild(rock);
    }

    rock->setVisible(true);
}

void Cell::removeRock()
{
    rock->setVisible(false);
}
