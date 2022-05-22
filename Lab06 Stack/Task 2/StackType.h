#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

const int maxItem = 10;

class FullStack{
    /*Exception class thrown by push
     *when stack is full */
};
class EmptyStack{
    /*Exception class thrown by pop and
     *top when stack is empty */
};
template <class T>

class StackType{

private :
    int top;
    T list[maxItem];
public :
    StackType();
    bool isFull();
    bool isEmpty();
    int length();
    void Push(T);
    void Pop();
    T Tops();
    void PrintStack();

};


#endif // STACKTYPE_H_INCLUDED
