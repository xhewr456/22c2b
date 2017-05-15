#ifndef QUEUEADT_H
#define QUEUEADT_H
#include"LinkedList.h"
#include<iostream>

template <class T>
class QueueADT : protected LinkedList<T>
{
private:
	//DataNode<T> *front;
	//DataNode<T> *rear;

public:
	// constuctor
	QueueADT()
	{
		// clifford: is this needed?  both front and rear pointers are redundant to first and last from LinkedList
		// clifford: also the code for front and rear don't compile
		//front = this->first;
		//rear = this->last;
	}

	// destructor
	~QueueADT()
	{
		// clifford: is this needed?
	}

	// add an item to the back of the queue
	void enQueue(T addValue)
	{
		this->push_last(addValue);
	}

	// remove the first item in the queue
	void deQueue()
	{
		this->pop_first();
	}

	// return the value stored in the first item
	T front()
	{
		return this->getFirst();
		//std::cout << this->getFirst();
	}

	// return the value stored in the last item
	T rear()
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