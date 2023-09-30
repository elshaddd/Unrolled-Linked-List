#include "../modules/UnrolledList.h"
#include <iostream>

void test_SearchByIndex()
{
    std::cout << "\nTesting searching by index:\n\n";
    int size1 = 15;
    int nums[size1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    UnrolledList myList;
    for (int i = 0; i < size1; i++)
    {
        myList.InsertAtEnd(nums[i]);
    }
    myList.Print();
    int size2 = 2;
    int ind[size2] = {15, -1};
    for (int i = 0; i < size1; i++)
    {
        std::cout << myList.SearchByIndex(i).first->array[myList.SearchByIndex(i).second] << ' ';
    }
    std::cout << '\n';
    for (int i = 0; i < size2; i++)
    {
        auto result = myList.SearchByIndex(ind[i]);
        if (result.first != nullptr)
        {
            std::cout << result.first->array[result.second] << ' ';
        }
    }
}

void test_SearchByValue()
{
    std::cout << "\nTesting searching by value:\n\n";
    int size1 = 15;
    int nums[size1] = {1, 2, 3, 43, 5, 6, 7, 8, 9, 10, 3, 12, 13, 14, 15};
    int size2 = 5;
    int val[size2] = {1, 15, 43, 3, 11};
    UnrolledList myList;
    for (int i = 0; i < size1; i++)
    {
        myList.InsertAtEnd(nums[i]);
    }
    myList.PrintByNodes();
    for (int i = 0; i < size2; i++)
    {
        auto result = myList.SearchByValue(val[i]);
        if (result.first != nullptr)
        {
            std::cout << result.first->array[result.second] << " - " << result.second << '\n';
        }
        else
        {
            std::cout << "No such element\n";
        }
    }
}

int main()
{
    int k;
    std::cout << "1 - Test for searching by index\n2 - Test for searching by value\n";
    std::cin >> k;
    switch (k)
    {
    case 1:
        test_SearchByIndex();
        break;

    case 2:
        test_SearchByValue();
        break;

    default:
        break;
    }
}