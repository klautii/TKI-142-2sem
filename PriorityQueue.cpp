#include "PriorityQueue.h"
#include <string>
#include <algorithm>

PriorityQueue::PriorityQueue() : head(nullptr), tail(nullptr), size(0) {}

PriorityQueue::PriorityQueue(std::initializer_list<std::pair<int, int>> initList) : PriorityQueue() {
    for (const auto& pair : initList) {
        push(pair.first, pair.second);
    }
}

PriorityQueue::PriorityQueue(const PriorityQueue& other) : PriorityQueue() {
    Node* current = other.head;
    while (current != nullptr) {
        push(current->value, current->priority);
        current = current->next;
    }
}

PriorityQueue::PriorityQueue(PriorityQueue&& other) noexcept
    : head(other.head), tail(other.tail), size(other.size) {
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

PriorityQueue::~PriorityQueue() {
    clear();
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            push(current->value, current->priority);
            current = current->next;
        }
    }
    return *this;
}

PriorityQueue& PriorityQueue::operator=(PriorityQueue&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        size = other.size;
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

PriorityQueue& PriorityQueue::operator<<(const std::pair<int, int>& element) {
    push(element.first, element.second);
    return *this;
}

PriorityQueue& PriorityQueue::operator>>(std::pair<int, int>& element) {
    if (!isEmpty()) {
        element.first = head->value;
        element.second = head->priority;
        popMax(element.first);
    }
    return *this;
}

void PriorityQueue::push(int value, int priority) {
    Node* newNode = new Node(priority);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->priority >= priority) {
            prev = current;
            current = current->next;
        }

        if (prev == nullptr) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (current == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = current;
            current->prev = newNode;
        }
    }
    size++;
}

bool PriorityQueue::popMax(int& value) {
    if (head == nullptr) {
        return false;
    }

    value = head->value;
    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete temp;
    size--;
    return true;
}

bool PriorityQueue::peekMax(int& value) const {
    if (isEmpty()) return false;
    value = head->value;
    return true;
}

bool PriorityQueue::peekMin(int& value) const {
    if (isEmpty()) return false;
    value = tail->value;
    return true;
}

bool PriorityQueue::isEmpty() const {
    return size == 0;
}

size_t PriorityQueue::getSize() const {
    return size;
}

std::string PriorityQueue::toString() const {
    std::string result;
    Node* current = head;
    while (current != nullptr) {
        result += "(" + std::to_string(current->value) + ", " +
            std::to_string(current->priority) + ")";
        if (current->next != nullptr) {
            result += " -> ";
        }
        current = current->next;
    }
    return result;
}

void PriorityQueue::clear() {
    while (!isEmpty()) {
        int temp;
        popMax(temp);
    }
}
