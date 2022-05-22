#include "dynamicArray.h"
#include <iostream>

using namespace std;

dynamicArray :: dynamicArray()
{
    data = NULL;
    size = 0;
}
dynamicArray :: dynamicArray(int s)
{
    data = new int[s];
    size = s;
}
dynamicArray :: ~dynamicArray()
{
    delete[] data;
}
int dynamicArray :: getValue(int index)
{
    return data[index];
}
void dynamicArray :: setValue(int index, int value)
{
    data[index] = value;
}
void dynamicArray :: allocate(int s)
{
    data = new int [s];
    size = s;
}
