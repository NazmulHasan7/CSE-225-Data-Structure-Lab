#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
Stack<T>::Stack()
{
    length = 0;
    topPtr = NULL;
}
template <class T>
Stack<T>::~Stack()
{
    Node *temp;
    while(topPtr != NULL)
    {
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
        length--;
    }
}
template <class T>
int Stack<T>::LengthIs()
{
    return length;
}
template <class T>
bool Stack<T>::isEmpty()
{
    return (length == 0);
}
template <class T>
bool Stack<T>::isFull()
{
    try{
       Node* temp = new Node;
       delete temp;
       return false;
    }
    catch(bad_alloc& exception){
       return true;
    }
}
template <class T>
void Stack<T>::Push(T item)
{
    if(isFull())
        throw FullStack();

    Node* newNode = new Node;
    newNode->info = item;

    if(topPtr == NULL){
        newNode->next = NULL;
        newNode->previous = NULL;
        topPtr = newNode;
    }
    else{
        Node* temp = topPtr;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
        newNode->next = NULL;
        topPtr = newNode;
    }
    length++;
}
template <class T>
void Stack<T>::PrintStack()
{
    cout <<"Stack : ";
    Node *temp = topPtr;
    while(temp != NULL){
        cout <<temp->info <<"<-->";
        temp = temp->previous;
    }
    cout <<"NULL"<<endl;
}
template <class T>
void Stack<T>::Pop(T& item)
{
    if(isEmpty())
        throw EmptyStack();

    else{
        Node *temp = topPtr;
        item = topPtr->info;
        topPtr = topPtr->previous;
        delete temp;
    }
}
