#include <stdio.h>
#include "set.h"

int main(void){
    char s[10];
    for(int i = 0; i < 10; i++){
        printf("Answer to question %d - ",i+1);
        scanf(" %c",s+i);
    }
    int score = answer_checker(s);
    printf("Your score is %d\n", score);

    return 0;
}