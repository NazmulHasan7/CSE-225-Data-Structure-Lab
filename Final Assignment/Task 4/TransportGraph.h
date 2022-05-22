#ifndef TRANSPORTGRAPH_H_INCLUDED
#define TRANSPORTGRAPH_H_INCLUDED

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
        void FindVertices(Vertex);
        void printSortedList(Vertex);

    private :
        void InsertLinkedListInSorted(Vertex);
        int numOfVertex;
        int maxNumOfVertex;
        Vertex* vertexList;
        int **edgeList;
        Node *head;
};
#endif // TRANSPORTGRAPH_H_INCLUDED
