#include "Node.h"

Node::Node(int n)
{
    prev = nullptr;
    next = nullptr;
    sizeNode = 0;
    array = new int[n];
}
// todo
void Node::InsertIntoNode(int index, int num)
{
    int *newArray = new int[sizeNode + 1];
    memcpy(newArray, array, index * sizeof(int));
    newArray[index] = num;
    memcpy(newArray + index + 1, array + index, (sizeNode - index) * sizeof(int));
    delete[] array;
    array = newArray;
    sizeNode++;
}

void Node::DecreaseCapacity(int capacity)
{
    int *newArray = new int[capacity];
    std::memcpy(newArray, array, sizeNode * sizeof(int));
    delete[] array;
    array = newArray;
}