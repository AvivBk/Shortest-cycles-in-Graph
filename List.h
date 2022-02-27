#pragma once
#include "ListNode.h"
class List
{

private:
	ListNode* head;
	//ListNode* nextPos;
	ListNode* tail;
	int numberOfNeighbors;

public:


	ListNode* MakeNewNode(int vertex, ListNode* prev = nullptr, ListNode* next = nullptr);
	List();
	~List();
	
	//Getters
	ListNode* GetHead() { return head; }
	ListNode* GetTail() { return tail; }
	int GetNumberOfNeighbors() { return numberOfNeighbors; }

	//Setters
	void SetHead(ListNode* newHead) { head = newHead; }
	void SetTail(ListNode* newTail) { tail = newTail; }

	void AddToHead(ListNode* newNodeToAdd); //after"dummy head"
	ListNode* RemoveFromTail();
	bool IsEmpty();
	void ClearList();
	void MakeEmptyList(int vertex);
	int GetListHeadValue();
	ListNode* GetListHead(); // return first neighbor
	bool IsNodeInList(int vertex);
	ListNode* FindNodeByData(int vertex);
	bool RemoveFromList(int vertex);
	int AddToList(int vertex);
};

