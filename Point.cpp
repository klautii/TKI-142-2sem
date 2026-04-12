#include "Point.h"

using namespace std;

Point::Point(int x, int y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

istream& operator>>(istream& is, Point& p) {
    while (!(is >> p.x >> p.y)) {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Enter coordinates again (x y): ";
    }
    return is;
}
