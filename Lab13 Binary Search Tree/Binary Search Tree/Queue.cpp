#include <iostream>
#include "Queue.h"

using namespace std;

template<class T>
Queue<T>::Queue()
{
    front = rear = NULL;
    length = 0;
}
template<class T>
Queue<T>::~Queue()
{
    MakeEmpty();
}
template<class T>
bool Queue<T>::isEmpty()
{
    return (front == NULL && rear == NULL);
}
template<class T>
bool Queue<T>::isFull()
{
    try{
        Node* newNode = new Node;
        delete newNode;
        return false;
    }
    catch(bad_alloc& exception){
        return true;
    }
}
template<class T>
int Queue<T>::LengthIs()
{
    return length;
}
template<class T>
void Queue<T>::MakeEmpty()
{
    Node* temp;
    while(front != NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
    front = rear = NULL;
}
template<class T>
void Queue<T>::Enqueue(T item)
{
    if(isFull())
        throw FullQueue();
    else{
        Node* newNode = new Node;
        newNode->next = NULL;
        newNode->info = item;

        if(rear == NULL)
            front = rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }
}
template<class T>
void Queue<T>::Dequeue(T& item)
{
    if(isEmpty())
        throw EmptyQueue();
    else{
        Node* temp = front;
        item = front->info;
        front = front->next;

        if(front == NULL)
            front = rear = NULL;
        delete temp;
    }
}

template<class T>
void Queue<T>::PrintQueue()
{
    Node* temp = front;
    while(temp != NULL){
        cout<<temp->info<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
