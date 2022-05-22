#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};
void PrintForward(Node* head)
{
    //Base case
    if(head == NULL)
        return;
    //Recursive case
    else
    {
        //Printing before function call
        cout <<" "<<head->info;
        PrintForward(head->next);
    }
}
void PrintReverse(Node* head)
{
    //Base case
    if(head == NULL)
        return;
    else
    {
        PrintReverse(head->next);
        //Printing while returning
        cout <<" "<<head->info;
    }
}
int main(void)
{
    Node *head;
    //Creating nodes
    Node *A = new Node;
    Node *B = new Node;
    Node *C = new Node;
    Node *D = new Node;

    A->info = 100;
    B->info = 200;
    C->info = 300;
    D->info = 400;

    head = A;
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = NULL;

    cout <<"List is : ";
    PrintForward(head);
    cout <<endl;
    cout <<"Reverse List is : ";
    PrintReverse(head);
    cout <<endl;
    return 0;
}
