#pragma once
#include <utility>
#include "Node.h"

class UnrolledList
{
public:
    Node *head;
    Node *tail;
    int capacityNode;
    int sizeList;

public:
    UnrolledList(int n_array = 4);
    // Балансировка при вставке
    void BalanceInsert(Node *currentNode);
    // Балансировка при удалении
    void BalanceDelete(Node *currentNode);
    // Вставка по индексу
    void InsertByIndex(int index, int num);
    // Вставка в конец
    void InsertAtEnd(int num);
    // Вставка в начало
    void InsertAtBeginning(int num);
    // Поиск по индексу
    std::pair<Node *, int> SearchByIndex(int index);
    // Поиск по значению (возвращает первое вхождение)
    std::pair<Node *, int> SearchByValue(int num);
    // Удаление по индексу
    void DeleteByIndex(int index);
    // Удаление по значению ()
    void DeleteByValue(int num);
    // Удаление с начала
    void DeleteAtBeggining();
    // Удаление с конца
    void DeleteAtEnd();
    // Вывод списка
    void Print();
    // Вывод списка по узлам
    void PrintByNodes();

    bool isEmpty();
};