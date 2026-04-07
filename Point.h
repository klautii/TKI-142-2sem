#pragma once
#include <iostream>
#include <limits>

using namespace std;

/**
 * @brief Класс для работы с точками на плоскости.
 * Хранит координаты точки и предоставляет основные операции:
 * сравнение, ввод/вывод.
 */
class Point {
public:
    int x, y;

    /**
     * @brief Конструктор точки
     * @param x Координата X (по умолчанию 0)
     * @param y Координата Y (по умолчанию 0)
     */
    Point(int x = 0, int y = 0);

    /**
     * @brief Оператор сравнения точек на равенство.
     * @param other Точка для сравнения.
     * @return true если точки идентичны.
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор сравнения точек на неравенство.
     * @param other Точка для сравнения.
     * @return true если точки различаются.
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор вывода точки в поток.
     * @param os Выходной поток.
     * @param p Точка для вывода.
     * @return Поток после вывода.
     */
    friend ostream& operator<<(ostream& os, const Point& p);

    /**
     * @brief Оператор ввода точки из потока.
     * @param is Входной поток.
     * @param p Точка для заполнения.
     * @return Поток после ввода.
     */
    friend istream& operator>>(istream& is, Point& p);
};