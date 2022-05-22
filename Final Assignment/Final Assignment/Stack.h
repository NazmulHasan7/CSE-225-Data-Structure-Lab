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
    bool isFull();
    bool isEmpty();
    void Push(T);
    void Pop();
    T Top();
private :
    Node *topPtr;

};

#endif // STACK_H_INCLUDED
