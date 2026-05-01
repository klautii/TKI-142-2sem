#include "Color.h"

using namespace std;

Color::Color(const int r, const int g, const int b) : r(r), g(g), b(b) {}

void Color::SetR(const int value) {
    if (value < 0 || value > 255) throw out_of_range("R must be 0-255");
    r = value;
}

void Color::SetG(const int value) {
    if (value < 0 || value > 255) throw out_of_range("G must be 0-255");
    g = value;
}

void Color::SetB(const int value) {
    if (value < 0 || value > 255) throw out_of_range("B must be 0-255");
    b = value;
}

ostream& operator<<(ostream& os, const Color& color) {
    os << "RGB(" << color.r << "," << color.g << "," << color.b << ")";
    return os;
}

istream& operator>>(istream& is, Color& color) {
    is >> color.r >> color.g >> color.b;
    return is;
}
