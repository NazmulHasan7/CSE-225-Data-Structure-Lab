#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

template<class T>
class BST
{
    struct BSTNode{
        T info;
        BSTNode* left;
        BSTNode* right;
    };
public :
    BST();
    bool isEmpty();
    bool isFull();
    void Insert(T item);
    bool Search(T item);
    void Delete(T item);
    void PrintInOrder();
    void PrintPostOrder();
    void PrintPreOrder();
    T FindMaximum();
    T FindMinimum();
    int HeightOfTree();
    int LengthIs();

private :
    BSTNode* root;
    int length;
    void BSTInsert(BSTNode* &root, T item);
    void BSTDelete(BSTNode* &root, T item);
    bool BSTSearch(BSTNode* root, T item);
    void DeleteNode(BSTNode* &root);
    T FindMaximum(BSTNode* root);
    T FindMinimum(BSTNode* root);
    int HeightOfTree(BSTNode* root);
    void PrintInOrder(BSTNode* root);
    void PrintPostOrder(BSTNode* root);
    void PrintPreOrder(BSTNode* root);
    int CountNodes(BSTNode* root);

};

#endif // BST_H_INCLUDED
