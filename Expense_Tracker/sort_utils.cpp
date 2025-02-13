#include "sort_utils.h"

int partition(std::vector<Expense>& arr, int low, int high) 
{
    int pivot = arr[high].id;
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (arr[j].id < pivot) 
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<Expense>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
