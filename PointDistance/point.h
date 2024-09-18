#pragma once
#include <cmath>
#include <iostream>

using namespace std;

namespace points
{
    class Point
    {
        private:
            int x;
            int y;
            Point* nearestPoint;

        public:
            //Constructor
            Point(int = 0, int = 0, Point* = nullptr);
            //Destructor
            ~Point();

            //Getters
            int getX();
            int getY();
            Point* getNearestPoint();

            //Setters
            void setX(int);
            void setY(int);
            void setNearestPoint(Point*);
            /*
            This method takes in the array of pointers to Point 
            and the array size. It returns a pointer to the Point that 
            is nearest to this
            */

            Point* calcNearestPoint(Point*[], unsigned long);

            /*
            This function takes in a Point and calculates 
            the cartesian distance between the passed in Point
            and this.

            Returns the distance as a double. 
            */
            double distPoints(Point&);
    };
}