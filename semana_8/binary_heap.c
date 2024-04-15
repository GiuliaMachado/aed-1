#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

struct BinaryHeap {
 Element* data;
 int capacity;
 int size;
 };

BinaryHeap* bheap_create(int capacity){
    BinaryHeap* bh = malloc(sizeof(BinaryHeap));
    
    bh->capacity = capacity;
    bh->size = 0;
    bh->data = malloc(capacity * sizeof(Element));

    return bh;
}
void bheap_destroy(BinaryHeap* heap){
    free(heap->data);
    free(heap);
}
//funcoes auxiliares
int left(int index){
    return index * 2 + 1;
}
int right(int index){
    return index * 2 + 2;
}
int parent(int index){
    return (index -1)/2;
}
bool hasLeft(BinaryHeap* heap, int index) {
    //tem filho esquerdo se o indice do esquerdo for menor que o tamanho da heap
    return left(index) < heap->size;
}
bool hasRight(BinaryHeap* heap, int index) {
    //tem filho direito se o indice do direito for menor que o tamanho da heap
    return right(index) < heap->size;
}
bool hasParent(BinaryHeap* heap, int index){
    return index > 0;
}
Element getLeft(BinaryHeap* heap, int index){
    //caso que nao tem filho esquerdo
    if(!hasLeft(heap, index)){
        return ELEMENT_NULL;
    }
    return heap->data[left(index)];
}
Element getRight(BinaryHeap* heap, int index){
    //caso nao tenha o filho direito
    if(!hasRight(heap, index)){
        return ELEMENT_NULL;
    }
    return heap->data[right(index)];
}
Element getParent(BinaryHeap* heap, int index){
    //caso nao tenha nó pai
    if(!hasParent(heap, index)){
        return ELEMENT_NULL;;
    }
    return heap->data[parent(index)];
}
Element get(BinaryHeap* heap, int index){
    if(index >= heap->size){
        return ELEMENT_NULL;
    }
    return heap->data[index];
}
//inserção
//algoritmo siftUp - garante a inserção correta de valores na heap
void swapAt(BinaryHeap* heap, int i, int j){
    Element temp = heap->data[i];
    heap->data[i] = heap->data[j];
    heap->data[j] = temp;
}
void siftUp(BinaryHeap* heap) {
    int cur = heap->size -1;

    while(hasParent(heap, cur)&& get(heap, cur) > getParent(heap, cur)){
        swapAt(heap, cur, parent(cur));
        cur = parent(cur);
    }
}

void bheap_insert(BinaryHeap *heap, Element element){
    if(bheap_isFull(heap)){
        return;
    }
    heap->data[heap->size] = element;
    heap->size++;

    siftUp(heap);
}

//funcoes auxiliares da remocao
int maximumAt(BinaryHeap* bheap, int pos1, int pos2){
    return get(bheap, pos1) > get(bheap, pos2) ? pos1 : pos2;
}
void siftDown(BinaryHeap* heap){
    int cur =0;
    while(hasLeft(heap, cur)){
        int max = maximumAt(heap, left(cur), right(cur));

        if(get(heap, cur) > get(heap, max)){
            break;
        }
        swapAt(heap, cur, max);
        cur = max;
    }
}
Element bheap_extract(BinaryHeap *heap){
    if(heap->size == 0){
        return ELEMENT_NULL;
    }
    Element result = heap->data[0];
    heap->data[0] = heap->data[heap->size-1];
    heap->size--;

    siftDown(heap);
    return result;
}
Element bheap_peek(BinaryHeap *heap){
    if(heap->size == 0){
        return ELEMENT_NULL;
    }

    return heap->data[0];
}
int bheap_size(BinaryHeap* heap){
    return heap->size;
}
bool bheap_isEmpty(BinaryHeap* heap){
    return heap->size == 0;
}
bool bheap_isFull(BinaryHeap* heap){
    return heap->size == heap->capacity;
}
void bheap_print(BinaryHeap* heap){
    for(int i =0; i< heap->size; i++){
        element_print(heap->data[i]);
        printf(" ");
    }
    printf("\n");
}