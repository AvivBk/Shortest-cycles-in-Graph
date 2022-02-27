#include "Queue.h"


Queue::Queue(){
	queue = new List();
}
Queue::~Queue() { }
//void Queue::MakeEmpty() {
//}
bool Queue::isEmpty() {
	return (queue->GetHead() == nullptr);
}

void Queue::Enqueue(ListNode* newItem) {
	ListNode* ToAdd = queue->MakeNewNode(newItem->vertex);
	if (isEmpty()) {
		queue->SetTail(ToAdd);
	}
	ToAdd->next = queue->GetHead();
	if (ToAdd->next != nullptr) {
		ToAdd->next->prev = ToAdd;
	}
	queue->SetHead(ToAdd);
}

ListNode* Queue::DeQueue() {
	ListNode* last;
	if (isEmpty()) {
		last = nullptr;
	}
	last = queue->GetTail();
	if (queue->GetTail() == queue->GetHead()) {
		queue->SetHead(nullptr);
		queue->SetTail(nullptr);
	}
	else {
		queue->SetTail(last->prev);
	}
	return last;
}

