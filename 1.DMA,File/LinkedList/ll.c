#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* NODE;
struct node{
    int ele;
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

NODE createNewNode(int value){
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->ele = value;
    myNode->next = NULL;
    return myNode;
}

void insertAfter(int searchEle, NODE n1, LIST l1){
    if(l1->head == NULL){
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else{
        NODE temp = l1->head;
        NODE prev = temp;
        while(temp != NULL){
            if(temp->ele == searchEle)break;
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Element not found");
            return;
        }
        else{
            if(temp->next == NULL){
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }
            else{
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}

void printList(LIST l1){
    NODE temp = l1->head;
    printf("[HEAD]->");
    while(temp != NULL){
        printf("%d ->",temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}

void deleteAt(int searchEle, LIST l1){
    NODE temp = l1->head;    
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    if(temp->ele == searchEle){
        l1->head = temp->next;
        free(temp);
        l1->count--;
        return;
    }
    NODE prev = temp;
    temp = temp->next;
    while(temp != NULL){
        if(temp->ele == searchEle){
            prev->next = temp->next;
            free(temp);
            l1->count--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Node not found\n");
}

void insertFirst(NODE n1, LIST l1){
    NODE temp = l1->head;
    l1->head = n1;
    n1->next = temp;
    l1->count++;
}

void deleteFirst(LIST l1){
    if(l1->head == NULL){
        printf("List is empty\n");
        return;
    }
    NODE temp = l1->head->next;
    free(l1->head);
    l1->head = temp;
    l1->count--;
}

int search(int value, LIST l1){
    NODE temp = l1->head;
    int index = 0;
    while(temp != NULL){
        if(temp->ele == value) return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

void rotate(int k, LIST l1){
    NODE last = l1->head;
    for(int i = 1; i < l1->count; i++){
        last = last->next;
    }
    last->next = l1->head;
    for(int i = 0; i < k; i++){
        l1->head = l1->head->next;
    }
    last = l1->head;
    for(int i = 1; i < l1->count; i++){
        last = last->next;
    }
    last->next = NULL;

}

bool hasCycle(LIST l1){
    NODE fast = l1->head;
    NODE slow = fast;
    
    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast == NULL) return false;
        fast = fast->next;
        slow = slow->next;
        if(fast == slow)return true;
    }
    return false;
}

int main(){
    LIST myLi = createNewList();
    NODE n;
    for(int i = 0; i < 6; i++){
        n = createNewNode(i);
        insertFirst(n,myLi);
    }
    printList(myLi);

    n = createNewNode(20);
    insertAfter(4,n,myLi);
    printList(myLi);

    deleteFirst(myLi);
    deleteAt(3,myLi);
    printList(myLi);

    int i = search(20,myLi);
    printf("20 found at index %d\n",i);

    rotate(3,myLi);
    printList(myLi);

    LIST acyclic = myLi;
    LIST cyclic = createNewList();
    for(int i = 0; i < 6; i++){
        n = createNewNode(6-i);
        insertFirst(n,cyclic);
    }
    NODE last = cyclic->head;
    for(int i = 1; i < cyclic->count; i++){
        last = last->next;
    }
    last->next = cyclic->head->next->next->next;

    LIST circular = createNewList();
    for(int i = 0; i < 6; i++){
        n = createNewNode(6-i);
        insertFirst(n,circular);
    }
    last = circular->head;
    for(int i = 1; i < circular->count; i++){
        last = last->next;
    }
    last->next = circular->head;

    printf("Acyclic - %s\n", hasCycle(acyclic)?"YES":"NO");
    printf("Cyclic - %s\n", hasCycle(cyclic)?"YES":"NO");
    printf("Circular - %s\n", hasCycle(circular)?"YES":"NO");
}