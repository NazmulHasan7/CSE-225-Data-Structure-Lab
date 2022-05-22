#include <iostream>
#include "UnsortedList.cpp"

using namespace std;

int main(void)
{
    UnsortedList<int> list;
    cout << "Inserting items:::::::::::::::::::::: \n" << endl;
    list.InsertItem(10);
    list.Print();
    list.InsertItem(20);
    list.Print();
    list.InsertItem(50);
    list.Print();
    list.InsertItem(70);
    list.Print();
    list.InsertItem(199);
    list.Print();

    int input;
    cout <<"\nEnter an integer to search : ";
    cin >> input;
    cout <<"Found? " << list.RetrieveItem(input);

    cout <<"\nEnter an integer to delete : ";
    cin >> input;
    list.DeleteItem(input);
    list.Print();

    cout <<"\nIs list Full ? " <<list.isFull();
    cout <<"\nIs list Empty ? " <<list.isEmpty();

    return 0;
}
