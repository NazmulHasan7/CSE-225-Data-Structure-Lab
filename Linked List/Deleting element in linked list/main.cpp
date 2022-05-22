/*
Deleting node in a linked list
Condition : 1) Deleting the 1st node
            2) Deleting the nth node
*/
#include <iostream>

using namespace std;
//Node
struct Node
{
    int info;
    Node* next;
};
//Deleting using index
void DeleteNode(Node** headPtr ,int n)
{
    Node* temp = *headPtr;
    //Case 1 : deleting 1st index
    if(n == 1)
    {
        /*
        Head pointer now points the next node
        so the previous head node is linked free
        */
        *headPtr = temp->next;
        delete temp;
    }
    else
    {
        for(int i=1; i<n-1; i++)
        {
            temp = temp->next;
        }
        /*temp points (n-1)th node &
          temp->next points nth node
        */
        Node* temp2 = temp->next;
        /*temp2 points nth node &
          temp2->next points (n+1)th node
        */
        temp->next = temp2->next;
        //temp->next points n+1th node
        delete temp2;
    }
}
//Printing
void Print(Node* head)
{
    cout <<"\nList is : ";
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->info <<" ";
        temp = temp->next;
    }
    cout << endl;
}
//Deleting using value
void Delete(Node** head, int value)
{
    //If item is found in the first node
    Node *temp = *head;
    if(temp->info == value)
    {
        *head = temp->next;
        delete temp;
    }
    else
    {
        while(temp!= NULL)
    {
        if((temp->next)->info == value) //Item found
            break; //Terminate the loop if item is found
        else //Move to the next node
            temp = temp->next;
    }
    Node* temp2 = temp->next;
    //temp2 points the n th node
    temp->next = temp2->next;
    //temp->next points n+1th node
    }

}
int main(void)
{
    //Creating nodes and Inserting elements
    Node *A = new Node;
    A->info = 100;
    Node *B = new Node;
    B->info = 200;
    Node *C = new Node;
    C->info = 300;
    Node *D = new Node;
    D->info = 700;
    Node *E = new Node;
    E->info = 500;
    //Linking the nodes
    Node* head = A;
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = NULL;

    Print(head);

    char choice;
    cout <<"\nDelete the list : \n1)Using index \n2)Using element \n\nYour choice ?"
    <<endl;
    cin >> choice;
        if(choice == '1')
        {
            int index;
            cout <<"Enter index to delete[Starts from 1]: ";
            cin >> index;
            DeleteNode(&head,index);
            Print(head);
        }
        else if(choice == '2')
        {
            int value;
            cout <<"Enter value to delete : ";
            cin >> value;
            Delete(&head,value);
            Print(head);
        }
        else
        cout << "Invalid choice" << endl;
    return 0;
}
