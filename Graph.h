#pragma once
#include "List.h"
#include "Queue.h"
#include <iostream>

#define infiniti -1

using namespace std;

class Graph
{
private:
	int _start;
	int _end;
	int numOfVertices;

public:
	List* VerticesArray;
	//Ctors & Dtor
	Graph();
	Graph(int numOfVertices);
	~Graph();

	Graph& Transpose();
	
	List& GetAdjList(int u);

	int* BFS(int vertex);

	bool IsAdjacent(int u, int v);
	bool isVertexValueValid(int value);

	int IsEmpty();
	int AddEdge(int i, int j);
	
	List* MakeEmptyGraph(int n);
	void RemoveEdge(int u, int v);
	void RemoveRedundantEdges(int* distanceArray);
	void RemoveUnreachableEdges(int* distanceArray);
	// need to implement 
	void ReadGraph();
	void PrintGraph();

	//Getters 
	List* GetVerticesArray() { return VerticesArray; }
	int GetStart() { return _start; }
	int GetEnd() { return _end; }
	int GetNumOfVertices() { return numOfVertices; }
	
	//Setters
	// ??? 
	
	
	//List Adj(int i); 
};

