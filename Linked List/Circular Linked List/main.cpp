#include <iostream>
#include "Circular Linked List.cpp"
using namespace std;

int main()
{
    CircularLinkedList<int> list;
    list.Insert(100);
    list.Insert(200);
    list.Insert(300);
    list.Insert(400);
    list.Insert(500);

    cout << "Length is "<<list.LengthIs() << endl;
    list.Print();

    cout <<"Is 500 is in the list ? " <<list.Retrieve(500)<<endl;
    cout <<"Is 700 is in the list ? " <<list.Retrieve(700)<<endl;
    cout <<"Is 200 is in the list ? " <<list.Retrieve(200)<<endl;

    cout <<"\nDeleting 100 & 300 from the list : "<<endl;
    list.Delete(100);
    list.Delete(300);
    list.Print();

    cout <<"Is 500 is in the list ? " <<list.Retrieve(500)<<endl;
    cout <<"Deleting 500 from the list : "<<endl;
    list.Delete(500);
    list.Print();
    return 0;
}
