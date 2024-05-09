#include "linked_list.h"
#include "heap_usage.h"
#include <stdlib.h>

LIST createNewList(){
    LIST l = (LIST)myalloc(sizeof(linked_list));
    if(l != NULL) l->count = 0;
    return l;
}

NODE createNewNode(Element data){
    NODE n = (NODE)myalloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insertNodeIntoList(NODE node, LIST list){
    NODE h = list->head;
    if(list->count == 0) list->tail = node;
    list->head = node;
    node->next = h;
    list->count++;
}

void removeFirstNode(LIST list){
    if(list->count > 1){
        NODE h = list->head->next;
        myfree(list->head);
        list->head = h;
        list->count--;
    }
    else if(list->count == 1){
        myfree(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->count--;
    }
}

void insertNodeAtEnd(NODE node, LIST list){
    if(list->count == 0){
        list->head = node;
        list->tail = node;
        
    }
    else{
        list->tail->next = node;
        list->tail = node; 
    }
    
    list->count++;
    return;
}

void destroyList(LIST l){
    NODE n = l->head;
    NODE temp = l->head;
    while(n != NULL){
        temp = temp->next;
        myfree(n);
        n = temp;
    }
    myfree(l);
}
