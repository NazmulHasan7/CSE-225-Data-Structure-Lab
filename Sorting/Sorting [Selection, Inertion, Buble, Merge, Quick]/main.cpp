#include <iostream>
#include "ArraySort.cpp"
using namespace std;

int main(void)
{
    ArraySort<int> List(10);
    cout << "Inserting 10 9 8 7 6 5 4 3 2 1" << endl;
    List.InsertElements(10);
    List.InsertElements(9);
    List.InsertElements(8);
    List.InsertElements(7);
    List.InsertElements(6);
    List.InsertElements(5);
    List.InsertElements(4);
    List.InsertElements(3);
    List.InsertElements(2);
    List.InsertElements(1);

    List.PrintArray();
    //List.SelectionSort();
    //List.InsertionSort();
    //List.BubbleSort();
    //List.MergeSort();
    List.QuickSort();
    cout<<"\nSorted : ";
    List.PrintArray();
    return 0;
}
