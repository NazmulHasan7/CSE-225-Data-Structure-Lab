#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class EmptyQueue{};
class FullQueue {};

template<class T>
class Queue
{
    struct Node{
        T info;
        Node* next;
    };
public :
    Queue();
    ~Queue();
    bool isEmpty();
    bool isFull();
    int LengthIs();
    void MakeEmpty();
    void Enqueue(T item);
    void Dequeue(T &item);
    void PrintQueue();

private :
    Node* front;
    Node* rear;
    int length;
};

#endif // QUEUE_H_INCLUDED
