#ifndef TRANSPORTGRAPH_H_INCLUDED
#define TRANSPORTGRAPH_H_INCLUDED

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

    private :
        int numOfVertex;
        int maxNumOfVertex;
        Vertex* vertexList;
        int **edgeList;

};
#endif // TRANSPORTGRAPH_H_INCLUDED
