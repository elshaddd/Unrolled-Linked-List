#include "../modules/UnrolledList.h"
#include <iostream>
#include <sstream>
#include <cassert>

void test_DeleteAtEnd()
{
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
    std::ostringstream oss;
    std::streambuf *p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    test_DeleteAtEnd();
    std::cout.rdbuf(p_cout_streambuf);
    assert(oss && oss.str() == "Node: 1 2 \nNode: 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 11 12 \nNode: 13 14 15 \n\n1 2 3 4 5 6 7 8 9 10 11 12 13 14 \n1 2 3 4 5 6 7 8 9 10 11 12 13 \n1 2 3 4 5 6 7 8 9 10 11 12 \n1 2 3 4 5 6 7 8 9 10 11 \n1 2 3 4 5 6 7 8 9 10 \n1 2 3 4 5 6 7 8 9 \n1 2 3 4 5 6 7 8 \n1 2 3 4 5 6 7 \n1 2 3 4 5 6 \n1 2 3 4 5 \n1 2 3 4 \n1 2 3 \n1 2 \n1 \n\nNothing to delete\n");
    std::cout << "\nTesting deleting at end:\n";
    std::cout << oss.str();

    std::ostringstream oss1;
    std::streambuf *p_cout_streambuf1 = std::cout.rdbuf();
    std::cout.rdbuf(oss1.rdbuf());
    test_DeleteAtBeginning();
    std::cout.rdbuf(p_cout_streambuf1);
    assert(oss1 && oss1.str() == "Node: 1 2 \nNode: 3 4 \nNode: 5 6 \nNode: 7 8 \nNode: 9 10 \nNode: 11 12 \nNode: 13 14 15 \n\n2 3 4 5 6 7 8 9 10 11 12 13 14 15 \n3 4 5 6 7 8 9 10 11 12 13 14 15 \n4 5 6 7 8 9 10 11 12 13 14 15 \n5 6 7 8 9 10 11 12 13 14 15 \n6 7 8 9 10 11 12 13 14 15 \n7 8 9 10 11 12 13 14 15 \n8 9 10 11 12 13 14 15 \n9 10 11 12 13 14 15 \n10 11 12 13 14 15 \n11 12 13 14 15 \n12 13 14 15 \n13 14 15 \n14 15 \n15 \n\nNothing to delete\n");
    std::cout << "\nTesting deleting at beginning:\n";
    std::cout << oss1.str();

    std::ostringstream oss2;
    std::streambuf *p_cout_streambuf2 = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());
    test_DeleteByIndex();
    std::cout.rdbuf(p_cout_streambuf2);
    assert(oss2 && oss2.str() == "Node: 1 2 3 \nNode: 4 5 6 \nNode: 7 8 9 \nNode: 10 11 12 \nNode: 13 14 15 \n\nNode: 1 2 3 \nNode: 5 6 7 8 9 \nNode: 10 11 12 \nNode: 13 14 15 \n\nNode: 1 2 3 \nNode: 6 7 8 9 \nNode: 10 11 12 \nNode: 13 14 15 \n\nNode: 1 2 3 \nNode: 6 7 8 9 \nNode: 10 11 12 \nNode: 14 15 \n\nNode: 1 2 3 \nNode: 6 7 8 9 \nNode: 10 11 14 15 \n\nNode: 1 2 3 \nNode: 6 7 8 9 \nNode: 10 11 14 \n\nNode: 2 3 6 \nNode: 7 8 9 \nNode: 10 11 14 \n\nInvalid index\nNode: 2 3 6 \nNode: 7 8 9 \nNode: 10 11 14 \n\nInvalid index\nNode: 2 3 6 \nNode: 7 8 9 \nNode: 10 11 14 \n\n");
    std::cout << "\nTesting deleting by index:\n";
    std::cout << oss2.str();

    std::ostringstream oss3;
    std::streambuf *p_cout_streambuf3 = std::cout.rdbuf();
    std::cout.rdbuf(oss3.rdbuf());
    test_DeleteByValue();
    std::cout.rdbuf(p_cout_streambuf3);
    assert(oss3 && oss3.str() == "Node: 1 2 \nNode: 3 4 \nNode: 5 3 \nNode: 7 8 \nNode: 9 10 \nNode: 3 12 \nNode: 13 2 15 \n\nNode: 1 2 \nNode: 3 4 \nNode: 3 7 8 \nNode: 9 10 \nNode: 3 12 \nNode: 13 2 15 \n\nNode: 1 2 \nNode: 4 7 8 \nNode: 9 10 \nNode: 12 13 \nNode: 2 15 \n\nNode: 1 4 \nNode: 7 8 \nNode: 9 10 \nNode: 12 13 \nNode: 15 \n\nNode: 4 7 8 \nNode: 9 10 \nNode: 12 13 \nNode: 15 \n\nNode: 4 7 8 \nNode: 9 10 \nNode: 12 13 \n\nNo such element\n");
    std::cout << "Testing deleting by value:\n";
    std::cout << oss3.str();
}