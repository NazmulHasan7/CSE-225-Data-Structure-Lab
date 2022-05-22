#ifndef BINARY_SEARCH_TREE_H_INCLUDED
#define BINARY_SEARCH_TREE_H_INCLUDED
#include "Queue.h"

template<class T>
struct BSTNode
{
    T info;
    BSTNode* left;
    BSTNode* right;
};
enum OrderType {IN_ORDER, PRE_ORDER, POST_ORDER};

template<class T>
class BST
{
public :
    BST();
    ~BST();
    void MakeEmpty();
    bool isEmpty();
    bool isFull();
    int LengthIs();
    void InsertItem(T item);
    void DeleteItem(T item);
    void RetrieveItem(T& item, bool& found);
    void ResetTree(OrderType order);
    void GetNextItem(T& item, OrderType order, bool& finished);
    void Print();

private :
    BSTNode<T>* root;
    Queue<T> preQueue;
    Queue<T> inQueue;
    Queue<T> postQueue;

};
#endif // BINARY_SEARCH_TREE_H_INCLUDED
