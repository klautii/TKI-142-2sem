#pragma once
#include "Point.h"
#include "Color.h"
#include "LineStyle.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Класс линии, заданной двумя точками.
 */
class Line {
private:
    Point start;
    Point end;
    Color color;
    LineStyle style;

public:
    /**
     * @brief Конструктор линии с указанием стиля и цвета.
     * @param start Начальная точка.
     * @param end Конечная точка.
     * @param color Цвет линии.
     * @param style Стиль линии.
     */
    Line(const Point& start, const Point& end, const Color& color, const LineStyle& style);

    /**
     * @brief Конструктор линии со стилем и цветом по умолчанию.
     * @param start Начальная точка.
     * @param end Конечная точка.
     */
    Line(const Point& start, const Point& end);

    /**
     * @brief Изменить стиль линии.
     * @param newStyle Новый стиль.
     */
    void SetStyle(const LineStyle& newStyle) { style = newStyle; }

    /**
     * @brief Изменить цвет линии.
     * @param newColor Новый цвет.
     */
    void SetColor(const Color& newColor) { color = newColor; }

    /**
     * @brief Получить стиль линии.
     * @return Текущий стиль.
     */
    LineStyle GetStyle() const { return style; }

    /**
     * @brief Получить цвет линии.
     * @return Текущий цвет.
     */
    Color GetColor() const { return color; }

    /**
     * @brief Получить начальную точку.
     * @return Начальная точка.
     */
    Point GetStart() const { return start; }

    /**
     * @brief Получить конечную точку.
     * @return Конечная точка.
     */
    Point GetEnd() const { return end; }

    /**
     * @brief Преобразовать линию в строку.
     * @return Строковое представление линии.
     */
    string ToString() const;

    /**
     * @brief Вывести информацию о линии.
     */
    void Print() const;

    /**
     * @brief Статический метод чтения линии из потока.
     * @param is Входной поток.
     * @return Объект Line.
     * @throw runtime_error При ошибках ввода.
     */
    static Line ReadFromStream(istream& is);

    /**
     * @brief Оператор вывода линии в поток.
     * @param os Выходной поток.
     * @param line Линия для вывода.
     * @return Поток после вывода.
     */
    friend ostream& operator<<(ostream& os, const Line& line);
};
