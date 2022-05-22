#include <iostream>
#include "Queue.cpp"
using namespace std;

int main(void)
{
    Queue<int> list;
    cout <<"Empty > "<<list.isEmpty() << endl;
    list.Enqueue(10);
    list.Enqueue(20);
    list.Enqueue(30);
    list.Enqueue(40);
    list.Enqueue(50);
    list.PrintQueue();
    int X;
    list.Dequeue(X);
    cout << "Dequeued : " << X << endl;
    list.Dequeue(X);
    cout << "Dequeued : " << X << endl;
    list.Dequeue(X);
    cout <<"Empty > "<<list.isEmpty() << endl;
    cout << "Dequeued : " << X << endl;
    list.Dequeue(X);
    cout << "Dequeued : " << X << endl;
    list.Dequeue(X);
    cout << "Dequeued : " << X << endl;
    cout <<"Empty > "<<list.isEmpty() << endl;
    list.PrintQueue();

    return 0;
}
