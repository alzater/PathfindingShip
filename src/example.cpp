#include "oxygine-framework.h"
#include <functional>
using namespace oxygine;

Resources gameResources;

void example_preinit(){}

void example_init()
{
	gameResources.loadXML("res.xml");
}

void example_update(){}

void example_destroy()
{
	gameResources.free();
}
