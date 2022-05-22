//INSERTION SORT
#include <iostream>
using namespace std;

void Swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void InsertItem(int arr[], int start, int end)
{
    while(end > 0 && arr[end] < arr[end-1])
    {
        Swap(arr[end],arr[end-1]);
        end--;
    }
}
void InsertionSort(int arr[], int len)
{
    for(int i=0; i<len; i++){
        InsertItem(arr,0,i);
    }
}
int main(void)
{
    cout << "Inserted : 10,9,8,6,7,5,3,4,1,2,100,-5,77,16,0\n" << endl;
    int arr[15] = {10,9,8,6,7,5,3,4,1,2,100,-5,77,16,0};
    InsertionSort(arr,15);

    cout << "Sorted Array : ";
    for(int i=0; i<15; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
/*----------------------------------------------------------------------
template<class ItemType>
void InsertItem(ItemType values [], int startIndex, int endIndex)
{
	bool finished = false;
	int current = endIndex;
	bool moreToSearch = (current != startIndex);
	while (moreToSearch && !finished)
	{
		if (values[current] < values[current -1] )
		{
			Swap(values[current], values[current-1]);
			current--;
			moreToSearch = (current != startIndex);
		}
		else finished = true;
	}
)
----------------------------------------------------------------------*/
