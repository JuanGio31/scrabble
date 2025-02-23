#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
private:
    struct Nodo
    {
        T value;
        Nodo* next;
        explicit Nodo(T val, Nodo* nxt = nullptr) : value(val), next(nxt) {}
    } * top;

    int _size;

public:
    Stack();

    ~Stack();

    void push(T _data);

    bool empty();

    T pop();

    T peek();

    int size() const;
};

#endif //STACK_H
