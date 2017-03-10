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
        Pathfinder pf(shm);

        TS_ASSERT( pf.setStartPosition(startPosition) );
        TS_ASSERT( pf.setEndPosition(endPosition) );

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
        Pathfinder pf(shm);

        TS_ASSERT( pf.setStartPosition(startPosition) );
        TS_ASSERT( pf.setEndPosition(endPosition) );

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
        Pathfinder pf(shm);

        TS_ASSERT( pf.setStartPosition(startPosition) );
        TS_ASSERT( pf.setEndPosition(endPosition) );

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
        Pathfinder pf(shm);

        TS_ASSERT( pf.setStartPosition(startPosition) );
        TS_ASSERT( pf.setEndPosition(endPosition) );

        bool error;
        auto path = pf.getPath(error);
        TS_ASSERT(!error);

        TS_ASSERT_EQUALS( path.size(), 3);
    }
};
