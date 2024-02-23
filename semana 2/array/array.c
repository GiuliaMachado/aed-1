#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "array.h"

struct Array{
    Element* array;
    int size;
};

Array* array_create(int size){
    //1- aloca o array e depois espaço para os elementos do array
    Array* array = malloc(sizeof(Array));
    array->array = malloc(size *sizeof(Element));
    array->size = size;

    return array;
}

void array_destroy(Array* array){
    free(array->array);
    free(array);
}

void array_print(Array* array){
    for(int i = 0; i < array->size; i++){
        print_element(array->array[i]);
    }
    printf("\n");
}

Element array_get(Array* array, int index){
    return array->array[index];
}

void array_set(Array* array, int index, Element value){
    array->array[index] = value;
}

int array_size(Array* array){
    return array->size;
}