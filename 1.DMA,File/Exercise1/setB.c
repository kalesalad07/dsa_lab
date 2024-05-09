#include "set.h"

int answer_checker(char* s){
    char* key = "BDACDABDCA";
    int score = 0;
    for(int i = 0; i < 10; i++){
        if(s[i] == key[i]) score += 4;
        else if(s[i] != 'N') score -= 1;
    }
    return score;
}