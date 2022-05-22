///CHECKING IF A TREE IS BINARY SEARCH TREE OR NOT
/*-----------------------------------------------------------|
|*There are many ways to solve this problem                  |
|*Two Easy ways are :                                        |
| *1) Check :                                                |
|    1.1) If the root value is lesser than the minimum value |
|    1.2) If the root value is greater than the maximum value|
|         If any of this 2 happens then It's the violation of|
|         BST rule. So, the tree is not BST.                 |
|    1.3) Do repeat 1.1 & 1.2 to check the left and right    |
|         Subtree Recursively.                               |
|------------------------------------------------------------|
|*2) Another way is :                                        |
|    Traverse the Tree in InOrder & store the root values in |
|    a array or queue and check if it is sorted or not!      |
|                                                            |
|    If it is sorted then the tree is a Binary Search Tree   |
|    otherwise not a BST.                                    |
|------------------------------------------------------------*/

#include <iostream>
#include <queue>
using namespace std;

struct BSTNode
{
    int info;
    BSTNode* left;
    BSTNode* right;
};
void BSTInsert(BSTNode*& root, int item);
bool isBSTCASE1(BSTNode* root, int max, int min);

bool isBSTCASE2(BSTNode* root, int size);
void TraverseInOrder(BSTNode* root, int *arr);
bool isSorted(int *arr, int length);

void PrintInOrder(BSTNode* root);

int i = 0; //Why this i is Globally declared ??
/* This i is used in the Recursive Function
 * void TraverseInOrder(BSTNode* root, int *arr)
 * where this is used as an iterator for the array arr
 * If we Don't declare it globally the i value would change
 * for each function call
*/
int main(void)
{
    BSTNode* root = NULL;
    cout<<"Inserting 15 10 20 5 12 17 25 in BST"<<endl;
    BSTInsert(root,15);
    BSTInsert(root,10);
    BSTInsert(root,20);
    BSTInsert(root, 5);
    BSTInsert(root,12);
    BSTInsert(root,17);
    BSTInsert(root,25);
    cout<<"-------->Insertion Complete-------->"<<endl;
    cout<<"\nSorted : ";
    PrintInOrder(root);
    cout<<endl;

    cout<<"\nIs the given Tree is a Binary Search Tree ? \n"<<endl;
//INT_MAX & INT_MIN is passed as the initial maximum and minimum values
    cout<<"In 1st Method ? " <<isBSTCASE1(root,INT_MAX,INT_MIN)<<endl;
    cout<<"\nIn 2nd Method ? " <<isBSTCASE2(root,7)<<endl;
    return 0;
}
void BSTInsert(BSTNode*& root, int item)
{
    if(root == NULL){
        BSTNode* newNode  = new BSTNode;
        newNode->info = item;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
    }
    else if(item < root->info){
        BSTInsert(root->left, item);
    }
    else{
        BSTInsert(root->right, item);
    }
}
void PrintInOrder(BSTNode* root)
{
    if(root == NULL)
        return;
    else{
        PrintInOrder(root->left);
        cout<<root->info<<" ";
        PrintInOrder(root->right);
    }
}
//CASE 1 : EFFICIENT AND CORRCET APPROACH
/*EXPLANATION OF RECURSIVE APPROACH ::

  isBSTCASE1(root->left, root->info , min) is this case the root
  becomes the left child of previous root. And according to the BST
  definition the the the root value should be > than its left child
  value and should be < than its right child.
  Which is checked in the else if condition.

  So, by passing root->info in the function we are basically changing
  or updating the min and max values based on the left and right child.
*/
bool isBSTCASE1 (BSTNode* root, int max, int min)
{
    if(root == NULL)
        return true;

    else if(root->info < min || root->info > max)
        return false;
    else
        return isBSTCASE1(root->left, root->info, min) &&
         isBSTCASE1(root->right, max, root->info);
}
//CASE 2 :
bool isBSTCASE2(BSTNode* root,int size)
{
    if(root == NULL){
        cout<<"The tree is Empty, So it's BST by default"<<endl;
        return true;
    }
    //First Traverse the Tree in InOrder and Store the root values in an array
    int *arr = new int[size];
    //Starting index of the array is 0
    TraverseInOrder(root, arr);
    //Now check if the Array is in sorted order
    return isSorted(arr,size);
}
void TraverseInOrder(BSTNode* root, int *arr)
{
    if(root == NULL)
        return;
    //Traverse the left subtree
    TraverseInOrder(root->left, arr);
    //Insert the root value in the array
    arr[i] = root->info;
    cout <<"Arr "<<i<<" : "<<arr[i]<<endl;
    i++;
    //Traverse the right Subtree
    TraverseInOrder(root->right, arr);
}
bool isSorted(int *arr, int size)
{
/*In BST InOrder traversal we get the sorted order
 *So the values are inserted in sorted order in the Array
 *Just check if the tree is sorted or not.
*/
    cout <<"\nArray : ";
    for(int s=0; s<size; s++)
        cout <<arr[s] <<" ";
    cout <<endl;
    //Checking if the array is Sorted or not
    for(int s=0; s<size-1; s++){
        if(arr[s] > arr[s+1])
            return false;
    }
    return true;
}
