#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    cout << "Bismillah"<<endl;
    Graph g(4); //graph with 4 vertices
    g.addEdge(0,1,0); //edge bw 0 and 1
    g.addEdge(0,2,1); //edge bw 0 and 2
    g.addEdge(2, 3,2);
    g.addEdge(1, 2,0); //bidirectional
    g.printAdjList();

    g.dijkstra(0);

    return 0;
}