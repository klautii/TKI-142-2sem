#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Перечисление типов линий.
 */
enum class LineType {
    Solid,      // сплошная
    Dash,       // пунктирная
    Dot,        // точки
    DashDot,    // точка-тире
    DashDotDot  // две точки тире
};

/**
 * @brief Класс стиля линии.
 * Содержит тип линии и толщину.
 */
class LineStyle {
private:
    LineType type;
    int thickness;  // целое число больше нуля

public:
    /**
     * @brief Конструктор стиля линии по умолчанию.
     * Тип: Solid, толщина: 1.
     */
    LineStyle();

    /**
     * @brief Конструктор стиля линии.
     * @param t Тип линии.
     * @param thick Толщина линии (>0).
     * @throw invalid_argument Если толщина <= 0.
     */
    LineStyle(LineType t, int thick);

    /**
     * @brief Получить тип линии.
     * @return Тип линии.
     */
    LineType GetType() const { return type; }

    /**
     * @brief Получить толщину линии.
     * @return Толщина линии.
     */
    int GetThickness() const { return thickness; }

    /**
     * @brief Установить тип линии.
     * @param t Новый тип линии.
     */
    void SetType(LineType t) { type = t; }

    /**
     * @brief Установить толщину линии.
     * @param thick Новая толщина (>0).
     * @throw invalid_argument Если толщина <= 0.
     */
    void SetThickness(int thick);

    /**
     * @brief Преобразовать тип линии в строку.
     * @return Строковое представление типа линии.
     */
    string TypeToString() const;

    /**
     * @brief Оператор вывода стиля линии в поток.
     * @param os Выходной поток.
     * @param style Стиль линии.
     * @return Поток после вывода.
     */
    friend ostream& operator<<(ostream& os, const LineStyle& style);

    /**
     * @brief Оператор ввода стиля линии из потока.
     * @param is Входной поток.
     * @param style Стиль линии.
     * @return Поток после ввода.
     */
    friend istream& operator>>(istream& is, LineStyle& style);
};