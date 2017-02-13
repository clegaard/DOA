#include "Queue.h"
#include "PriorityQueueException.h"
template <class T>
class PriorityQueue
{
public:
	enum pEnum
	{
		LOW,
		MED,
		HIGH
	};

	PriorityQueue()
	{
		for (int i = 0; i < 3; ++i)
			queues.emplace_back(Queue<T>());
	}

	void push(T elem, pEnum priority)
	{
		queues.at(priority).push(elem);
	}

	// Pops the element with highest priority
	void pop()
	{
		for (auto itr = queues.rbegin(); itr != queues.rend(); ++itr)
		{
			if(!itr->isEmpty())
			{
				itr->pop();
				return;
			}
		}
		assert(true, "test");
	}

	// return a copy of the element at head
	T front() const
	{
		if (isEmpty()) throw PriorityQueueException();
		for (auto itr = queues.rbegin(); itr != queues.rend(); ++itr)
		{
			if (!itr->isEmpty()) return itr->front();
		}
		return {}; //TODO wtf does this do
	}
	
	bool isEmpty() const
	{
		for (Queue<T> queue : queues)
		{
			if (!queue.isEmpty()) return false;
		}
		return true;
	}

	// print the entire queue by propping list;
	void dump()
	{
	}

private:
	std::vector<Queue<T>> queues;
};
