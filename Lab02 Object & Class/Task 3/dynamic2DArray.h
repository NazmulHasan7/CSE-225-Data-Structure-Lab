#ifndef DYNAMIC2DARRAY_H_INCLUDED
#define DYNAMIC2DARRAY_H_INCLUDED

class Dynamic2DArray{

private :
    int **arr;
    int rowSize, columnSize;
public :
    Dynamic2DArray();
    Dynamic2DArray(int,int);
    ~Dynamic2DArray();
    void allocate(int,int);
    void setValue(int,int,int);
    int getValue(int,int);
};

#endif // DYNAMIC2DARRAY_H_INCLUDED
