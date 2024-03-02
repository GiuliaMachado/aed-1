#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include "element.h"

typedef struct LinkedList LinkedList;

LinkedList* list_create();
void list_destroy(LinkedList* list);
//inserção tem 3 tipos: 1- NO COMEÇO/ 2- NO FINAL/ 3- NO MEIO
void list_insertFirst(LinkedList* list, Element e);
void list_insertAfter(LinkedList* list, int pos, Element e);
//remoção
bool list_removeFirst(LinkedList* list);
bool list_removeAt(LinkedList* list, int pos);
bool list_remove(LinkedList* list, int pos, Element e);
//pegar elementos
int list_get(LinkedList* list, int pos);
int list_size(LinkedList* list);
int list_isEmpty(LinkedList* list);
void list_print(LinkedList* list);
#endif