#include "PriorityQueue.h"
#include <stdexcept>
#include <sstream>

PriorityQueue::PriorityQueue() : head(nullptr), tail(nullptr), size(0) {}

PriorityQueue::PriorityQueue(initializer_list<pair<int, int>> initList) 
    : head(nullptr), tail(nullptr), size(0) {
    for (const auto& item : initList) {
        push(item.first, item.second);
    }
}

PriorityQueue::PriorityQueue(const PriorityQueue& other) 
    : head(nullptr), tail(nullptr), size(0) {
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

void PriorityQueue::push(int value, int priority) {
    Node* newNode = new Node(value, priority);
    
    if (isEmpty()) {
        head = tail = newNode;
    } else if (priority > head->priority) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (priority <= tail->priority) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        Node* current = head;
        while (current != nullptr && current->priority > priority) {
            current = current->next;
        }
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    size++;
}

PriorityQueue& PriorityQueue::operator<<(const pair<int, int>& element) {
    push(element.first, element.second);
    return *this;
}

bool PriorityQueue::popMax(int& value) {
    if (isEmpty()) {
        return false;
    }
    
    value = head->value;
    Node* temp = head;
    head = head->next;
    
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    
    delete temp;
    size--;
    return true;
}

PriorityQueue& PriorityQueue::operator>>(pair<int, int>& element) {
    if (isEmpty()) {
        throw runtime_error("Cannot extract from empty queue");
    }
    
    element.first = head->value;
    element.second = head->priority;
    popMax(element.first);
    return *this;
}

bool PriorityQueue::peekMax(int& value) const {
    if (isEmpty()) {
        return false;
    }
    value = head->value;
    return true;
}

bool PriorityQueue::peekMin(int& value) const {
    if (isEmpty()) {
        return false;
    }
    value = tail->value;
    return true;
}

bool PriorityQueue::isEmpty() const {
    return size == 0;
}

size_t PriorityQueue::getSize() const {
    return size;
}

string PriorityQueue::toString() const {
    stringstream ss;
    ss << "[";
    Node* current = head;
    while (current != nullptr) {
        ss << "(" << current->value << "," << current->priority << ")";
        if (current->next != nullptr) {
            ss << " ";
        }
        current = current->next;
    }
    ss << "]";
    return ss.str();
}

void PriorityQueue::clear() {
    while (!isEmpty()) {
        int dummy;
        popMax(dummy);
    }
}
