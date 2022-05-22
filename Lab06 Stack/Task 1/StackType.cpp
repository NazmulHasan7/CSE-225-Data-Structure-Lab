#include "StackType.h"
#include <iostream>

using namespace std;

template <class T>
StackType<T>::StackType(){
    top = -1;
}
template <class T>
bool StackType<T>::isFull(){
    return (top == maxItem-1);
}
template <class T>
bool StackType<T>::isEmpty(){
    return (top == -1);
}
template <class T>
int StackType<T>::length(){
    return top;
}
template <class T>
void StackType<T>::Push(T item){
    if(isFull())
        throw FullStack();
    else{
        top++;
        list[top] = item;
    }
}
template <class T>
void StackType<T>::Pop(){
    if(isEmpty())
        throw EmptyStack();
    else
        top--;
}
template <class T>
T StackType<T>::Tops(){
    if(isEmpty())
        throw EmptyStack();
    else
        return list[top];
}
template <class T>
void StackType<T>:: PrintStack(){

    for(int i=0;i<=top;i++) {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}
