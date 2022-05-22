#include <iostream>
#include <string.h>
#include "TransportGraph.cpp"

using namespace std;

int main()
{
    TransportGraph<string> myGraph(8);
    cout<<"Vertex are : Dhaka  Rajshahi  Rangpur  Khulna  Barisal  Chittagong  Sylhet  Mymensingh"<<endl;
    string location[8] = {"Dhaka", "Rajshahi", "Rangpur", "Khulna",
                          "Barisal", "Chittagong", "Sylhet", "Mymensingh"};

    ///Inserting vertex
    for(int i=0; i<8; i++)
        myGraph.AddVertex(location[i]);
    cout<<"All Vertices are added"<<endl;

    ///Adding Edges
    myGraph.AddEdge("Rangpur","Mymensingh",1);
    myGraph.AddEdge("Mymensingh","Rangpur",1);

    myGraph.AddEdge("Rangpur","Barisal",1);
    myGraph.AddEdge("Barisal","Rangpur",1);

    myGraph.AddEdge("Rajshahi","Chittagong",1);
    myGraph.AddEdge("Chittagong","Rajshahi",1);

    myGraph.AddEdge("Rajshahi","Dhaka",1);
    myGraph.AddEdge("Dhaka","Rajshahi",1);

    myGraph.AddEdge("Khulna","Dhaka",1);
    myGraph.AddEdge("Dhaka","Khulna",1);

    myGraph.AddEdge("Barisal","Dhaka",1);
    myGraph.AddEdge("Dhaka","Barisal",1);

    myGraph.AddEdge("Dhaka","Mymensingh",1);
    myGraph.AddEdge("Mymensingh","Dhaka",1);

    myGraph.AddEdge("Dhaka","Sylhet",1);
    myGraph.AddEdge("Sylhet","Dhaka",1);

    myGraph.AddEdge("Dhaka","Chittagong",1);
    myGraph.AddEdge("Chittagong","Dhaka",1);

    myGraph.AddEdge("Sylhet","Chittagong",1);
    myGraph.AddEdge("Chittagong","Sylhet",1);

    myGraph.AddEdge("Chittagong","Barisal",1);
    myGraph.AddEdge("Barisal","Chittagong",1);

    myGraph.PrintAdjacencyMatrix();

    return 0;
}
