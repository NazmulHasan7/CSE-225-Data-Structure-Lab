#include <iostream>
#include "dynamicArray.h"
#include "dynamicArray.cpp"

using namespace std;

int main()
{
    dynamicArray obj;
    // allocating
    obj.allocate(5);

    // taking input
    int value;
    cout << "Enter values : \n\n";
    for(int i=0; i <5 ;i++)
    {
        cout <<"Element " <<i+1 << ": ";
        cin >> value;
        obj.setValue(i,value);
    }
    cout << endl;
    cout <<"\nThe values you have entered : \n";
    for(int i=0; i <5; i++)
    {
        cout << obj.getValue(i) <<"\t";
    }

    //using destructor
    obj.~dynamicArray();
    cout <<"\nAfter using destructor : \n";
    for(int i=0; i <5; i++)
    {
        cout << obj.getValue(i) <<"\t";
    }

    return 0;
}
