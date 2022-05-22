#include <iostream>
#include "Dynamic2DArray.cpp"

using namespace std;

int main(void)
{
    int row,col;
    cout <<"How many rows and columns ? ";
    cin >> row >> col;

    Dynamic2DArray obj10(row,col);

    // creating an object Dynamic2DArray with the user input
    Dynamic2DArray obj(row,col);
    cout << "\n\nEnter values : \n";
    int value;
    for(int i =0 ; i<row; i++)
    {
        for(int j=0; j<col ; j++)
        {
            cout <<"Element ["<<i<<"] ["<<j<<"] : ";
            cin >> value;
            obj.setValue(value,i,j);
        }
    }
    cout << endl;

    // Printing
    cout <<"\nThe values you have entered : \n";
    for(int i =0 ; i<row; i++)
    {
        for(int j=0; j<col ; j++)
        {
            cout << obj.getValue(i,j)<< "\t";
        }
        cout << endl;
    }

    // Destructing
    obj.~Dynamic2DArray();
    cout <<"\nAfter destructing object : \n";
    for(int i =0 ; i<row; i++)
    {
        for(int j=0; j<col ; j++)
        {
            cout << obj.getValue(i,j)<< "\t";
        }
        cout << endl;
    }

    return 0;
}
