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

        explicit Nodo(T val, Nodo* nxt = nullptr) : value(val), next(nxt)
        {
        }
    } * top;

    int _size;

public:
    Stack();

    ~Stack();

    void push(T _data);

    bool empty();

    T pop();

    T peek();

    [[nodiscard]] int size() const;

    Stack(const Stack& other)
        : top(other.top),
          _size(other._size)
    {
    }

    Stack(Stack&& other) noexcept
        : top(other.top),
          _size(other._size)
    {
    }

    Stack& operator=(const Stack& other)
    {
        if (this == &other)
            return *this;
        top = other.top;
        _size = other._size;
        return *this;
    }

    Stack& operator=(Stack&& other) noexcept
    {
        if (this == &other)
            return *this;
        top = other.top;
        _size = other._size;
        return *this;
    }
};

#include "../../src/estructuras/Stack.tpp"
#endif //STACK_H
