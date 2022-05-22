#ifndef QUEUETYPE_H_INCLUDED
#define QUEUETYPE_H_INCLUDED
const int maxSize = 10;

class FullQueue{};
class EmptyQueue{};

template <class T>
class QueueType{

private :
    int size;
    int front;
    int rear;
    T* list;
public :
    QueueType();
    QueueType(int);
    ~QueueType();
    void MakeEmpty();
    bool IsFull();
    bool IsEmpty();
    void Enqueue(T);
    void Dequeue(T&);

};

#endif // QUEUETYPE_H_INCLUDED
