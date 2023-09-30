#include <iostream>
#include "UnrolledList.h"

UnrolledList::UnrolledList(int n_array /*= 4*/)
{
    head = nullptr;
    tail = nullptr;
    capacityNode = n_array;
    sizeList = 0;
}

void UnrolledList::BalanceInsert(Node *currentNode)
{
    Node *newNode = new Node(capacityNode);
    int j = 0;
    //memcpy(newNode->array,currentNode->array + (capacityNode + 1)/2, (currentNode->sizeNode - (capacityNode + 1)/2) * sizeof(int));
    for (int i = (capacityNode + 1) / 2; i < currentNode->sizeNode; i++, j++)
    {
        newNode->array[j] = currentNode->array[i];
        newNode->sizeNode++;
    }
    currentNode->sizeNode -= newNode->sizeNode;
    currentNode->DecreaseCapacity(capacityNode);
    if (currentNode->next != NULL)
    {
        currentNode->next->prev = newNode;
    }
    newNode->next = currentNode->next;
    newNode->prev = currentNode;
    currentNode->next = newNode;
    if (currentNode == tail)
    {
        tail = newNode;
    }
}

void UnrolledList::BalanceDelete(Node *currentNode)
{
    Node *nextNode = currentNode->next;
    int needToPush = (capacityNode + 1) / 2 - currentNode->sizeNode;

    if (currentNode->sizeNode < (capacityNode + 1) / 2)
    {
        if (nextNode != nullptr && nextNode->sizeNode <= (capacityNode + 1) / 2)
        {
            memcpy(currentNode->array + currentNode->sizeNode, nextNode->array, nextNode->sizeNode * sizeof(int));
            currentNode->next = nextNode->next;
            if (nextNode->next != nullptr)
            {
                nextNode->next->prev = currentNode;
            }
            currentNode->sizeNode += nextNode->sizeNode;
            if (nextNode == tail)
            {
                tail = currentNode;
            }
            delete[] nextNode->array;
            delete nextNode;
        }
        else if (nextNode != nullptr)
        {
            memcpy(currentNode->array + currentNode->sizeNode, nextNode->array, needToPush * sizeof(int));
            currentNode->sizeNode += needToPush;
            nextNode->sizeNode -= needToPush;
            memcpy(nextNode->array, nextNode->array + needToPush, nextNode->sizeNode * sizeof(int));
        }
    }
    if (currentNode->sizeNode == 0)
    {
        if (currentNode == tail)
        {
            tail = currentNode->prev;
        }
        if (currentNode == head)
        {
            head = currentNode->next;
        }
        if (currentNode->prev != nullptr)
        {
            currentNode->prev->next = currentNode->next;
        }
        if (currentNode->next != nullptr)
        {
            currentNode->next->prev = currentNode->prev;
        }
        delete[] currentNode->array;
        delete currentNode;
    }
}

void UnrolledList::InsertByIndex(int index, int num)
{
    if (index == 0)
    {
        InsertAtBeginning(num);
        return;
    }
    if (index == sizeList)
    {
        InsertAtEnd(num);
        return;
    }
    if (index > sizeList || index < 0)
    {
        std::cout << "Index out of range\n";
        return;
    }
    if (head == nullptr)
    {
        head = new Node(capacityNode);
        head->array[0] = num;
        head->sizeNode++;
        tail = head;
        sizeList++;
        return;
    }
    Node *currentNode;
    int count;
    if (index < sizeList / 2)
    {
        currentNode = head;
        count = 0;
        while (count + currentNode->sizeNode <= index && currentNode->next != nullptr)
        {
            count += currentNode->sizeNode;
            currentNode = currentNode->next;
        }
        currentNode->InsertIntoNode(index - count, num);
    }
    else
    {
        currentNode = tail;
        count = sizeList - 1;
        while (count - currentNode->sizeNode >= index)
        {
            count = count - currentNode->sizeNode;
            currentNode = currentNode->prev;
        }
        currentNode->InsertIntoNode(index - (count - currentNode->sizeNode + 1), num);
    }
    if (currentNode->sizeNode > capacityNode)
    {
        BalanceInsert(currentNode);
    }
    sizeList++;
}

