#include "../modules/UnrolledList.h"
#include <iostream>
#include <sstream>
#include <cassert>

void test_InsertAtEnd()
{
	UnrolledList myList;
	int size = 5;
	int val[size] = {6, 7, 5, 9, 13};
	for (int i = 0; i < size; i++)
	{
		myList.InsertAtEnd(val[i]);
		myList.PrintByNodes();
	}
}

void test_InsertAtBeginning()
{
	UnrolledList myList;
	int size = 5;
	int val[size] = {9, 13, 5, 6, 8};
	for (int i = 0; i < size; i++)
	{
		myList.InsertAtBeginning(val[i]);
		myList.PrintByNodes();
	}
}

void test_InsertByIndex()
{
	int size = 15;
	int nums[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	UnrolledList myList;
	for (int i = 0; i < size; i++)
	{
		myList.InsertAtEnd(nums[i]);
	}
	myList.PrintByNodes();
	myList.InsertByIndex(2, 100);
	myList.PrintByNodes();
	myList.InsertByIndex(1, 101);
	myList.PrintByNodes();
	myList.InsertByIndex(0, 102);
	myList.PrintByNodes();
	myList.InsertByIndex(4, 200);
	myList.PrintByNodes();
	myList.InsertByIndex(5, 201);
	myList.PrintByNodes();
	myList.InsertByIndex(15, 300);
	myList.PrintByNodes();
	myList.InsertByIndex(17, 301);
	myList.PrintByNodes();
	myList.InsertByIndex(22, 400);
	myList.PrintByNodes();
	myList.InsertByIndex(24, 0);
	myList.InsertByIndex(-9, 100);
}

int main()
{
	std::ostringstream oss;
	std::streambuf *p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());
	test_InsertAtEnd();
	std::cout.rdbuf(p_cout_streambuf);
	assert(oss && oss.str() == "Node: 6 \n\nNode: 6 7 \n\nNode: 6 7 5 \n\nNode: 6 7 5 9 \n\nNode: 6 7 \nNode: 5 9 13 \n\n");
	std::cout << "\nTesting inserting at end:\n";
	std::cout << oss.str();

	std::ostringstream oss1;
	std::streambuf *p_cout_streambuf1 = std::cout.rdbuf();
	std::cout.rdbuf(oss1.rdbuf());
	test_InsertAtBeginning();
	std::cout.rdbuf(p_cout_streambuf1);
	assert(oss1 && oss1.str() == "Node: 9 \n\nNode: 13 9 \n\nNode: 5 13 9 \n\nNode: 6 5 13 9 \n\nNode: 8 6 \nNode: 5 13 9 \n\n");
	std::cout << "Testing inserting at beginning:\n";
	std::cout << oss1.str();

	std::ostringstream oss2;
	std::streambuf *p_cout_streambuf2 = std::cout.rdbuf();
	std::cout.rdbuf(oss2.rdbuf());
	test_InsertByIndex();
	std::cout.rdbuf(p_cout_streambuf2);
	assert(oss2 && oss2.str() == "Node: 1 2 \nNode: 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 11 12 \nNode: 13 14 15 \n\nNode: 1 2 \nNode: 100 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 11 12 \nNode: 13 14 15 \n\nNode: 1 101 2 \nNode: 100 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 11 12 \nNode: 13 14 15 \n\nNode: 102 1 101 2 \nNode: 100 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 11 12 \nNode: 13 14 15 \n\nNode: 102 1 101 2 \nNode: 200 100 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 11 12 \nNode: 13 14 15 \n\nNode: 102 1 101 2 \nNode: 200 201 \nNode: 100 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 11 12 \nNode: 13 14 15 \n\nNode: 102 1 101 2 \nNode: 200 201 \nNode: 100 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 300 11 12 \nNode: 13 14 15 \n\nNode: 102 1 101 2 \nNode: 200 201 \nNode: 100 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 300 11 301 12 \nNode: 13 14 15 \n\nNode: 102 1 101 2 \nNode: 200 201 \nNode: 100 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 300 11 301 12 \nNode: 13 14 15 400 \n\nIndex out of range\nIndex out of range\n");
	std::cout << "Testing inserting at beginning:\n";
	std::cout << oss2.str();
}