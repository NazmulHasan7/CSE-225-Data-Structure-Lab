/*--------------------------------------------------------------------------------------|
|------------------------------MERGE SORT-----------------------------------------------|
| Using the Divide and Conquer technique, we divide a problem into subproblems. When the|
| solution to each subproblem is ready, we 'combine' the results from the subproblems to|
| solve the main problem.                                                               |
|---------------------------------------------------------------------------------------|
| Suppose we had to sort an array A. A subproblem would be to sort a sub-section of this|
| array starting at index p and ending at index r, denoted as A[p..r].                  |
|---------------------------------------------------------------------------------------|
| Divide                                                                                |
| If q is the half-way point between p and r, then we can split the subarray A[p..r]    |
| into two arrays A[p..q] and A[q+1, r].                                                |
|---------------------------------------------------------------------------------------|
| Conquer                                                                               |
| In the conquer step, we try to sort both the subarrays A[p..q] and A[q+1, r]. If we   |
| haven't yet reached the base case, we again divide both these subarrays and try to    |
| sort them.                                                                            |
|---------------------------------------------------------------------------------------|
| Combine                                                                               |
| When the conquer step reaches the base step and we get two sorted subarrays A[p..q]   |
| and A[q+1, r] for array A[p..r], we combine the results by creating a sorted array    |
| A[p..r] from two sorted subarrays A[p..q] and A[q+1, r].                              |
----------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;
void Merge(int arr1[], int arr2[], int start, int mid, int end)
{
    cout <<"Merge Function Called" <<endl;
    cout <<"In Merge Function Start "<<start<<" Mid "<<mid<<" End "<<end<<endl<<endl;
    int i=start,j=mid+1,k=start;

    while(i <= mid && j <= end)
    {
        if(arr1[i] < arr1[j]){
            arr2[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr2[k] = arr1[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        arr2[k] = arr1[i];
        i++;
        k++;
    }
    while(j <= end){
        arr2[k] = arr1[j];
        j++;
        k++;
    }
    for(int x=start; x<=end; x++)
        arr1[x] = arr2[x];
}
void MergeSort(int arr1[], int arr2[], int start, int end)
{
    if(start < end)
    {
        int mid = (start+end)/2;
        cout <<"\nSTART : "<<start<<" MID : "<<mid<<" Value : "<<arr1[mid]<<" END : "<<end <<endl;
        cout <<"MergeSort Function Called -> LEFT" <<endl;
        MergeSort(arr1,arr2,start,mid);
        cout <<"MergeSort Function Called -> RIGHT" <<endl;
        MergeSort(arr1,arr2,mid+1,end);
        cout <<"PASSING TO MERGE\n" <<endl;
        Merge(arr1,arr2,start,mid,end);
    }
}
int main(void)
{
    int arr1[6] = {6,5,12,10,9,1};
    int arr2[6];
    cout << "6,5,12,10,9,1 Inserted" << endl;

    MergeSort(arr1,arr2,0,5);
    cout << "Sorted Array : ";
    for(int i=0; i<6; i++)
        cout << arr1[i] << " ";
    cout << endl;
    return 0;
}
