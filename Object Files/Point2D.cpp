#include <iostream>
#include <math.h>
#include "Point2D.h"
using namespace std;

Point2D::Point2D()
{
    x = 0.0;
    y = 0.0;
}

Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    return sqrt((pow(p1.x - p2.x, 2.0))+pow(p1.y - p2.y, 2.0));
}

bool operator == (Point2D p1, Point2D p2)
{
    if(p1.x == p2.x && p1.y == p2.y)
    {
        return true;
    }
    return false;
}

ostream& operator << (ostream& out, Point2D p1)
{
    out << "(" << p1.x << "," << p1.y << ")";
    return out;
}

Point2D operator + (Point2D p1, Vector2D p2)
{
    return Point2D(p1.x + p2.x, p1.y + p2.y);
}

Vector2D operator - (Point2D p1, Point2D p2)
{
    return Vector2D(p1.x - p2.x, p1.y - p2.y);
}













