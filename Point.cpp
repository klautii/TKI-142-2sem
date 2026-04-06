#include "Point.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }

void Point::print() const
{
    cout << "(" << x << ", " << y << ", " << z << ")";
}

double Point::distanceTo(const Point& other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

Point Point::operator-(const Point& other) const
{
    return Point(x - other.x, y - other.y, z - other.z);
}

bool operator==(const Point& p1, const Point& p2)
{
    return abs(p1.getX() - p2.getX()) <= numeric_limits<double>::epsilon() &&
        abs(p1.getY() - p2.getY()) <= numeric_limits<double>::epsilon() &&
        abs(p1.getZ() - p2.getZ()) <= numeric_limits<double>::epsilon();
}

bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1 == p2);
}