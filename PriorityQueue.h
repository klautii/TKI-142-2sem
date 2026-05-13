#pragma once﻿
#include <initializer_list>
#include <utility>
#include <string>

using namespace std;

class PriorityQueue {
private:
    /**
     * @brief Узел очереди
     */
    struct Node {
        int value = 0;
        int priority;
        Node* next;
        Node* prev;

        /**
         * @brief Конструктор узла
         * @param val Значение элемента
         * @param prio Приоритет элемента
         */
        Node(const int prio) : priority(prio), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:

    /**
     * @brief Конструктор по умолчанию
     */
    PriorityQueue();

    /**
     * @brief Конструктор из списка инициализации
     * @param initList Список пар {значение, приоритет} для инициализации
     */
    PriorityQueue(const initializer_list<pair<int, int>> initList);

    /**
     * @brief Конструктор копирования
     * @param other Очередь для копирования
     */
    PriorityQueue(const PriorityQueue& other);

    /**
    * @brief Конструктор перемещения
    * @param other Очередь для перемещения
    */
    PriorityQueue(PriorityQueue&& other) noexcept;

    /**
     * @brief Деструктор
     */
    ~PriorityQueue();

    /**
     * @brief Оператор присваивания копированием
     * @param other Очередь для копирования
     * @return Ссылка на текущий объект
     */
    PriorityQueue& operator=(const PriorityQueue& other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other Очередь для перемещения
     * @return Ссылка на текущий объект
     */
    PriorityQueue& operator=(PriorityQueue&& other) noexcept;

    /**
     * @brief Оператор вставки элемента
     * @param element Пара {значение, приоритет} для вставки
     * @return Ссылка на текущий объект
     */
    PriorityQueue& operator<<(const pair<int, int>& element);

    /**
     * @brief Оператор извлечения элемента с максимальным приоритетом
     * @param element Ссылка для сохранения извлеченного элемента
     * @return Ссылка на текущий объект
     */
    PriorityQueue& operator>>(pair<int, int>& element);

    /**
     * @brief Добавление элемента в очередь
     * @param value Значение элемента
     * @param priority Приоритет элемента
     */
    void push(const int value, int priority);

    /**
     * @brief Извлечение элемента с максимальным приоритетом
     * @param value Ссылка для сохранения извлеченного значения
     * @return true если элемент был извлечен, false если очередь пуста
     */
    bool popMax(int& value);

    /**
     * @brief Просмотр элемента с максимальным приоритетом без извлечения
     * @param value Ссылка для сохранения значения
     * @return true если элемент существует, false если очередь пуста
     */
    bool peekMax(int& value) const;

    /**
     * @brief Просмотр элемента с минимальным приоритетом без извлечения
     * @param value Ссылка для сохранения значения
     * @return true если элемент существует, false если очередь пуста
     */
    bool peekMin(int& value) const;

    /**
    * @brief Проверка очереди на пустоту
    * @return true если очередь пуста, false в противном случае
    */
    bool isEmpty() const;

    /**
     * @brief Получение текущего размера очереди
     * @return Количество элементов в очереди
     */
    size_t getSize() const;

    /**
     * @brief Преобразование очереди в строку
     * @return Строковое представление очереди
     */
    string toString() const;

    /**
     * @brief Очистка очереди
     */
    void clear();
};
