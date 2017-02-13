#include <stdexcept>
struct PriorityQueueException : std::runtime_error
{
	PriorityQueueException() throw () : std::runtime_error("Priority queue error occurred")
	{

	}
};
