#include "../modules/UnrolledList.h"
#include <iostream>
#include <sstream>
#include <cassert>

void test_SearchByIndex()
{
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
    std::ostringstream oss;
    std::streambuf *p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    test_SearchByIndex();
    std::cout.rdbuf(p_cout_streambuf);
    assert(oss && oss.str() == "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 \n1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 \nInvalid index\nInvalid index\n");
    std::cout << "\nTesting searching by index:\n";
    std::cout << oss.str();

    std::ostringstream oss1;
    std::streambuf *p_cout_streambuf1 = std::cout.rdbuf();
    std::cout.rdbuf(oss1.rdbuf());
    test_SearchByValue();
    std::cout.rdbuf(p_cout_streambuf1);
    assert(oss1 && oss1.str() == "Node: 1 2 \nNode: 3 43 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 3 12 \nNode: 13 14 15 \n\n1 - 0\n15 - 2\n43 - 1\n3 - 0\nNo such element\n");
    std::cout << "\nTesting searching by value:\n";
    std::cout << oss1.str();
}