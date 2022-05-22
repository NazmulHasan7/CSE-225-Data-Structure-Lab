#include <iostream>
#include "Stack.cpp"
using namespace std;

int main(void)
{
    Stack<int> list;
    list.Push(10);
    list.Push(20);
    list.Push(40);
    list.Push(50);
    list.Print();

    cout <<endl;
    cout <<"Is Stack Empty ? " <<list.isEmpty()<<endl;
    cout <<"Is Stack Full ? " <<list.isFull()<<endl;

    cout <<"Top ? " <<list.Top()<<endl;
    list.Pop();
    cout <<"After 1st POP : "<<endl;
    list.Print();
    list.Pop();
    cout <<"\nAfter 2nd POP : "<<endl;
    list.Print();
    list.Pop();
    cout <<"\nAfter 3rd POP : "<<endl;
    list.Print();
    list.Pop();
    cout <<"\nAfter Last POP : "<<endl;
    list.Print();

    cout <<"Is Stack Empty ? " <<list.isEmpty()<<endl;
    cout <<"Is Stack Full ? "  <<list.isFull()<<endl;
    return 0;
}
