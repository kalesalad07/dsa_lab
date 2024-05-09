#include <stdio.h>

struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

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

int main(){
    struct person data[] = {{1,"Sokka",15,150,45},
                {2,"Aang",112,137,35},
                {3,"Zuko",16,160,50},
                {4,"Katara",14,145,38},
                {5,"Toph",12,113,30}};

    for(int i = 0; i < 5; i++){
        printf("%d %s %d %d %d\n", data[i].id,data[i].name,data[i].age,data[i].height,data[i].weight);
    }
    printf("\n\n");
    sort(data, 5);

    for(int i = 0; i < 5; i++){
        printf("%d %s %d %d %d\n", data[i].id,data[i].name,data[i].age,data[i].height,data[i].weight);
    }
}