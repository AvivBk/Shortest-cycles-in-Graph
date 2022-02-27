#include "Graph.h"

void printNeighborList(List* neighboorArray, int size, int start, int end);
void printDistancesArray(int* d, int size );
void main() {
	Graph g ;
	g.ReadGraph();
	int* distanceArrayG = g.BFS(g.GetStart());
	int* d = g.BFS(g.GetStart());
	//cout << "Printing NeighborList:" << endl;
	//printNeighborList(g.GetVerticesArray(), g.GetNumOfVertices());
	//printDistancesArray(distanceArrayG, g.GetNumOfVertices());
	
	//cout << "Printing NeighborList after RemoveRedundantEdges :" << endl;
	g.RemoveRedundantEdges(distanceArrayG);
	//printNeighborList(g.GetVerticesArray(), g.GetNumOfVertices());

	//cout << "Printing H(G Transpose) NeighborList :" << endl;
	Graph H = g.Transpose();
	//printNeighborList(H.GetVerticesArray(), g.GetNumOfVertices());
	
	//cout << "Printing DistanceArray after BFS :" << endl;
	int* distanceArrayH = H.BFS(g.GetEnd());
	//printDistancesArray(distanceArrayH, g.GetNumOfVertices());

	//cout << "Printing H(G Transpose) NeighborList after RemoveUnreachableEdges :" << endl;
	H.RemoveUnreachableEdges(distanceArrayH);
	//printNeighborList(H.GetVerticesArray(), g.GetNumOfVertices());

	cout << "Printing final graph NeighborList after all:" << endl;
	Graph FinalGraph = H.Transpose();
	printNeighborList(FinalGraph.GetVerticesArray(), g.GetNumOfVertices() , g.GetStart() , g.GetEnd());
}

void printNeighborList(List* neighboorArray, int size , int start , int end ) {
	ListNode* currVertex = neighboorArray[start].GetListHead();
	while (currVertex != nullptr) {
		ListNode* currNeighbor = currVertex->next;
		while (currNeighbor != nullptr) {
			cout << (currVertex->vertex) << "\t" << (currNeighbor->vertex) << endl;
			currNeighbor = currNeighbor->next;
		}
		currVertex = currVertex->next;
	}
}

void printDistancesArray(int* d , int size) {
	cout << "Distance array -->" << endl;
	for (int i = 1; i <= size; i++) {
		cout << "d" << "[" << i << "]" << d[i] << endl;
	}
}
