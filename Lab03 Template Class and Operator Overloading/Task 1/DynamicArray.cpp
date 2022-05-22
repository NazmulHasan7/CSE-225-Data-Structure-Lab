#include "DynamicArray.h"

template <class ItemType>
DynamicArray<ItemType>::DynamicArray()
{
    arr = NULL;
    size = 0;
}
template <class ItemType>
DynamicArray<ItemType>::DynamicArray(int s)
{
    arr = new ItemType[s];
    size = s;
}
template <class ItemType>
DynamicArray<ItemType>::~DynamicArray()
{
    delete [] arr;
}
template <class ItemType>
void DynamicArray<ItemType>::allocate(int s)
{
    arr = new ItemType[s];
    size = s;
}
template <class ItemType>
void DynamicArray<ItemType>::setValue(int index, ItemType value)
{
    arr[index] = value;
}
template <class ItemType>
ItemType DynamicArray<ItemType>::getValue(int index)
{
    return arr[index];
}
