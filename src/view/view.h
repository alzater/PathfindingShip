// view.h

#include "cell.h"

#include "oxygine-framework.h"

#include <vector>

using namespace oxygine;

class View : public Actor
{
    public:
        View(int columns, int rows);
        virtual ~View();

    private:
        void initField();

        void cellClick(Event* e, int column, int row);
        bool cellClickLeft(int column, int row);
        bool cellClickRight(int column, int row);

    private:
        std::vector<std::vector<spCell>> _field;
        //spShip _ship;
        //spButton _editButton;

        int _columns;
        int _rows;
        float _cellSize;
        const int MAX_WIDTH  = 600;
        const int MAX_HEIGHT = 600;
};

DECLARE_SMART(View, spView)
