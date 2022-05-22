#include"quetype.h"
template<class ItemType>
QueType<ItemType>::QueType(int max){
    maxQueue=max+1;
    rear=max;
    front=max;
    items= new ItemType[ maxQueue];
}
template<class ItemType>
QueType<ItemType>::QueType(){
    maxQueue=501;
    rear=maxQueue-1;
    front=maxQueue-1;
    items= new ItemType[ maxQueue];
}
template<class ItemType>
QueType<ItemType>::~QueType(){
    delete[] items;
}
template<class ItemType>
void QueType<ItemType>::MakeEmpty(){
    rear=maxQueue-1;
    front=maxQueue-1;
}
template<class ItemType>
bool QueType<ItemType>::IsEmpty(){
    return (rear==front);
}
template<class ItemType>
bool QueType<ItemType>::IsFull(){
    return ((rear+1)%maxQueue==front);
}
template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem){
    if(IsFull())
        throw FullQueue();
    else{
        rear=(rear+1)%maxQueue;
        items[rear]=newItem;
    }
}
template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& Item){
    if(IsEmpty())
        throw EmptyQueue();
    else{
        front=(front+1)%maxQueue;
        Item=items[front];
    }
}
