#include "MergeSort.h"

void MergeSort::mergeSort(int* arr, int l, int r)
{
    if (l >= r)
    {
        return; //выходим из рекурсии
    }
    int m = (l + r - 1) / 2;   

    //многопоточное условие
    if ( (m - l) >= 10'000'000)
    {
        std::future<void> f = std::async(std::launch::async, mergeSort, arr, l, m);

        mergeSort(arr, m + 1, r);

        f.get();

        merge(arr, l, m, r);
    }
    //для одного потока
    else
    {
        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);       

        merge(arr, l, m, r);
    }    
}

void MergeSort::merge(int* arr, int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;

    // создаем временные массивы
    int* left = new int[nl];
    int* right = new int[nr];

    // копируем данные во временные массивы
    for (int i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l;  // начало левой части

    while (i < nl && j < nr) {
        // записываем минимальные элементы обратно во входной массив
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // записываем оставшиеся элементы левой части
    while (i < nl) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // записываем оставшиеся элементы правой части
    while (j < nr) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}
