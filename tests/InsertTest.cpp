#include "../modules/UnrolledList.h"
#include <iostream>

void test_InsertAtEnd()
{
	std::cout << "\nTesting inserting at end:\n\n";
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
	std::cout << "\nTesting inserting at beginning:\n\n";
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
	std::cout << "\nTesting inserting by index:\n\n";
	int size = 15;
	int nums[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	UnrolledList myList;
	for (int i = 0; i < size; i++)
	{
		myList.InsertAtEnd(nums[i]);
	}
	std::cout << "STATE BEFORE INSERTING:\n";
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
	int k;
	std::cout << "1 - Test for inserting at end\n2 - Test for inserting at beginning\n3 - Test for inserting by index\n";
	std::cin >> k;
	switch (k)
	{
	case 1:
		test_InsertAtEnd();
		break;

	case 2:
		test_InsertAtBeginning();
		break;

	case 3:
		test_InsertByIndex();
		break;
	default:
		break;
	}
}