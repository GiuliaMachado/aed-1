#include "sorted_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Student* student;
    struct Node* next;
} Node;

struct SortedList {
    Node* first;
    Node* last;
    int size;
};

SortedList* slist_create() {
    SortedList* list = (SortedList*) malloc(sizeof(SortedList));
    
    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

void slist_destroy(SortedList* list) {
    while (list->first != NULL) {
        Node* trash = list->first;
        
        list->first = list->first->next;
        student_destroy(trash->student);
        free(trash);
    }
    free(list);
}

int slist_size(SortedList* list) {
    return list->size;
}

Student* slist_get(SortedList* list, int pos) {
    if (pos < 0 || pos >= list->size) {
        return NULL;
    }

    Node* cur = list->first;

    for (int i = 0; i < pos; i++) {
        cur = cur->next;
    }

    return cur->student;
}

Student* slist_getMin(SortedList* list) {
    if (list->first == NULL) {
        return NULL;
    }
    return list->first->student;
}

Student* slist_getMax(SortedList* list) {
    if (list->last == NULL) {
        return NULL;
    }

    return list->last->student;
}

bool slist_is_empty(SortedList* list) {
    return list->first == NULL;
}

void slist_print(SortedList* list) {
    Node* cur = list->first;

    while (cur != NULL) {
        student_print(cur->student);
        if (cur->next != NULL) {
            printf(" -> ");
        }
        cur = cur->next;
    }
    printf("\n");
}

// new functions

bool slist_insert(SortedList *list, unsigned int ra, const char* name, float grade) {
    Node* newNode = malloc(sizeof(Node)); //criou o nó ALOCOU NO
    newNode->student = student_create(ra, name, grade); //associou com os dados  ALOCOU DADOS DO STUDENT

    //caso 1: lista vazia
    if(slist_is_empty(list)){
        list->first = newNode;
        list->last = newNode;
        newNode->next = NULL;
        list->size++;
        return true;
    }
    //caso 2: adiciona no comeco
    if(newNode->student->ra < slist_getMin(list)->ra){
        newNode->next = list->first;
        list->first = newNode;
        list->size++;
        return true;
    }
    //caso 3: adiciona no final
    if(newNode->student->ra > slist_getMax(list)->ra){
        newNode->next = NULL;
        list->last->next = newNode;
        list->last = newNode;
        list->size++;
        return true;
    }
    //caso 4: percorre e o ra ja esta na lista ou nao
    else{
        Node* cur = list->first;
        while(cur != NULL){
            if(cur->student->ra < newNode->student->ra && cur->next->student->ra > newNode->student->ra){
                Node* temp = cur->next;
                cur->next = newNode;
                newNode->next = temp;
                list->size++;
                return true;
            }
            cur =  cur->next;
        }
    }
    //CASO FINAL: NAO ADICIONOU 
    student_destroy(newNode->student); //DESALOCA O STUDENT CRIADO
    free(newNode); //DESALOCA O NÓ CRIADO
    return false;
}