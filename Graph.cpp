#include "Graph.h"

Graph::Graph() :numOfVertices(0) , VerticesArray(nullptr) {
}


Graph::Graph(int numOfVertices):numOfVertices(numOfVertices) {
	VerticesArray = MakeEmptyGraph(numOfVertices);
}

Graph::~Graph() 
{
	delete[] VerticesArray;
}

Graph& Graph::Transpose() {
	Graph* transpose = new Graph(numOfVertices);
	ListNode* currNeighbor;
	for (int i = 1; i <= numOfVertices; i++) {
		currNeighbor = VerticesArray[i].GetListHead(); 
		while (currNeighbor != nullptr) {
			transpose->VerticesArray[currNeighbor->vertex].AddToList(i);
			currNeighbor = currNeighbor->next;
		}
	}
	return *transpose;
}


List& Graph::GetAdjList(int u) {
	return VerticesArray[u];
}

int* Graph::BFS(int vertex) {
	Queue queue = Queue();
	int* distanceArray = new int[numOfVertices+1];
	int currentVertexValue;
	ListNode* currentVertex;
	
	distanceArray[vertex] = 0 ;
	for (int i = 1; i <= numOfVertices + 1; i++) {
		if (i != vertex) {
			distanceArray[i] = infiniti;
		}
	}
	ListNode* SourceVertex = new ListNode();
	SourceVertex->vertex = vertex;
	queue.Enqueue(SourceVertex);

	
	while (!queue.isEmpty()) {
		currentVertex = queue.DeQueue(); // currentVertex  = u
		currentVertexValue = currentVertex->vertex;
		ListNode* currentNeighbor = VerticesArray[currentVertexValue].GetListHead();
		delete currentVertex;
		while (currentNeighbor != nullptr) { // currentNeighbor = v 
			if (distanceArray[currentNeighbor->vertex] == infiniti) {
				distanceArray[currentNeighbor->vertex] = distanceArray[currentVertexValue] + 1;
				queue.Enqueue(currentNeighbor);
			}
			currentNeighbor = currentNeighbor->next;
		}
	}
	return distanceArray;
}

int Graph::IsEmpty(){
	int result;
	if (numOfVertices == 0)
		result = 0;
	else
		result = 1;
	return result;
}

int Graph::AddEdge(int i, int j) {
	if((i < 1) || (j < 1) || (i > numOfVertices) || (j > numOfVertices) )
		return 0; // issue
	return VerticesArray[i].AddToList(j);  //returns result from addEdge
}

bool Graph::IsAdjacent(int u, int v) {
	return VerticesArray[u].IsNodeInList(v);
}

List* Graph::MakeEmptyGraph(int n) {
	List* Array = new List[n];
	for (int i = 1; i <= n; i++) {
		Array[i].MakeEmptyList(i);
	}
	return Array;
}

void Graph::RemoveEdge(int u, int v) {
	VerticesArray[u].RemoveFromList(v);
}

void Graph::RemoveRedundantEdges(int* distanceArray) {
	ListNode* currentVertex;
	int edge;
	for (int i = 1; i <= numOfVertices; i++) {
		ListNode* currentNeighbor = VerticesArray[i].GetListHead();
		while (currentNeighbor != nullptr) {
			if (distanceArray[i] + 1 != distanceArray[currentNeighbor->vertex]) {
				edge = currentNeighbor->vertex;
				currentNeighbor = currentNeighbor->next;
				RemoveEdge(i, edge);
			}
			else {
				currentNeighbor = currentNeighbor->next;
			}

		}
	}
}

void Graph::RemoveUnreachableEdges(int* distanceArray) {
	for (int i = 1; i <= numOfVertices; i++) {
		if (distanceArray[i] == infiniti) {
			VerticesArray[i].ClearList();
		}
	}
}

void Graph::ReadGraph() {
	int num,start,end;
	int SourceVertex , destVertex;
	cin >> num >> start >> end;
	if (num < 1) {
		// error invalid size (negative) 
	}
	VerticesArray = MakeEmptyGraph(num);
	numOfVertices = num; 
	if (!isVertexValueValid(start) || !isVertexValueValid(end)) {
		// error invalid input ( start , end ) 
	}
	_start = start;
	_end = end; 
	while (cin >> SourceVertex) {
		if (isVertexValueValid(SourceVertex)) {
			if (cin >> destVertex) {
				if (isVertexValueValid(destVertex)) {
					AddEdge(SourceVertex, destVertex);
				}
				else {
					cout << "Illegal input --> " << "source Value --> " << SourceVertex << "dest value --> " << destVertex << endl;
					//throw error --> illegal input 
				}
			}
			else {
				cout << "missing destination" << endl;
				// throw error --> missing destination
			}
		}
		else {
			cout << "illegal input" << endl;
			//throw error --> illegal input 
		}
	}
	//cin >> length;
}

void Graph::PrintGraph() {

}


bool Graph::isVertexValueValid(int inputValue){
	bool result = false;
	if (inputValue > 0 && inputValue <= numOfVertices) {
		result = true;
	}
	return result;
}