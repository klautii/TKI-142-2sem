#include "Tetrahedron.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

Tetrahedron::Tetrahedron(const Point& p1, const Point& p2,
    const Point& p3, const Point& p4)
    : p1(p1), p2(p2), p3(p3), p4(p4)
{
    if (hasDuplicatePoints())
    {
        cout << "Некоторые точки совпадают!" << endl;
        exit(1);
    }

    if (areCoplanar())
    {
        cout << "Все точки лежат в одной плоскости! Тетраэдр не может быть построен." << endl;
        exit(1);
    }
}

double Tetrahedron::triangleArea(const Point& a, const Point& b, const Point& c) const
{
    double ab = a.distanceTo(b);
    double bc = b.distanceTo(c);
    double ca = c.distanceTo(a);

    double p = (ab + bc + ca) / 2.0;

    return sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

double Tetrahedron::pointToPlaneDistance(const Point& point, const Point& a,
    const Point& b, const Point& c) const
{
    Point ab = b - a;
    Point ac = c - a;

    double nx = ab.getY() * ac.getZ() - ab.getZ() * ac.getY();
    double ny = ab.getZ() * ac.getX() - ab.getX() * ac.getZ();
    double nz = ab.getX() * ac.getY() - ab.getY() * ac.getX();

    double normalLength = sqrt(nx * nx + ny * ny + nz * nz);

    // Используем epsilon для сравнения с нулем
    if (normalLength < numeric_limits<double>::epsilon())
    {
        return 0.0;
    }

    Point ap = point - a;

    double distance = abs(ap.getX() * nx + ap.getY() * ny + ap.getZ() * nz) / normalLength;

    return distance;
}

bool Tetrahedron::areCoplanar() const
{
    double height = pointToPlaneDistance(p4, p1, p2, p3);
    // Используем epsilon для проверки на нуль
    return height < numeric_limits<double>::epsilon();
}

bool Tetrahedron::hasDuplicatePoints() const
{
    // Используем оператор != который уже использует epsilon для сравнения
    return (p1 == p2) || (p1 == p3) || (p1 == p4) ||
        (p2 == p3) || (p2 == p4) || (p3 == p4);
}

double Tetrahedron::calculateVolume() const
{
    double baseArea = triangleArea(p1, p2, p3);
    double height = pointToPlaneDistance(p4, p1, p2, p3);

    return (1.0 / 3.0) * baseArea * height;
}

double Tetrahedron::volume() const
{
    return calculateVolume();
}

void Tetrahedron::printPoints() const
{
    cout << "Вершины тетраэдра:" << endl;
    cout << "  P1: "; p1.print(); cout << endl;
    cout << "  P2: "; p2.print(); cout << endl;
    cout << "  P3: "; p3.print(); cout << endl;
    cout << "  P4: "; p4.print(); cout << endl;
}