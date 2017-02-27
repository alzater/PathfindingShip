// TestField.h
#include <cxxtest/TestSuite.h>

#include "../src/model/field.cpp"

class TestField : public CxxTest::TestSuite
{
public:
    void testDefaultConstructor(void)
    {
        Field field;

        TS_ASSERT_EQUALS(field.getWidth(), 1);
        TS_ASSERT_EQUALS(field.getHeight(), 1);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 0), false);

        //TS_ASSERT_EQUALS(1, 1);
    }

    void testConstructor(void)
    {
        Field field(5, 5);

        TS_ASSERT_EQUALS(field.getWidth(), 5);
        TS_ASSERT_EQUALS(field.getHeight(), 5);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 4), false);
        TS_ASSERT_EQUALS(field.hasBarrier(4, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(4, 4), false);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 2), false);
    }

    void testBigField(void)
    {
        Field field(50, 50);

        TS_ASSERT_EQUALS(field.getWidth(), 50);
        TS_ASSERT_EQUALS(field.getHeight(), 50);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 49), false);
        TS_ASSERT_EQUALS(field.hasBarrier(49, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(49, 49), false);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 2), false);
    }

    void testSettingBarriers(void)
    {
        Field field(3, 3);

        field.setBarrier(2, 2);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 2), true);

        field.setBarrier(1, 1);
        TS_ASSERT_EQUALS(field.hasBarrier(1, 1), true);

        field.setBarrier(0, 2);

        TS_ASSERT_EQUALS(field.hasBarrier(0, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 1), false);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 2), true);
        TS_ASSERT_EQUALS(field.hasBarrier(1, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(1, 1), true);
        TS_ASSERT_EQUALS(field.hasBarrier(1, 2), false);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 1), false);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 2), true);
    }

    void testRemovingBarriers(void)
    {
        Field field(3, 3);

        field.setBarrier(2, 2);
        field.setBarrier(1, 1);
        field.setBarrier(0, 0);
        field.setBarrier(0, 1);
        field.setBarrier(0, 2);

        field.removeBarrier(0, 2);
        field.removeBarrier(1, 1);
        field.removeBarrier(2, 2);


        TS_ASSERT_EQUALS(field.hasBarrier(0, 0), true);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 1), true);
        TS_ASSERT_EQUALS(field.hasBarrier(0, 2), false);
        TS_ASSERT_EQUALS(field.hasBarrier(1, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(1, 1), false);
        TS_ASSERT_EQUALS(field.hasBarrier(1, 2), false);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 0), false);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 1), false);
        TS_ASSERT_EQUALS(field.hasBarrier(2, 2), false);
    }
};
