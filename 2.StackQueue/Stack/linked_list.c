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
        list->count--;
    }
}

void insertNodeAtEnd(NODE node, LIST list){
    NODE temp = list->head;
    if(temp == NULL){
        list->head = node;
        list->count++;
        return;
    }
    while(temp->next != NULL) temp = temp->next;
    temp->next = node;
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
