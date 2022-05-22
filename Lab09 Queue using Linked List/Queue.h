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
    ~Queue();
    bool isFull();
    bool isEmpty();
    void Enqueue(T);
    void Dequeue(T&);
    void PrintQueue();
    void ReverseQueue(Node*);
    void MakeEmpty();

private :
    Node *front;
    Node *rear;

};
#endif // QUEUE_H_INCLUDED
