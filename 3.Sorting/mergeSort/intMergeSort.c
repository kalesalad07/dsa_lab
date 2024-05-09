#include "intMerge.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


void mergeSort(int A[], int st, int en){
    if(en-st < 1)return;
    int mid = (st+en)/2;
    mergeSort(A,st,mid);
    mergeSort(A,mid+1,en);
    merge(A,st,mid,en);
}

int main(){
    FILE* file = fopen("marks.txt","r");
    int data[1000];

    for(int i = 0; i < 1000; i++){
        fscanf(file,"%d",data+i);
    }

    struct timeval t1,t2;
    double time_taken;

    gettimeofday(&t1,NULL);
    mergeSort(data,0,1000);
    gettimeofday(&t2,NULL);

     time_taken = (t2.tv_sec - t1.tv_sec) *1e6;
    time_taken = (time_taken + (t2.tv_usec-t1.tv_usec))*1e-6;

    printf("Sorting time- %f seconds\n",time_taken);
}