#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct Queue{
    Element* elements;
    int size;
    int front;
    int back;
    int capacity;
};

Queue* queue_create(int capacity){
    Queue* queue = malloc(sizeof(Queue));

    queue->elements = malloc(sizeof(Element) * capacity);
    queue->capacity = capacity;
    queue->size = 0;
    //pode ser zero, -1;
    queue->front = 0;
    queue->back = 0;

    return queue;
}
void queue_destroy(Queue* queue){
    free(queue->elements);
    free(queue);
}
void queue_enqueue(Queue* queue, Element element){
    if(queue_isFull(queue)){
        return;
    }
    queue->elements[queue->back] = element;
    queue->back = (queue->back + 1)  % queue->capacity;
    if(queue->back == queue->capacity -1){
        queue->back = 0;
    }else{
        queue->back++;
    }
    queue->size++;
}
Element queue_dequeue(Queue* queue){
    if(queue_isEmpty(queue)){
        return ELEMENT_NULL;
    }
    Element element = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return element;
    //enqueue e dequeue add e remove e já retorna deixando os algoritmos
    //esteticamente melhores, mas poderia ser null
}
Element queue_front(Queue* queue){
    if(queue_isEmpty(queue)){
        return ELEMENT_NULL;
    }
    return queue->elements[queue->front];
}
Element queue_back(Queue* queue){
    if(queue_isEmpty(queue)){
        return ELEMENT_NULL;
    }
    return queue->elements[queue->back];
}
int queue_size(Queue* queue){
    return queue->size;
}

bool queue_isEmpty(Queue* queue){
    return queue->size == 0;
    //desafio: determinar se ta cheio ou vazia sem size
}

bool queue_isFull(Queue* queue){
    return queue->size == queue->capacity;
}

void queue_print(Queue* queue){
    //imprimir só as posicoes do array que estou usando na fila
    //a fila é contígua
    for(int i =0; i < queue_size(queue); i++){
        int pos  = (queue->front + i) % queue->capacity;

        element_print(queue->elements[pos]);
        printf(" ");
    }
    printf("\n");
}
