#include <iostream>
#include "dynArr.h"
#include "dynArr.cpp"

using namespace std;

int main(void)
{
    // creating an object with default constructor
    dynArr obj1;
    // creating an object with size 5
    dynArr obj2(5);

    int value;
    for(int i =0 ; i <5 ; i++)
    {
        cout <<"Enter value in position "<< i+1 << ": ";
        cin >> value;
        obj2.setValue(i,value);
    }
    cout << "\n\nValues you have entered : \n";
    for(int i=0 ; i<5 ;i++)
    {
        cout <<obj2.getValue(i)<<"\t";
    }

    // destroying obj2
    obj2.~dynArr();
    cout << "\n\nAfter destroying : \n";
    for(int i=0 ; i<5 ;i++)
    {
        cout <<obj2.getValue(i)<<"\t";
    }


    return 0;
}
