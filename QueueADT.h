#ifndef QUEUEADT_H
#define QUEUEADT_H
#include"LinkedList.h"
#include<iostream>


/*
	The QueueADT is derived from LinkedList and gets the bulk of the functions from LinkedList as well.
	The queue has 4 main functions, enQueue(), that adds an item the back of the queue
	deQueue() that removes the first item from the queue
	getFront() returns the value stored in the front of the queue, which the user can then use
	getRear() returns the value stored at the end of the queue, which the user can then use
	displayQueue(), printFront(), and printRear() are mainly used as debug functions to verify that frontPtr and rearPtr are valid
	emptyQueue() destroys all items in the queue, and isEmpty() returns true if the queue is empty, or false if the queue has items
*/
template <class T>
class QueueADT : protected LinkedList<T>
{
private:
	DataNode<T> *frontPtr;  // pointer to the front of the queue
	DataNode<T> *rearPtr;  // pointer to the rear of the queue

public:
	// constuctor
	QueueADT()
	{
		// clifford: is this needed?  both front and rear pointers are redundant to first and last from LinkedList
		frontPtr = this->getFirstPtr();
		rearPtr = this->getLastPtr();
	}

	// destructor
	//~QueueADT()
	//{
	//	// clifford: is this needed?
	//}

	// this is a debug function that prints out the first item in the queue, if there is an item to display
	void printFront()
	{
		// if there are no items in the queue, display the message
		if (!frontPtr)
		{
			std::cout << "error: queue is empty";
		}
		else
		{
			std::cout << frontPtr->data;
		}
	}

	// this is a debug function that prints out the last item in the queue, if there is an item to display
	void printRear()
	{
		// if there are no items in the queue, display the message
		if (!rearPtr)
		{
			std::cout << "error: queue is empty";
		}
		else
		{
			std::cout << rearPtr->data;
		}
	}

	// add an item to the back of the queue and update rearPtr
	void enQueue(T addValue)
	{
		this->push_last(addValue);
		rearPtr = this->getLastPtr();
	}

	// remove the first item in the queue and update frontPtr
	void deQueue()
	{
		this->pop_first();
		frontPtr = this->getFirstPtr();
	}

	// return the value stored in the first item
	T getFront()
	{
		return this->getFirst();
	}

	// return the value stored in the last item
	T getRear()
	{
		return this->getLast();
	}

	// remove all items in the queue
	void emptyQueue()
	{
		this->emptyList();
	}

	// return true if there are no items in the queue, else return false
	bool isEmpty()
	{
		if (!this->first)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// print out the items stored in the queue
	void displayQueue()
	{
		this->displayList();
	}
};

#endif