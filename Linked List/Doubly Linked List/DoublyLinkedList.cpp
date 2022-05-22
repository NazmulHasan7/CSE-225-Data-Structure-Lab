#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = NULL;
    length = 0;
}
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (length ==0);
}
template <class T>
bool DoublyLinkedList<T>::isFull()
{
    try{
        Node *newNode = new Node;
        delete newNode;
        return false;
    }
    catch(bad_alloc& exception){
        return true;
    }
}
template <class T>
int DoublyLinkedList<T>::LengthIs()
{
    return length;
}
template <class T>
void DoublyLinkedList<T>::InsertInList(T item)
{
    if(isFull())
        cout <<"The list is Full. Insertion is not possible." <<endl;
    else{
        Node *newNode = new Node;
        newNode->info = item;

        if(head == NULL){
            newNode->previous = NULL;
            newNode->next = NULL;
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode->previous = temp;
            newNode->next = NULL;
            temp->next = newNode;
        }
    }
    length++;
}
template <class T>
void DoublyLinkedList<T>::PrintList()
{
    cout <<"List :         ";
    Node *temp = head;
    while(temp != NULL)
    {
        cout <<temp->info<<" <--> ";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}
template <class T>
void DoublyLinkedList<T>::ReversePrint()
{
    cout <<"Reverse List : ";
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != head)
    {
        cout <<temp->info<<" <--> ";
        temp = temp->previous;
    }
    cout <<temp->info<<" <--> ";
    cout <<"NULL"<<endl;
}
template <class T>
void DoublyLinkedList<T>::SortedInsert(T item)
{
    if(isFull()){
        cout <<"The list is Full. Insertion is not possible." <<endl;
        return;
    }
    Node* newNode = new Node;
    newNode->info = item;

    if(head == NULL){
        newNode->next = NULL;
        newNode->previous = NULL;
        head = newNode;
    }
    else if(item <= head->info){
        newNode->next = head;
        newNode->next->previous = newNode;
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL)
        {
            if ((temp->next)->info > item)
                break;
            else
                temp = temp->next;
        }
        newNode->next = temp->next;
        if(temp->next != NULL)
            newNode->next->previous = newNode;

        temp->next = newNode;
        newNode->previous = temp;
    }
    length++;
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
        length--;
    }
}
template <class T>
void DoublyLinkedList<T>::DeleteFromList(T item)
{
    if(isEmpty()){
        cout <<"List is empty."<<endl;
        return;
    }
    if(head->info == item){
        Node *temp = head;
        head->next->previous = NULL;
        head = head->next;
        delete temp;
    }
    else{
        Node *temp = head;
        while(temp != NULL)
        {
            if(temp->next->info == item)
                break;
            else
                temp = temp->next;
        }
        if(temp == NULL){
            cout <<"Not found to delete.";
        }
        else{
            Node *temp2 = temp->next;
            if(temp2->next != NULL){
                temp2->next->previous = temp;
                temp->next = temp2->next;
            }
            else{
                temp->next = NULL;
            }
            delete temp2;
        }
        length--;
    }
}
template <class T>
bool DoublyLinkedList<T>::RetrieveItem(T item)
{
    if(isEmpty())
        return false;

    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->info == item)
            return true;
        else
            temp = temp->next;
    }
    return false;
}
