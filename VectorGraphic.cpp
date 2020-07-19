#include "VectorGraphic.h"
#include "Point.h"

//In constructor VectorGraphic, initialize topleft and bottom right coordinates
VectorGraphic::VectorGraphic() : topleft(0,0), bottomright(0,0)
{
}

//Destructor for VectorGraphic
VectorGraphic::~VectorGraphic()
{
}

//Method to add a coordinate to vector "myPath"
void VectorGraphic::addPoint(const Point& point)
{	
	//Save point to vector
	myPath.push_back(point);

	//Compare coordinate the top left and bottom right position  against current point (this->point)
	//Then if needed, then update width and height
	if (point.getX() < topleft.getX())
	{
		topleft.setX(point.getX());
	}
	else if (point.getX() > bottomright.getX()) 
	{
		bottomright.setX(point.getX());
	}

	if (point.getY() < topleft.getY())
	{
		topleft.setY(point.getY());
	}
	else if (point.getY() > bottomright.getY())
	{
		bottomright.setY(point.getY());
	}

}

//Method to remove a point (x,y) from vector of points "myPath"
void VectorGraphic::removePoint(const Point& p)
{
	//Use an iterator
	for (auto it = myPath.begin(); it != myPath.end();)
	{
		//p.getX represents my existent point "p". Compare if existing coordinates "p" is equal to coordinates 
		//stored in vector myPath
		if ( (   (p.getX() == (*it).getX() )) && ( (p.getY() == (*it).getY()) ) )
		{
			//Vector myPath will be changed
			myPath.erase(it);
		}
		else {
			//Increment iterator, if there is no point erased.
			it++;
		}
	}
}

//Method to erase a point based on the index information
void VectorGraphic::erasePoint(int index)
{
	//Erase point in vector "myPath" at position #index
	myPath.erase(myPath.begin() + index);
}

//Check if it is an open shape
void VectorGraphic::openShape()
{
	isopen = true;

}

//Method to set close shape condition
void VectorGraphic::closeShape()
{
	isopen = false;
}

//Get number of elements in vector of points "myPath"
int VectorGraphic::getPointCount() const
{
	return myPath.size();
}

//Get a given coordinate (x,y) based on index
Point VectorGraphic::getPoint(int index) const
{
	//Address exceptions here or in main. Ask
	return myPath[index];
}

//Calculate width upon top left coordinate change
int VectorGraphic::getWidth() const
{
	
	return bottomright.getX() - topleft.getX();
}

//Calculate height based on coordinate changes
int VectorGraphic::getHeight() const
{
	return bottomright.getY() - topleft.getY();
}

//Set is closed condition 
bool VectorGraphic::isClosed() const
{
	return !isopen;
}

//Set isopen condition
bool VectorGraphic::isOpen() const
{
	return isopen;
}
 

