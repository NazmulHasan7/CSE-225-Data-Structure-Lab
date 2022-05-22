///TASK : SORTED INSERT IN A BINARY SEARCH TREE
#include <iostream>
#include "Binary Search Tree.cpp"
using namespace std;

void SortedInsert(BST<int> &root, int *arr, int first, int last);

int main(void)
{
//TAKING INPUTS FROM THE USER
    BST<int> bstTree;
    int input,times;
    cout <<"How many items to be inserted ? ";
    cin >> times;
    cout <<"\nInsert "<<times<<" Items : ";
    for(int i=0; i<times; i++){
        cin >> input;
        bstTree.InsertItem(input);
    }
    cout <<"Insertion Complete\n"<<endl;
    bstTree.Print();

//SORTING THE USER GIVEN INPUTS AND STORING IT IN AN ARRAY
    int *arr = new int[bstTree.LengthIs()];
    int i=0;
    bool finished = false;

//RESET THE TREE IN INORDER [SORTED ORDER]
    bstTree.ResetTree(IN_ORDER);
    do{
        bstTree.GetNextItem(input,IN_ORDER,finished);
        arr[i] = input;
        i++;
    }while(!finished);

//NOW THE arr LIST IS SORTED
    cout <<"\nThe Sorted List : ";
    for(int i=0; i<10 ; i++)
        cout<<arr[i]<<"-->";
    cout<<"NULL\n"<<endl;

//NOW INSERT THE SORTED LIST IN A NEW TREE
    BST<int> newTree;
    SortedInsert(newTree,arr,0,bstTree.LengthIs()-1);
    newTree.Print();
    return 0;
}
void SortedInsert(BST<int> &root, int *arr, int first, int last)
{
    //BASE CASE
    if(first > last)
        return;
    //FINDING THE MID-POINT SO IT WILL BE THE ROOT
    int mid = (first + last)/2;
    root.InsertItem(arr[mid]);
    //RECURSIVELY BUILD THE LEFT SUBTREE
    SortedInsert(root, arr, first, mid-1);
    //RECURSIVELY BUILD THE RIGHT SUBTREE
    SortedInsert(root, arr, mid+1, last);
}