void UnrolledList::InsertAtEnd(int num)
{
    if (head == nullptr)
    {
        head = new Node(capacityNode);
        head->array[0] = num;
        head->sizeNode++;
        tail = head;
        sizeList++;
        return;
    }
    tail->array[tail->sizeNode] = num;
    tail->sizeNode++;
    if (tail->sizeNode > capacityNode)
    {
        BalanceInsert(tail);
    }

    sizeList++;
}

void UnrolledList::InsertAtBeginning(int num)
{
    if (head == nullptr)
    {
        head = new Node(capacityNode);
        head->array[0] = num;
        head->sizeNode++;
        tail = head;
        sizeList++;
        return;
    }

    head->InsertIntoNode(0, num);
    if (head->sizeNode > capacityNode)
    {
        BalanceInsert(head);
    }

    sizeList++;
}

std::pair<Node *, int> UnrolledList::SearchByIndex(int index)
{
    if (index >= sizeList || index < 0)
    {
        std::cout << "Invalid index\n";
        return std::make_pair(nullptr, -1);
    }
    Node *currentNode;
    int count;
    if (index < sizeList / 2)
    {
        currentNode = head;
        count = 0;
        while (count + currentNode->sizeNode <= index)
        {
            count += currentNode->sizeNode;
            currentNode = currentNode->next;
        }
        return std::make_pair(currentNode, index - count);
    }
    else
    {
        currentNode = tail;
        count = sizeList - 1;
        while (count - currentNode->sizeNode >= index)
        {
            count -= currentNode->sizeNode;
            currentNode = currentNode->prev;
        }
        return std::make_pair(currentNode, index - (count - currentNode->sizeNode + 1));
    }
}
/// count <= ind < count + cur
/// count - cur < ind <= count

std::pair<Node *, int> UnrolledList::SearchByValue(int num)
{
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        for (int i = 0; i < currentNode->sizeNode; i++)
        {
            if (currentNode->array[i] == num)
            {
                return std::make_pair(currentNode, i);
            }
        }
        currentNode = currentNode->next;
    }
    return std::make_pair(nullptr, -1);
}

void UnrolledList::DeleteByIndex(int index)
{
    if (index >= sizeList || index < 0)
    {
        std::cout << "Invalid index\n";
        return;
    }
    if (index == sizeList - 1)
    {
        DeleteAtEnd();
        return;
    }
    auto result = SearchByIndex(index);
    memcpy(result.first->array + result.second, result.first->array + result.second + 1, (result.first->sizeNode - 1 - result.second) * sizeof(int));
    result.first->sizeNode--;
    sizeList--;
    BalanceDelete(result.first);
}

void UnrolledList::DeleteAtBeggining()
{
    if (head == nullptr)
    {
        std::cout << "Nothing to delete\n";
        return;
    }
    DeleteByIndex(0); // same logic in DBI
}

void UnrolledList::DeleteAtEnd()
{
    if (head == nullptr)
    {
        std::cout << "Nothing to delete\n";
        return;
    }
    tail->sizeNode--;
    sizeList--;
    BalanceDelete(tail);
}

void UnrolledList::DeleteByValue(int num)
{
    int flag = 0;
    auto result = SearchByValue(num);
    while (result.first != nullptr)
    {
        flag++;
        memcpy(result.first->array + result.second, result.first->array + result.second + 1, (result.first->sizeNode - 1 - result.second) * sizeof(int));
        result.first->sizeNode--;
        sizeList--;
        BalanceDelete(result.first);
        result = SearchByValue(num);
    }
    if (!flag)
    {
        std::cout << "No such element\n";
    }
    return;
}

void UnrolledList::Print()
{
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        for (int i = 0; i < currentNode->sizeNode; i++)
        {
            std::cout << currentNode->array[i] << " ";
        }
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

void UnrolledList::PrintByNodes()
{
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        std::cout << "Node: ";
        for (int i = 0; i < currentNode->sizeNode; i++)
        {
            std::cout << currentNode->array[i] << " ";
        }
        std::cout << '\n';
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

bool UnrolledList::isEmpty()
{
    return sizeList == 0;
}