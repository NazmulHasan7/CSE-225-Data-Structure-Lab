#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue()
{
    front = NULL;
    rear  = NULL;
}
template <class T>
bool Queue<T>::isEmpty()
{
    return (front == NULL && rear == NULL);
}
template <class T>
bool Queue<T>::isFull()
{
    try{
        Node *temp = new Node;
        delete temp;
        return false;
    }
    catch(bad_alloc& exception){
    return true;
    }
}
template <class T>
void Queue<T>::Enqueue(T item)
{
    if(isFull())
        throw FullQueue();
    else{
        Node *newNode = new Node;
        newNode->info = item;
        newNode->next = NULL;

        if(rear == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }
}
template <class T>
void Queue<T>::Dequeue(T& item)
{
    if(isEmpty())
        throw EmptyQueue();
    else{
        Node* temp = front;
        item = front->info;
        front = front->next;

        if(front == NULL)
            rear = NULL;
        delete temp;
    }
}

