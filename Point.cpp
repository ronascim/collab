#include "Point.h"

Point::Point(int x, int y) 
{
	this->x = x;
	this->y = y;
	Point{ 0,0 };
}

int Point::getX() const
{
	return this->x;
}

int Point::getY() const
{
	return this->y;

}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

bool Point::operator==(const Point& p) const
{

	if (((this->getX() == p.getX()) && ((this->getY() == p.getY()))))
		return true;
	return false;

}

bool Point::operator!=(const Point& p) const
{
	if (((this->getX() == p.getX()) && ((this->getY() == p.getY()))))
		return false;
	return true;
	
}


