#ifndef QUEUEADT_H
#define QUEUEADT_H
#include"LinkedList.h"
#include<iostream>

template <class T>
class QueueADT : protected LinkedList<T>
{
private:
	DataNode<T> *frontPtr;
	DataNode<T> *rearPtr;

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

	// this is a debug function that prints out the first item in the queue
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

	// this is a debug function that prints out the last item in the queue
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

	// add an item to the back of the queue
	void enQueue(T addValue)
	{
		this->push_last(addValue);
		rearPtr = this->getLastPtr();
	}

	// remove the first item in the queue
	void deQueue()
	{
		this->pop_first();
		frontPtr = this->getFirstPtr();
	}

	// return the value stored in the first item
	T getFront()
	{
		return this->getFirst();
		//std::cout << this->getFirst();
	}

	// return the value stored in the last item
	T getRear()
	{
		return this->getLast();
		//std::cout << this->getLast();
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