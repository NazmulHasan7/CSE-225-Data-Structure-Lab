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
        Node *previous;
    };
public :
    Stack();
    ~Stack();
    int LengthIs();
    bool isFull();
    bool isEmpty();
    void Push(T);
    void Pop(T&);
    void PrintStack();
private :
    int length;
    Node *topPtr;
};

#endif // STACK_H_INCLUDED
