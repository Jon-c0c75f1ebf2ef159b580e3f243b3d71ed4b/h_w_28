#pragma once
#include <thread>
#include <future>

class MergeSort
{
public:
    static void mergeSort(int* arr, int l, int r);

private:
    static void merge(int* arr, int l, int m, int r);
};
