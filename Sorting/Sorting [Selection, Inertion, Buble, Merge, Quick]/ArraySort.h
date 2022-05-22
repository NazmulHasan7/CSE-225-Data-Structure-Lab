#ifndef ARRAYSORT_H_INCLUDED
#define ARRAYSORT_H_INCLUDED

template<class T>
class ArraySort
{
public :
    ArraySort();
    ArraySort(int size);
    int Length();
    void MakeEmpty();
    bool isEmpty();
    bool isFull();
    void PrintArray();
    void InsertElements(T item);
    void SelectionSort();
    void InsertionSort();
    void BubbleSort();
    void MergeSort();
    void QuickSort();

private :
    int length,currentPosition;
    T *arr;
    void Swap(T &a,T &b);
    int GetMinimumIndex(T arr[],int start,int end);
    void InsertItem(T *arr, int start, int end);
    void BubbleUp(T *arr, int start, int end, int &flag);
    void MergeSort(T *arr1, T*arr2, int start, int end);
    void Merge(T *arr1, T *arr2, int start, int mid, int end);
    void QuickSort(T *arr, int start, int end);
    int Partition(T *arr, int start, int end);
};

#endif // ARRAYSORT_H_INCLUDED
