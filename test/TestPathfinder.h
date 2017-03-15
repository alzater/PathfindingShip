// TestPathfinder.h
#include <cxxtest/TestSuite.h>

#include "../src/model/pathfinder.h"

class TestPathfinder : public CxxTest::TestSuite
{
private:
    void printPath(const std::vector<ShipManager::MOVEMENT>& path)
    {
        std::cout << std::endl;

        std::string res;
        for( auto movement : path )
        {
            switch( movement )
            {
                case ShipManager::MOVEMENT::RIGHT: res = "right"; break;
                case ShipManager::MOVEMENT::LEFT: res = "left"; break;
                case ShipManager::MOVEMENT::UP: res = "up"; break;
                case ShipManager::MOVEMENT::DOWN: res = "down"; break;
                case ShipManager::MOVEMENT::ROTATE_RIGHT: res = "rotate_right"; break;
                case ShipManager::MOVEMENT::ROTATE_LEFT: res = "rotate_left"; break;
            }
            std::cout << res << " ";
        }
        std::cout << std::endl;
    }

public:
    void testMove1Down()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};
        ShipManager::Position endPosition = {2, 2, true, true};
        Ship ship(shm);
        Pathfinder pf(shm, ship);

        TS_ASSERT( ship.setStartPosition(startPosition) );
        TS_ASSERT( ship.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(!error);

        TS_ASSERT_EQUALS( path.size(), 1);
    }

    void testMove4Down()
    {
        Field field(7, 7);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};
        ShipManager::Position endPosition = {2, 5, true, true};
        Ship ship(shm);
        Pathfinder pf(shm, ship);

        TS_ASSERT( ship.setStartPosition(startPosition) );
        TS_ASSERT( ship.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(!error);

        TS_ASSERT_EQUALS( path.size(), 4);
    }

    void testRotate()
    {
        Field field(4, 4);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};
        ShipManager::Position endPosition = {2, 1, false, true};
        Ship ship(shm);
        Pathfinder pf(shm, ship);

        TS_ASSERT( ship.setStartPosition(startPosition) );
        TS_ASSERT( ship.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(!error);

        TS_ASSERT_EQUALS( path.size(), 1);
    }


    void testDownAndRotateAndLeft()
    {
        Field field(5, 5);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 2, true, true};
        ShipManager::Position endPosition = {3, 3, false, true};
        Ship ship(shm);
        Pathfinder pf(shm, ship);

        TS_ASSERT( ship.setStartPosition(startPosition) );
        TS_ASSERT( ship.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(!error);

        TS_ASSERT_EQUALS( path.size(), 3);
    }

    void testBarrierWhenDown()
    {
        Field field(5, 9);
        field.setBarrier(2, 5);
        ShipManager shm(field);
        ShipManager::Position startPosition = {2, 1, true, true};
        ShipManager::Position endPosition = {2, 7, true, true};
        Ship ship(shm);
        Pathfinder pf(shm, ship);

        TS_ASSERT( ship.setStartPosition(startPosition) );
        TS_ASSERT( ship.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(!error);

        TS_ASSERT_EQUALS( path.size(), 12 );
    }

    void testCorrectWay()
    {
        Field field(5, 7);
        field.setBarrier(0, 0);
        field.setBarrier(0, 3);
        field.setBarrier(0, 4);
        field.setBarrier(0, 5);
        field.setBarrier(0, 6);
        field.setBarrier(2, 2);
        field.setBarrier(2, 3);
        field.setBarrier(2, 4);
        field.setBarrier(2, 5);
        field.setBarrier(2, 6);
        field.setBarrier(3, 2);
        field.setBarrier(4, 2);

        ShipManager shm(field);
        ShipManager::Position startPosition = {1, 5, true, true};
        ShipManager::Position endPosition = {3, 1, false, true};
        Ship ship(shm);
        Pathfinder pf(shm, ship);

        TS_ASSERT( ship.setStartPosition(startPosition) );
        TS_ASSERT( ship.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(!error);

        const ShipManager::MOVEMENT UP = ShipManager::MOVEMENT::UP;
        const ShipManager::MOVEMENT RR = ShipManager::MOVEMENT::ROTATE_RIGHT;
        const ShipManager::MOVEMENT R  = ShipManager::MOVEMENT::RIGHT;
        const std::vector<ShipManager::MOVEMENT> movements = {UP, UP, UP, UP, RR, R, R};

        TS_ASSERT_EQUALS( path.size(), movements.size() );

        for( int i = 0; i < movements.size(); ++i )
            TS_ASSERT_EQUALS( (int)path[i], (int)movements[i] );
    }

    void testOneWay()
    {
        Field field(7, 7);
        field.setBarrier(3, 0);
        field.setBarrier(3, 1);
        field.setBarrier(3, 3);
        field.setBarrier(3, 4);
        field.setBarrier(3, 5);
        field.setBarrier(0, 1);
        field.setBarrier(6, 3);

        ShipManager shm(field);
        ShipManager::Position startPosition = {1, 4, true, true};
        ShipManager::Position endPosition = {5, 1, true, true};
        Ship ship(shm);
        Pathfinder pf(shm, ship);

        TS_ASSERT( ship.setStartPosition(startPosition) );
        TS_ASSERT( ship.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(!error);

        const ShipManager::MOVEMENT UP = ShipManager::MOVEMENT::UP;
        const ShipManager::MOVEMENT RR = ShipManager::MOVEMENT::ROTATE_RIGHT;
        const ShipManager::MOVEMENT R  = ShipManager::MOVEMENT::RIGHT;
        const ShipManager::MOVEMENT RL = ShipManager::MOVEMENT::ROTATE_LEFT;
        const std::vector<ShipManager::MOVEMENT> movements = {UP, UP, RR, R, R, R, R, RL, UP};

        TS_ASSERT_EQUALS( path.size(), movements.size() );

        for( int i = 0; i < movements.size(); ++i )
            TS_ASSERT_EQUALS( (int)path[i], (int)movements[i] );
    }

    void testNoWay()
    {
        Field field(7, 7);
        field.setBarrier(3, 0);
        field.setBarrier(3, 1);
        field.setBarrier(3, 2);
        field.setBarrier(3, 3);
        field.setBarrier(3, 4);
        field.setBarrier(3, 5);

        ShipManager shm(field);
        ShipManager::Position startPosition = {1, 4, true, true};
        ShipManager::Position endPosition = {5, 1, true, true};
        Ship ship(shm);
        Pathfinder pf(shm, ship);

        TS_ASSERT( ship.setStartPosition(startPosition) );
        TS_ASSERT( ship.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(error);
        TS_ASSERT_EQUALS( path.size(), 0 );
    }
};
