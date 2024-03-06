#ifndef LINKED_LIST_2_H
#define LINKED_LIST_2_H

#include <stdbool.h>
#include "element.h"

typedef struct LinkedList LinkedList;

LinkedList* list_create();
void list_destroy(LinkedList* list);
void list_insertFirst(LinkedList* list, Element e);
void list_insertAfter(LinkedList* list, int pos, Element e);
bool list_removeFirst(LinkedList* list);
bool list_removeAt(LinkedList* list, int pos);
void list_print(LinkedList* list);
void list_insertLast(LinkedList* list, Element e);
#endif