#pragma once
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <ctime>

using namespace std;

const int REGULAR = 0;
const int POWER_UP = 1;
const int OBSTACLE = 2;
int prime = 0;
void menu();
int navigateMenu(int currentOption, int totalOptions);



//The Node structure represents each element in the adj list
struct node
{
	int data;
	node* next;
	int type; //0: regular, 1: power up, 2: obstacle
};

class Graph
{
	int vertices;
	node** adjLists; //array of pointers where each pointer points to the head of a linked list (representing the adjacency list of a vertex)
public:

	Graph(int vertices)
	{
		this->vertices = vertices;
		adjLists = new node * [vertices];
		for (int i = 0; i < vertices; i++) {
			adjLists[i] = nullptr;
		}

	}

	void addEdge(int x, int y, int type) 
	{
		
		//creating new nodes
	  
		node* newNode = new node;
		newNode->data = y;
		newNode->type = type;
		newNode->next = adjLists[x];
		adjLists[x] = newNode;

		if (isConnected(y, x)) {
			node* newNode2 = new node;
			newNode2->data = x;
			newNode2->type = type;
			newNode2->next = adjLists[y];
			adjLists[y] = newNode2;
		}

	}

	void printAdjList() {
		for (int i = 0; i < vertices; i++) {
			cout << "Vertex " << i << "->";
			node* newNode = adjLists[i];
			while (newNode)
			{
				cout << newNode->data << " ";
				newNode = newNode->next;
			}
			cout << endl;
		}
	}

	bool isConnected(int x, int y) {
		//to check if two nodes are connected
		node* temp = adjLists[x];
		while (temp != nullptr) {
			if (temp->data == y) return true;
			temp = temp->next;
		}
		return false;
	}

	template <typename T>
	class NewVector {
		T* arr;
		int capacity;
		int size;
	public:
		NewVector() :capacity(10), size(0) {
			arr = new T[capacity];
		}

		void push_back(T value) {
			//this function doubles the capacity of the vector when it is full
			if (size == capacity) {
				T* newArr = new T[2 * capacity];
				for (int i = 0; i < size; i++) {
					newArr[i] = arr[i];
				}
				delete[] arr;
				arr = newArr;
				capacity = capacity * 2;
			}
			arr[size] = value;
			size++;
		}
		//the operator method is to access elements
		T& operator[](int index) {
			/*if (index < 0 || index >= size) {
				throw out_of_range("Index out of range");
			}*/
			return arr[index];
		}

		int getSize() {
			return size;
		}

		~NewVector() {
			delete[] arr;
		}

	};

	void dijkstra(int src) {

		NewVector<int> distance;
		NewVector<bool> sptSet; //keeps track of vertices included in the shortest path tree
		//once a vertice has been added to the sptSet it cannot be considered again

		for (int i = 0; i < vertices; i++) {
			distance.push_back(INT_MAX);
			sptSet.push_back(false);
		}
		//distance from source to start is zero
		distance[src] = 0;

		for (int count = 0; count < vertices - 1; count++) {
			int u = minDistance(distance, sptSet);
			sptSet[u] = true;

			node* temp = adjLists[u];
			while (temp != nullptr) {
				int v = temp->data;

				//edit distance acc to type of node
				if (temp->type == OBSTACLE) {
					distance[v] = distance[u] + 1 - 5; //minus score by 5

				}
				else if (temp->type == POWER_UP) {
					distance[v] = distance[u] + 1 + 2;//plus 2 for power up

				}
				else {
					distance[v] = distance[u] + 1;
				}




				////need to prevent repetition of vertices in shortest tree
				//if (!sptSet[vertices] && distance[u] != INT_MAX && distance[u] + 1 < distance[v]) {
				//	distance[vertices] = distance[u] + 1;
				//}
				temp = temp->next;
			}
		}

		printSolution(distance, vertices);
	}

	int minDistance(NewVector<int>& distance, NewVector<bool>& sptSet) {
		int min = INT_MAX, min_index = -1;

		for (int v = 0; v < vertices; v++) {
			if (sptSet[v] == false && distance[v] <= min) {
				min = distance[v], min_index = v;
			}
		}
		if (min_index == -1) {
			return -1;
		}
		return min_index;
	}

	void printSolution(NewVector<int>& distance, int n)
	{
		cout << "Vertex \t Distance from Source \n";
		for (int i = 0; i < n; i++)
		{
			cout << i << "\t\t" << distance[i] << "\n";
		}
	}

	void printMaze()
	{
		for (int i = 0; i < vertices; i++)
		{
			cout << i;
			node* newNode = adjLists[i];

			while (newNode)
			{
				if (newNode->type == REGULAR)
				{
					cout << " --- " << newNode->data;
				}
				else if (newNode->type == POWER_UP)
				{
					cout << "+++" << newNode->data;
				}
				else
				{
					cout << "###" << newNode->data;
				}

				newNode = newNode->next;  // Move to the next node
			}

			cout << endl;
		}
	}

	//void printAdjacencyGrid(node** adjLists, int numberOfVertices) {
	//	for (int i = 0; i < numberOfVertices; ++i) {
	//		cout << "Vertex " << i << ": ";

	//		node* current = adjLists[i];  // Start with the head of the linked list

