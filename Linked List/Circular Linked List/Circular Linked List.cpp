#include <iostream>
#include "Circular Linked List.h"

using namespace std;

template <class T>
CircularLinkedList<T>::CircularLinkedList()
{
    length = 0;
    head = NULL;
}
template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    Node *temp;
    while(head->next != head)
    {
        temp = head;
        head = head->next;
        delete temp;
        length--;
    }
    delete head;
    length--;
}

template <class T>
bool CircularLinkedList<T>::isEmpty()
{
    return (length == 0);
}
template <class T>
bool CircularLinkedList<T>::isFull()
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
void CircularLinkedList<T>::Insert(T item)
{
    if(isFull()){
        cout <<"List is full."<<endl;
        return;
    }
    Node *newNode = new Node;
    newNode->info = item;

    if(head == NULL){
        newNode->next = NULL;
        newNode->previous = NULL;
        head = newNode;
    }
    else if(head->next == NULL){
        newNode->next = head;
        newNode->previous = head;
        head->next = newNode;
        head->previous = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        newNode->previous = temp;
        temp->next = newNode;
    }
   length++;
}
template <class T>
int CircularLinkedList<T>::LengthIs()
{
    return length;
}
template <class T>
void CircularLinkedList<T>::Print()
{
    cout <<"List is : ";
    Node *temp = head;
    while(temp->next != head)
    {
        cout <<temp->info<<"<-->";
        temp = temp->next;
    }
    cout <<temp->info<<"<-->";
    cout <<"HEAD"<<endl;
}
template <class T>
bool CircularLinkedList<T>::Retrieve(T item)
{
    if(isEmpty())
        return false;
    if(head->info == item)
        return true;
    else{
        Node* temp = head;
        while(temp->next != head){
            if(temp->next->info == item)
                return true;
            else
                temp = temp->next;
        }
        return false;
    }
}
template <class T>
void CircularLinkedList<T>::Delete(T item)
{
    if(isEmpty()){
        cout <<"List is empty."<<endl;
        return;
    }
    Node *temp;
    if(head->info == item){
        temp = head;
        cout <<"Head == Temp : "<<head->info<<endl;
        cout <<"Head->previous " <<head->previous->info <<endl;
        head = head->next;
        cout <<"Head " <<head->info <<endl;
        cout <<"Head->previous " <<head->previous->info <<endl;
        cout <<"Temp->previous " <<(head->previous)->previous->info <<endl;
        head->previous = head->previous->previous;

        head->previous->previous->next = head;
        cout <<"temp->previous->next " <<head->previous->previous->next->info <<endl;
        cout <<"Head : "<<head->info<<endl;
        delete temp;
        length--;
    }
    else if(head->previous->info == item){
        temp = head->previous;
        temp->previous->next = head;
        head->previous = temp->previous;
        delete temp;
        length--;
    }
//INCOMPLETE //
}
