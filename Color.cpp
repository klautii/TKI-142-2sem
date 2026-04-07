#include "Color.h"

using namespace std;

Color::Color(int r, int g, int b) {
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        throw out_of_range("Компоненты цвета должны быть в диапазоне от 0 до 255");
    }
    red = static_cast<unsigned int>(r);
    green = static_cast<unsigned int>(g);
    blue = static_cast<unsigned int>(b);
}

ostream& operator<<(ostream& os, const Color& color) {
    os << "RGB(" << color.red << ", " << color.green << ", " << color.blue << ")";
    return os;
}

istream& operator>>(istream& is, Color& color) {
    int r, g, b;
    while (!(is >> r >> g >> b)) {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Неверный ввод. Введите значения RGB (красный зеленый синий): ";
    }
    color = Color(r, g, b);
    return is;
}