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
        explicit Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {}
    } * front;

    int _size;

public:
    Queue();

    ~Queue();

    void enqueue(T data);

    T dequeue();

    T peek();

    [[nodiscard]] bool empty() const;

    [[nodiscard]] int size() const;
};

#endif //QUEUE_H
