#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

template <class ItemType>

class DynamicArray{

private :
    ItemType *arr;
    int size;
public :
    DynamicArray();
    DynamicArray(int);
    ~DynamicArray();
    void allocate(int);
    ItemType getValue(int);
    void setValue(int, ItemType);
};


#endif // DYNAMICARRAY_H_INCLUDED
