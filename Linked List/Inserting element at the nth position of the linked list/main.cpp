/*
Inserting element at the nth position of the linked list
Conditions : 1) The position is 1 or the list can be empty
             2) The position is greater than 1
             3) The position is invalid
*/
#include <iostream>

using namespace std;

//A global variable count to keep the track of the Inserted items
int count = 1;


//Node
struct Node
{
    int info;
    Node* next;
};

//Print Function
void Print(Node* head)
{
    Node* temp = head;
    cout << "\nList is : ";
    while(temp!= NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout <<endl;
}

//Insert Function
void Insert(Node** headPtr,int value,int pos)
{
    /*
    After every successful Insert() call the count is increased by 1
    means 1 item will be inserted
    */
    count++;
    //A new node will be created
    Node* temp = new Node;
    temp->info = value;

    //Now, we need to link the newly created node with other nodes
    if(pos == 1) //[Condition 1] List is empty or the position is 1
    {
        //temp->next points the first node or head node
        temp->next = *headPtr;
        //headPtr holds the address of the newly created node
        *headPtr = temp;
    }
    else //[Condition 12 List is not empty or the position is > 1
    {
        Node *temp2 = *headPtr;
        //Another new node to traverse through the list & find the position
        for(int i=1; i<pos-1; i++)
        {
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        //Now, temp->next has the address of next node to the position
        temp2->next = temp;
    }

}

int main(void)
{
    //Initially the node is empty, so head points to NULL
    Node* head = NULL;

    int input,position;
    char check = 'y';
    cout <<"Inserting element at nth position of a linked list [Press Y to insert again]: " <<endl;
    cout <<"----------------------------------------------------------------------------- " <<endl;
    do{
       try
       {
           cout << endl;
        cout <<"Enter an integer to insert--------: ";
        cin >> input;
        cout <<"Enter position to insert----------: ";
        cin >> position;
        //Handling invalid position [Condition 3]
        if(position <=0 || position >count)
            throw position;

        cout <<"Want to Insert again ?[Press 'y']-: ";
        cin >> check;

/* After an insertion, there may be a scenario that the head needed to be modified
   so here the address of head is passed to the Insert method. A pointer to a
   pointer is needed to receive it
*/
        Insert(&head,input,position);
        Print(head);
       }
       catch(int ex)
       {
           cout <<"Invalid Position. Position can not be " <<ex <<endl;
       }

    }while(check == 'y');
    return 0;
}
