#ifndef QUEUEADT_H
#define QUEUEADT_H
#include<iostream>
#include"LinkedList.h"

template <class T>
class QueueADT : protected LinkedList<T>
{
private:


public:
	// constuctor
	QueueADT()
	{
		//LinkedList::LinkedList();
	}

	// destructor
	~QueueADT()
	{

	}

	void enQueue(T addValue)
	{
		this->push_last(addValue);
	}

	void deQueue()
	{
		this->pop_first();
	}

	void front()
	{
		std::cout << this->getFirst();
	}

	void rear()
	{
		std::cout << this->getLast();
	}

	void emptyStack()
	{
		this->emptyList();
	}

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
	void displayQueue()
	{
		this->displayList();
	}
};

#endif