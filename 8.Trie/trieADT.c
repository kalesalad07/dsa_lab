#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 128

int CHAR_TO_INDEX(char c){
    return (int)c;
}

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    int noOfChildren;
};

struct TrieNode* getNode(){
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));

    if(pNode){
        int i;
        pNode->isEndOfWord = false;
        pNode->noOfChildren = 0;
        for(int i = 0; i < ALPHABET_SIZE; i++){
            pNode->children[i] = NULL;
        }
        
    }
    return pNode;
}

void insert(struct TrieNode *root, const char *key){
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for(level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
            pCrawl->noOfChildren++;
        }
        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode* root, const char *key){
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode* pCrawl = root;
    for(level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index]) return false;
        
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEndOfWord);
}

void delete(struct TrieNode* root, const char* key){
    deleteRec(root, key, 0);
}

bool recDelete(struct TrieNode* node, const char* key, int index){
    if(index < strlen(key)-1){
        int pos = CHAR_TO_INDEX(key[index]);
        if(recDelete(node->children[pos], key, index+1)){
            node->children[pos] = NULL;
            node->noOfChildren--;
            if(node->noOfChildren == 0){
                free(node);
                return true;
            }
            return false;
        }
        return false;
    }
    else{
        node->isEndOfWord = false;
        if(node->noOfChildren == 0){
            free(node);
            return true;
        }
        return false;
    }
}   

int main(){
    char keys[][8] = {"the","a","there","answer","any","by","bye","their"};
    char output[][32] = {"Not present in trie","Present in trie"};

    struct TrieNode* root = getNode();
    //construct trie
    int i;
    for(i = 0; i < sizeof(keys)/sizeof(keys[0]); i++){
        insert(root,keys[i]);
    }

    printf("%s --- %s \n", "the", output[search(root,"the")]);
    printf("%s --- %s \n", "these", output[search(root,"these")]);
    printf("%s --- %s \n", "their", output[search(root,"their")]);
    printf("%s --- %s \n", "thaw", output[search(root,"thaw")]);
    
    return 0;
}