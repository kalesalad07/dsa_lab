#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char** stringArr;
    int n;

    printf("Input size of the array- ");
    scanf("%d", &n);
    
    stringArr = calloc(n, sizeof(char*));
    printf("Input %d strings- \n", n);    
    for(int i = 0; i < n; i++){
        char* s = calloc(20, sizeof(char));
        scanf(" %s", s);
        stringArr[i] = s;
    }
    char c;
    do{
        
        printf("a)Add a string to the end of the array\n");
        printf("b)Add a string to the beginning of the array\n");
        printf("c)Delete an element of the array\n");
        printf("d)Display length of the array\n");
        printf("e)Display all elements of the array\n");
        printf("f)Exit\n");
        printf("Enter your choice - ");
        scanf(" %c", &c);

        if(c == 'a'){
            printf("Enter string -");
            char* s = calloc(20, sizeof(char));
            scanf(" %s", s);
            n++;
            stringArr = realloc(stringArr, n*sizeof(char*));
            stringArr[n-1] = s;
        }
        else if(c == 'b'){
            printf("Enter string -");
            char* s = calloc(20, sizeof(char));
            scanf(" %s", s);
            n++;
            stringArr = realloc(stringArr, n*sizeof(char*));
            char* temp;
            
            for(int i = 0; i < n; i++){
                temp = stringArr[i];
                stringArr[i] = s;
                s = temp;
            }
        }
        else if(c == 'c'){
            printf("Input index to delete -");
            int x;
            scanf("%d", &x);
            free(stringArr[x]);
            for(int i = x; i < n-1; i++){
                stringArr[i] = stringArr[i+1];
            }
            n--;
            stringArr = realloc(stringArr, n*sizeof(char*));

        }
        else if(c == 'd'){
            printf("Length of array is %d\n",n);
        }
        else if(c == 'e'){
            printf("Elements of array - \n");
            for(int i = 0; i < n; i++){
                printf("%s\n", stringArr[i]);
            }
        }


    }while(c!='f');

    return 0;
}