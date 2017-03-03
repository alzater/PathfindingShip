// ship_manager.h
#include <vector>

class Field;

class ShipManager
{
    public:
        struct Position
        {
            int x, y;
            bool isVertical;
            bool isLegal = false;

            static Position illegal() { return {-1, -1, false, false}; };
        };

        enum class MOVEMENT
        {
            RIGHT,
            LEFT,
            UP,
            DOWN,
            ROTATE_RIGHT,
            ROTATE_LEFT,
            FIRST = RIGHT,
            LAST = ROTATE_LEFT
        };
        friend const MOVEMENT& operator++(MOVEMENT& x) { return x = (MOVEMENT)(std::underlying_type<MOVEMENT>::type(x) + 1); }
        friend MOVEMENT operator*(MOVEMENT m) {return m;}
        friend MOVEMENT begin(MOVEMENT r) {return MOVEMENT::FIRST;}
        friend MOVEMENT end(MOVEMENT r)   {MOVEMENT l=MOVEMENT::LAST; return ++l;}

    public:
        ShipManager(const Field& field);

        bool goodPosition( const Position& position ) const;
        Position getNewPosition(const Position& position, MOVEMENT movement) const;

    private:
        Position moveRight(const Position& position) const;
        Position moveLeft(const Position& position) const;
        Position moveUp(const Position& position) const;
        Position moveDown(const Position& position) const;
        Position moveRotateRight(const Position& position) const;
        Position moveRotateLeft(const Position& position) const;

        bool mainDiagonalRotationCheck(const Position& position) const;
        bool sideDiagonalRotationCheck(const Position& position) const;

    private:
        const Field& _field;
};

