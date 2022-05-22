#include <iostream>
#include <queue>
using namespace std;

struct BSTNode
{
    int info;
    BSTNode* left;
    BSTNode* right;
};
void Insert(BSTNode*& root, int item);
void LevelOrderTraversal(BSTNode* root);

int main(void)
{
    BSTNode* root = NULL;
    int times, input;
    cout << "How many elements to be inserted ? ";
    cin >> times;

    cout << "Enter elements : ";
    for(int i=0; i<times; i++){
        cin >> input;
        Insert(root,input);
    }
    cout <<"\nInsertion Complete\n"<<endl;

    cout <<"Level Order Traversal : ";
    LevelOrderTraversal(root);
    return 0;
}
void Insert(BSTNode*& root, int item)
{
    if(root == NULL){
        BSTNode* newNode = new BSTNode;
        newNode->info = item;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
    }
    else if(item < root->info){
        Insert(root->left,item);
    }
    else{
        Insert(root->right,item);
    }
}
///ALGORITHM :-------------------------------------------
/* 1) First Enqueue or Push the root to a Queue
 * 2) Take out or Dequeue the front node from the Queue
 *    And Visit the node
 * 3) Enqueue it's children(left , right) in the Queue
 * Do repeat step 2 and 3 until the the Queue is empty */
///------------------------------------------------------
void LevelOrderTraversal(BSTNode* root)
{
    if(root == NULL)
        return;
    BSTNode* currentNode;
    queue<BSTNode*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        currentNode = Q.front();
        cout <<currentNode->info<<" ";

        if(currentNode->left != NULL)
            Q.push(currentNode->left);
        if(currentNode->right != NULL)
            Q.push(currentNode->right);

        Q.pop();
    }
}
