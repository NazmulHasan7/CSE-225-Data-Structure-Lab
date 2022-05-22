#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

class EmptyStack{};
class FullStack {};

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
    bool isEmpty();
    bool isFull();
    void Push(T);
    T Top();
    void Pop();
    void PrintStack();
    void ReversePrint(Node*);
private :
    Node *topPtr;

};

#endif // STACK_H_INCLUDED
