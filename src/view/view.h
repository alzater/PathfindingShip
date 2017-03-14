// view.h

#include "oxygine-framework.h"

#include <vector>

class View : public Actor
{
    public:
        View();
        virtual View();

    private:
        std::vector<std::vector<spCell>> _field;
        spShip _ship;
        spButton _editButton;
};
