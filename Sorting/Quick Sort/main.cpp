/*-----------------------------------------------------------|
|------------------------QUICK SORT--------------------------|
| Divide                                                     |
| The array is divided into subparts taking pivot as the     |
| partitioning point. The elements smaller than the pivot are|
| placed to the left of the pivot and the elements greater   |
| than the pivot are placed to the right.                    |
|------------------------------------------------------------|
| Conquer                                                    |
| The left and the right subparts are again partitioned using|
| the by selecting pivot elements for them. This can be      |
| achieved by recursively passing the subparts into the      |
| algorithm.                                                 |
|------------------------------------------------------------|
| Combine                                                    |
| This step does not play a significant role in quick sort.  |
| The array is already sorted at the end of the conquer step.|
|-----------------------------------------------------------*/
#include <iostream>
using namespace std;

int Partition (int Arr[], int start, int end);
void QuickSort(int Arr[], int start, int end);
void Swap(int &a, int &b);

int main(void)
{
    cout << "Inserting 7,2,1,6,8,5,3,4 in Array" << endl << endl;
    int Arr[8] = {7,2,1,6,8,5,3,4};

    QuickSort(Arr,0,7);

    cout << "Sorted Array : ";
    for(int i=0; i<8; i++)
        cout << Arr[i] << " ";
    cout << endl;
    return 0;
}
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void QuickSort(int Arr[], int start, int end)
{
    if(start < end)
    {
        ///PARTITIONING THE ARRAY AND GETTING THE PARTITION INDEX
/*--------------------------------------------------------------|
| Partition(Arr,start,end) Basically rearrange the array in     |
| such order so that the elements < pivot are in the left of the|
| pivot. And the elements > pivot stays at the right of pivot   |
|---------------------------------------------------------------|
*/      int pIndex = Partition(Arr,start,end);

        ///RECUSIVELY SORT THE LEFT SEGEMENT OF THE PARTITION
        QuickSort(Arr,start,pIndex-1);
        ///RECUSIVELY SORT THE RIGHT SEGEMENT OF THE PARTITION
        QuickSort(Arr,pIndex+1,end);
    }
}
int Partition(int Arr[], int start, int end)
{
    int pivot = Arr[end];
    int partitionIndex = start;

    for(int i=start; i<end; i++)
    {
        if(Arr[i] <= pivot)
        {
            Swap(Arr[i],Arr[partitionIndex]);
            partitionIndex++;
        }
    }
    Swap(Arr[partitionIndex],Arr[end]);
    return partitionIndex;
}
