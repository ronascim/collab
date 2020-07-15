#ifndef _VECTORGRAPHIC_H_
#define _VECTORGRAPHIC_H_
#include "Point.h"
#include "Serialization.h"

#include <vector>

using Points = std::vector<Point>;
class VectorGraphic
{
public:
    VectorGraphic();
    ~VectorGraphic();

    void addPoint(const Point& p);
    void removePoint(const Point& p);
    void erasePoint(int index);

    void openShape();
    void closeShape();

    bool isOpen() const;
    bool isClosed() const;

    int getWidth() const;
    int getHeight() const;

    int getPointCount() const;
    Point getPoint(int index) const; //<== Can I make this a reference?

private:
    Points myPath;
    int width;
    int height;
    bool isopen;

};

#endif
