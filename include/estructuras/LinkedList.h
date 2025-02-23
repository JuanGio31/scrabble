//
// Created by giovani on 20/02/25.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node* next;
        explicit Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {}
    } * head;

    int _size;

public:
    LinkedList();

    ~LinkedList();

    void insertAtHead(T data);

    void insertAtEnd(T data);

    void deleteAtHead();

    void deleteAtEnd();

    T search(int index);

    bool deleteAt(int index);

    bool empty() const;

    int size() const;

    bool contains(T object);
};

#endif //LINKEDLIST_H
