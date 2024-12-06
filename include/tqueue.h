#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
    std::vector<T> data;
    size_t head = 0;
    size_t tail = 0;
    size_t size = 0;
    size_t capacity;
    T last_element;

public:
    Queue(size_t capacity) : capacity(capacity), data(capacity) {}

    bool isFull() const { 
        return size == capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size; 
    }

    void push(const T& item) {
        if (isFull()) {
            throw std::runtime_error("Queue is full!");
        }
        data[tail] = item;
        tail = (tail + 1) % capacity;
        size++;
        last_element = item;
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty!");
        }
        head = (head + 1) % capacity;
        size--;

        if (!isEmpty()) {
            last_element = data[(tail + capacity - 1) % capacity];
        }
        else {
            last_element = T{};
        }

    }

    T& top() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }
        return last_element;
    }

    const T& top() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }
        return last_element;
    }

    T& front() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }
        return data[head];
    }

    const T& front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }
        return data[head];
    }

    void print() const {
        std::cout << "Queue: ";
        if (!isEmpty()) {
            size_t i = head;
            for (size_t j = 0; j < size; ++j) {
                std::cout << data[i] << " ";
                i = (i + 1) % capacity;
            }
        }
        std::cout << std::endl;
    }
};