#include<iostream>
#include<string>
#include"LinkedList.h"
#include"QueueADT.h"

using namespace std;


int main()
{
	QueueADT<string> queuedList;
	LinkedList<double> testList;
	testList.push_first(11);
	testList.push_first(7);
	testList.push_first(5);
	testList.push_first(3);
	testList.push_first(1);
	testList.displayList();
	cout << "\ninsert '2.2' at posistion 3";
	testList.insert_node(2.2, 3);
	cout << endl;
	testList.displayList();
	cout << "\ndeleting 2.2\n";
	testList.deleteNode(2.2);
	testList.displayList();
	cout << "\ndeleting 11 and 1\n";
	testList.deleteNode(11);
	testList.deleteNode(1);
	testList.displayList();
	cout << "\nfirst returns: " << testList.getFirst() << endl;
	cout << "last returns: " << testList.getLast() << endl;
	cout << "getIndex(0) returns: " << testList.getIndex(0) << endl;
	cout << "getIndex(1) returns: " << testList.getIndex(1) << endl;
	cout << "getIndex(2) returns: " << testList.getIndex(2) << endl;
	cout << "empty the list\n";
	testList.emptyList();
	cout << "display the list\n";
	testList.displayList();
	//cout << "getIndex(4) returns: " << testList.getIndex(4) << endl;  // don't go out of bounds
	//string x;
	//double x;
	//testList.top(x);
	//cout << "\n\n";
	//testList.printLast();
	//cout << "\n\n" << x;
	LinkedList<string> strList;
	strList.push_first("one");
	strList.push_first("three");
	strList.push_first("five");
	strList.push_first("seven");
	strList.push_first("eleven");
	cout << endl << endl;
	strList.displayList();
	cout << endl;
	cout << "\npop first\n";
	strList.pop_first();
	strList.displayList();
	cout << endl;
	cout << "\npop last\n";
	strList.pop_last();
	strList.displayList();
	cout << endl;
	//string y;
	//strList.top(y);
	cout << "getFirst() returns: " << strList.getFirst() << endl;
	cout << "search for seven returns: " << strList.searchNodes("seven") << endl;
	cout << "search for five returns: " << strList.searchNodes("five") << endl;
	cout << "search for eleven returns: " << strList.searchNodes("eleven") << endl;
	LinkedList<string> str2List;
	cout << endl;
	str2List.displayList();
	cout << endl << endl << endl;
	cout << "enqueue 'one' and 'two'" << endl;
	queuedList.enQueue("one");
	queuedList.enQueue("two");
	cout << "display queue:" << endl;
	queuedList.displayQueue();
	cout << "\nenqueue 'three' and 'four'" << endl;
	queuedList.enQueue("three");
	queuedList.enQueue("four");
	cout << "display queue:" << endl;
	queuedList.displayQueue();
	cout << "\nenqueue 'five'" << endl;
	queuedList.enQueue("five");
	cout << "display queue:" << endl;
	queuedList.displayQueue();
	cout << "\ndequeue one item" << endl;
	queuedList.deQueue();
	cout << "display queue" << endl;
	queuedList.displayQueue();
	cout << "\ndequeue one item" << endl;
	queuedList.deQueue();
	cout << "display queue" << endl;
	queuedList.displayQueue();
	cout << endl << "front returns: " << queuedList.front();
	cout << endl << "rear returns: " << queuedList.rear() << endl;
	//int xyz;
	//cout << endl << xyz;
	cout << "\n\npress <Enter> to exit the program...";
	cin.get();
	return 0;
}