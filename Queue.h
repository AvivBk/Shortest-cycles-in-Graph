#pragma once
#include "List.h"

class Queue
{
	private:
		List* queue;
	public:
		Queue();
		~Queue();
		bool isEmpty();
		void Enqueue(ListNode* newItem);
		ListNode* DeQueue();
};

