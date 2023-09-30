#pragma once
#include "cstring"
class Node
{
public:
    Node *prev;
    Node *next;
    int sizeNode;
    int *array;

    Node(int n);
    // Вставка числа по индексу в массив узла
    void InsertIntoNode(int index, int num);
    // Уменьшение емкости
    void DecreaseCapacity(int capacity);
};