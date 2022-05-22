#include <iostream>
#include "SortedList.h"

using namespace std;

template <class T>
SortedList<T>::SortedList()
{
    head = NULL;
    currentPos = head;
    length = 0;
}
template <class T>
void SortedList<T>::MakeEmpty()
{
    Node *temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        delete temp;
        length--;
    }
}
template <class T>
int SortedList<T>::Length()
{
    return length;
}
template <class T>
bool SortedList<T>::isEmpty()
{
    return length == 0;
}
template <class T>
bool SortedList<T>::isFull()
{
    try
    {
        Node *temp = new Node;
        delete temp;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class T>
void SortedList<T>::ResetList()
{
    currentPos = head;
}
template <class T>
void SortedList<T>::InsertItem(T item)
{
    Node *newNode = new Node;
    if(head == NULL)
    {
        newNode->info = item;
        newNode->next = NULL;
        head = newNode;
        length++;
    }
    else if(head->info > item)
    {
        newNode->info = item;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while((temp->next) != NULL && (temp->next)->info < item)
        {
            temp = temp->next;
        }
        newNode->info = item;
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
}
template <class T>
void SortedList<T>::Print()
{
    cout <<"List is  : ";
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->info <<" ";
        temp = temp->next;
    }
}
template <class T>
void SortedList<T>::DeleteItem(T item)
{
    Node *temp = head;
    if(temp->info == item)
    {
        head = temp->next;
        delete temp;
        length--;
    }
    else
    {
        while(temp != NULL)
        {
            if((temp->next)->info == item)
                break;
            else
                temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        length--;
    }
}
template <class T>
bool SortedList<T>::RetrieveItem(T item)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if((temp->next)->info == item)
            return true;
        else
        temp = temp->next;
    }
    return false;
}
