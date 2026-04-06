#pragma once

/**
 * @brief Класс, представляющий точку в трехмерном пространстве.
 */
class Point
{
private:
    double x, y, z;

public:
    /**
     * @brief Конструктор для инициализации точки.
     * @param x Координата x (по умолчанию 0).
     * @param y Координата y (по умолчанию 0).
     * @param z Координата z (по умолчанию 0).
     */
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    /**
     * @brief Возвращает координату x.
     * @return Значение координаты x.
     */
    double getX() const;

    /**
     * @brief Возвращает координату y.
     * @return Значение координаты y.
     */
    double getY() const;

    /**
     * @brief Возвращает координату z.
     * @return Значение координаты z.
     */
    double getZ() const;

    /**
     * @brief Выводит координаты точки на экран.
     */
    void print() const;

    /**
     * @brief Вычисляет расстояние между двумя точками.
     * @param other Другая точка.
     * @return Расстояние между точками.
     */
    double distanceTo(const Point& other) const;

    /**
     * @brief Оператор вычитания точек.
     * @param other Другая точка.
     * @return Вектор-разность.
     */
    Point operator-(const Point& other) const;
};

/**
 * @brief Оператор сравнения точек.
 * @param p1 Первая точка.
 * @param p2 Вторая точка.
 * @return true, если точки совпадают, иначе false.
 */
bool operator==(const Point& p1, const Point& p2);

/**
 * @brief Оператор сравнения точек.
 * @param p1 Первая точка.
 * @param p2 Вторая точка.
 * @return true, если точки не совпадают, иначе false.
 */
bool operator!=(const Point& p1, const Point& p2);