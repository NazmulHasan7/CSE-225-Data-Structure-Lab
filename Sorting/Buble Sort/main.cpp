/*------------------------BUBBLE SORT----------------------------*
 *In case of Bubble sort : We take two elements and compare them *
 *A variable flag is used to check if the array is sorted or not *
 *Flag is used to trace if any swapping take place or not        *
 *If elements are swapped then the flag will be updated.         *
 *                                                               *
 *After BubbleUp functions returns, we will check if the flag is *
 *updated or not. If flag is not updated it means that the array *
 *is already sorted. So we don't need to run the loop anymore.   *
----------------------------------------------------------------*/
#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void BubbleUp(int arr[], int start, int end,int &flag)
{
    flag = 0;
    for(int i=end; i>start; i--)
    {
        if(arr[i-1] > arr[i]){
            Swap(arr[i-1],arr[i]);
            flag++;
        }
    }
}
void BubbleSort(int arr[], int len)
{
    int flag = 0;
    for(int i=0; i<len-1; i++)
    {
        BubbleUp(arr,i,len-1,flag);

        if(flag == 0)
            break;
    }
}
int main(void)
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    BubbleSort(arr,10);

    cout << "Sorted List : ";
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
