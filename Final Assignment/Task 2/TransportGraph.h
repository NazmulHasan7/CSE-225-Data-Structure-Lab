#ifndef TRANSPORTGRAPH_H_INCLUDED
#define TRANSPORTGRAPH_H_INCLUDED

#include"Stack.h"
#include"Queue.h"

template<class Vertex>
class TransportGraph
{
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

    private :
        int numOfVertex;
        int maxNumOfVertex;
        bool *markList;
        Vertex* vertexList;
        int **edgeList;

};
#endif // TRANSPORTGRAPH_H_INCLUDED
