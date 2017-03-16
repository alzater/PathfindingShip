// view.h

#include "../presenter/ipresenter.h"
#include "cell.h"
#include "ship_view.h"

#include "oxygine-framework.h"

#include <vector>

using namespace oxygine;

class View : public Actor
{
    public:
        View(IPresenter* presenter, int columns, int rows);
        virtual ~View();

        void setCell(int x, int y, bool hasBarrier);

        void setShipStartPosition(int x, int y, bool isVertical);
        void setShipEndPosition(int x, int y, bool isVertical);


    private:
        void initField();
        void initShips();
        void initButtons();

        void cellClick(Event* e, int column, int row);
        bool cellClickLeft(int column, int row);
        bool cellClickRight(int column, int row);

        void setShip(spShipView ship, int column, int row, bool isVertical);

        void changeMode();
        void pathfinding();


    private:
        IPresenter* _presenter;

        std::vector<std::vector<spCell>> _field;
        spTextField _modeButtonText;
        spButton _pathfindButton;

        int _columns;
        int _rows;
        float _cellSize;
        const int MAX_WIDTH  = 600;
        const int MAX_HEIGHT = 600;

        bool _modifyMode = false;

        spShipView _mainShip;
        spShipView _startShipPosition;
        spShipView _endShipPosition;
};

DECLARE_SMART(View, spView)
