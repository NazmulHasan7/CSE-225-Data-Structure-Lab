#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

class FullStack{};
class EmptyStack{};

template <class T>

class Stack
{
    struct Node
    {
        T info;
        Node *next;
    };
public :
    Stack();
    ~Stack();
    bool isFull();
    bool isEmpty();
    void Push(T);
    void Pop();
    T Top();
    void Print();
    void ReversePrint(Node*);
private :
    Node *topPtr;

};

#endif // STACK_H_INCLUDED
