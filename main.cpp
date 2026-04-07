#include "../decision/Point.h"
#include "../decision/Color.h"
#include "../decision/LineStyle.h"
#include "../decision/Line.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

void ShowLineTypeMenu() {
    cout << "\nВыберите тип линии:" << endl;
    cout << "1. Сплошная (solid)" << endl;
    cout << "2. Пунктирная (dash)" << endl;
    cout << "3. Точки (dot)" << endl;
    cout << "4. Точка-тире (dash-dot)" << endl;
    cout << "5. Две точки тире (dash-dot-dot)" << endl;
    cout << "Ваш выбор: ";
}

LineType GetLineTypeFromUser() {
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: return LineType::Solid;
    case 2: return LineType::Dash;
    case 3: return LineType::Dot;
    case 4: return LineType::DashDot;
    case 5: return LineType::DashDotDot;
    default:
        cout << "Неверный выбор. Используется сплошная линия." << endl;
        return LineType::Solid;
    }
}

void ShowMainMenu() {
    cout << "\n========== ГЛАВНОЕ МЕНЮ ==========" << endl;
    cout << "1. Создать новую линию" << endl;
    cout << "2. Показать информацию о линии" << endl;
    cout << "3. Изменить стиль линии" << endl;
    cout << "4. Изменить цвет линии" << endl;
    cout << "5. Демонстрация всех типов линий" << endl;
    cout << "6. Демонстрация всех цветов" << endl;
    cout << "7. Выйти" << endl;
    cout << "Ваш выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");

    Line* currentLine = nullptr;
    bool hasLine = false;

    cout << "=========================================" << endl;
    cout << "   ПРОГРАММА ДЛЯ РАБОТЫ С ЛИНИЯМИ" << endl;
    cout << "=========================================" << endl;

    try {
        cout << "\n>>> Создана линия по умолчанию (черная, сплошная, толщина 1):" << endl;
        Point defaultP1(10, 20);
        Point defaultP2(100, 200);
        Line defaultLine(defaultP1, defaultP2);
        defaultLine.Print();
        currentLine = &defaultLine;
        hasLine = true;

        while (true) {
            ShowMainMenu();
            int choice;
            cin >> choice;

            if (choice == 7) {
                cout << "\nДо свидания!" << endl;
                break;
            }

            switch (choice) {
            case 1: {
                cout << "\n--- СОЗДАНИЕ НОВОЙ ЛИНИИ ---" << endl;

                int x1, y1;
                cout << "Введите координаты начальной точки (x y): ";
                cin >> x1 >> y1;
                Point start(x1, y1);

                int x2, y2;
                cout << "Введите координаты конечной точки (x y): ";
                cin >> x2 >> y2;
                Point end(x2, y2);

                int r, g, b;
                cout << "Введите цвет в формате RGB (red green blue от 0 до 255): ";
                cin >> r >> g >> b;
                Color lineColor(r, g, b);

                ShowLineTypeMenu();
                LineType type = GetLineTypeFromUser();

                int thickness;
                cout << "Введите толщину линии (целое число > 0): ";
                cin >> thickness;
                LineStyle style(type, thickness);

                currentLine = new Line(start, end, lineColor, style);
                hasLine = true;

                cout << "\n✓ Линия успешно создана!" << endl;
                cout << "Созданная линия: " << *currentLine << endl;
                break;
            }

            case 2: {
                if (!hasLine || currentLine == nullptr) {
                    cout << "\nНет созданных линий!" << endl;
                    break;
                }

                cout << "\n--- ИНФОРМАЦИЯ О ТЕКУЩЕЙ ЛИНИИ ---" << endl;
                currentLine->Print();
                break;
            }

            case 3: {
                if (!hasLine || currentLine == nullptr) {
                    cout << "\nНет созданных линий! Сначала создайте линию." << endl;
                    break;
                }

                cout << "\n--- ИЗМЕНЕНИЕ СТИЛЯ ЛИНИИ ---" << endl;
                cout << "Текущий стиль: " << currentLine->GetStyle() << endl;

                ShowLineTypeMenu();
                LineType newType = GetLineTypeFromUser();

                int newThickness;
                cout << "Введите новую толщину линии: ";
                cin >> newThickness;

                LineStyle newStyle(newType, newThickness);
                currentLine->SetStyle(newStyle);

                cout << "\n✓ Стиль линии успешно изменен!" << endl;
                cout << "Новый стиль: " << currentLine->GetStyle() << endl;
                break;
            }

            case 4: {
                if (!hasLine || currentLine == nullptr) {
                    cout << "\nНет созданных линий! Сначала создайте линию." << endl;
                    break;
                }

                cout << "\n--- ИЗМЕНЕНИЕ ЦВЕТА ЛИНИИ ---" << endl;
                cout << "Текущий цвет: " << currentLine->GetColor() << endl;

                int r, g, b;
                cout << "Введите новый цвет в формате RGB (red green blue от 0 до 255): ";
                cin >> r >> g >> b;

                Color newColor(r, g, b);
                currentLine->SetColor(newColor);

                cout << "\n✓ Цвет линии успешно изменен!" << endl;
                cout << "Новый цвет: " << currentLine->GetColor() << endl;
                break;
            }

            case 5: {
                cout << "\n--- ДЕМОНСТРАЦИЯ ВСЕХ ТИПОВ ЛИНИЙ ---" << endl;

                LineStyle styles[] = {
                    LineStyle(LineType::Solid, 1),
                    LineStyle(LineType::Dash, 2),
                    LineStyle(LineType::Dot, 2),
                    LineStyle(LineType::DashDot, 2),
                    LineStyle(LineType::DashDotDot, 2)
                };

                string typeNames[] = {
                    "Сплошная (solid)",
                    "Пунктирная (dash)",
                    "Точки (dot)",
                    "Точка-тире (dash-dot)",
                    "Две точки тире (dash-dot-dot)"
                };

                for (int i = 0; i < 5; i++) {
                    Line demoLine(Point(0, i * 30), Point(150, i * 30), Color(100, 100, 100), styles[i]);
                    cout << typeNames[i] << " (толщина " << styles[i].GetThickness() << "): ";
                    cout << demoLine << endl;
                }
                break;
            }

            case 6: {
                cout << "\n--- ДЕМОНСТРАЦИЯ ВСЕХ ЦВЕТОВ ---" << endl;

                struct ColorInfo {
                    Color color;
                    string name;
                };

                ColorInfo colors[] = {
                    {Color(255, 0, 0), "Красный"},
                    {Color(0, 255, 0), "Зеленый"},
                    {Color(0, 0, 255), "Синий"},
                    {Color(255, 255, 0), "Желтый"},
                    {Color(255, 0, 255), "Пурпурный"},
                    {Color(0, 255, 255), "Голубой"},
                    {Color(255, 165, 0), "Оранжевый"},
                    {Color(128, 0, 128), "Фиолетовый"}
                };

                for (int i = 0; i < 8; i++) {
                    Line coloredLine(Point(i * 40, 400), Point(i * 40 + 60, 430), colors[i].color, LineStyle());
                    cout << colors[i].name << ": " << coloredLine << endl;
                }
                break;
            }

            default:
                cout << "\nНеверный выбор! Пожалуйста, выберите пункт от 1 до 7." << endl;
                break;
            }
        }

        if (currentLine != nullptr && currentLine != &defaultLine) {
            delete currentLine;
        }

    }
    catch (const exception& e) {
        cerr << "\nОшибка: " << e.what() << endl;
        return 1;
    }

    cout << "\nПрограмма завершена успешно!" << endl;
    return 0;
}