#include "sort.h"
#include <stdlib.h>

void mergeAux(struct person A[], int s1, int e1, struct person B[], int s2, int e2, struct person C[], int s3, int e3){
    int i,j,k;
    i = s1;j=s2;k=s3;
    while(i <= e1 && j <= e2){
        if(A[i].height < B[j].height){
            C[k++] = A[i++];
        }
        else{
            C[k++] = B[j++];
        }
    }
    while(i <= e1){
        C[k++] = A[i++];
    }
    while(j <= e2){
        C[k++] = B[j++];
    }

}

void merge(struct person A[], int s, int mid, int e){
    struct person *C = (struct person*)malloc(sizeof(struct person) * (e-s+1));
    mergeAux(A,s,mid,A,mid+1,e,C,0,e-s);
    for(int i = 0; i < e-s+1; i++){
        A[s+i] = C[i];
    }
    free(C);
}

void mergeSort(struct person* A, int st, int en){
    if(en-st < 1)return;
    int mid = (st+en)/2;
    mergeSort(A,st,mid);
    mergeSort(A,mid+1,en);
    merge(A,st,mid,en);
}

void sort(struct person* arr, int n){
    mergeSort(arr,0,n);
}







