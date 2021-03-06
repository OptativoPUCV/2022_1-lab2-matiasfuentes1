#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
       List * siguiente =(List *)malloc(sizeof(List)); 
       siguiente -> head = NULL;
       siguiente -> tail = NULL;
       siguiente -> current = NULL;

     return siguiente;
}

void * firstList(List * list) {
    list -> current = list ->head;
    if(list -> head == NULL ){
        return NULL;
    }
    return list -> head -> data;
}

void * nextList(List * list) {
    if(!list ->current || !list -> current -> next) return NULL;
    list -> current = list -> current -> next;
    return list -> current -> data;
}

void * lastList(List * list) {
    list ->current=list->tail;
    if(list->tail == NULL ) return NULL;
    return list -> tail -> data;
}

void * prevList(List * list) {
    if(!list ->current || !list -> current -> prev) return NULL;
    list -> current = list -> current -> prev;
    return list -> current -> data;
}

void pushFront(List * list, void * data) {

    Node * nodo = createNode(data);

    nodo -> next = list -> head;
    if(list -> head != NULL)
    list -> head -> prev = nodo;

    list -> head = nodo;
    nodo -> prev = NULL;

    if(list -> tail == NULL){
        list -> tail = nodo;
        nodo -> prev = list -> current;
    } 
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {

    Node *  nodo = createNode(data);

    if(list  -> head ==  NULL){
        list -> head = nodo;
    }
    if (list -> current -> next != NULL)
    {
        list -> current -> next = nodo;
        nodo -> next = list -> current -> next ;
        nodo -> prev = list -> current;
    }else{
        list -> tail = nodo;
        nodo -> prev = list ->current;
        list -> current -> next = nodo;
    }
    
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}