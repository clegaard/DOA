#include "../LinkedList/LLToolkit.h"
#include <iostream>
#include "QueueException.h"
template<class T>
class Queue
{
public:
	Queue(): head(nullptr), tail(nullptr)
	{
		
	}

	// Adds a new element at tail
	void push(T elem)
	{
		if(isEmpty())
		{
			ll.headInsert(head,elem);
			tail = head;
			return;
		}

		ll.insert(tail, elem);
		tail = tail->next; // advance tail to point to newly inserted node
	}

	// Removes the element pointed to by head if it exists
	void pop()
	{
		ll.headRemove(head);
	}

	// return a copy of the element at head
	T front() const
	{
		if (isEmpty()) throw QueueException();
		return head->info;
	}

	bool isEmpty() const
	{
		return head == nullptr;
	}

	// print the entire queue by propping list;
	void dump()
	{
		T* itr = head;
		while(!isEmpty())
		{
			std::cout << itr << std::endl;
			pop();
			if (isEmpty()) break;
		}
	}

private:
	Node<T>* head;
	Node<T>* tail;
	LLToolkit<T> ll;
	
};