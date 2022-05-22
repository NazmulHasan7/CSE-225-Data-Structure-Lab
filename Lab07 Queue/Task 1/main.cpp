#include <iostream>
#include "QueueType.cpp"

using namespace std;

int main()
{
    QueueType <int> q(5);

    int i,j,k;
    cout<<"How much you want to insert: "<<endl;
    cin>>j;

    if(q.IsEmpty())
        cout<< "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    cout<<"enter the values: "<<endl;
    for(i=0; i<(j-1); i++)
    {
        cin>>k;
        q.Enqueue(k);
    }

    if(q.IsEmpty())
        cout<< "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    if(q.IsFull())
        cout<< " Queue is Full" << endl;
    else
        cout << "Queue not Full" << endl;

    cout<<"Enter another data: ";
    cin>>k;
    q.Enqueue(k);

    if(q.IsFull())
        cout<< " Queue is Full" << endl;
    else
        cout << "Queue not Full" << endl;


    QueueType <int> q1(j);
    int item;
    while(q.IsEmpty()!=true)
    {
        q.Dequeue(item);
        cout << item << " ";
        q1.Enqueue(item);
    }

    cout<<endl;
    cout<<"Enter another data: ";
    cin>>k;
    q1.Enqueue(k); //Overflow



    q1.Dequeue(k);
    q1.Dequeue(k);

    QueueType <int> q2(j);
    int item1;
    while(q1.IsEmpty()!=true)
    {
        q1.Dequeue(item1);
        cout << item1 << " ";
        q2.Enqueue(item1);
    }

    q2.Dequeue(k);
    q2.Dequeue(k);
    q2.Dequeue(k);


    if(q2.IsEmpty())
        cout<< "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    //Underflow
    q2.Dequeue(k);
}
