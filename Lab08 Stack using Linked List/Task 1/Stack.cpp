#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
Stack<T>::Stack()
{
    topPtr = NULL;
}
template <class T>
Stack<T>::~Stack()
{
    Node *tempPtr;
    while(topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
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
        Node *tempNode = new Node;
        delete tempNode;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
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
T Stack<T>::Top()
{
    if(isEmpty())
        throw EmptyStack();
    else
        return topPtr->info;
}
template <class T>
void Stack<T>::PrintStack()
{
    Node *temp = topPtr;
    cout <<"Reverse Stack : ";
    ReversePrint(temp);
    cout <<"NULL"<<endl;

    cout <<"Stack : ";
    temp = topPtr;
    while(temp != NULL)
    {
        cout <<temp->info<<"-->";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}
template <class T>
void Stack<T>::ReversePrint(Node *tPtr)
{
    if(tPtr == NULL)
        return;
    else
    {
        ReversePrint(tPtr->next);
        cout <<tPtr->info<<"-->";
    }
}
