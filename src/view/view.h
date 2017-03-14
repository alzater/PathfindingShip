// view.h

#include "oxygine-framework.h"

#include <vector>

class View : public Actor
{
    public:
        View(int columns, int rows);
        virtual ~View();

    private:
        void initField(int columns, int rows);

        bool cellClickLeft(int i, int j);
        bool cellClickRight(int i, int j);

    private:
        std::vector<std::vector<spCell>> _field;
        //spShip _ship;
        //spButton _editButton;

        int _colomns;
        int _rows;
        float _cellSize;
        const int MAX_WIDTH  = 600;
        const int MAX_HEIGHT = 600;
};
