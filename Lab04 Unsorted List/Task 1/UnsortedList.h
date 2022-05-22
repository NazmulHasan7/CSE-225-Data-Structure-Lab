#ifndef UNSORTEDLIST_H_INCLUDED
#define UNSORTEDLIST_H_INCLUDED

const int max = 100;
template <class ItemType>
class UnsortedType{

private :
    ItemType list [max];
    int length;
    int currentPosition;
public :
    UnsortedType();
    UnsortedType(int);
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void ResetList();
    void GetNextItem(ItemType&);
    void RetrieveItem(ItemType&, bool&);
    void InsertItem(ItemType);
    void DeleteItem(ItemType);

};

#endif // UNSORTEDLIST_H_INCLUDED
