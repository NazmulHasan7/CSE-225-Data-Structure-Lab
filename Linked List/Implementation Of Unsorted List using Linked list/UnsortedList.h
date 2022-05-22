#ifndef UNSORTEDLIST_H_INCLUDED
#define UNSORTEDLIST_H_INCLUDED

template <class T>
class UnsortedList
{
    struct Node
    {
        T info;
        Node *next;
    };

public :
    UnsortedList();
    void MakeEmpty();
    int Length();
    bool isEmpty();
    bool isFull();
    void InsertItem(T);
    void DeleteItem(T);
    void ResetList();
    bool RetrieveItem(T);
    void Print();

private :
    Node* currentPosition;
    Node* head;
    int length;
};

#endif // UNSORTEDLIST_H_INCLUDED
