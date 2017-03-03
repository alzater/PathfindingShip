// TestShipManager.h
#include <cxxtest/TestSuite.h>

#include "../src/model/ship_manager.cpp"
#include "../src/model/field.cpp"

class TestShipManager : public CxxTest::TestSuite
{
public:
    void testPosition(void)
    {
        ShipManager::Position position = {0, 0, false, true};

        TS_ASSERT( position.isLegal );
    }

    void testEnumMovement(void)
    {
        int i = 0;
        ShipManager::MOVEMENT movement = ShipManager::MOVEMENT::RIGHT;
        TS_ASSERT_EQUALS( (int)movement, i );

        for ( auto mv : ShipManager::MOVEMENT() )
        {
            ++movement;
            TS_ASSERT_EQUALS( (int)movement, ++i);
        }
    }

    void testMoveUp()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 2, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::UP);

        TS_ASSERT_EQUALS( newPosition.x, 2);
        TS_ASSERT_EQUALS( newPosition.y, 1);
        TS_ASSERT_EQUALS( newPosition.isLegal, true);
        TS_ASSERT_EQUALS( newPosition.isVertical, true);
    }

    void testMoveUpBorder()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::UP);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testMoveUpHorisontal()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 2, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::UP);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testMoveDown()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::DOWN);

        TS_ASSERT_EQUALS( newPosition.x, 2);
        TS_ASSERT_EQUALS( newPosition.y, 2);
        TS_ASSERT_EQUALS( newPosition.isLegal, true);
        TS_ASSERT_EQUALS( newPosition.isVertical, true);
    }

    void testMoveDownBorder()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 2, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::DOWN);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testMoveDownHorisontal()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::DOWN);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }
};
