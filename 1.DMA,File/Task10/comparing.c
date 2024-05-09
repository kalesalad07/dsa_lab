#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

struct student{
    char id[20];
    float cgpa;
};

typedef struct node* NODE;
struct node{
    struct student s;
    NODE next;
};

typedef struct linked_list* LIST;
struct linked_list{
    int count;
    NODE head;
};

LIST createNewList(){
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}

NODE createNewNode(struct student s1){
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->s = s1;
    myNode->next = NULL;
    return myNode;
}

void insertArray(struct student* arr, int n, struct student s1){
    arr = realloc(arr, (n+1)*sizeof(struct student));
    arr[n] = s1;
}

void insertList(LIST l1, struct student s){
    NODE newNode = createNewNode(s);
    NODE temp = l1->head;
    if(temp == NULL){
        l1->head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

struct student* dataArray(){
    FILE* data = fopen("data.txt","r");    
    struct student* arr =(struct student *) malloc(10000*sizeof(struct student));

    struct timeval t1,t2;
    double time_taken;

    char* id;
    float cg;
    gettimeofday(&t1,NULL);    
    char line[50];
    int i = 0;
    while(fgets(line,50,data)){
        char* token = strtok(line,",");
        strcpy(arr[i].id,token);
        token = strtok(NULL,",");
        arr[i].cgpa = atof(token);
        i++;        
    }
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) *1e6;
    time_taken = (time_taken + (t2.tv_usec-t1.tv_usec))*1e-6;

    printf("Array data insert took %f seconds\n",time_taken);
    return arr;
}

LIST dataList(){
    FILE* data = fopen("data.txt","r");
    LIST mydata = createNewList();
    struct student s;
    char line[50];

    struct timeval t1,t2;
    double time_taken; 

    gettimeofday(&t1,NULL);
    fgets(line,50,data);
    char* token = strtok(line,",");
    strcpy(s.id,token);
    token = strtok(NULL,",");
    s.cgpa = atof(token);

    NODE n = createNewNode(s);
    mydata->head = n;
    NODE p = n;
    while(fgets(line,50,data)){
        token = strtok(line,",");
        strcpy(s.id,token);
        token = strtok(NULL,",");
        s.cgpa = atof(token);

        n = createNewNode(s);
        p->next = n;
        p = n;
    }
    gettimeofday(&t2,NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) *1e6;
    time_taken = (time_taken + (t2.tv_usec-t1.tv_usec))*1e-6;

    printf("LinkedList data insert took %f seconds\n",time_taken);
    return mydata;
}


int main(){
    struct student* arr = dataArray();
    LIST li = dataList();
}