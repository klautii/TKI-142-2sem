#include "Point.h"
#include "Tetrahedron.h"
#include <iostream>
#include <locale>

using namespace std;

/**
* @brief Ввод координат точек с клавиатуры.
* @param message Сообщение перед вводом.
*/
Point getPoint(string message);

/**
* @brief Функция создания тетраэдра по четырем точкам.
*/
Tetrahedron getTetrahedron();

/**
* @brief Точка входа в программу.
* @return 0 в случае успешного завершения программы.
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    Tetrahedron tetra = getTetrahedron();
    tetra.printPoints();
    cout << "Объем тетраэдра: " << tetra.volume() << endl;
    return 0;
}

Point getPoint(string message)
{
    cout << message << endl;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "z = ";
    cin >> z;
    if (cin.fail())
    {
        throw invalid_argument("Введено некорректное значение");
    }

    return Point(x, y, z);
}

Tetrahedron getTetrahedron()
{
    Point P1 = getPoint("Введите координаты x, y и z для первой точки: ");
    Point P2 = getPoint("Введите координаты x, y и z для второй точки: ");
    Point P3 = getPoint("Введите координаты x, y и z для третьей точки: ");
    Point P4 = getPoint("Введите координаты x, y и z для четвертой точки: ");
    return Tetrahedron(P1, P2, P3, P4);
}