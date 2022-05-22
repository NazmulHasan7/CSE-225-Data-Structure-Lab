#include "QueueType.h"

template <class T>
QueueType<T>::QueueType(){
    size = maxSize+1;
    front = rear = size-1;
    list = new T[size];
}
template <class T>
QueueType<T>::QueueType(int siZe){
    size = siZe+1;
    front = rear = size-1;
    list = new T[size];
}
template <class T>
QueueType<T>::~QueueType(){
    delete[] list;
}
template <class T>
void QueueType<T>::MakeEmpty(){
    front = rear = size-1;
}
template <class T>
bool QueueType<T>::IsFull(){
    return (((rear+1) % size) == front);
}
template <class T>
bool QueueType<T>::IsEmpty(){
    return rear == front;
}
template <class T>
void QueueType<T>::Enqueue(T item){
    if(IsFull())
        throw FullQueue();
    else{
        rear = (rear+1) % size;
        list[rear] = item;
    }
}
template <class T>
void QueueType<T>::Dequeue(T& item){
    if(IsEmpty())
        throw EmptyQueue();
    else{
        front = (front+1) % size;
        item = list[front];
    }
}
