#include "oxygine-framework.h"
#include <functional>

#include "presenter/presenter.h"

#include <iostream>
using namespace oxygine;

Resources gameResources;

Presenter* presenter = nullptr;

void example_preinit(){}

void example_init()
{
    gameResources.loadXML("res.xml");

    presenter = new Presenter(getStage(), std::make_pair(10, 10));
}

void example_update(){}

void example_destroy()
{
	gameResources.free();
}
