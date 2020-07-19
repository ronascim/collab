#include "Point.h"
#include "TestHarness.h"


TEST(equality, Point)
{
    CHECK_EQUAL(Point(1, 2), Point(1, 2));
}

TEST(inequality, Point)
{
    CHECK(Point(1, 2) != Point(3, 4));
}

TEST(constexprPoint, Point)
{
    constexpr int i = Point{ 4, 5 }.getX();

    CHECK_EQUAL(i, 4);
}


