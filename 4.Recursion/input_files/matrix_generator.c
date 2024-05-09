#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void rowAdd(int n, int (*mat1)[n], int (*mat2)[n]){
    int mat3[n][n];
    struct timeval t1,t2;
    double time_taken;
    
    gettimeofday(&t1,NULL);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_usec-t1.tv_usec)*1e6;

    printf("Time taken for adding(row) - %f\n", time_taken);
}


void colAdd(int n, int (*mat1)[n], int (*mat2)[n]){
    int mat3[n][n];
    struct timeval t1,t2;
    double time_taken;
    
    gettimeofday(&t1,NULL);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_usec-t1.tv_usec)*1e6;
    printf("Time taken for adding(col) - %f\n", time_taken);
}

int main(void)
{

    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int mat1[n][n];
    int mat2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat1[i][j] = rand() % 100;
            mat2[i][j] = rand() % 100;
        }
    }
    rowAdd(n,mat1,mat2);
    colAdd(n,mat1,mat2);

}

