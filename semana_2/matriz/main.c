#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

int main(){
    Matriz* matriz = matriz_create(3,3);

    for(int i = 0; i < matriz_rows(matriz); i++){
        for(int j = 0; j < matriz_cols(matriz); j++){
            matriz_set(matriz, i, j, i * matriz_cols(matriz) + j + 1);
        }
    }
    matriz_print(matriz);
    matriz_destroy(matriz);

    return 0;
}