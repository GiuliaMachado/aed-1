#include <stdio.h>
#include "array_dinamico.h"
#include "../array/element.h"

int main(void){
    ArrayDinamico* array = array_dinamico_create(10);

    for (int i = 0; i < 100; i++) {
        array_dinamico_add(array, i);
    }
    array_dinamico_print(array);
    array_dinamico_destroy(array);

    return 0;
}