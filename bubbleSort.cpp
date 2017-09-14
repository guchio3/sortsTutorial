#include "bubbleSort.h"

void bubbleSort(vector<int> &source_array){
    int a_size = source_array.size();
    for(int i = 0; i < a_size; ++i){
        for(int j = 0; j < a_size - i - 1; ++j){
            if(source_array[j] > source_array[j + 1]){
                int temp = source_array[j];
                source_array[j] = source_array[j + 1];
                source_array[j + 1] = temp;
            }
        }
    }
}
