#include <iostream>

using namespace std;

int main(void)
{
    int size;

    TAKE_INPUT :
    try
    {
        cout << "Enter an array size : ";
        cin >>size;

        if(size < 0)
            throw size;
    }
    catch(int size)
    {
        cout << "Please enter a valid positive integer."<<endl;
        goto TAKE_INPUT;
    }

    //Allocating dynamic memory
    int *arr = new int[size];

    cout << "\nEnter values  : " <<endl;
    for(int i=0; i<size; i++)
    {
        cout <<"Element "<<i+1<<" : ";
        cin >> arr[i];
    }
    //Printing
    cout <<"\n\nThe input array is : ";
    for(int i=0; i<size; i++)
    {
        cout <<arr[i]<<" ";
    }
    //Deallocating memory
    delete [] arr;
    cout <<"\n\nAfter deletion the input array is : ";
    for(int i=0; i<size; i++)
    {
        cout <<arr[i]<<" ";
    }

    return 0;
}
