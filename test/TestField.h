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
};
