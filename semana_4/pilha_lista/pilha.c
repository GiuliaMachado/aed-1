#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    Element value;
    struct Node* next;
} Node;

struct Stack{
    Node* top;
    int size;
};

Stack* stack_create(){
    Stack* stack = malloc(sizeof(Stack));

    stack->size = 0;
    stack->top = NULL;

    return stack;
}

void stack_destroy(Stack* stack){
    Node* cur = stack->top;

    while(cur != NULL){
        Node* trash = cur;
        cur = cur->next;
        free(trash);
    }
    free(stack);
}

void stack_push(Stack* stack, Element value){
    Node* newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;

    stack->size++;

}

Element stack_pop(Stack* stack){
    if(stack_is_empty(stack)){
        return ELEMENT_NULL;
    }

    Node* trash = stack->top;
    Element e = trash->value;

    stack->top = trash->next;
    free(trash);
    stack->size--;

    return e;

}

Element stack_peek(Stack* stack){
    if(stack_is_empty(stack)){
        return ELEMENT_NULL;
    }

    return stack->top->value;
}

bool stack_is_empty(Stack* stack){
    return stack->top == NULL;
}

int stack_size(Stack* stack){
    return stack->size;
}

void stack_print(Stack* stack){
    Node* cur = stack->top;

    while(cur != NULL){
        element_print(cur->value);
        cur = cur->next;
    }
    printf("\n");
}