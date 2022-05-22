/*Inserting a node at the beginning of the list
  Condition : 1) The list is empty
              2) The list is not empty
*/
#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};
/*head in the main function is a pointer to a node & address of node is passed to Insert
  So a pointer to a pointer needed [Node** headPtr] to modify the head after Insertion
*/
void Insert(Node** headPtr, int info)
{
    //A temporary node to create new node every time
    Node* temp = new Node;
    temp->info = info;

    //Checking if the list is empty or not
    if(*headPtr == NULL){
        temp->next = NULL;
    }
    else if(*headPtr != NULL){
        temp->next = *headPtr;
        //Now temp->next has the address of next node
    }
    *headPtr = temp;
}
void PrintList(Node* head)
{
    cout <<"List : ";
    while(head != NULL){
        cout << head->info <<" ";
        head = head->next;
    }
}
int main(void)
{
    //To trace the first node
    Node* head = NULL;
    int input;
    cout <<"Enter elements in the list [press 0 to exit] : " <<endl;
    do{
        try{
            cout <<"\nEnter an integer : ";
            cin >> input;
            //Inserting elements and printing the list after every Insertion
            Insert(&head,input);
            //Since we will add items at the very first node each time,
            //so head will be changed after each insertion
            PrintList(head);
        }
        catch(exception ex){
            cout << "Enter a valid number"<<endl;
        }
    }while(input !=0);
    return 0;
}
