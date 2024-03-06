#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int capacity;
    int top;
    Element* data;
};

Stack* stack_create(int capacity){
    Stack* stack = malloc(sizeof(Stack));
    //pilha baseada em array: posicao do top é -1 é pilha vazia
    //com isso temos dois pontos:
    // lista cheia: top = capacity - 1
    //size = top + 1
    stack->top = -1;
    stack->capacity = capacity;
    stack->data = malloc(sizeof(Element) * capacity);

    return stack;
}

void stack_destroy(Stack* stack){
    free(stack->data);
    free(stack);
}

bool stack_push(Stack* stack, Element value){
    if(stack_is_full(stack)){
        return false;
    }
    stack->data[++stack->top] = value;
    //ou so uma linha: stack->data[++stack->top] = value;
    
    return true;
}

Element stack_pop(Stack* stack){
    if(stack_is_empty(stack)){
        return ELEMENT_NULL;
    }
    //retorna o elemento eliminado e depois elimina com o decremento
    return stack->data[stack->top--];
}

Element stack_peek(Stack* stack){
    if(stack_is_empty(stack)){
        return ELEMENT_NULL;
    }
    return stack->data[stack->top];
}

bool stack_is_empty(Stack* stack){
    return stack->top == -1;
}

bool stack_is_full(Stack* stack){
    return stack->top == stack->capacity - 1;
}

int stack_size(Stack* stack){
    return stack->top + 1;
}

void stack_print(Stack* stack){
    for(int i = stack->top; i >= 0; i--){
        element_print(stack->data[i]);
        printf(" "); 
    }
    printf("\n");
}
