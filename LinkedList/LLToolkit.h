#include "Node.h"

template <class T>
class LLToolkit
{
public:
	// Precondition: headPtr points to the head of a list
	// Postcondition: Info has been inserted at the head of the list, and headPtr is updated
	void LLToolkit::headInsert(Node<T>*& headPtr, T info)
	{
		// elements are inserted
		if (headPtr == nullptr)
		{
			headPtr = new Node<T>(info, nullptr);
			return;
		}
		auto oldHead = headPtr;
		headPtr = new Node<T>(info, oldHead);
	}

	// Precondition: headPtr points to the head of a list with at least 1 element
	// Postcondition: The head element has been removed and headPtr is updated to point to the new
	// head element
	static void LLToolkit::headRemove(Node<T>*& headPtr)
	{
		//if (headPtr == nullptr) throw std::exception("Cannot remove head because head is already nullptr");
		if (headPtr == nullptr) return; //TODO fix shitty testcase

		auto tempHeadPtr = headPtr->next;
		delete headPtr;
		headPtr = tempHeadPtr;
	}

	// Precondition: prevPtr points to Node just before insertion point
	// Postcondition: A new Node with data=info has been inserted into the list after prevPtr
	void LLToolkit::insert(Node<T>* prevPtr, T info)
	{
		if (prevPtr == nullptr) return;

		// Insert new node after prevPtr
		Node<T>* insNode = new Node<T>(info, prevPtr->next);
		insNode->previous = prevPtr;

		// Set next of first node to point to inserted node
		prevPtr->next = insNode;

		// Set previous of last node to point to inserted node
		if (insNode->next != nullptr) insNode->next->previous = insNode;
	}

	// Precondition: prevPtr points to Node just before Node to remove
	// Postcondition: The Node after prevPtr has been removed from the list
	void LLToolkit::remove(Node<T>* prevPtr)
	{
		// Check if list is empty
		if (prevPtr == nullptr) return;
		// Check if a node actually exist after prevptr
		Node<T>* remove = prevPtr->next;
		if (remove == nullptr) return;

		// Check to see if a node exist after the node we are removing
		Node<T>* next = remove->next;
		
		if (next == nullptr)
		{
			prevPtr->next = nullptr;
			prevPtr->previous = prevPtr;
		}
		else
		{
			prevPtr->next = next;
			next->previous = prevPtr;
		}
		delete remove;
	}

	// Precondition: sourcePtr is the head pointer of a linked list.
	// Postcondition: A pointer to a deep copy of the linked list is returned. The original list is
	// unaltered.
	Node<T>* LLToolkit::copy(Node<T>* sourcePtr)
	{
		if (sourcePtr == nullptr) return nullptr;

		Node<T>* current = sourcePtr;

		//Copy first element
		Node<T>* copy = new Node<T>();
		copy->info = T(current->info);

		// Keep track of head
		auto head = copy;

		// Advance iterator
		current = current->next;

		while (current != nullptr)
		{
			//allocate create new node, link and advance current node to newly created
			copy->next = new Node<T>();
			copy = copy->next;

			//copy contents using to copy using cctor
			copy->info = T(current->info);

			//advance through the original array
			current = current->next;
		}
		return head;
	}
};
