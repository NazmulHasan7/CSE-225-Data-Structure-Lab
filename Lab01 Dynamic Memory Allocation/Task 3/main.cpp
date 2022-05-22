#include <iostream>

using namespace std;

int main(void)
{
    int row,column;
    TAKE_INPUT :
    try
    {
        //Taking user input for rows and columns
        cout << "Enter row : ";
        cin >> row;
        if(row < 0)
            throw row;
        //Declaring a pointer to pointer
        //arr holds the address of a 2D array
        int **arr = new int *[row];
        //An array to store the column numbers
        int columnArray[5];
        int input;
        //Taking column inputs
        for(int i=0; i<row; i++)
        {
            cout<<"How many columns for row "<<i+1<<" ? ";
            cin >> input;
            if(input < 0)
                throw input;

            columnArray[i] = input;
            arr[i] = new int [input];
        }
        //Filling array
        cout <<"\nEnter values [Integers] : "<<endl;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<columnArray[i]; j++)
            {
                cout <<"Element ["<<i<<"]["<<j<<"] : ";
                cin >> arr[i][j];
            }
        }
        //Printing array
        cout <<"\nOutput Array : "<<endl;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<columnArray[i]; j++)
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
            for(int j=0; j<columnArray[i]; j++)
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
