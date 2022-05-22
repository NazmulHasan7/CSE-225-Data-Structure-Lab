#include <iostream>
#include "DynamicArray.cpp"

using namespace std;

int main(void)
{
    DynamicArray<int> obj1(10);
    DynamicArray<double> obj2(10);

    for(int i=0; i<10; i++)
    {
        obj1.setValue(i,3*i+1);
        obj2.setValue(i,7.29*i/1.45);
    }
    for(int i=0; i<10; i++)
        cout << obj1.getValue(i) << "\t" << obj2.getValue(i) << endl;

    return 0;
}

