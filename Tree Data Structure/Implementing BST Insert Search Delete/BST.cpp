#include <iostream>
#include "BST.h"
using namespace std;

template<class T>
BST<T>::BST()
{
    root = NULL;
    length = 0;
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
        BSTNode* newNode = new BSTNode;
        delete newNode;
        return false;
    }
    catch(bad_alloc& exception){
        return true;
    }
}
template<class T>
void BST<T>::Insert(T item)
{
    if(isFull()){
        cout<<"No space available"<<endl;
        return;
    }
    BSTInsert(root,item);
    length++;
}
template<class T>
void BST<T>::BSTInsert(BSTNode* &root, T item)
{/* If the root is NULL then create a new Node */
    if(root == NULL){
        BSTNode* newNode = new BSTNode;
        newNode->info  = item;
        newNode->left  = NULL;
        newNode->right = NULL;
        root = newNode;
    }
/*If the given value is lesser than root value then
 *Insert item recursively to the left
 */ else if(item < root->info)
        BSTInsert(root->left, item);
/*If the given value is greater or equal to root value then
 *Insert item recursively to the right
 */ else
        BSTInsert(root->right, item);
}
template<class T>
bool BST<T>::Search(T item)
{
    if(isEmpty())
        return false;
    else
        return BSTSearch(root, item);
}
template<class T>
bool BST<T>::BSTSearch(BSTNode* root, T item)
{/* If the root is NULL means the item is not found */
    if(root == NULL)
        return false;
    /* The item is found */
    else if(item == root->info)
        return true;
    /* Search in left subtree */
    else if(item < root->info)
        return BSTSearch(root->left, item);
    else /* Search in right subtree */
        return BSTSearch(root->right, item);
}
template<class T>
void BST<T>::Delete(T item)
{
    if(isEmpty()){
        cout<<"Empty Tree!"<<endl;
        return;
    }
    BSTDelete(root,item);
    length--;
}
template<class T>
void BST<T>::BSTDelete(BSTNode* &root, T item)
{
    if(item < root->info)
        BSTDelete(root->left, item);
    else if(item > root->info)
        BSTDelete(root->right, item);
    else if(root->info == item)
        DeleteNode(root);
    else
        cout<<"Item not found"<<endl;
}
template<class T>
void BST<T>::DeleteNode(BSTNode* &root)
{
    BSTNode* temp = root;
/*CASE 1 : A node with no child
 *Action : Simply delete the node
 */ //Means the root node has no child
    if(root->left == NULL && root->right == NULL){
        delete temp;
        root = NULL;
    }
/*CASE 2 : A node with One child
 *But there are 2 sub cases
 * 2.1) The child is in left (Means the right is empty)
 * 2.2) The child is in the right (Means the left is empty)
 */
    else if(root->right == NULL){
        root = root->left;
        delete temp;
    }//SUBCASE 2.1
    else if(root->left == NULL){
        root = root->right;
        delete temp;
    }//SUBCASE 2.2

/*CASE 3 : A node with 2 child
 *There are 2 possible solutions
 *1)Replace the node with the highest value of its left subtree
 *2)Replace the node with the lowest value of its right subtree
 */ //Going with the 1st Choice -->
    else{
    //First replace the value with the Highest value of left Subtree
        root->info = FindMaximum(root->left);
    /*After that Delete the right most node of left Subtree
     *Where root->left becomes the root of the left Subtree
     */ BSTDelete(root->left, root->info);
    }
}
template<class T>
T BST<T>::FindMaximum()
{
    if(isEmpty()){
        cout<<"The tree is empty"<<endl;
    }
    return FindMaximum(root);
}
template<class T>
T BST<T>::FindMaximum(BSTNode* root)
{
    while(root->right != NULL){
        root = root->right;
    }
    return root->info;
}
template<class T>
T BST<T>::FindMinimum()
{
    if(isEmpty()){
        cout<<"Tree is empty"<<endl;
    }
    return FindMinimum(root);
}
template<class T>
T BST<T>::FindMinimum(BSTNode* root)
{
    while(root->left != NULL){
        root = root->left;
    }
    return root->info;
}
template<class T>
int BST<T>::HeightOfTree()
{
    if(root == NULL)
        return 0;
    return HeightOfTree(root);
}
template<class T>
int BST<T>::HeightOfTree(BSTNode* root)
{
    if(root == NULL)
        return -1;

    int leftHeight = HeightOfTree(root->left);
    int rightHeight = HeightOfTree(root->right);

    if(leftHeight < rightHeight)
        return rightHeight+1;
    else
        return leftHeight+1;
}
template<class T>
int BST<T>::LengthIs()
{
    return CountNodes(root);
}
template<class T>
int BST<T>::CountNodes(BSTNode* root)
{
    if(root == NULL)
        return 0;
    else
        return CountNodes(root->left) + CountNodes(root->right) + 1;
}
template<class T>
void BST<T>::PrintInOrder()
{
    PrintInOrder(root);
}
template<class T>
void BST<T>::PrintInOrder(BSTNode* root)
{
    if(root == NULL)
        return;
    else{
        PrintInOrder(root->left);
        cout<<root->info<<" ";
        PrintInOrder(root->right);
    }
}
template<class T>
void BST<T>::PrintPostOrder()
{
    PrintPostOrder(root);
}
template<class T>
void BST<T>::PrintPostOrder(BSTNode* root)
{
    if(root == NULL)
        return;
    else{
        PrintPostOrder(root->left);
        PrintPostOrder(root->right);
        cout<<root->info<<" ";
    }
}
template<class T>
void BST<T>::PrintPreOrder()
{
    PrintPreOrder(root);
}
template<class T>
void BST<T>::PrintPreOrder(BSTNode* root)
{
    if(root == NULL)
        return;
    else{
        cout<<root->info<<" ";
        PrintPreOrder(root->left);
        PrintPreOrder(root->right);
    }
}
