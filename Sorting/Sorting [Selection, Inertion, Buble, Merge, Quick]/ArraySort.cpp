#include "ArraySort.h"
#include <iostream>
using namespace std;

template<class T>
ArraySort<T>::ArraySort()
{
    length = 0;
    arr = new T[0];
    currentPosition = 0;
}
template<class T>
ArraySort<T>::ArraySort(int size)
{
    length = size;
    arr = new T[size];
    currentPosition = 0;
}
template<class T>
void ArraySort<T>::MakeEmpty()
{
    delete[] arr;
    length = 0;
}
template<class T>
bool ArraySort<T>::isEmpty()
{
    return (length == 0);
}
template<class T>
bool ArraySort<T>::isFull()
{
    return (length == currentPosition);
}
template<class T>
void ArraySort<T>::PrintArray()
{
    cout<<"Array : ";
    for(int i=0; i<length; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
template<class T>
int ArraySort<T>::Length()
{
    return length;
}
template<class T>
void ArraySort<T>::InsertElements(T item)
{
    if(isFull())
        cout<<"The Array is Full\nNo items can be inserted."<<endl;
    else{
        arr[currentPosition] = item;
        currentPosition++;
    }
}
template<class T>
void ArraySort<T>::Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
///SELECTION SORT------------------------------->
template<class T>
void ArraySort<T>::SelectionSort()
{
    int minIndex;
    for(int i=0; i<length-1; i++)
    {
        minIndex = GetMinimumIndex(arr,i,length);
        Swap(arr[i],arr[minIndex]);
    }
}
template<class T>
int ArraySort<T>::GetMinimumIndex(T *arr, int start, int end)
{
    int minimumIndex = start;
    for(int i=start+1; i<end; i++)
    {
        if(arr[i] < arr[minimumIndex])
            minimumIndex = i;
    }
    return minimumIndex;
}
///INSERTION SORT------------------------------->
template<class T>
void ArraySort<T>::InsertionSort()
{
    for(int i=0; i<length; i++)
        InsertItem(arr,0,i);
}
template<class T>
void ArraySort<T>::InsertItem(T *arr, int start, int end)
{
    while(end > 0)
    {
        if(arr[end] < arr[end-1])
        {
            Swap(arr[end],arr[end-1]);
            end--;
        }
    }
}
///BUBBLE SORT---------------------------------->
template<class T>
void ArraySort<T>::BubbleSort()
{
    int flag = 0;
    for(int i=0; i<length-1; i++)
    {
        BubbleUp(arr,i,length-1,flag);

        if(flag == 0)
            break;
    }
}
template<class T>
void ArraySort<T>::BubbleUp(T *arr, int start, int end, int &flag)
{
    for(int i=end; i>start; i--)
    {
        if(arr[i-1] > arr[i]){
            Swap(arr[i-1],arr[i]);
            flag++;
        }
    }
}

template<class T>
void ArraySort<T>::MergeSort()
{
    T *arr2 = new T[length];
    MergeSort(arr,arr2,0,length-1);
}
template<class T>
void ArraySort<T>::MergeSort(T *arr1, T*arr2, int start, int end)
{
    if(start < end)
    {
        int mid = (start+end)/2;
        MergeSort(arr1, arr2, start, mid);
        MergeSort(arr1, arr2, mid+1, end);
        Merge(arr1, arr2, start, mid, end);
    }
}
template<class T>
void ArraySort<T>::Merge(T *arr1, T *arr2, int start, int mid, int end)
{
    int i=start, j = mid+1, k = start;

    while(i <= mid && j <= end)
    {
        if(arr1[i] < arr1[j]){
            arr2[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr2[k] = arr1[j];
            k++;
            j++;
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
template<class T>
void ArraySort<T>::QuickSort()
{
    QuickSort(arr,0,length-1);
}
template<class T>
void ArraySort<T>::QuickSort(T *arr, int start, int end)
{
    if(start < end)
    {
        int partitionIndex = Partition(arr,start,end);
        QuickSort(arr,start,partitionIndex-1);
        QuickSort(arr,partitionIndex+1,end);
    }
}
template<class T>
int ArraySort<T>::Partition(T *arr, int start, int end)
{
    T pivot = arr[end];
    int pIndex = start;

    for(int i=start; i<end; i++)
    {
        if(arr[i] <= pivot){
            Swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    Swap(arr[pIndex],arr[end]);
    return pIndex;
}
