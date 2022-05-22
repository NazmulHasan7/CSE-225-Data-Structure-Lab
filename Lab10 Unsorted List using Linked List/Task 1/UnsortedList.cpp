#include <iostream>
#include "UnsortedList.h"

using namespace std;

template <class T>
UnsortedList<T>::UnsortedList()
{
    length = 0;
    head = NULL;
    currentPosition = NULL;
}
template <class T>
int UnsortedList<T>::LengthIs()
{
    return length;
}
template <class T>
bool UnsortedList<T>::isEmpty()
{
    return (length == 0);
}
template <class T>
bool UnsortedList<T>::isFull()
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
void UnsortedList<T>::MakeEmpty()
{
    Node* temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
        length--;
    }
}
template <class T>
UnsortedList<T>::~UnsortedList()
{
    MakeEmpty();
}
template <class T>
void UnsortedList<T>::ResetList()
{
    currentPosition = NULL;
}
template <class T>
void UnsortedList<T>::GetNextItem(T& item)
{
    if(currentPosition == NULL){
        currentPosition = head;
        item = currentPosition->info;
    }
    else{
        currentPosition = currentPosition->next;
        item = currentPosition->info;
    }
}
template <class T>
void UnsortedList<T>::InsertItem(T item)
{
    if(isFull()){
        cout <<"List is full. No more item can be inserted."<<endl;
        return;
    }
    Node *newNode = new Node;
    newNode->info = item;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    length++;
}
template <class T>
void UnsortedList<T>::DeleteItem(T item)
{
    Node* temp = head;
    if(temp->info == item){
        head = head->next;
        delete temp;
    }
    else{
        while(temp != NULL){
            /* Since we've already checked the 1st node
              in the if condition. So, we don't temp->next->info
              starts checking from the 2nd Node */
            if((temp->next)->info == item){
                break;
            }
            else{
                temp = temp->next;
            }
        }
        if(temp == NULL)
            cout <<"Item is not found to delete."<<endl;
        else{
            Node* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
    }
    length--;
}
template <class T>
void UnsortedList<T>::RetrieveItem(T& item, bool& found)
{
    Node* temp = head;
    bool moreToSearch = (temp != NULL);
    found = false;

    while(moreToSearch && !found)
    {
        if(temp->info == item)
            found = true;
        else{
            temp = temp->next;
            moreToSearch = (temp != NULL);
        }
    }
}
template <class T>
void UnsortedList<T>::PrintList()
{
    cout <<"List is : ";
    Node* temp = head;
    while(temp != NULL){
        cout <<temp->info<<"-->";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
}
