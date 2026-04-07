#include "Line.h"
#include <sstream>
#include <limits>

using namespace std;

Line::Line(const Point& start, const Point& end, const Color& color, const LineStyle& style)
    : start(start), end(end), color(color), style(style) {
}

Line::Line(const Point& start, const Point& end)
    : start(start), end(end), color(0, 0, 0), style() {
}

string Line::ToString() const {
    ostringstream oss;
    oss << "Линия: " << start << " -> " << end
        << ", Цвет: " << color
        << ", " << style;
    return oss.str();
}

void Line::Print() const {
    cout << ToString() << endl;
}

Line Line::ReadFromStream(istream& is) {
    Point start, end;
    Color color(0, 0, 0);
    LineStyle style;

    cout << "Введите начальную точку (x y): ";
    is >> start;

    cout << "Введите конечную точку (x y): ";
    is >> end;

    cout << "Введите цвет (красный зеленый синий): ";
    is >> color;

    cout << "Введите стиль линии (тип толщина) [solid/dash/dot/dash-dot/dash-dot-dot]: ";
    is >> style;

    return Line(start, end, color, style);
}

ostream& operator<<(ostream& os, const Line& line) {
    os << line.ToString();
    return os;
}