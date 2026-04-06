#pragma once
#include "Point.h"

/**
 * @brief Класс, представляющий тетраэдр (треугольную пирамиду).
 */
class Tetrahedron
{
private:
    Point p1, p2, p3, p4;  // Четыре вершины тетраэдра

    /**
     * @brief Вычисляет площадь треугольника по трем точкам (формула Герона).
     * @param a Первая точка.
     * @param b Вторая точка.
     * @param c Третья точка.
     * @return Площадь треугольника.
     */
    double triangleArea(const Point& a, const Point& b, const Point& c) const;

    /**
     * @brief Вычисляет расстояние от точки до плоскости (высоту).
     * @param point Точка, от которой ищем расстояние.
     * @param a Первая точка плоскости.
     * @param b Вторая точка плоскости.
     * @param c Третья точка плоскости.
     * @return Расстояние от точки до плоскости.
     */
    double pointToPlaneDistance(const Point& point, const Point& a,
        const Point& b, const Point& c) const;

    /**
     * @brief Проверяет, лежат ли все четыре точки в одной плоскости.
     * @return true, если точки компланарны, иначе false.
     */
    bool areCoplanar() const;

    /**
     * @brief Проверяет, совпадают ли какие-либо точки.
     * @return true, если есть совпадающие точки, иначе false.
     */
    bool hasDuplicatePoints() const;

    /**
     * @brief Вычисляет объем тетраэдра по формуле V = (1/3) * S * h.
     * @return Объем тетраэдра.
     */
    double calculateVolume() const;

public:
    /**
     * @brief Конструктор для инициализации тетраэдра четырьмя точками.
     * @param p1 Первая вершина.
     * @param p2 Вторая вершина.
     * @param p3 Третья вершина.
     * @param p4 Четвертая вершина.
     */
    Tetrahedron(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    /**
     * @brief Вычисляет объем тетраэдра.
     * @return Объем тетраэдра.
     */
    double volume() const;

    /**
     * @brief Выводит координаты всех точек тетраэдра на экран.
     */
    void printPoints() const;
};