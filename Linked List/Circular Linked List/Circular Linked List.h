#ifndef CIRCULAR_LINKED_LIST_H_INCLUDED
#define CIRCULAR_LINKED_LIST_H_INCLUDED

template <class T>
class CircularLinkedList
{
    struct Node
    {
        T info;
        Node *next;
        Node *previous;
    };
public :
    CircularLinkedList();
    ~CircularLinkedList();
    int LengthIs();
    bool isFull();
    bool isEmpty();
    void Insert(T);
    void Delete(T);
    bool Retrieve(T);
    void Print();
private :
    int length;
    Node *head;
};

#endif // CIRCULAR_LINKED_LIST_H_INCLUDED
