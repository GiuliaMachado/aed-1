#include "linked_list.h"
#include <stdio.h>

int main(){
    /* 
    
    list_insertFirst(list1, 1);
    list_insertFirst(list1, 3);
    list_insertFirst(list1, 10);
    list_print(list1);
    

    LinkedList* list2 = list_create();
    list_insertFirst(list2, 9);
    list_insertFirst(list2, 6);
    list_insertFirst(list2, 3);
    list_insertFirst(list2, 1);
    list_insertFirst(list2, 4);
    list_insertFirst(list2, 6);
    list_insertFirst(list2, 8);
    list_insertFirst(list2, 4);
    list_insertFirst(list2, 7);
    list_insertFirst(list2, 8);

    list_print(list2);
    list_removeDuplicates(list2);
    list_print(list2);
    list_printReverse(list2);

    //list_printElements(list1, list2);

    if(list_equals(list1, list2)){
        printf("SÃO IGUAIS.");
    }
    else{
        printf("Não são iguais.");
    }

    if(list_isSorted(list1) == 1){
        printf("Lista em ordem crescente");
    }
    else if(list_isSorted(list1) == 2){
        printf("Lista em ordem decrescente");
    }
    else{
        printf("Lista fora de ordem.");
    }
    list_destroy(list2);
    */
    LinkedList* list1 = list_create();
    list_destroy(list1);
    return 0;
}

LinkedList* reverse(LinkedList* l){
    LinkedList* nova = list_create();
    int cont = 0;
    while(cont < list_size(l)){
        list_insertAfter(nova, cont, list_get(l, list_size(l) - cont - 1));
        cont++;
        nova = nova
    }
}