/*--------------------------------------*
 *SELECTION SORT :                      *
 *1)Scan the array from starting index  *
 *  to the end of the array & find      *
 *  the minimum element.                *
 *2)Now swap the minimum element with   *
 *  the index from where the Scanning   *
 *  started.                            *
 *3)Do repeat Step 1 & 2 [In this case  *
 *  the starting index will the starting*
 *  index of previous scan + 1          *
 ----------------------------------------
 */

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int len);
int GetMinIndex(int arr[], int i, int len);
void Swap(int &num1, int &num2);
void PrintArray(int arr[], int len);

int main(void)
{
    int noOfInputs,input;
    cout << "How many elements to be Inserted ? ";
    cin >> noOfInputs;
    cout << "Enter elements : ";

    int arr[noOfInputs];

    for(int i=0; i<noOfInputs; i++){
        cin >> input;
        arr[i] = input;
    }
    cout << "\nSorted Array : ";
    SelectionSort(arr,noOfInputs);
    PrintArray(arr,noOfInputs);

    return 0;
}
//PRINTING ARRAY
void PrintArray(int arr[], int len)
{
    for(int i=0; i<len; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
//SWAPPING TWO NUMBERS
void Swap(int &num1, int &num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
//GETTING MINIMUM ELEMENTS INDEX
int GetMinIndex(int arr[], int i, int len)
{
    int minIndex = i;
    for(int j=i+1; j<len; j++){
        if(arr[j] < arr[minIndex]){
            minIndex = j;
        }
    }
    return minIndex;
}
//SELECTION SORT
void SelectionSort(int arr[], int len)
{
    int minIndex;
    for(int i=0; i<len-1; i++){

        minIndex = GetMinIndex(arr,i,len);
        Swap(arr[i],arr[minIndex]);
    }
}
/*SELECTION SORT---------------------------|
|void SelectionSort(int arr[], int len)    |
|{                                         |
|    int minIndex;                         |
|    for(int i=0; i<len-1; i++){           |
|        minIndex = i;                     |
|                                          |
|        for(int j=i+1; j<len; j++){       |
|            if(arr[j] < arr[minIndex]){   |
|                minIndex = j;             |
|            }                             |
|        }                                 |
|        int temp = arr[minIndex];         |
|        arr[minIndex] = arr[i];           |
|        arr[i] = temp;                    |
|    }                                     |
|}----------------------------------------*/


