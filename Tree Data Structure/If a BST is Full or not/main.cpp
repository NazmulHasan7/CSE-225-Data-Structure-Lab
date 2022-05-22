///CHECK IF A GIVEN BINARY TREE IS A FULL TREE OR NOT
#include <iostream>
using namespace std;
/*----------------------------------------------------|
 * According to FULL BST definition the tree root has |
 * either 0 child or 2 child                          |
 * So, we just need to handle this two conditions     |
 *----------------------------------------------------|
*/
struct BSTNode
{
    int info;
    BSTNode* left;
    BSTNode* right;
};
void BSTInsert(BSTNode*& root, int item);
void Print(BSTNode* root);
bool isFullTree(BSTNode* root);

int main(void)
{
    BSTNode* root = NULL;
    cout<<"Inserting in BST\n=>=>=>=>=>=>=>=>"<<endl;
    BSTInsert(root,15);
    BSTInsert(root,10);
    BSTInsert(root,20);
    BSTInsert(root, 8);
    BSTInsert(root,12);
    BSTInsert(root,17);
    BSTInsert(root,25);

    cout<<"Insertion complete\n"<<endl;

    cout<<"In Order Traversal : ";
    Print(root);
    cout<<endl;

    cout<<"\nIs the Tree is a Full Tree ? "<<isFullTree(root)<<endl;
    return 0;
}
void BSTInsert(BSTNode*& root, int item)
{
    if(root == NULL){
        BSTNode* newNode = new BSTNode;
        newNode->info = item;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
    }
    else if(item < root->info)
        BSTInsert(root->left, item);
    else
        BSTInsert(root->right, item);
}
void Print(BSTNode* root)
{
    if(root == NULL)
        return;

    Print(root->left);
    cout<<root->info<<" ";
    Print(root->right);
}
bool isFullTree(BSTNode* root)
{
    //CASE:EMPTY TREE
    if(root == NULL)
        return true;
    //CASE:THE NODE IS A LEAF NODE
    else if(root->left == NULL && root->right == NULL)
        return true;
    //CASE:THE ROOT HAS BOTH LEFT AND RIGHT CHILD
    //SO CHECK BOTH THE LEFT AND RIGHT SUBTREE RECURSIVELY
    else if((root->left != NULL) && (root->right != NULL))
        return (isFullTree(root->left) && isFullTree(root->right));
    //ELSE:THE ROOT HAS EITHER LEFT CHILD OR RIGHT CHILD ONLY
    return false;
}
