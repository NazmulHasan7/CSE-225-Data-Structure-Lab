#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

class dynamicArray
{
    private :
        int *data;
        int size;

    public  :
        dynamicArray();
        dynamicArray(int);
        // destructor
        ~dynamicArray();
        int getValue(int);
        void setValue(int ,int);
        void allocate (int );

};

#endif // DYNAMICARRAY_H_INCLUDED
