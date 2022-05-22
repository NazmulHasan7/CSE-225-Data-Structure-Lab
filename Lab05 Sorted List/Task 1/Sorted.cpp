#include "Sorted.h"

template <class T>
SortedList<T>::SortedList(){
    length = 0;
    currentPosition = -1;
}
template <class T>
SortedList<T>::SortedList(int size){
    length = 0;
    currentPosition = -1;
    T list [size];
}
template <class T>
void SortedList<T>::MakeEmpty(){
    length = 0;
}
template <class T>
int SortedList<T>::LengthIs(){
    return length ;
}
template <class T>
bool SortedList<T>::IsFull(){
    return (length == max);
}
template <class T>
void SortedList<T>::ResetList(){
    currentPosition = -1;
}
template <class T>
void SortedList<T>::GetNextItem(T& item){
    currentPosition++;
    item = list[currentPosition];
}
template <class T>
void SortedList<T>::InsertItem(T item){
    int location = 0;
    bool moreToSearch = location < length;

    while(moreToSearch){
        if(item > list[location]){
            location++;
            moreToSearch = location < length;
        }
        else
            moreToSearch = false;
    }
    for(int i=length; i>location; i--){
        list[i] = list[i-1];
    }
    list[location] = item;
    length++;
}
template <class T>
void SortedList<T>::DeleteItem(T item){
    int location = 0;
    bool moreToSearch = location < length;

    while(item != list[location] && moreToSearch){
        location++;
        moreToSearch = location < length;
    }
    for(int i = location+1 ; i<length; i++){
        list[i-1] = list[i];
    }
    length--;
}
template <class T>
void SortedList<T>::RetrieveItem(T& item, bool &found){
    int first,last,midpoint;
    found = false;

    first = 0;
    last = length -1;
    bool moreToSearch = (first <= last);

    while(moreToSearch && !found){
        midpoint = (first + last)/2;
        if(item > list[midpoint]){
            first = midpoint+1;
            moreToSearch = (first <= last);
        }
        else if(item < list[midpoint]){
            last = midpoint-1;
            moreToSearch = (first <= last);
        }
        else{
            found = true;
            item = list[midpoint];
        }
    }
}
