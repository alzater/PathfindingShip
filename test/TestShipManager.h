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

    void testMoveUpBarrier()
    {
        Field field(4, 4);
        field.setBarrier(1, 0);
        ShipManager shm(field);
        ShipManager::Position startPosition = {1, 2, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::UP);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
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

    void testMoveDownBarrier()
    {
        Field field(4, 4);
        field.setBarrier(1, 3);
        ShipManager shm(field);
        ShipManager::Position startPosition = {1, 1, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::DOWN);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
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

    void testMoveRight()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {1, 1, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::RIGHT);

        TS_ASSERT_EQUALS( newPosition.x, 2);
        TS_ASSERT_EQUALS( newPosition.y, 1);
        TS_ASSERT_EQUALS( newPosition.isLegal, true);
        TS_ASSERT_EQUALS( newPosition.isVertical, false);
    }

    void testMoveRightBarrier()
    {
        Field field(4, 4);
        field.setBarrier(3, 1);
        ShipManager shm(field);
        ShipManager::Position startPosition = {1, 1, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::RIGHT);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testMoveRightBorder()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 2, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::RIGHT);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testMoveRightVertical()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::RIGHT);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testMoveLeft()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::LEFT);

        TS_ASSERT_EQUALS( newPosition.x, 1);
        TS_ASSERT_EQUALS( newPosition.y, 1);
        TS_ASSERT_EQUALS( newPosition.isVertical, false);
        TS_ASSERT_EQUALS( newPosition.isLegal, true);
    }

    void testMoveLeftBarrier()
    {
        Field field(4, 4);
        field.setBarrier(0, 1);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::LEFT);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testMoveLeftBorder()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {1, 2, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::LEFT);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testMoveLeftVertical()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::LEFT);

        TS_ASSERT_EQUALS( newPosition.isLegal, false);
    }

    void testRotateLeftVertical()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::ROTATE_LEFT);

        TS_ASSERT_EQUALS( newPosition.x, 2);
        TS_ASSERT_EQUALS( newPosition.y, 1);
        TS_ASSERT_EQUALS( newPosition.isVertical, false);
        TS_ASSERT_EQUALS( newPosition.isLegal, true);
    }

    void testRotateRightVertical()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::ROTATE_RIGHT);

        TS_ASSERT_EQUALS( newPosition.x, 2);
        TS_ASSERT_EQUALS( newPosition.y, 1);
        TS_ASSERT_EQUALS( newPosition.isVertical, false);
        TS_ASSERT_EQUALS( newPosition.isLegal, true);
    }

    void testRotateLeftHorisontal()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::ROTATE_LEFT);

        TS_ASSERT_EQUALS( newPosition.x, 2);
        TS_ASSERT_EQUALS( newPosition.y, 1);
        TS_ASSERT_EQUALS( newPosition.isVertical, true);
        TS_ASSERT_EQUALS( newPosition.isLegal, true);
    }

    void testRotateRightHorisontal()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, false, true};

        auto newPosition = shm.getNewPosition(startPosition, ShipManager::MOVEMENT::ROTATE_RIGHT);

        TS_ASSERT_EQUALS( newPosition.x, 2);
        TS_ASSERT_EQUALS( newPosition.y, 1);
        TS_ASSERT_EQUALS( newPosition.isVertical, true);
        TS_ASSERT_EQUALS( newPosition.isLegal, true);
    }
};
