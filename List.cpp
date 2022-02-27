#include "List.h"

//List::List() : head(nullptr), tail(nullptr), nextPos(nullptr), numberOfNeighbors(0)
List::List() : head(nullptr), tail(nullptr), numberOfNeighbors(0)
{
}

List::~List() {
	ClearList();
	numberOfNeighbors = 0;
	delete head;
	head = nullptr;
	tail = nullptr;
}

void List::AddToHead(ListNode* newNodeToAdd) {
	newNodeToAdd->next = head->next;
	newNodeToAdd->prev = head; 
	if (!IsEmpty()) {
		head->next->prev = newNodeToAdd;
	}
	if (tail == nullptr) {
		tail = newNodeToAdd;
	}
	head->next = newNodeToAdd;
	numberOfNeighbors++;
}

ListNode* List::RemoveFromTail() {
	ListNode* nodeToDelete = tail;
	if (!IsEmpty()) {
		tail = tail->prev;
		tail->next = nullptr;
		numberOfNeighbors--;
	}
	else {
		tail = nullptr;
	}
	return nodeToDelete;
}

bool List::IsEmpty() {
	bool result = false;
	if (numberOfNeighbors == 0)
		result = true;
	return result;
}
	
void List::MakeEmptyList(int vertex) {
	head = MakeNewNode(vertex);
	numberOfNeighbors = 0;
	tail = nullptr;
}

void List::ClearList() {
	ListNode* nodeToDelete;
	while (head->next != nullptr) {
		nodeToDelete = head->next;
		head->next = nodeToDelete->next;
		delete nodeToDelete;
	}
	numberOfNeighbors = 0;
	head->next = nullptr;
	tail = head;
}

ListNode* List::MakeNewNode(int vertex, ListNode* prev, ListNode* next) {
	ListNode* newNode = new ListNode;

	newNode->vertex = vertex;
	newNode->next = next;
	newNode->prev = prev;

	return newNode;
}

int List::GetListHeadValue() {
	return head->vertex;
}

ListNode* List::GetListHead() {
	return head->next;
}

ListNode* List::FindNodeByData(int vertex) {
	ListNode* result = nullptr;
	ListNode* curr = head->next;
	while (curr != nullptr) {
		if (curr->vertex == vertex)
		{
			result = curr;
			break;
		}
		curr = curr->next;
	}
	return result;
}

bool List::IsNodeInList(int vertex) {
	bool result = false;
	ListNode * temp = FindNodeByData(vertex);
	if (temp != nullptr)
		result = true;
	return false;
}

bool List::RemoveFromList(int vertex) {
	bool result = false;
	ListNode* temp = FindNodeByData(vertex);
	if (temp == tail) {
		temp = RemoveFromTail();
		result = true;
	}
	else {
		if (temp->next != nullptr) {
			temp->next->prev = temp->prev;
		}
		temp->prev->next = temp->next;
		numberOfNeighbors--;
		result = true;
	}
	delete temp;
	return result;
}

int List::AddToList(int vertex) {
	int result = 1 ;
	ListNode* newNode = MakeNewNode(vertex);
	AddToHead(newNode);
	return result;
}