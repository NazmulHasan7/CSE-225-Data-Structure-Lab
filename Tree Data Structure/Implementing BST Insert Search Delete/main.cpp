#include <iostream>
#include "BST.cpp"
using namespace std;

int main(void)
{
        BST<int> bst;
        int times,input;
        MENU :
        cout <<"\t\tBINARY SEARCH TREE "<<endl;
        cout <<"\t\t------------------ "<<endl;
        cout <<"1--> BST-Insert\n2--> BST-Delete\n3--> BST-Search\n"<<
               "4--> Find Maximum\n5--> Find Minimum\n6--> BST-Print\n"<<
               "7--> BST-Height\n8--> BST-Length\n9--> Exit\n"<<endl;
        cout <<"Enter your choice : ";
        char ch;
        cin >> ch;
        switch(ch)
        {
            case '1' : cout <<"\nHow many elements to be inserted ? ";
                       cin >> times;
                       cout <<"Enter "<<times<< " integers : ";
                       for(int i=0; i<times ;i++){
                           cin >> input;
                           bst.Insert(input);
                       }
                       cout <<"Insertion complete\n"<<endl;
                       goto MENU;

            case '2' : cout<<"\nEnter an item to be deleted : ";
                       cin >> input;
                       bst.Delete(input);
                       cout <<"Deleted\n"<<endl;
                       goto MENU;

            case '3' : cout<<"\nEnter an item to be Searched : ";
                       cin >> input;
                       cout <<"Found ? "<<bst.Search(input)<<endl;
                       cout <<endl;
                       goto MENU;

            case '4' : cout <<"\nMaximum value : "<<bst.FindMaximum()<<endl;
                       cout <<endl;
                       goto MENU;

            case '5' : cout <<"\nMinimum value : "<<bst.FindMinimum()<<endl;
                       cout <<endl;
                       goto MENU;

            case '6' : cout <<"\nIn Order Tree : ";
                       bst.PrintInOrder();
                       cout <<"\nPost Order Tree : ";
                       bst.PrintPostOrder();
                       cout <<"\nPre Order Tree : ";
                       bst.PrintPreOrder();
                       cout <<"\n"<<endl;
                       goto MENU;

            case '7' : cout <<"\nHeight of Tree : "<<bst.HeightOfTree()<<endl;
                       cout <<endl;
                       goto MENU;

            case '8' : cout <<"\nTotal Nodes : "<<bst.LengthIs()<<endl;
                       cout <<endl;
                       goto MENU;

            default  : break;
        }
   return 0;
}
