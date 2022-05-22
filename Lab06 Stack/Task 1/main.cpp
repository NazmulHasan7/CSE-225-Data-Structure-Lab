#include <iostream>
#include "StackType.cpp"
using namespace std;

int main(void)
{
    StackType <int> obj;

    bool check = obj.isEmpty();
    if(check)
        cout << "Stack is empty" << endl;
    else
         cout << "Stack is not empty" << endl;

    int num,input;
    cout << "How many elements do you  want to push ? ";
    cin >> num;

    cout << "Enter elements : ";
    for(int i=0; i<num; i++){
        cin >> input;
        obj.Push(input);
    }
    cout << endl;
    cout << "Printing stack : ";
    obj.PrintStack();

    cout << "Enter another value to push: ";
    cin >> input;
    obj.Push(input);

    if(obj.isFull()) {
        cout<< "Stack is full" << endl;
    }
    else {
        cout << "Stack is not full" << endl;
    }

    cout << "\nPopping 2 elements ";
    obj.Pop();
    obj.Pop();

    cout<< "\nThe top item is " << obj.Tops() << endl;
    return 0;
}

