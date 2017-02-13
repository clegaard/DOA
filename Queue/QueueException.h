#include <stdexcept>
struct QueueException : std::runtime_error
{
	QueueException() throw () : std::runtime_error("Queue error occurred")
	{
		
	}
};