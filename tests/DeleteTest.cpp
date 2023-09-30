#include "../modules/UnrolledList.h"
#include <iostream>

void test_DeleteAtEnd()
{
    std::cout << "\nTesting deleting at end:\n";
    int size = 15;
    int nums[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    UnrolledList myList;
    for (int i = 0; i < size; i++)
    {
        myList.InsertAtEnd(nums[i]);
    }
    myList.PrintByNodes();
    while (!myList.isEmpty())
    {
        myList.DeleteAtEnd();
        myList.Print();
    }
    myList.DeleteAtEnd();
}

void test_DeleteAtBeginning()
{
    std::cout << "\nTesting deleting at beginning:\n\n";
    int size = 15;
    int nums[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    UnrolledList myList;
    for (int i = 0; i < size; i++)
    {
        myList.InsertAtEnd(nums[i]);
    }
    myList.PrintByNodes();
    while (!myList.isEmpty())
    {
        myList.DeleteAtBeggining();
        myList.Print();
    }
    myList.DeleteAtBeggining();
}

void test_DeleteByIndex()
{
    std::cout << "\nTesting deleting by index:\n\n";
    int size = 15;
    int nums[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    UnrolledList myList(5);
    for (int i = 0; i < size; i++)
    {
        myList.InsertAtEnd(nums[i]);
    }
    myList.PrintByNodes();

    int size2 = 8;
    int ind[size2] = {3, 3, 10, 9, 10, 0, -2, 12};
    for (int i = 0; i < size2; i++)
    {
        myList.DeleteByIndex(ind[i]);
        myList.PrintByNodes();
    }
}

void test_DeleteByValue()
{
    std::cout << "\nTesting deleting by value:\n\n";
    int size = 15;
    int nums[size] = {1, 2, 3, 4, 5, 3, 7, 8, 9, 10, 3, 12, 13, 2, 15};
    UnrolledList myList;
    for (int i = 0; i < size; i++)
    {
        myList.InsertAtEnd(nums[i]);
    }
    int size2 = 6;
    int val[size2] = {5, 3, 2, 1, 15, 60};
    for (int i = 0; i < size2; i++)
    {
        myList.PrintByNodes();
        myList.DeleteByValue(val[i]);
    }
}

int main()
{
    int k;
    std::cout << "1 - Test for deleting at end\n2 - Test for deleting at beginning\n3 - Test for deleting by index\n4 - Test for deleting by value\n";
    std::cin >> k;
    switch (k)
    {
    case 1:
        test_DeleteAtEnd();
        break;

    case 2:
        test_DeleteAtBeginning();
        break;

    case 3:
        test_DeleteByIndex();
        break;
    case 4:
        test_DeleteByValue();
        break;
    default:
        break;
    }
}