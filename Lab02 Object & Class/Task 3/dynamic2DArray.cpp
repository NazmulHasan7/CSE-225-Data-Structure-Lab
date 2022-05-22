#include "Dynamic2DArray.h"

Dynamic2DArray::Dynamic2DArray()
{
    arr = NULL;
    rowSize = columnSize = 0;
}
Dynamic2DArray::Dynamic2DArray(int row,int col)
{
    allocate(row,col);
}
Dynamic2DArray::~Dynamic2DArray()
{
    for(int i=0; i<rowSize; i++)
    {
        delete []arr[i];
    }
    delete [] arr;
}
void Dynamic2DArray::allocate(int row, int col)
{
    arr = new int *[row];
    for(int i=0; i<row; i++)
    {
        arr[i] = new int[col];
    }
    rowSize = row;
    columnSize = col;
}
void Dynamic2DArray::setValue(int value,int row, int col)
{
    arr[row][col] = value;
}
int Dynamic2DArray::getValue(int row,int col)
{
    return arr[row][col];
}
