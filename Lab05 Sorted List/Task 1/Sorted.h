#ifndef SORTED_H_INCLUDED
#define SORTED_H_INCLUDED

const int max = 100;

template <class T>
class SortedList{

private :
    int length;
    int currentPosition;
    T list [max];
public :
    SortedList();
    SortedList(int);
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void ResetList();
    void GetNextItem(T&);
    void InsertItem(T);
    void DeleteItem(T);
    void RetrieveItem(T&, bool&);

};

#endif // SORTED_H_INCLUDED
