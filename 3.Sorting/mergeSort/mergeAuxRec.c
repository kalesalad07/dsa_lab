#include "intMergeAux.h"

void mergeAux(int A[], int s1, int e1, int B[], int s2, int e2, int C[], int s3, int e3){
    if(A[s1] > B[s2]){
        C[s3] = B[s2];
        mergeAux(A,s1,e1,B,s2+1,e2,C,s3+1,e3);
    }
    else{
        C[s3] = A[s1];
        mergeAux(A,s1+1,e1,B,s2,e2,C,s3+1,e3);
    }
}