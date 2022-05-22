#include <iostream>
#include "UnsortedList.cpp"
using namespace std;

int main(void)
{
    UnsortedType<int> list;
    int num,item;
    int ListItem;
    cout << "How many items do you want to insert ? ";
    cin >> num;
    cout << endl;

    cout << "Insert "<< num << " Items : ";
    for(int i=0; i<num; i++){
        cin >> item;
        list.InsertItem(item);
    }
    cout << "\nLength of the List is : "<< list.LengthIs()<< endl;
    cout << "\nPrinting List : ";
    for(int i=0; i<num; i++){
        list.GetNextItem(ListItem);
        cout << ListItem << " ";
    }
    cout << endl;

    cout << "\nInsert another item : ";
    cin >> item;
    list.InsertItem(item);
    cout << "\nLength of the List is : "<< list.LengthIs()<< endl;
    cout << "\nPrinting List : ";

    list.ResetList();
    for(int i=0; i<list.LengthIs(); i++){
        list.GetNextItem(ListItem);
        cout << ListItem << " ";
    }

    cout <<"\n\nEnter an item to retrieve : ";
    cin >> num;
    bool isFound;
    list.RetrieveItem(ListItem,isFound);

    if(isFound)
        cout <<"\nItem found"<< endl;
    else
        cout <<"\nNot found "<< endl;

    cout << "\nIs List full ? "<< list.IsFull() << endl;
    cout << "\nEnter an item to delete : ";
    cin >> num;
    list.DeleteItem(num);

    list.ResetList();
    cout << "\nPrinting List : ";
    for(int i=0; i<list.LengthIs(); i++){
        list.GetNextItem(ListItem);
        cout << ListItem << " ";
    }

    cout << "\nEnter another item to delete : ";
    cin >> num;
    list.DeleteItem(num);

    list.ResetList();
    cout << "\nPrinting List : ";
    for(int i=0; i<list.LengthIs(); i++){
        list.GetNextItem(ListItem);
        cout << ListItem << " ";
    }

}
