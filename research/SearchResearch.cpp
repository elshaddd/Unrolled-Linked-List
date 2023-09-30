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

void search_at_beginning(int data)
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
    for (int i = 1; i <= data; i++)
    {
        ull.SearchByIndex(0);
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        vec.at(0);
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        list.front();
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

void search_at_end(int data)
{
    std::cout << "Data - " << data << '\n';
    int nums[data];

    UnrolledList ull(4000);
    vector<int> vec;
    list<int> list;

    for (int i = 0; i < data; i++)
    {
        nums[i] = GetRandomNumber(0, 10);
        vec.push_back(nums[i]);
        list.push_back(nums[i]);
        ull.InsertAtEnd(nums[i]);
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        ull.SearchByIndex(ull.sizeList - 1);
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        vec.at(vec.size() - 1);
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        list.back();
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

void search_at_center(int data)
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
    for (int i = 1; i <= data; i++)
    {
        ull.SearchByIndex(ull.sizeList / 2);
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        vec.at(vec.size() / 2);
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        auto it = list.begin();
        advance(it, list.size() / 2);
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

int main()
{
    std::cout << "Search at beginning\n";
    search_at_beginning(10);
    search_at_beginning(10000);
    search_at_beginning(100000);

    std::cout << "Search at end\n";
    search_at_end(10);
    search_at_end(10000);
    search_at_end(100000);

    std::cout << "Search at center\n";
    search_at_center(10);
    search_at_center(10000);
    search_at_center(100000);
}