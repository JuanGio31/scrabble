//
// Created by giovani on 20/02/25.
//

#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
private:
    struct Node
    {
        T value;
        Node* next;

        explicit Node(T val, Node* nxt = nullptr) : value(val), next(nxt)
        {
        }
    } * front;

    int _size;

public:
    Queue();

    ~Queue();

    void enqueue(T data);

    T dequeue();

    T peek();

    void rotar();

    [[nodiscard]] bool empty() const;

    [[nodiscard]] int size() const;

    Node* getFront()
    {
        return this->front;
    }

    Queue(const Queue& other)
        : front(other.front),
          _size(other._size)
    {
    }

    Queue(Queue&& other) noexcept
        : front(other.front),
          _size(other._size)
    {
    }

    Queue& operator=(const Queue& other)
    {
        if (this == &other)
            return *this;
        front = other.front;
        _size = other._size;
        return *this;
    }

    Queue& operator=(Queue&& other) noexcept
    {
        if (this == &other)
            return *this;
        front = other.front;
        _size = other._size;
        return *this;
    }
};

#endif //QUEUE_H
