#include "intMergeAux.h"

void mergeAux(int A[], int s1, int e1, int B[], int s2, int e2, int C[], int s3, int e3){
    int i,j,k;
    i = s1;j=s2;k=s3;
    while(i <= e1 && j <= e2){
        if(A[i] < B[j]){
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