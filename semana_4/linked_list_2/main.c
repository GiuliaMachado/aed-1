#include "linked_list.h"
#include <stdio.h>

int main(){
    LinkedList* list = list_create();
    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);

    list_print(list);

    list_insertAfter(list, 1, 23);
    list_insertAfter(list, 3, 45);
    list_removeAt(list, 1);
    list_print(list);
    list_removeFirst(list);
    list_print(list);

    list_destroy(list);
    return 0;
}