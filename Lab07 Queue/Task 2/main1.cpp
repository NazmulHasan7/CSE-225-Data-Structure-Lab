#include <iostream>
#include "quetype.cpp"

using namespace std;

int main(void)
{
    QueType <string> binary;

    string temp;
    int num;
    cout << "Enter N [This program will print binary numbers from 1 to N] : ";
    cin >> num;
    cout << endl;

    binary.Enqueue("1");
    for(int i=0; i<num; i++)
    {
        binary.Dequeue(temp);
        cout <<temp<<endl;
        binary.Enqueue(temp+"0");
        binary.Enqueue(temp+"1");
    }
}
