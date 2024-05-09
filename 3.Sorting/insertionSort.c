#include "sort.h"

void sort(struct person *arr, int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        struct person v = arr[i];
        while(j >= 0 && v.height < arr[j].height){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;        
    }
}