#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @brief Класс цвета с компонентами RGB.
 * Каждый компонент хранится в диапазоне 0-255.
 */
class Color {
private:
    unsigned int red;  
    unsigned int green;  
    unsigned int blue;

public:
    /**
     * @brief Конструктор цвета.
     * @param r Красный компонент (0-255)
     * @param g Зеленый компонент (0-255)
     * @param b Синий компонент (0-255)
     * @throw out_of_range Если значения выходят за пределы 0-255
     */
    Color(int r, int g, int b);

    /**
     * @brief Получить красный компонент.
     * @return Значение красного компонента.
     */
    unsigned int GetRed() const { return red; }

    /**
     * @brief Получить зеленый компонент.
     * @return Значение зеленого компонента.
     */
    unsigned int GetGreen() const { return green; }

    /**
     * @brief Получить синий компонент.
     * @return Значение синего компонента.
     */
    unsigned int GetBlue() const { return blue; }

    /**
     * @brief Оператор вывода цвета в поток.
     * @param os Выходной поток.
     * @param color Цвет для вывода.
     * @return Поток после вывода.
     */
    friend ostream& operator<<(ostream& os, const Color& color);

    /**
     * @brief Оператор ввода цвета из потока.
     * @param is Входной поток.
     * @param color Цвет для заполнения.
     * @return Поток после ввода.
     */
    friend istream& operator>>(istream& is, Color& color);
};