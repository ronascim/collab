#ifndef _POINT_H_
#define _POINT_H_
#include <fstream>

class Point
{

public:
	Point(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	bool operator == (const Point &) const;
	bool operator != (const Point &) const;

private:
	int x;
	int y;


};
#endif