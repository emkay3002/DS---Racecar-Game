#include <iostream>
#include "Header.h"

using namespace std;




int main()
{
    const int numberOfVertices = 20;
    Graph maze(numberOfVertices);
    int type1 = 0;

    srand(time(0)); 

    int numberOfEnqueues = 50;
    Queue myQueue(51); 

    for (int i = 0; i < numberOfEnqueues; ++i)
    {
        int randomNumber = rand() % 3; 

        myQueue.enqueue(randomNumber);
    }

    int ran = myQueue.dequeue();

 
    maze.addEdge(0, 0, REGULAR);
    maze.addEdge(0, 1, REGULAR);
    maze.addEdge(0, 2, myQueue.dequeue());
    maze.addEdge(0, 3, REGULAR);
    maze.addEdge(0, 4, myQueue.dequeue());
    maze.addEdge(0, 5, REGULAR);
    maze.addEdge(0, 6, REGULAR);
    maze.addEdge(0, 16, myQueue.dequeue());
    maze.addEdge(1, 1, REGULAR);
    maze.addEdge(1, 6, REGULAR);
    maze.addEdge(1, 16, myQueue.dequeue());
    maze.addEdge(2, 1, REGULAR);
    maze.addEdge(2, 6, myQueue.dequeue());
    maze.addEdge(2, 16, REGULAR);
    maze.addEdge(3, 1, myQueue.dequeue());
    maze.addEdge(3, 6, REGULAR);
    maze.addEdge(3, 10, REGULAR);
    maze.addEdge(3, 11, myQueue.dequeue());
    maze.addEdge(3, 12, REGULAR);
    maze.addEdge(3, 13, REGULAR);
    maze.addEdge(3, 14, myQueue.dequeue());
    maze.addEdge(3, 15, REGULAR);
    maze.addEdge(3, 16, myQueue.dequeue());
    maze.addEdge(4, 1, REGULAR);
    maze.addEdge(4, 6, myQueue.dequeue());
    maze.addEdge(4, 16, REGULAR);
    maze.addEdge(5, 1, myQueue.dequeue());
    maze.addEdge(5, 6, REGULAR);
    maze.addEdge(5, 7, myQueue.dequeue());
    maze.addEdge(5, 8, REGULAR);
    maze.addEdge(6, 1, REGULAR);
    maze.addEdge(6, 6, myQueue.dequeue());
    maze.addEdge(6, 8, REGULAR);
    maze.addEdge(6, 9, REGULAR);
    maze.addEdge(6, 10, myQueue.dequeue());
    maze.addEdge(6, 11, REGULAR);
    maze.addEdge(6, 12, REGULAR);
    maze.addEdge(6, 13, myQueue.dequeue());
    maze.addEdge(6, 14, REGULAR);
    maze.addEdge(6, 15, myQueue.dequeue());
    maze.addEdge(6, 16, REGULAR);
    maze.addEdge(7, 1, REGULAR);
    maze.addEdge(7, 2, REGULAR);
    maze.addEdge(7, 3, myQueue.dequeue());
    maze.addEdge(7, 4, REGULAR);
    maze.addEdge(7, 8, myQueue.dequeue());
    maze.addEdge(7, 11, REGULAR);
    maze.addEdge(8, 1, REGULAR);
    maze.addEdge(8, 8, REGULAR);
    maze.addEdge(8, 11, myQueue.dequeue());
    maze.addEdge(9, 1, REGULAR);
    maze.addEdge(9, 8, REGULAR);
    maze.addEdge(9, 11, myQueue.dequeue());
    maze.addEdge(10, 1, REGULAR);
    maze.addEdge(10, 8, REGULAR);
    maze.addEdge(10, 11, myQueue.dequeue());
    maze.addEdge(10, 12, REGULAR);
    maze.addEdge(10, 13, myQueue.dequeue());
    maze.addEdge(10, 14, REGULAR);
    maze.addEdge(10, 15, myQueue.dequeue());
    maze.addEdge(10, 16, REGULAR);
    maze.addEdge(10, 16, REGULAR);
    maze.addEdge(10, 17, myQueue.dequeue());
    maze.addEdge(11, 1, REGULAR);
    maze.addEdge(11, 1, myQueue.dequeue());
    maze.addEdge(11, 8, myQueue.dequeue());
    maze.addEdge(11, 11, REGULAR);
    maze.addEdge(12, 0, REGULAR);
    maze.addEdge(12, 1, REGULAR);
    maze.addEdge(12, 2, myQueue.dequeue());
    maze.addEdge(12, 3, REGULAR);
    maze.addEdge(12, 4, REGULAR);
    maze.addEdge(12, 5, myQueue.dequeue());
    maze.addEdge(12, 6, REGULAR);
    maze.addEdge(12, 7, myQueue.dequeue());
    maze.addEdge(12, 8, REGULAR);
    maze.addEdge(12, 11, REGULAR);
    maze.addEdge(13, 2, REGULAR);
    maze.addEdge(13, 11, myQueue.dequeue());
    maze.addEdge(13, 11, REGULAR);
    maze.addEdge(14, 2, REGULAR);
    maze.addEdge(14, 11, REGULAR);
    maze.addEdge(15, 2, REGULAR);
    maze.addEdge(15, 3, myQueue.dequeue());
    maze.addEdge(15, 4, REGULAR);
    maze.addEdge(15, 5, myQueue.dequeue());
    maze.addEdge(15, 6, REGULAR);
    maze.addEdge(15, 7, myQueue.dequeue());
    maze.addEdge(15, 8, REGULAR);
    maze.addEdge(15, 9, myQueue.dequeue());
    maze.addEdge(15, 10, REGULAR);
    maze.addEdge(15, 11, REGULAR);
    maze.addEdge(15, 12, myQueue.dequeue());
    maze.addEdge(15, 13, REGULAR);
    maze.addEdge(15, 14, REGULAR);
    maze.addEdge(15, 15, myQueue.dequeue());
    maze.addEdge(15, 16, REGULAR);
    maze.addEdge(15, 17, myQueue.dequeue());
    maze.addEdge(15, 18, REGULAR);
    maze.addEdge(15, 19, REGULAR);
    maze.addEdge(16, 4, REGULAR);
    maze.addEdge(16, 9, myQueue.dequeue());
    maze.addEdge(16, 19, REGULAR);
    maze.addEdge(17, 4, REGULAR);
    maze.addEdge(17, 9, myQueue.dequeue());
    maze.addEdge(17, 19, REGULAR);
    maze.addEdge(18, 4, REGULAR);
    maze.addEdge(18, 9, myQueue.dequeue());
    maze.addEdge(18, 19, REGULAR);
    maze.addEdge(19, 19, 9);
    //maze.addEdge(20, 19, 9);

    
    maze.mainMenu();

    return 0;
}
