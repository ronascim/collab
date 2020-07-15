#ifndef _POINT_H_
#define _POINT_H_
#include <fstream>

class Point
{

public:
	Point(int x, int y);
	int getX();
	int getY();


private:
	int x;
	int y;


};
#endif