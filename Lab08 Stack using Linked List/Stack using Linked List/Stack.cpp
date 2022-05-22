#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
Stack<T>::Stack()
{
    topPtr = NULL;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return topPtr == NULL;
}

template <class T>
bool Stack<T>::isFull()
{
    try
    {
        Node *temp = new Node;
        delete temp;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}

template <class T>
T Stack<T>::Top()
{
    if(isEmpty())
        throw EmptyStack();
    else
        return topPtr->info;
}

template <class T>
void Stack<T>::Push(T item)
{
    if(isFull())
        throw FullStack();
    else
    {
        Node *newNode = new Node;
        newNode->info = item;
        newNode->next = topPtr;
        topPtr = newNode;
    }
}

template <class T>
void Stack<T>::Pop()
{
    if(isEmpty())
        throw EmptyStack();
    else
    {
        Node *temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

template <class T>
Stack<T>::~Stack()
{
    Node *temp;
    while(temp != NULL)
    {
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

template <class T>
void Stack<T>::Print()
{
    cout <<"Reverse Stack : ";
    Node *temp = topPtr;
    ReversePrint(temp);
    cout <<"NULL"<<endl;

    temp = topPtr;
    cout <<"Stack : ";
    while(temp != NULL)
    {
        cout <<temp->info<<"<-- ";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}

template <class T>
void Stack<T>::ReversePrint(Node* tempTop)
{
    if(tempTop == NULL)
        return;
    else
    {
        ReversePrint(tempTop->next);
        cout <<tempTop->info<<"-->";
    }
}
