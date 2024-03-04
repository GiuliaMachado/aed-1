#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    Element element;
    struct Node* next;
} Node;

struct Queue{
    Node* front;
    Node* back;
    int size;
};

Queue* queue_create(){
    Queue* queue = malloc(sizeof(Queue));

    //pode ser zero, -1;
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;

    return queue;
}
void queue_destroy(Queue* queue){
    while(!queue_isEmpty(queue)){
        queue_dequeue(queue);
    }
    free(queue);
}
void queue_enqueue(Queue* queue, Element element){
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = NULL;
    if(queue_isEmpty(queue)){
        queue->front =  newNode;
    }
    else{
        queue->back->next = newNode;
    }
    queue->back = newNode;
    queue->size++;

}
Element queue_dequeue(Queue* queue){
    if(queue_isEmpty(queue)){
        return ELEMENT_NULL;
    }
    //remocao no inicio da lista encadeada
    Node* trash = queue->front;
    Element element = trash->element;

    queue->front = queue->front->next;
    free(trash);

    queue->size--;

    return element;
}
Element queue_front(Queue* queue){
    //implementar
}
Element queue_back(Queue* queue){
    //implementar
}
int queue_size(Queue* queue){
    return queue->size;
}

bool queue_isEmpty(Queue* queue){
    return queue->size == 0;
    //desafio: determinar se ta cheio ou vazia sem size
}

void queue_print(Queue* queue){
    Node* cur = queue->front;

    while(cur != NULL){
        element_print(cur->element);
        cur = cur->next;
    }
}
