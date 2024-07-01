//многопоточная сортировка слиянием
#include <iostream>
#include "MergeSort.h"
#define SIZE_ARRAY 100'000'000

int main()
{
    //подготовим массив
    int* array = new int[SIZE_ARRAY];
    for (int i = 0; i < SIZE_ARRAY; ++i) {
        array[i] = rand() % 5000;
    }
    
    MergeSort MergeSort;    

    try
    {
        //многопоточная сортировка слиянием
        MergeSort.mergeSort(array, 0, SIZE_ARRAY-1);

    } catch(...) {
        std::cout << "some mistake\n";
    };

    delete[] array;
    return 0;
}
