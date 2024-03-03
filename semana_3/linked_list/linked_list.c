#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

//definir o NODE e LinkedList com ponteiro pra cabeça
typedef struct Node {
    Element element;
    struct Node* next;
}Node;

struct LinkedList{
    Node* head;
    int size;
};

LinkedList* list_create(){
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size =0;

    return list;
}

void list_destroy(LinkedList* list){
    Node* cur = list->head;

    while(cur != NULL){
        Node* tresh = cur;
        cur = cur->next;
        free(tresh);
    }
    free(list);
}

void list_insertFirst(LinkedList* list, Element e){
    //criamos o novo nó
    Node* newNode = malloc(sizeof(Node));
    //passamos o elemento do nó
    newNode->element = e;
    //o ponteiro pro proximo nó é a cabeça da lista
    newNode->next = list->head;
    //a cabeça da lista recebe o conteudo do novo nó
    list->head = newNode;
    list->size++;
}

void list_insertAfter(LinkedList* list, int pos, Element e){
    //caso 1: inserir no começo
    if(list->head == NULL || pos < 0){
        list_insertFirst(list, e);
    }
    else{
        Node* cur = list->head;
        int i = 0;

        while(i < pos && cur->next != NULL){
            cur = cur->next;
            i++;
        }

        Node* newNode = malloc(sizeof(Node));
        newNode->element = e;
        newNode->next = cur->next;
        cur->next = newNode;
        list->size++;

    }
}
bool list_removeFirst(LinkedList* list){
    if(list->head == NULL){
        return false;
    }

    Node* trash = list->head;
    list->head = list->head->next;
    free(trash);
    list->size--;

    return true;
}
bool list_removeAt(LinkedList* list, int pos){
    // caso 0: posicao invalida
    if(pos <0 || pos >= list->size){
        return false;
    }
    //caso 1: lista vazia
    if(list->head == NULL){
        return false;
    }
    //caso 2: remocao no inicio
    if(pos ==0){
        list_removeFirst(list);
    }
    else{ //caso 3: remocao na cauda
        Node* prev = list->head;
        int i = 0;
        while(i < pos -1){
            prev = prev->next;
            i++;
        }

        Node* trash = prev->next;
        prev->next = prev->next->next; // ou trash->next;
        free(trash);
        list->size--;
        
    }
    return true;
}

void list_print(LinkedList* list){
    Node* cur = list->head;

    while(cur != NULL){
        element_print(cur->element);
        cur = cur->next;
    }
    printf("\n");
}
