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

void insert_at_beginning(int data)
{
    std::cout << "Data - " << data << '\n';
    int size = 4;
    int nums[size] = {1, 2, 3, 4};
    UnrolledList ull(400);
    vector<int> vec = {1, 2, 3, 4};
    list<int> list = {1, 2, 3, 4};

    for (int i = 0; i < size; i++)
    {
        ull.InsertAtEnd(nums[i]);
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        ull.InsertAtBeginning(10);
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        auto it = vec.begin();
        vec.insert((it), 10);
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        list.push_front(10);
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

void insert_at_end(int data)
{
    std::cout << "Data - " << data << '\n';
    int size = 4;
    int nums[size] = {1, 2, 3, 4};
    UnrolledList ull(4000);
    vector<int> vec = {1, 2, 3, 4};
    list<int> list = {1, 2, 3, 4};

    for (int i = 0; i < size; i++)
    {
        ull.InsertAtEnd(nums[i]);
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        ull.InsertAtEnd(10);
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        vec.push_back(10);
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        list.push_back(10);
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

void insert_at_center(int data)
{
    std::cout << "Data - " << data << '\n';
    int size = 4;
    int nums[size] = {1, 2, 3, 4};
    UnrolledList ull(4000);
    vector<int> vec = {1, 2, 3, 4};
    list<int> list = {1, 2, 3, 4};

    for (int i = 0; i < size; i++)
    {
        ull.InsertAtEnd(nums[i]);
    }

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        ull.InsertByIndex(ull.sizeList / 2, 10);
    }
    auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "Ull: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count() << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        auto it = vec.begin();
        std::advance(it, vec.size() / 2);
        vec.insert((it), 10);
    }
    auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "Array: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed2).count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= data; i++)
    {
        auto it = list.begin();
        std::advance(it, list.size() / 2);
        list.insert(it, 10);
    }
    auto elapsed3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "List: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed3).count() << std::endl;
    std::cout << '\n';
}

int main()
{
    std::cout << "Insert at beginning\n";
    insert_at_beginning(10);
    insert_at_beginning(10000);
    insert_at_beginning(100000);

    std::cout << "Insert at end\n";
    insert_at_end(10);
    insert_at_end(10000);
    insert_at_end(100000);

    std::cout << "Insert at center\n";
    insert_at_center(10);
    insert_at_center(10000);
    insert_at_center(100000);
}