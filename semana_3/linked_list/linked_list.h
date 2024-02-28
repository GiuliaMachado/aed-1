#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList LinkedList;

LinkedList* list_create();
void list_destroy(LinkedList* list);

bool list_removeAt(LinkedList* list, int pos);
#endif