	//		while (current != nullptr) {
	//			cout << current->data << " ";
	//			current = current->next;
	//		}

	//		cout << endl;
	//	}
	//}

	int getAttribute(int x, int y)
	{
		node* temp = adjLists[x];
		while (temp != nullptr) 
		{
			if (temp->data == y)
			{
				return temp->type;
			}
			temp = temp->next;
		}
		return -1; // Return -1 if there is no connection
	}

	void adjacencyGrid(Graph& myGraph, int a) {
		int numberOfVertices = a;

		// column index
		cout << "    ";
		for (int col = 0; col < numberOfVertices; ++col) {
			cout << col << " ";
		}
		cout << endl;

		for (int i = 0; i < numberOfVertices; ++i) {
			// row index
			if (i <= 9) {
				cout << "0" << i << " ";
			}
			else {
				cout << i << " ";
			}

			for (int j = 0; j < numberOfVertices; ++j) {
				int type = myGraph.getAttribute(i, j);
				char symbol = ' ';

				switch (type) {
				case REGULAR:
					setColor(3); // purple
					symbol = '+';
					break;
				case POWER_UP:
					setColor(10); // green
					symbol = '*';
					break;
				case OBSTACLE:
					setColor(4); // red
					symbol = '#';
					break;
				}

				cout << symbol << " ";
			}
			cout << endl;
		}

		setColor(15); // white
	}








	////////////////////////////////////////////////////////////////////////////////////////////////////




	void startSound()
	{
		Beep(500, 500);
		Sleep(500);
		Beep(500, 550);
		Sleep(500);
		Beep(501, 950);
	}

	void setColor(int color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	void resetColor()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Reset to default color
	}




	void menuOption(int option)
	{
		prime = option;
		menu();
		switch (option)
		{
		case 1:
			cout << "\
>START GAME\n\
 RESUME GAME\n\
 EXIT\n\
 HIGH SCORES\n";
			prime = 1;
			break;
		case 2:
			cout << "\
 START GAME\n\
>RESUME GAME\n\
 EXIT\n\
 HIGH SCORES\n";
			prime = 2;
			break;
		case 3:
			cout << "\
 START GAME\n\
 RESUME GAME\n\
>EXIT\n\
 HIGH SCORES\n";
			prime = 3;
			break;
		case 4:
			cout << "\
 START GAME\n\
 RESUME GAME\n\
 EXIT\n\
>HIGH SCORES\n";
			prime = 4;
			break;
		}


		char key = _getch();


		// FOR SELECTION OF OPTIONS
		if (key == 13 && prime == 1)
		{
			startSound();
			system("cls");
			printMaze();

		}


		if (key == 13 && prime == 2)
		{
			system("cls");
		}


		if (key == 13 && prime == 3)
		{
			//displayTestMessage();
		}


		if (key == 13 && prime == 4)
		{
			//displayTestMessage();
		}
	}

	void menu()
	{
		system("cls");
		int choice = 0;

		setColor(13);
		cout << "\
  ____             ____             _                                 \n\
/ ____| __ _ _ __ |  _ \\ __ _  ___(_)_ __   __ _                    \n\
| |   / _` | '__| | |_) / _` |/ __| | '_ \\ / _` |     ______        \n\
| |__| (_| | |    |  _ < (_| | (__| | | | | (_| |    /|_||_\\` __    \n\
 \\____\\__,_|_|    |_| \\_\\__,_|\\___|_|_| |_|\\__, |   (   _    _ _||  \n\
                                           |___/    =`-(_)--(_)-'   \n\n\n\
==============================================================================\n\n";
	}

	void mainMenu()
	{

		int option = 1;
		const int totalOptions = 4;
		char key = '0';
		while (option != 99)
		{
			menuOption(option);
			// Get user input and update the selected option
			option = navigateMenu(option, totalOptions);

			// Add a small delay for better visualization (optional)
			// Sleep(10);
		}
	}

	int navigateMenu(int currentOption, int totalOptions)
	{
		char key = _getch(); // skip the [
		char arrow = _getch();
		switch (arrow)
		{ // the real value
		case 'A':
		case 'H':
			// code for arrow up
			return (currentOption > 1) ? currentOption - 1 : totalOptions;
			break;
		case 'B':
		case 'P':
			return (currentOption < totalOptions) ? currentOption + 1 : 1;
			// code for arrow down
			break;
		default:
			cout << key;
			return currentOption; // No change
		}
	}


};


struct Queue
{
	int front, rear, capacity;
	int* queue;

	Queue(int capacity)
	{
		front = rear = 0;
		this->capacity = capacity;

		queue = new int[capacity];
	}

	~Queue()
	{
		delete[] queue;
	}

	void enqueue(int data)
	{
		if (capacity == rear)
		{
			std::cout << "Queue is full." << std::endl;
			return;
		}
		else {
			queue[rear] = data;
			rear++;
		}
	}
	int dequeue()
	{
		if (front == rear)
		{
			std::cout << "Queue is empty." << std::endl;
			return -1; // Assuming -1 is an invalid value
		}

		int dequeuedValue = queue[front];
		for (int i = 0; i < rear - 1; i++) {
			queue[i] = queue[i + 1];
		}

		// decrement rear
		rear--;

		return dequeuedValue;
	}

};
