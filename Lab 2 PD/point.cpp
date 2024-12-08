#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint)
{
    //comment was dumb, watch the cases
    x = X;
    y = Y;
    nearestPoint = closestPoint;
}

//Destructor
points::Point::~Point()
{
 // lets figure out dynamic allocating memory
}

//Getters
int points::Point::getX()
{
    return x; //return the actual X value
}

int points::Point::getY()
{
    return y; //return the actual Y value
}
// small cases = happy
points::Point* points::Point::getNearestPoint()
{
    return nearestPoint; //return nearest pt
}

// layers: Calc pt from list of pts. array of pointers to Pt objects. Returns the ptr nrst pt
// should be the bulk.. does that mean i can exceed 1-3 lines lol
points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{
    if (arrSize == 0) {
        return nullptr; // Handle empty list, but like is that even necessary or am I making my code too long
    }

    Point* nearest = nullptr;//CHECK* should you declare a point, hella reduce girl, each one needs to have 1-3 lines smh
    double nearestDist = std::numeric_limits<double>::max(); // Max value for init

    for (size_t i = 0; i < arrSize; i++) {
        if (pointList[i] != this) {
            double dist = distPoints(*pointList[i]); // calc distance

            if (dist < nearestDist) {
                nearestDist = dist;
                nearest = pointList[i];
            }
        }
    }

    setNearestPoint(nearest); // Save the nearest point
    return nearest; // i genuinely dislike the code i typed for this
}

//Setters (x cord)
void points::Point::setX(int newVal)
{
    x = newVal;
}

//(y cord)
void points::Point::setY(int newVal)
{
    y = newVal;
}

//nrst pt to this one
void points::Point::setNearestPoint(Point* newNearestPoint)
{
    nearestPoint = newNearestPoint;
}

//Calc distance btwn pt and another, point: A reference
// Returns the distance btn the 2 pts.
double points::Point::distPoints(Point& point)
{
    int dx = x - point.getX();
    int dy = y - point.getY();// let's use my previous math degree to use lets go
    return dx*dx + dy*dy; //return the squared distance
}