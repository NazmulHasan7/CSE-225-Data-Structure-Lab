#include <iostream>

using namespace std;

int main(void)
{
    int row,column;
    TAKE_INPUT :
    try
    {
        // Taking user input for rows and columns
        cout << "Enter row    : ";
        cin >> row;
        if(row < 0)
            throw row;
        // Declaring a pointer to pointer
        // Arr holds the address of a 2D array
        char **arr = new char *[row];

        cout << "Enter column : ";
        cin >> column;
        if(column < 0)
            throw column;

        for(int i=0; i<row; i++)
        {
            arr[i] = new char[column];
        }
        // Filling array
        cout <<"\nEnter values [Characters] : "<<endl;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                cout <<"Element ["<<i<<"]["<<j<<"] : ";
                cin >> arr[i][j];
            }
        }
        //Printing array
        cout <<"\nOutput Array : "<<endl;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                cout << arr[i][j]<<"\t";
            }
            cout<<endl;
        }
        //Deallocating array
        for(int i=0; i<row; i++)
        {
            delete [] arr[i];
        }
        delete [] arr;

        //Printing after deletion
        cout <<"\nOutput Array after deletion : "<<endl;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                cout << arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    catch(int ex)
    {
        cout << "Please enter a valid positive integer."<<endl;
        goto TAKE_INPUT;
    }

    return 0;
}
