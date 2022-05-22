#include <iostream>
#include "Queue.cpp"
#include "Binary Search Tree.h"

using namespace std;

template<class T>
BST<T>::BST()
{
    root = NULL;
}
template<class T>
void Destroy(BSTNode<T>* &root)
{
    if(root != NULL){
        Destroy(root->left);
        Destroy(root->right);
        delete root;
        root = NULL;
    }
}
template<class T>
BST<T>::~BST()
{
    Destroy(root);
}
template<class T>
void BST<T>::MakeEmpty()
{
    Destroy(root);
}
template<class T>
bool BST<T>::isEmpty()
{
    return (root == NULL);
}
template<class T>
bool BST<T>::isFull()
{
    try{
        BSTNode<T>* newNode = new BSTNode<T>;
        delete newNode;
        return false;
    }
    catch(bad_alloc& exception){
        return true;
    }
}
template<class T>
int CountNodes(BSTNode<T>* root)
{
    if(root == NULL)
        return 0;
    else
        return CountNodes(root->left) + CountNodes(root->right) + 1;
}
template<class T>
int BST<T>::LengthIs()
{
    return CountNodes(root);
}
template<class T>
void Retrieve(BSTNode<T>* root, T& item, bool& found)
{
    if(root == NULL)
        found = false;
    else if(root->info == item){
        found = true;
        item = root->info;
    }
    else if(item < root->info)
        Retrieve(root->left, item, found);
    else
        Retrieve(root->right, item, found);
}
template<class T>
void BST<T>::RetrieveItem(T& item, bool& found)
{
    Retrieve(root, item, found);
}
template<class T>
void Insert(BSTNode<T>*& root, T item)
{
    if(root == NULL){
        BSTNode<T>* newNode = new BSTNode<T>;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->info = item;
        root = newNode;
    }
    else if(item < root->info){
        Insert(root->left, item);
    }
    else{
        Insert(root->right, item);
    }
}
template<class T>
void BST<T>::InsertItem(T item)
{
    Insert(root, item);
}
template<class T>
void Delete(BSTNode<T>*& root, T item)
{
    if(item < root->info)
        Delete(root->left, item);
    else if(item > root->info)
        Delete(root->right, item);
    else
        DeleteNode(root);
}
template<class T>
void DeleteNode(BSTNode<T>*& root)
{
    T data;
    BSTNode<T>* temp = root;
    if(root->left == NULL && root->right == NULL){
        delete temp;
        root = NULL;
    }
    else if(root->left == NULL){
        root = root->right;
        delete temp;
    }
    else if(root->right == NULL){
        root = root->left;
        delete temp;
    }
    else{
        GetPredecessor(root->left, data);
        root->info = data;
        Delete(root->left, data);
    }
}
template<class T>
void GetPredecessor(BSTNode<T>* root, T& data)
{
    while(root->right != NULL)
        root = root->right;

    data = root->info;
}
template<class T>
void BST<T>::DeleteItem(T item)
{
    Delete(root, item);
}
template<class T>
void InOrder(BSTNode<T>* root, Queue<T>& inQueue)
{
    if(root != NULL){
        InOrder(root->left, inQueue);
        inQueue.Enqueue(root->info);
        InOrder(root->right, inQueue);
    }
}
template<class T>
void PreOrder(BSTNode<T>* root, Queue<T>& preQueue)
{
    if(root != NULL){
        PreOrder(root->left, preQueue);
        preQueue.Enqueue(root->info);
        PreOrder(root->right, preQueue);
    }
}
template<class T>
void PostOrder(BSTNode<T>* root, Queue<T>& postQueue)
{
    if(root != NULL){
        PostOrder(root->left, postQueue);
        postQueue.Enqueue(root->info);
        PostOrder(root->right, postQueue);
    }
}
template<class T>
void BST<T>::ResetTree(OrderType order)
{
    switch(order)
    {
        case IN_ORDER   : InOrder(root, inQueue);
                          break;
        case PRE_ORDER  : PreOrder(root, preQueue);
                          break;
        case POST_ORDER : PostOrder(root, postQueue);
                          break;
    }
}
template<class T>
void BST<T>::GetNextItem(T& item, OrderType order, bool& finished)
{
    finished = false;
    switch(order)
    {
        case IN_ORDER   : inQueue.Dequeue(item);
                          if(inQueue.isEmpty())
                              finished = true;
                          break;
        case PRE_ORDER  : preQueue.Dequeue(item);
                          if(preQueue.isEmpty())
                              finished = true;
                          break;
        case POST_ORDER : postQueue.Dequeue(item);
                          if(postQueue.isEmpty())
                              finished = true;
                          break;
    }
}
template<class T>
void PrintTreeInOrder(BSTNode<T>* root)
{
    if(root == NULL)
            return;
    else{
        PrintTreeInOrder(root->left);
        cout<<root->info<<" ";
        PrintTreeInOrder(root->right);
    }
}
template<class T>
void PrintTreePreOrder(BSTNode<T>* root)
{
    if(root == NULL)
            return;
    else{
        cout<<root->info<<" ";
        PrintTreePreOrder(root->left);
        PrintTreePreOrder(root->right);
    }
}
template<class T>
void PrintTreePostOrder(BSTNode<T>* root)
{
    if(root == NULL)
            return;
    else{
        PrintTreePostOrder(root->left);
        PrintTreePostOrder(root->right);
        cout<<root->info<<" ";
    }
}
template<class T>
void BST<T>::Print()
{
    cout<<"In Order Tree : ";
    PrintTreeInOrder(root);
    cout<<endl;
    cout<<"Pre Order Tree : ";
    PrintTreePreOrder(root);
    cout<<endl;
    cout<<"Post Order Tree : ";
    PrintTreePostOrder(root);
    cout<<endl;
}
