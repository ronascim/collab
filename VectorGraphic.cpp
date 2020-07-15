#include "VectorGraphic.h"
#include "Point.h"

VectorGraphic::VectorGraphic()
{


}

VectorGraphic::~VectorGraphic()
{
}


void VectorGraphic::addPoint(const Point& point)
{	
	//Save point to vector
	myPath.push_back(point);

	//Compare coordinate the top left and bottom right position  against current point (this->point)
	//Then if needed, then update width and height
}

void VectorGraphic::removePoint(const Point& p)
{
	std::remove(myPath.begin(), myPath.end(), p);
}

void VectorGraphic::erasePoint(int index)
{
	myPath.erase(myPath.begin() + index);
}

void VectorGraphic::openShape()
{
	isopen = true;

}

void VectorGraphic::closeShape()
{
	isopen = false;
}

int VectorGraphic::getPointCount() const
{
	return myPath.size();
}

Point VectorGraphic::getPoint(int index) const
{
	//Address exceptions here or in main. Ask
	return myPath[index];
}

int VectorGraphic::getWidth() const
{
	
	return this->width;
}

int VectorGraphic::getHeight() const
{
	return this->height;
}

bool VectorGraphic::isClosed() const
{
	return true;
}

bool VectorGraphic::isOpen() const
{
	return true;
}
 

