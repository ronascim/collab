#include "Point.h"
#include "VectorGraphic.h"
#include "TestHarness.h"
#include "Serialization.h"


TEST(vector, VectorGraphic)
{
    VectorGraphic vg;
    //VectorGraphic::VectorGraphic vg;

    CHECK_EQUAL(0, vg.getPointCount());
    CHECK_EQUAL(true, vg.isClosed());
    CHECK_EQUAL(false, vg.isOpen());
}

TEST(insertPoint, VectorGraphic)
{
    VectorGraphic vg;
    vg.addPoint(Point{ 1, 1 });
    CHECK_EQUAL(1, vg.getPointCount());

    vg.addPoint(Point{ 2, 2 });
    CHECK_EQUAL(2, vg.getPointCount());
}

TEST(removePoint, VectorGraphic)
{
    VectorGraphic vg;
    vg.addPoint(Point{ 1, 1 });
    vg.addPoint(Point{ 2, 2 });
    vg.removePoint(Point{ 1, 1 });

    CHECK_EQUAL(1, vg.getPointCount());
    CHECK_EQUAL(Point(2, 2), vg.getPoint(0));
}

TEST(erasePoint, VectorGraphic)
{
    VectorGraphic vg;
    vg.addPoint(Point{ 1, 1 });
    vg.addPoint(Point{ 2, 2 });
    vg.addPoint(Point{ 3, 3 });
    vg.erasePoint(1);

    CHECK_EQUAL(2, vg.getPointCount());
    CHECK_EQUAL(Point(1, 1), vg.getPoint(0));
    CHECK_EQUAL(Point(3, 3), vg.getPoint(1));
}

TEST(erasePointOutOfRange, VectorGraphic)
{
    VectorGraphic vg;
    vg.addPoint(Point{ 1, 1 });
    vg.addPoint(Point{ 2, 2 });
    vg.addPoint(Point{ 3, 3 });

    try
    {
        vg.erasePoint(5);
    }
    catch (std::out_of_range&)
    {
        CHECK_EQUAL(3, vg.getPointCount());
        return;
    }
    CHECK(false); // should have caught exception
}

TEST(equality, VectorGraphic)
{
    VectorGraphic vg1;
    vg1.addPoint(Point{ 1, 1 });
    vg1.addPoint(Point{ 2, 2 });
    vg1.addPoint(Point{ 3, 3 });

    VectorGraphic vg2;
    vg2.addPoint(Point{ 1, 1 });
    vg2.addPoint(Point{ 2, 2 });
    vg2.addPoint(Point{ 3, 3 });

    //CHECK(vg1 == vg2);
}

TEST(inequality, VectorGraphic)
{
    VectorGraphic vg1;
    vg1.addPoint(Point{ 1, 1 });
    vg1.addPoint(Point{ 1, 2 });
    vg1.addPoint(Point{ 1, 3 });

    VectorGraphic vg2;
    vg2.addPoint(Point{ 2, 1 });
    vg2.addPoint(Point{ 2, 2 });
    vg2.addPoint(Point{ 2, 3 });

   // CHECK(vg1 != vg2);

    VectorGraphic vg3;
    vg3.addPoint(Point{ 1, 1 });
    vg3.addPoint(Point{ 1, 2 });
    vg3.addPoint(Point{ 1, 3 });
    vg3.openShape();

   // CHECK(vg3 != vg1);
}

TEST(closeShape, VectorGraphic)
{
    VectorGraphic vg;
    vg.closeShape();
    CHECK_EQUAL(true, vg.isClosed());
    CHECK_EQUAL(false, vg.isOpen());
}

TEST(openShape, VectorGraphic)
{
    VectorGraphic vg;
    vg.openShape();
    CHECK_EQUAL(false, vg.isClosed());
    CHECK_EQUAL(true, vg.isOpen());
}

TEST(widthHeight, VectorGraphic)
{
    VectorGraphic vectorGraphic;
    vectorGraphic.addPoint(Point{ 0, 2 });
    vectorGraphic.addPoint(Point{ 4, 3 });
    vectorGraphic.addPoint(Point{ 5, 8 });
    vectorGraphic.addPoint(Point{ 2, 1 });
    CHECK_EQUAL(5, vectorGraphic.getWidth());
    CHECK_EQUAL(7, vectorGraphic.getHeight());

    vectorGraphic.erasePoint(2);
    CHECK_EQUAL(4, vectorGraphic.getWidth());
    CHECK_EQUAL(2, vectorGraphic.getHeight());
}

// C++11 has a new "raw string literal" that is useful for
// embedding long strings in a file for testing. Previously
// this would have to be done with a "stringification" macro:
//   #define STR(a) #a

const std::string VectorGraphicXml = R"(
<VectorGraphic closed="true">
<Point x="0" y="0"/>
<Point x="10" y="0">
</Point>
<Point x="10" y="10"/>
<Point x="0" y="10"/>
</VectorGraphic>
)";

TEST(fromXml, VectorGraphic)
{
    std::stringstream sstr(VectorGraphicXml);

    auto vg = VectorGraphicStreamer::fromXml(sstr);

    CHECK_EQUAL(true, vg.isClosed());
    CHECK_EQUAL(4, vg.getPointCount());
    CHECK_EQUAL(10, vg.getPoint(2).getX());
    CHECK_EQUAL(10, vg.getPoint(2).getY());
}



TEST(toXml, VectorGraphic)
{
    VectorGraphic vg1;
    vg1.addPoint(Point(1, 1));
    vg1.addPoint(Point(2, 2));
    vg1.addPoint(Point(3, 3));

    std::stringstream sstr;
    VectorGraphicStreamer::toXml(vg1, sstr);

    auto vg2 = VectorGraphicStreamer::fromXml(sstr);

    CHECK(vg1 == vg2);
}
