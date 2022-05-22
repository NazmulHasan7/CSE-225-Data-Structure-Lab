#ifndef UNSORTEDLIST_H_INCLUDED
#define UNSORTEDLIST_H_INCLUDED

template <class T>
class UnsortedList
{
    struct Node{
        T info;
        Node *next;
    };
public :
    UnsortedList();
    ~UnsortedList();
    bool isEmpty();
    bool isFull();
    int LengthIs();
    void InsertItem(T);
    void DeleteItem(T);
    void RetrieveItem(T&,bool&);
    void GetNextItem(T&);
    void ResetList();
    void MakeEmpty();
    void PrintList();

private :
    Node *head;
    Node *currentPosition;
    int length;
};

#endif // UNSORTEDLIST_H_INCLUDED
