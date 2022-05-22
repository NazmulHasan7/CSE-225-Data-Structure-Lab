#include <iostream>
using namespace std;

struct Node{
    int info;
    Node* next;
};

int main(void)
{
    //To trace the address of the first node
    Node* head;
    //Creating an empty node
    Node* A = new Node;
    //Copying the address of the first node to head
    head = A;
    //Inserting item to the node
    A->info = 100;
    A->next = NULL;
    //Creating another node
    Node* B = new Node;
    B->info = 200;
    //Copying the address of node B to A->next
    A->next = B;
    B->next = NULL;

    cout << "Printing Node Information : " << endl;
    //Creating a  temporary node
    Node* temp;
    //Copies the Address of the head node to temp
    //Since linked list can be accessed through the head only
    temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        cout <<"\nNode "<<count<<"\nElement : "
        <<temp->info<<"\nAddress : "<<temp->next<<endl;
        //Copies the address of next Node to temp
        temp = temp->next;
    }
    return 0;
}
