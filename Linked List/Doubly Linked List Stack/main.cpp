#include <iostream>
#include "Stack.cpp"
using namespace std;

int main(void)
{
    Stack<int> list;
    cout <<"Pushing 100 200 300 400 500 in the Stack"<<endl;
    list.Push(100);
    list.Push(200);
    list.Push(300);
    list.Push(400);
    list.Push(500);
    list.PrintStack();

    cout <<"\nPopping from the Stack and Printing : " <<endl;
    int X;
    list.Pop(X);
    cout <<"Popped "<<X<<endl;
    list.PrintStack();

    list.Pop(X);
    cout <<"Popped "<<X<<endl;
    list.PrintStack();

    cout <<"\nIs Stack Empty ? "<<list.isEmpty()<<endl;
    return 0;
}
