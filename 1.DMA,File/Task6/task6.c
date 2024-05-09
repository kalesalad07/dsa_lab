#include <stdio.h>

int main(void){
    FILE* og = fopen("text1.txt", "r");
    FILE* cpy = fopen("text2.txt", "w");

    char line[100];
    while(fgets(line,100,og)){
        fputs(line,cpy);
    }

    fclose(og);
    fclose(cpy);
    og = fopen("text1.txt","w");
    fclose(og);
    return 0;
}