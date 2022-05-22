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
void Queue<T>::MakeEmpty()
{
    Node *temp;
    while(front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    front = rear = NULL;
}
template <class T>
Queue<T>::~Queue()
{
    MakeEmpty();
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
        /* If the rear is null it means the queue is empty
           Since we are using Linked list instead of circular
           array. So front and rear both should point the newly
           created node */
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
template <class T>
void Queue<T>::PrintQueue()
{
    cout <<"Queue :  ";
    Node* temp = front;
    while(temp != NULL)
    {
        cout <<temp->info<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

    cout <<"Reverse Queue : ";
    temp = front;
    ReverseQueue(temp);
    cout <<"NULL"<<endl;
}
template <class T>
void Queue<T>::ReverseQueue(Node *temp)
{
    if(temp == NULL)
        return;
    else{
        ReverseQueue(temp->next);
        cout <<temp->info<<"<--";
    }
}
