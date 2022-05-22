#ifndef SORTEDLIST_H_INCLUDED
#define SORTEDLIST_H_INCLUDED

template <class T>
class SortedList
{
    struct Node
    {
        T info;
        Node *next;
    };
private :
    int length;
    Node *head;
    Node *currentPos;
public :
    SortedList();
    void MakeEmpty();
    bool isFull();
    bool isEmpty();
    int Length();
    void ResetList();
    void Print();
    void InsertItem(T);
    void DeleteItem(T);
    bool RetrieveItem(T);
};

#endif // SORTEDLIST_H_INCLUDED
