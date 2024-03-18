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
int list_size(LinkedList* list){
    Node* cur = list->head;
    int tam = 0;
    while(cur != NULL){
        tam++;
        cur = cur->next;
    }

    return tam;
}
Element list_get(LinkedList* list, int pos){
    Node* cur = list->head;
    int cont = 0;
    while(cur != NULL){
        if(cont == pos){
            return cur->element;
        }
        cont++;
        cur = cur->next;
    }
    return ELEMENT_NULL;
}

void list_printElements(LinkedList* l1, LinkedList* l2){
    //imprimir elementos da 1 lista, cuja posicao está na segunda lista
    Node* cur2 = l2->head;

    while(cur2 != NULL){
        Node* cur1 = l1->head;
        int pos = 0;
        while(pos < list_size(l1) && cur1 != NULL){
            if(pos == cur2->element){
                element_print(cur1->element);
            }
            pos++;
            cur1 = cur1->next;
        }
        cur2 = cur2->next;
    }
}

bool list_equals(LinkedList* l1, LinkedList* l2){
    if(list_size(l1) == list_size(l2)){
        Node* cur1 = l1->head;
        Node* cur2 = l2->head;

        while(cur1 != NULL && cur2 != NULL){
            if (cur1->element != cur2->element){
                return false;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;     
        }
        return true;
    }
    return false;
}

int list_isSorted(LinkedList* l){
    //1 - crescente. 2- decrescente. 0 - fora de ordem
    Node* cur = l->head;
    int cont_cresc = 0;
    int cont_decresc = 0;
    while(cur->next != NULL){
        if(cur->next->element > cur->element){
            cont_cresc++;
        }
        else{
            cont_decresc++;
        }
        cur = cur->next; 
    }
    if(cont_cresc == list_size(l)-1){
        return 1;
    }
    else if(cont_decresc == list_size(l)-1){
        return 2;
    }
    else{
        return 0;
    }
}

void list_removeDuplicates(LinkedList* l){
    if(l->head == NULL){
        return;
    }
    Node* cur = l->head;
    while(cur != NULL){
        Node* percorre = cur;
        while(percorre->next != NULL){
            if(percorre->next->element == cur->element){
                Node* temp = percorre->next;
                percorre->next = percorre->next->next;
                free(temp);
            }
            else{
                percorre = percorre->next;
            }
        }
        cur = cur->next;
    }
}
//funcao auxiliar recursiva da print reverse
void printReverseRecursive(Node* node) {
    if (node == NULL) {
        return;
    }
    printReverseRecursive(node->next);
    printf("%d ", node->element);
}

void list_printReverse(LinkedList* l) {
    printReverseRecursive(l->head);
    printf("\n");
}
