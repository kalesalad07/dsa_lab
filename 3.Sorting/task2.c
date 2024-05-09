#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "sort.h"

#define FILEPATH "dat10000.csv"
#define INPUT_SIZE 10000





struct person *readData(){
    FILE* file = fopen(FILEPATH, "r");
    struct person* arr = (struct person*)malloc(INPUT_SIZE*sizeof(struct person));
    printf("File opened and array created\n");
    char line[100];
    int i = 0;
    while(fgets(line,100,file)){
        printf("%s",line);
        char* token = strtok(line,",");        
        arr[i].id = atoi(token);

        token = strtok(NULL,",");       
        strcpy(arr[i].name,token);

        token = strtok(NULL,",");       
        arr[i].age = atoi(token);

        token = strtok(NULL,",");
        arr[i].height = atoi(token);
        
        token = strtok(NULL,",");       
        arr[i].weight = atoi(token);

        
        i++;
    }

    return arr;
}

int main(){
    printf("Reading data\n");
    struct person *data = readData();
    struct timeval t1,t2;
    double time_taken;
    printf("Sorting\n");
    gettimeofday(&t1,NULL);
    sort(data,INPUT_SIZE);
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) *1e6;
    time_taken = (time_taken + (t2.tv_usec-t1.tv_usec))*1e-6;

    printf("Sorting size %d took - %f seconds\n",INPUT_SIZE,time_taken);
    
}