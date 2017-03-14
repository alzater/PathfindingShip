// ship_manager.h
#ifndef SHIP_MANAGER_H
#define SHIP_MANAGER_H

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

            static int toInt(const Position& pos) {
                const int res = pos.x + pos.y * 100 + 10000*( pos.isVertical ? 1 : 0 );
                return ( pos.isLegal ? res : -1 );
            }
        };
        friend bool operator<(const Position& lhs, const Position& rhs) { return Position::toInt(lhs) < Position::toInt(rhs); }
        friend bool operator==(const Position& lhs, const Position& rhs) { return Position::toInt(lhs) == Position::toInt(rhs); }

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

        std::pair<int, int> getFieldSize() const;

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

#endif

