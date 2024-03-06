#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "../linked_list_2/element.h"

typedef struct Stack Stack;
//Cria uma nova pilha com a capacidade especificada.
Stack* stack_create(int capacity);
//Libera a memória alocada para a pilha.
void stack_destroy(Stack* stack);
//Empilha um elemento.
bool stack_push(Stack* stack, Element value);
//Desempilha em elemento.
Element stack_pop(Stack* stack);
//Consulta o elemento do topo sem desempilhar.
Element stack_peek(Stack* stack);
//Verifica se a pilha está vazia.
bool stack_is_empty(Stack* stack);
//Verifica se a pilha está cheia.
bool stack_is_full(Stack* stack);
//Consulta a quantidade de elementos na pilha.
int stack_size(Stack* stack);
//Imprime os elementos da pilha.
void stack_print(Stack* stack);


#endif