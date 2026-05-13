#include "../decision/PriorityQueue.h"
#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    PriorityQueue pq1 = { {10, 3}, {20, 1}, {30, 5}, {40, 2} };
    cout << "Начальная очередь: " << pq1.toString() << endl;

    pq1.push(50, 4);
    pq1 << make_pair(60, 0);
    cout << "После добавления элементов: " << pq1.toString() << endl;

    int value;
    cout << "\nИзвлечение элементов с максимальным приоритетом:" << endl;
    while (pq1.popMax(value)) {
        cout << "Извлеченный максимум: " << value << endl;
    }

    cout << "\nОчередь пуста: " << boolalpha << pq1.isEmpty() << endl;

    PriorityQueue pq2;
    pq2.push(100, 10);
    pq2.push(200, 5);
    pq2.push(300, 20);
    cout << "\nВторая очередь: " << pq2.toString() << endl;


    if (pq2.peekMax(value)) {
        cout << "Текущий максимум: " << value << endl;
    }

    PriorityQueue pq3 = pq2;
    cout << "\nСкопированная очередь: " << pq3.toString() << endl;

    pair<int, int> element;
    pq3 >> element;
    cout << "Извлечено через оператор >>: (" << element.first << ", " << element.second << ")" << endl;

    return 0;
}
