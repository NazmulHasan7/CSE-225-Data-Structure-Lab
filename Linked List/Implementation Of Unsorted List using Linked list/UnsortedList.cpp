#include "UnsortedList.h"
#include <iostream>
using namespace std;

template <class T>
UnsortedList<T>::UnsortedList()
{
    head = NULL;
    currentPosition = new Node;
    length = 0;
}
template <class T>
void UnsortedList<T>::MakeEmpty()
{
    Node* temp = head;
    //Deleting each node & reduce the length
    while(temp != NULL)
    {
        temp = temp->next;
        length--;
        delete temp;
    }
}
template <class T>
int UnsortedList<T>::Length()
{
    return length;
}
template <class T>
bool UnsortedList<T>::isEmpty()
{
    return length == 0;
}
template <class T>
void UnsortedList<T>::ResetList()
{
    //Move the currentPosition to the beginning of the list
    currentPosition = head;
}
template <class T>
bool UnsortedList<T>::isFull()
{
    try
    {
        /*Trying to create a new node, if the node is created successfully
        then the node is not full , So return false */
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
void UnsortedList<T>::InsertItem(T item)
{
    if(isFull())
    {
        cout <<"No more memory available"<<endl;
    }
    else
    {
        Node* temp = new Node;
        if(head == NULL)
        {
           temp->info = item;
           temp->next = NULL;
           head = temp;
           length++;
           return;
        }
        else
        {
            temp = head;
            Node *newNode = new Node;
            newNode->info = item;
            newNode->next = NULL;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            length++;
            return;
        }
    }
}
template <class T>
void UnsortedList<T>::DeleteItem(T item)
{
    Node* temp = head;
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
bool UnsortedList<T>::RetrieveItem(T item)
{
    Node*temp = head;
    while(temp!= NULL)
    {
        if((temp->next)->info == item)
            return true;
        else
            temp = temp->next;
    }
    return false;
}
template <class T>
void UnsortedList<T>::Print()
{
    cout <<"List is : ";
    Node* temp = head;
    while(temp!= NULL)
    {
        cout << temp->info <<" ";
        temp = temp->next;
    }
    cout <<endl;
}
