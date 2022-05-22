#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

int main()
{
    DoublyLinkedList<int> list1;
    DoublyLinkedList<int> list2;
    cout << "Unsorted List : " << endl;
    list1.InsertInList(100);
    list1.InsertInList(200);
    list1.InsertInList(300);
    list1.InsertInList(400);
    list1.InsertInList(500);
    list1.PrintList();
    list1.ReversePrint();

    cout <<"Sorted List : "<<endl;
    list2.SortedInsert(100);
    list2.SortedInsert(500);
    list2.SortedInsert(100);
    list2.SortedInsert(200);
    list2.SortedInsert(300);
    list2.PrintList();
    list2.ReversePrint();

    cout <<"Destructing : "<<endl;
    list1.~DoublyLinkedList();
    list1.PrintList();

    cout <<"Deleting 300 from sorted list : "<<endl;
    list2.DeleteFromList(300);
    list2.PrintList();
    list2.ReversePrint();
    cout <<"Deleting 500 from sorted list : "<<endl;
    list2.DeleteFromList(500);
    list2.PrintList();
    list2.ReversePrint();

    cout <<"\nIs 200 is in the list ? "<<list2.RetrieveItem(200)<<endl;
    cout <<"Is 700 is in the list ? "<<list2.RetrieveItem(700)<<endl;
    return 0;
}
