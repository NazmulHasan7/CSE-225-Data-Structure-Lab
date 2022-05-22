#include <iostream>
#include "UnsortedList.cpp"
using namespace std;

int main(void)
{
    UnsortedList<int> list;
    list.InsertItem(100);
    list.InsertItem(200);;
    list.InsertItem(300);
    list.InsertItem(400);
    list.InsertItem(500);

    list.PrintList();
    cout <<"After Deleting 300 : " <<endl;
    list.DeleteItem(300);
    list.PrintList();

    int x = 700;
    bool found;
    list.RetrieveItem(x,found);
    cout <<x <<" Found ? " << found << endl;

    x = 500;
    list.RetrieveItem(x,found);
    cout <<x <<" Found ? " << found << endl;

    list.ResetList();
    list.GetNextItem(x);
    cout <<"1st item : " << x << endl;

    cout<<"Length of the list : " << list.LengthIs() <<endl;

    list.MakeEmpty();
    list.PrintList();
    cout <<"Is list Empty ? " << list.isEmpty() << endl;

    return 0;
}
