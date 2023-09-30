#include <iostream>
#include "../modules/UnrolledList.h"
#include <chrono>
#include <list>
#include <vector>

using namespace std;

int GetRandomNumber(const int from, const int to)
{
    if (to == from)
        return to;

    if (to < from)
        return GetRandomNumber(to, from);

    return from + rand() % (to - from + 1);
}

void delete_at_beginning(int data)
{
    std::cout << "Data - " << data << '\n';
    int nums[data];

    UnrolledList ull(400);
    vector<int> vec;
    list<int> list;

    for (int i = 0; i < data; i++)
    {
        nums[i] = GetRandomNumber(-10, 10);
        vec.push_back(nums[i]);
        list.push_back(nums[i]);
        ull.InsertAtEnd(nums[i]);
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        ull.DeleteAtBeggining();
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        auto it = vec.begin();
        vec.erase(it);
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        list.pop_front();
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

void delete_at_end(int data)
{
    std::cout << "Data - " << data << '\n';
    int nums[data];
    UnrolledList ull(4000);
    vector<int> vec;
    list<int> list;

    for (int i = 0; i < data; i++)
    {
        nums[i] = GetRandomNumber(-10, 10);
        vec.push_back(nums[i]);
        list.push_back(nums[i]);
        ull.InsertAtEnd(nums[i]);
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data && i <= ull.sizeList; i++)
    {
        ull.DeleteAtEnd();
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        vec.pop_back();
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        list.pop_back();
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

void delete_at_center(int data)
{
    std::cout << "Data - " << data << '\n';
    int nums[data];

    UnrolledList ull(4000);
    vector<int> vec;
    list<int> list;

    for (int i = 0; i < data; i++)
    {
        nums[i] = GetRandomNumber(-10, 10);
        vec.push_back(nums[i]);
        list.push_back(nums[i]);
        ull.InsertAtEnd(nums[i]);
    }
    ull.InsertAtEnd(1);
    ull.InsertAtEnd(2);

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        ull.DeleteByIndex(ull.sizeList / 2);
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        auto it = vec.begin();
        advance(it, vec.size() / 2);
        vec.erase(it);
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        auto it = list.begin();
        advance(it, list.size() / 2);
        list.erase(it);
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

int main()
{
    std::cout << "Delete at beginning results\n";
    delete_at_beginning(10);
    delete_at_beginning(10000);
    delete_at_beginning(100000);

    std::cout << "Delete at end results\n";
    delete_at_end(10);
    delete_at_end(10000);
    delete_at_end(100000);

    std::cout << "Delete at center\n";
    delete_at_center(10);
    delete_at_center(10000);
    delete_at_center(100000);
}