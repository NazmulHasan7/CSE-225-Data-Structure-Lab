#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED

class dynArr
{
    private :
        int *data;
        int size;

    public  :
        dynArr();
        dynArr(int);
        // destructor
        ~dynArr();
        int getValue(int);
        void setValue(int ,int);

};

#endif // DYNARR_H_INCLUDED
