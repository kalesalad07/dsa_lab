#include "count.h"

int count(char* string){
    int count = 0;
    for(int i = 0; i < strlen(string); i++){
        char c = tolower(string[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            count++;
        }
    }
    return count;
}