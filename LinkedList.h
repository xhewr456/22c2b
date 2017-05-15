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
	// the default constructor should only be triggered by the LinkedList's headNode, thus it should be safe to set data to zero
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
	// the data and pointer members are private, thus LinkedList class needs to be delcared as a friend
	template <class T>
	friend class LinkedList;
	template <class T>
	friend class QueueADT;
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

	// returns a pointer of first
	DataNode<T> *getFirstPtr()
	{
		return first;
	}

	// returns a pointer of last
	DataNode<T> *getLastPtr()
	{
		return last;
	}

public:
	// constructor
	LinkedList()
	{
		first = nullptr;
		last = nullptr;

		// recast the first pointer, a DataNode<T>, into a DataNode<int> that can be stored in headNode's nextNode pointer
		// otherwise, headNode's nextNode pointer will not accept the value
		headNode.nextNode = reinterpret_cast<DataNode<int>*>(first);
	}

	// destructor
	~LinkedList()
	{
		DataNode<T> *currentNode; // To traverse the list
		DataNode<T> *nextNode; // To point to the next node

		// Position nodePtr at the head of the list.
		currentNode = first;

		// While nodePtr is not at the end of the list...
		while (currentNode != nullptr)
		{
			// Save a pointer to the next node.
			nextNode = currentNode->nextNode;

			// Delete the current node.
			delete currentNode;
			//headNode.data--;

			// Position nodePtr at the next node.
			currentNode = nextNode;
		}
	}

	// check the list for items, if the list is empty return true, else return false
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

	// remove all items in the list
	void emptyList()
	{
		// if the list is empty, set first and last to null for redundency and return
		if (!first)
		{
			first = nullptr;
			last = nullptr;
			return;
		}

		else
		{
			DataNode<T> *currentNode = first;
			DataNode<T> *nextNode = nullptr;

			// While nodePtr is not at the end of the list...
			while (currentNode != nullptr)
			{
				// Save a pointer to the next node.
				nextNode = currentNode->nextNode;

				// Delete the current node.
				delete currentNode;

				// Position nodePtr at the next node.
				currentNode = nextNode;
			}
			first = nullptr;
			last = nullptr;
			headNode.data = 0;
		}
	}

	// this is a debug function that prints out the first item in the list
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

	// this is a debug function that prints out the last item in the list
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

	// add a new node at the beginning of the list and update first
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

	// add a new node to the end of the list and update last as required
	void push_last(T newData)
	{
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

	// remove the first item from the list and update first as required
	void pop_first()
	{
		DataNode<T> *tempPtr = first;

		if (!first)
		{
			std::cout << "error: list is empty";
		}

		// if there is only one item in the list, copy the location of the first item, set first and last to null and delete the node
		else if (first->nextNode == nullptr)
		{
			first = nullptr;
			last = nullptr;
			delete tempPtr;
			headNode.data--;
		}

		else
		{
			first = tempPtr->nextNode;
			delete tempPtr;
			headNode.data--;
		}
	}

	// remove the last item in the list and update last as required
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

	// return the data stored in the first node
	T getFirst()
	{
		return first->data;
	}

	// return the data stored in the last node
	T getLast()
	{
		return last->data;
	}

	// return the data stored at the index value
	T getIndex(int index)
	{
		DataNode<T> *currentNode = first;

		for (int count = 0; (count < index && count < headNode.data); count++)
		{
			currentNode = currentNode->nextNode;
		}

		return currentNode->data;
	}

	// this function takes two arguments, a <T> value, and <int>
	// the function will create a new node with the <T> value and insert it into posistion <int>
	// the function will NOT sort the value, only add it to the list at the requested location
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

	// use a linear search to look for the value and return its location if found
	// if the value was not found, return -1
	int searchNodes(T searchValue)
	{
		// If the list is empty, return -1
		if (!first)
			return -1;

		// if the first node is the value, return its index, 1
		else if (first->data == searchValue)
		{
			return 0;
		}

		// else, traverse the list looking for the value
		else
		{
			int listLocation = 0;
			DataNode<T> *currentNode = first; // To traverse the list

			// Skip all nodes whose value member is not equal to searchValue.
			while (currentNode != nullptr && currentNode->data != searchValue)
			{
				currentNode = currentNode->nextNode;
				listLocation++;
			}

			//  if the value was not found, and the list is at the end, return -1
			if (currentNode == nullptr)
			{
				return -1;
			}

			// else, return the index of where the value was found
			else
			{
				return listLocation;
			}
		}
	}

	// use a linear search to look for the value, remove the node, and update the link chain as required
	// if the value was not found, return
	void deleteNode(T deleteValue)
	{
		DataNode<T> *currentNode = first; // To traverse the list
		DataNode<T> *previousNode = nullptr; // To point to the previous node

		// If the list is empty, do nothing.
		if (!first)
			return;

		// Determine if the first node is the one.
		else if (first->data == deleteValue)
		{
			first = currentNode->nextNode;
			delete currentNode;

			// if the list only has one item, set first and last to nullptr
			if (headNode.data == 1)
			{
				first = nullptr;
				last = nullptr;
			}
		}

		else
		{
			// Skip all nodes whose value member is not equal to searchValue.
			while (currentNode != nullptr && currentNode->data != deleteValue)
			{
				previousNode = currentNode;
				currentNode = currentNode->nextNode;
			}

			// if the list does not have the value, return
			if (currentNode == nullptr)
			{
				return;
			}

			// if the last item in the list has the desired value, set previousNode->nextNode to null and delete the current node
			// and update last to point to the previous node
			else if (currentNode->data == deleteValue && currentNode->nextNode == nullptr)
			{
				previousNode->nextNode = nullptr;
				delete currentNode;
				last = previousNode;
			}

			// if the list continues past the current node, update the link chain and delete the current node
			else if (currentNode->nextNode != nullptr)
			{
				previousNode->nextNode = currentNode->nextNode;
				delete currentNode;
			}
		}
		// update the list size
		headNode.data--;
	}

	// print out all the items in the list, if there are any items to print
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
			DataNode<T> *currentNode = first;

			do
			{
				std::cout << currentNode->data << endl;
				currentNode = currentNode->nextNode;
			} while (currentNode != nullptr);

			//std::cout << "list count: " << headNode.data;
		}
	}

	// return the number of items in the list
	int listSize()
	{
		return headNode.data;
	}
};

#endif
