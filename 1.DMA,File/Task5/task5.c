#include <stdio.h>

int main(void){
    FILE *fptr = fopen(__FILE__, "r");    
    char line[100];
    while(fgets(line,100,fptr)){
        printf("%s",line);
    }
    fclose(fptr);
    return 0;
}
