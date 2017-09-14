#include "quickSort.h"
#include <iostream>

void swap(int &a, int &b){
    int temp = a;
    a = b; 
    b = temp;
    return;
}

int partition(vector<int> &source_array, int left, int right){
    int pivot = source_array[right], res = left;
    for(int i = left; i < right; ++i)
        if(source_array[i] <= pivot)
            swap(source_array[res++], source_array[i]);
    swap(source_array[res], source_array[right]);
    return res;
}

void quickSort(vector<int> &source_array, int left, int right){
    if(left >= right)
        return;
    int pi = partition(source_array, left, right);
    quickSort(source_array, left, pi - 1);
    quickSort(source_array, pi + 1, right);
    return;
}
