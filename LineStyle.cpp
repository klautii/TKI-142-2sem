#include "LineStyle.h"
#include <limits>
#include <stdexcept>

using namespace std;

LineStyle::LineStyle() : type(LineType::Solid), thickness(1) {}

LineStyle::LineStyle(const LineType t, const int thick) : type(t) {
    SetThickness(thick);
}

void LineStyle::SetType(const LineType t) {
    type = t;
}

void LineStyle::SetThickness(const int thick) {
    if (thick <= 0) {
        throw invalid_argument("Толщина должна быть больше 0");
    }
    thickness = thick;
}

string LineStyle::TypeToString() const {
    switch (type) {
    case LineType::Solid:     return "solid (сплошная)";
    case LineType::Dash:      return "dash (пунктирная)";
    case LineType::Dot:       return "dot (точки)";
    case LineType::DashDot:   return "dash-dot (точка-тире)";
    case LineType::DashDotDot:return "dash-dot-dot (две точки тире)";
    default:                  return "неизвестно";
    }
}

ostream& operator<<(ostream& os, const LineStyle& style) {
    os << "Стиль линии{" << style.TypeToString() << ", толщина=" << style.thickness << "}";
    return os;
}

istream& operator>>(istream& is, LineStyle& style) {
    string typeStr;
    int thick;

    while (!(is >> typeStr >> thick)) {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Неверный ввод. Введите тип линии и толщину: ";
    }

    LineType type;
    if (typeStr == "solid" || typeStr == "сплошная") type = LineType::Solid;
    else if (typeStr == "dash" || typeStr == "пунктирная") type = LineType::Dash;
    else if (typeStr == "dot" || typeStr == "точки") type = LineType::Dot;
    else if (typeStr == "dash-dot" || typeStr == "точка-тире") type = LineType::DashDot;
    else if (typeStr == "dash-dot-dot" || typeStr == "две точки тире") type = LineType::DashDotDot;
    else {
        throw invalid_argument("Неизвестный тип линии: " + typeStr);
    }

    style = LineStyle(type, thick);
    return is;
}
