#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class EmptyQueue{};
class FullQueue {};

template<class T>
class Queue
{
    struct Node
    {
        T info;
        Node *next;
    };

public :
    Queue();
    bool isFull();
    bool isEmpty();
    void Enqueue(T);
    void Dequeue(T&);

private :
    Node *front;
    Node *rear;

};
#endif // QUEUE_H_INCLUDED
