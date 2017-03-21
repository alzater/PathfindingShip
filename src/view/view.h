// view.h

#include "../presenter/ipresenter.h"
#include "cell.h"
#include "ship_view.h"
#include "ship_place.h"

#include "oxygine-framework.h"

#include <vector>

using namespace oxygine;

class View : public Actor
{
    public:
        View(IPresenter* presenter);
        virtual ~View();

        void setCell(int x, int y, bool hasBarrier);

        void setShipStartPosition(int x, int y, bool isVertical);
        void setShipEndPosition(int x, int y, bool isVertical);

        void initField(int columns, int rows);

    private:
        void initShips();
        void initButtons();

        void cellClick(Event* e, int column, int row);
        bool cellClickLeft(int column, int row);
        bool cellClickRight(int column, int row);

        void setShip(spActor ship, int column, int row, bool isVertical);

        void changeMode();
        void pathfinding();
        void nextMap();

        void destroyField();
        void showError();

    private:
        IPresenter* _presenter;

        std::vector<std::vector<spCell>> _field;
        spTextField _modeButtonText;
        spButton _pathfindButton;
        spSprite _error;

        int _columns;
        int _rows;
        float _cellSize;
        const int MAX_WIDTH  = 600;
        const int MAX_HEIGHT = 600;

        bool _modifyMode = false;

        spShipView _mainShip;
        spShipPlace _startShipPosition;
        spShipPlace _endShipPosition;
};

DECLARE_SMART(View, spView)
