#include <iostream>
#include "SortedList.cpp"
using namespace std;

int main(void)
{
    SortedList<int> list;
    list.InsertItem(2);
    list.Print();
    cout <<endl;
    list.InsertItem(1);
    list.Print();
    cout <<endl;
    list.InsertItem(5);
    list.Print();
    cout <<endl;
    list.InsertItem(10);
    list.Print();
    cout <<endl;
    list.InsertItem(4);
    list.Print();
    cout <<endl;
    list.InsertItem(7);
    list.Print();
    cout <<endl;


    cout<<"\nIs list Empty ? "<<list.isEmpty()<<endl;
    cout<<"Is list Full ? "<<list.isFull()<<endl;

    int input;
    cout <<"Enter an item to delete : ";
    cin >> input;
    list.DeleteItem(input);
    list.Print();
    cout <<endl;
    cout <<"Enter an item to search : ";
    cin >> input;
    cout <<"Is Found ? " <<list.RetrieveItem(input);
    cout <<endl;

    list.MakeEmpty();
    list.Print();
    cout<<"\nIs list Empty ? "<<list.isEmpty()<<endl;

    return 0;
}
