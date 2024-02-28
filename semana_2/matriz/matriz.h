//interface
#ifndef MATRIZ_H
#define MATRIZ_H
#include <stdbool.h>

//tipo opaco
typedef struct Matriz Matriz;

//protótipo de funções
Matriz* matriz_create(int row, int col);
void matriz_destroy(Matriz* matriz);
void matriz_print(Matriz* matriz);
double matriz_get(Matriz* matriz, int row, int col);
void matriz_set(Matriz* matriz, int row, int col, double value);
int matriz_rows(Matriz* matriz);
int matriz_cols(Matriz* matriz);

// New functions
bool matriz_equals(Matriz* matriz1, Matriz* matriz2);
Matriz* matriz_add(Matriz* matriz1, Matriz* matriz2);
Matriz* matriz_sub(Matriz* matriz1, Matriz* matriz2);
Matriz* matriz_scalar_mul(Matriz* matriz1, double scalar);
Matriz* matriz_transpose(Matriz* matriz);
bool matriz_is_symmetric(Matriz* matriz);

#endif