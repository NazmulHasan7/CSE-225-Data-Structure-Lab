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
    bool isFull();
    bool isEmpty();
    int LengthIs();
    void MakeEmpty();
    void InsertItem(T);
    void DeleteItem(T);
    void ResetList();
    void GetNextItem(T&);
    void RetrieveItem(T&, bool&);
    void PrintList();

private :
    Node* head;
    Node* currentPosition;
    int length;
};

#endif // UNSORTEDLIST_H_INCLUDED
