#include<iostream>
#include<string>
#include"LinkedList.h"

using namespace std;


int main()
{
	LinkedList<double> testList;
	testList.push_first(11);
	testList.push_first(7);
	testList.push_first(5);
	testList.push_first(3);
	testList.push_first(1);
	testList.displayList();
	testList.insert_node(2.2, 3);
	cout << endl;
	testList.displayList();
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
	string y;
	strList.top(y);
	cout << "top: " << y << endl;
	LinkedList<string> str2List;
	cout << endl;
	str2List.displayList();
	//int xyz;
	//cout << endl << xyz;
	cout << "\n\npress <Enter> to exit the program...";
	cin.get();
	return 0;
}