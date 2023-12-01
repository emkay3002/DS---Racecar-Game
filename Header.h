#pragma once
#include <iostream>

using namespace std;

//The Node structure represents each element in the adj list
struct node
{
	int data; 
	node* next;

};

class Graph {
	int vertices;
	node** adjLists; //array of pointers where each pointer points to the head of a linked list (representing the adjacency list of a vertex)
public:

	Graph(int vertices) {
		this->vertices = vertices;
		adjLists = new node*[vertices];
		for (int i = 0; i < vertices; i++) {
			adjLists[i] = nullptr;
		}

	}

	void addEdge(int x, int y) {
		//creating new nodes
		node* newNode = new node;
		newNode->data = y;
		newNode->next = adjLists[x];
		adjLists[x] = newNode;

		newNode = new node;
		newNode->data = x;
		newNode->next = adjLists[y];
		adjLists[y] = newNode;
	}

	void printAdjList() {
		for (int i = 0; i < vertices; i++) {
			cout << "Vertex " << i << "->";
			node* newNode = adjLists[i];
			while (newNode) {
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
			temp = temp-> next;
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

				//need to prevent repetition of vertices in shortest tree
				if (!sptSet[vertices] && distance[u] != INT_MAX && distance[u] + 1 < distance[v]) {
					distance[vertices] = distance[u] + 1;
				}
				temp = temp->next;
			}
		}

		printSolution(distance, vertices);
	}

	int minDistance(NewVector<int>& distance, NewVector<bool>& sptSet) {
		int min = INT_MAX, min_index=-1;

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

	void printSolution(NewVector<int>& distance, int n) {
		cout << "Vertex \t Distance from Source \n";
		for (int i = 0; i < n; i++) {
			cout << i << "\t\t" << distance[i] << "\n";
		}
	}

};


