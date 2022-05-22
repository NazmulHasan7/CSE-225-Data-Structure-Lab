#include "UnsortedList.h"

template <class ItemType>
UnsortedType<ItemType>::UnsortedType(){
    length = 0;
    currentPosition = -1;
}
template <class ItemType>
UnsortedType<ItemType>::UnsortedType(int size){
    length = size;
    currentPosition = -1;
    ItemType list[length];
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty(){
    length = 0;
}
template <class ItemType>
bool UnsortedType<ItemType>::IsFull(){
    return (length == max);
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs(){
    return length;
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList(){
    currentPosition = -1;
}
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item){
    currentPosition++;
    item = list[currentPosition];
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item){
    list[length] = item;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item){
    int location = 0;
    while(item != list[location]){
        location++;
    }
    list[location] = list[length -1];
    length--;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found){
    int location = 0;
    bool moreToSearch = (location < length);
    found = false;

    while(moreToSearch && !found){
        if(item == list[location]){
            found = true;
            item = list[location];
        }
        else {
           location++;
           moreToSearch = (location < length);
        }
    }

}
