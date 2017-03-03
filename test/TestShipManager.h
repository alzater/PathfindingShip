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
        ShipManager::MOVEMENT movement = ShipManager::MOVEMENT::RIGHT;
        TS_ASSERT_EQUALS( (int)movement, ++i );

        int i = 0;
        for ( auto mv : ShipManager::MOVEMENT() )
        {
            ++movement;
            TS_ASSERT_EQUALS( (int)movement, ++i);
        }

    }
};
