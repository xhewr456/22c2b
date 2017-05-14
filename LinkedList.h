#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>


template <class T>
class DataNode
{
private:
	T data;
	DataNode <T>*nextNode;
public:
	DataNode()
	{
		data = 0;
		nextNode = nullptr;
	}
	DataNode(T value)
	{
		data = value;
		nextNode = nullptr;
	}
	template <class T>
	friend class LinkedList;
};


template <class T>
class LinkedList
{
private:
	DataNode<int> headNode;
	DataNode<T> *first;
	DataNode<T> *last;

protected:
	// protected functions

public:
	// constructor
	LinkedList()
	{
		first = nullptr;
		last = nullptr;
		headNode.nextNode = reinterpret_cast<DataNode<int>*>(first);
	}

	// destructor
	~LinkedList()
	{
		DataNode<T> *traversalNode; // To traverse the list
		DataNode<T> *nextNode; // To point to the next node

		// Position nodePtr at the head of the list.
		traversalNode = first;

		// While nodePtr is not at the end of the list...
		while (traversalNode != nullptr)
		{
			// Save a pointer to the next node.
			nextNode = traversalNode->nextNode;

			// Delete the current node.
			delete traversalNode;
			//headNode.data--;

			// Position nodePtr at the next node.
			traversalNode = nextNode;
		}
	}

	bool isEmpty()
	{
		if (!first)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void emptyList()
	{
		// if the list is empty, set first and last to null and return
		if (!first)
		{
			first = nullptr;
			last = nullptr;
			return;
		}

		else
		{
			DataNode<T> *traversalNode = first;
			DataNode<T> *nextNode = nullptr;

			// While nodePtr is not at the end of the list...
			while (traversalNode != nullptr)
			{
				// Save a pointer to the next node.
				nextNode = traversalNode->nextNode;

				// Delete the current node.
				delete traversalNode;

				// Position nodePtr at the next node.
				traversalNode = nextNode;
			}
			first = nullptr;
			last = nullptr;
			headNode.data = 0;
		}
	}

	void printFirst()
	{
		// if there are no items in the list, display the message
		if (!first)
		{
			std::cout << "error: list is empty";
		}
		else
		{
			std::cout << first->data;
		}
	}

	void printLast()
	{
		// if there are no items in the list, display the message
		if (!last)
		{
			std::cout << "error: list is empty";
		}
		else
		{
			std::cout << last->data;
		}
	}

	void push_first(T newData)
	{
		// dynamically create a new node and store value in it
		DataNode<T> *newNode = new DataNode<T>(newData);

		// if there are no items in the list, make newNode the first item and make last point to the new node
		if (!first)
		{
			first = newNode;
			last = newNode;
			newNode->nextNode = nullptr;
		}

		// else, add the new node to the front of the list and update the link chain
		else
		{
			newNode->nextNode = first;
			first = newNode;
		}
		headNode.data++;
	}

	void push_last(T newData)
	{
		// push the new node as the last item in the list
		DataNode<T> *newNode = new DataNode<T>(newData);

		// if there are no items in the list, make newNode the first item and make last point to newNode
		if (!first && !last)
		{
			first = newNode;
			last = newNode;
			newNode->nextNode = nullptr;
		}

		// else, store last in tempPtr, set the new node as the new last and set tempPtr->next to last
		else
		{
			newNode->nextNode = nullptr;
			last->nextNode = newNode;
			last = newNode;
		}
		headNode.data++;
	}

	void pop_first()
	{
		// remove the first item in the list

		if (!first)
		{
			std::cout << "error: list is empty";
		}

		// if there is only one item in the list, copy the location of the first item, set first and last to null and delete the node
		else if (first->nextNode == nullptr)
		{
			DataNode<T> *tempPtr = first;
			first = nullptr;
			last = nullptr;
			delete tempPtr;
			headNode.data--;
		}

		else
		{
			DataNode<T> *tempPtr = first;
			first = tempPtr->nextNode;
			delete tempPtr;
			headNode.data--;
		}
	}

	void pop_last()
	{
		// remove the last item in the list

		// if the head is null, print the error message
		if (!first && !last)
		{
			std::cout << "error: list is empty";
		}

		// if there is only one item in the list, copy the location of the first item, set first and last to null and delete the node
		else if (first->nextNode == nullptr)
		{
			DataNode<T> *tempPtr = first;
			first = nullptr;
			last = nullptr;
			delete tempPtr;
			headNode.data--;
		}

		// traverse the list until the last node is found, move back one node and update that node as the last node and delete the last node
		else
		{
			DataNode<T> *currentNode = first;
			DataNode<T> *previous = nullptr;
			while (currentNode->nextNode != nullptr)
			{
				previous = currentNode;
				currentNode = previous->nextNode;
			}
			previous->nextNode = nullptr;
			last = previous;
			delete currentNode;
			headNode.data--;
		}
	}


	void top(T &passedByReference)
	{
		// if the head is null, print the error message
		if (!first)
			std::cout << "error: list is empty";

		// else, make the passed reference equal to the data stored in the first item
		else
		{
			passedByReference = first->data;
		}
	}

	void insert_node(T value, int index)
	{
		// dynamically create a new node and store value in it
		DataNode<T> *newNode = new DataNode<T>(value);

		// change a negative index value to 1
		if (index < 1)
		{
			index = 1;
		}

		// if there are no items in the list, make newNode the first item and make last point to the new node
		if (!first)
		{
			first = newNode;
			last = newNode;
			newNode->nextNode = nullptr;
		}

		else
		{
			DataNode<T> *currentNode = first;

			// if location is 1 newNode becomes the first item in the list and update the link chain
			if (index == 1)
			{
				newNode->nextNode = first;
				first = newNode;
			}

			// if location is greater than the size of the list, set newNode as the last item in the list
			else if (index > headNode.data)
			{
				newNode->nextNode = nullptr;
				last->nextNode = newNode;
				last = newNode;
			}

			else
			{
				DataNode<T> *previous = nullptr;

				// list does not start at zero, the first element is item one
				for (int count = 1; (count < index && currentNode->nextNode != nullptr); count++)
				{
					previous = currentNode;
					currentNode = currentNode->nextNode;
				}

				previous->nextNode = newNode;
				newNode->nextNode = currentNode;
			}
		}
		headNode.data++;
	}

	void displayList()
	{
		// if there are no items in the list, display the message
		if (!first)
		{
			std::cout << "error: list is empty";
		}

		// else, display all the nodes
		else
		{
			DataNode<T> *tempPtr = first;

			do
			{
				std::cout << tempPtr->data << endl;
				tempPtr = tempPtr->nextNode;
			} while (tempPtr != nullptr);

			std::cout << "list count: " << headNode.data;
		}
	}

	// return the number of items in the list
	int listSize()
	{
		return headNode.data;
	}
};

#endif
