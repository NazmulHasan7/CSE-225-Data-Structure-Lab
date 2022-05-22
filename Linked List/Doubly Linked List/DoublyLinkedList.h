#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

template <class T>
class DoublyLinkedList
{
  struct Node{
      T info;
      Node *next;
      Node *previous;
  };
public :
/*--------------------------------------
Implementing all the lists : 1)Sorted---
-----------------------------2)Unsorted-
----NAZMUL---HASAN-----------3)Stack----
--------1911742--------------4)Queue----
--------------------------------------*/
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool isEmpty();
    bool isFull();
    int  LengthIs();
    void InsertInList(T);
    void SortedInsert(T);
    void DeleteFromList(T);
    bool RetrieveItem(T);
    void PrintList();
    void ReversePrint();

private :
    Node *head;
    int length;

};

#endif // DOUBLYLINKEDLIST_H_INCLUDED
