#ifndef TRANSPORTGRAPH_H_INCLUDED
#define TRANSPORTGRAPH_H_INCLUDED

#include"Stack.h"
#include"Queue.h"

template<class Vertex>
class TransportGraph
{
    //Using Doubly Linked List
    struct Node
    {
        Vertex info;
        Node *next;
        Node *previous;
    };
    public :
        TransportGraph(int size);
        ~TransportGraph();
        bool IsEmpty();
        bool IsFull();
        void MakeEmpty();
        void AddVertex(Vertex);
        void AddEdge(Vertex, Vertex, int);
        void PrintAdjacencyMatrix();
        void MarkVertex(Vertex);
        bool IsVertexMarked(Vertex);
        void ClearAllMarks();
        void GoToVertices(Vertex, Queue<Vertex>&);
        void DFSGraph(Vertex, Vertex);
        void BFSGraph(Vertex, Vertex);
        void PrintLinkedList();
        void printSortedList(Vertex);

    private :
        void InsertInSortedLinkedList(Vertex);
        void InsertInLinkedList(Vertex);
        int numOfVertex;
        int maxNumOfVertex;
        bool *markList;
        Vertex* vertexList;
        int **edgeList;
        Node *head;
        Node *headPtrOfSortedList;
};
#endif // TRANSPORTGRAPH_H_INCLUDED
