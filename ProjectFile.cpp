#include <iostream>
#include "Header.h"

using namespace std;
//
//int main()
//{
//
//    Graph maze(20);
//
//    // Add edges to create the maze structure
//    maze.addEdge(0, 1, REGULAR);
//    maze.addEdge(1, 2, REGULAR);
//    maze.addEdge(2, 3, REGULAR);
//    maze.addEdge(3, 4, REGULAR);
//    maze.addEdge(4, 5, REGULAR);
//    maze.addEdge(6, 7, REGULAR);
//    maze.addEdge(7, 8, REGULAR);
//    maze.addEdge(8, 9, REGULAR);
//    maze.addEdge(9, 10, REGULAR);
//    maze.addEdge(10, 11, REGULAR);
//    maze.addEdge(12, 13, REGULAR);
//    maze.addEdge(13, 14, REGULAR);
//    maze.addEdge(14, 15, REGULAR);
//    maze.addEdge(15, 16, REGULAR);
//    maze.addEdge(16, 17, REGULAR);
//    maze.addEdge(18, 19, REGULAR);
//    maze.addEdge(19, 20, REGULAR);
//    maze.addEdge(20, 21, REGULAR);
//    maze.addEdge(21, 22, REGULAR);
//    maze.addEdge(22, 23, REGULAR);
//
//    maze.mainMenu();
//   
//   
//    //g.dijkstra(0);
//
//    return 0;
//}

int main() {
    const int numberOfVertices = 16;
    Graph maze(numberOfVertices);

    // Adding edges to the graph
    maze.addEdge(0, 0, REGULAR);
    maze.addEdge(0, 1, REGULAR);
    maze.addEdge(0, 2, REGULAR);
    maze.addEdge(1, 3, REGULAR);
    maze.addEdge(2, 3, REGULAR);
    maze.addEdge(3, 3, REGULAR);
    maze.addEdge(4, 3, REGULAR);
    maze.addEdge(5, 3, REGULAR);
    maze.addEdge(6, 3, REGULAR);
    maze.addEdge(3, 2, REGULAR);
    maze.addEdge(3, 1, REGULAR);
    maze.addEdge(3, 7, REGULAR);
    maze.addEdge(3, 8, REGULAR);
    maze.addEdge(3, 9, REGULAR);
    maze.addEdge(4, 1, REGULAR);
    maze.addEdge(4, 7, REGULAR);
    maze.addEdge(5, 1, REGULAR);
    maze.addEdge(5, 3, REGULAR);
    maze.addEdge(5, 7, REGULAR);
    maze.addEdge(6, 1, REGULAR);
    maze.addEdge(6, 2, REGULAR);
    maze.addEdge(6, 3, REGULAR);
    maze.addEdge(6, 4, REGULAR);
    maze.addEdge(6, 7, REGULAR);
    maze.addEdge(7, 4, REGULAR);
    maze.addEdge(7, 7, REGULAR);
    maze.addEdge(7, 9, REGULAR);
    maze.addEdge(8, 4, REGULAR);
    maze.addEdge(8, 7, REGULAR);
    maze.addEdge(9, 4, REGULAR);
    maze.addEdge(9, 5, REGULAR);
    maze.addEdge(9, 6, REGULAR);
    maze.addEdge(9, 7, REGULAR);
    maze.addEdge(4, 9, REGULAR);
    maze.addEdge(5, 9, REGULAR);
    maze.addEdge(6, 9, REGULAR);
    maze.addEdge(7, 9, REGULAR);
    maze.addEdge(8, 9, REGULAR);
    maze.addEdge(9, 9, REGULAR);
    maze.addEdge(9, 10, REGULAR);
    maze.addEdge(9, 11, REGULAR);

    //maze.addEdge(3, 8, REGULAR);








    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    maze.printAdjList();
    cout << endl;

    // Print the adjacency grid
    maze.adjacencyGrid(maze, 16);

    return 0;
}