#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
//set this->X = X, this->Y = Y
}
//Destructor
points::Point::~Point()
{

}

//Getters
int points::Point::getX()
{
    return 0; //return the actual X value
}

int points::Point::getY()
{
    return 0; //return the actual Y value
}

points::Point* points::Point::getNearestPoint()
{
    return nullptr; //return nearest pt
}
// layers: Calc pt from list of pts. array of pointers to Pt objects. Returns the ptr nrst pt
points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    return nullptr;
}

//Setters (x cord)
void points::Point::setX(int newVal)
{

}
//(y cord)
void points::Point::setY(int newVal)
{

}
//nrst pt to this one
void points::Point::setNearestPoint(Point* newNearestPoint)
{

}
//Calc distance btwn pt and another, point: A reference
// Returns the distance btn the 2 pts.
double points::Point::distPoints(Point& point)
{
    return 0.0;//return the actual distance
}