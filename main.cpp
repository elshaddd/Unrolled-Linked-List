#include <iostream>
#include "modules/UnrolledList.h"
#include <list>
#include <array>
// графики и ассерты
void check(int arr_1[], int size1, int arr_2[], int size2, int n_array = 4)
{
    UnrolledList myList(n_array);
    for (int i = 0; i < size1; i++)
    {
        myList.InsertAtEnd(arr_1[i]);
        myList.PrintByNodes();
    }
    myList.Print();
    std::cout << '\n';
    for (int i = 0; i < size2; i++)
    {
        myList.DeleteByValue(arr_2[i]);
        myList.PrintByNodes();
    }
}

int main()
{
    int size1, size2;
    std::cin >> size1 >> size2;
    int arr_1[size1];
    for (size_t i = 0; i < size1; i++)
    {
        std::cin >> arr_1[i];
    }
    int arr_2[size2];
    for (size_t i = 0; i < size2; i++)
    {
        std::cin >> arr_2[i];
    }
    check(arr_1, size1, arr_2, size2);
    return 0;
}