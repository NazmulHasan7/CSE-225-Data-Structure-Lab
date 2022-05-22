#include <iostream>
#include "Sorted.cpp"

using namespace std;

int main(void)
{
    SortedList<int> obj;
    cout << "Length of the list is  : "<< obj.LengthIs()<< endl;
    int num;
    cout << "\nHow many items do you want to Store ? ";
    cin >> num;
    cout << "\nEnter elements : ";

    int input;
    for(int i=0; i<num ; i++){
        cin >> input;
        obj.InsertItem(input);
    }
    obj.ResetList();
    cout << "\nPrinting list in sorted order : ";
    int listItem;
    for(int i=0; i<num ; i++){
        obj.GetNextItem(listItem);
        cout << listItem << " ";
    }
    int itemToFound;
    cout << "\n\nEnter an item to found : ";
    cin >> itemToFound;
    obj.ResetList();

    bool isFound;
    obj.RetrieveItem(itemToFound,isFound);
    if(isFound)
        cout <<"\nItem found";
    else
        cout <<"\nNot found";

    isFound = false;
    cout << "\n\nEnter another item to found : ";
    cin >> itemToFound;
    obj.ResetList();

    obj.RetrieveItem(itemToFound,isFound);
    if(isFound)
        cout <<"\nItem found";
    else
        cout <<"\nNot found";

    cout << "\n\nEnter another item to delete : ";
    cin >> itemToFound;
    obj.ResetList();
    obj.DeleteItem(itemToFound);

    cout << "\nPrinting list : ";
    obj.ResetList();
    for(int i=0; i<num ; i++){
        obj.GetNextItem(listItem);
        cout << listItem << " ";
    }

    cout << "\nIs list full ? " <<obj.IsFull();

    return 0;
}
