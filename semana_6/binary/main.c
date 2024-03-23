#include <stdbool.h>
#include <stdio.h>

#include "element.h"
#include "bst.h"

void printTree(BST* bst){
    printf("In order: ");
    bst_printInOrder(bst);
    printf("Pre order: ");
    bst_printPreOrder(bst);
    printf("Pos order: ");
    bst_printPostOrder(bst);
}

int main(){
    BST* bst = bst_create();
    int valid_keys[] = {50, 61, 58, 43, 70, 48, 3};
    //int invalid_keys[] = {0, 1, 9};

    for(int i = 0; i < 7; i++){
        bst_insert(bst, valid_keys[i]);
    }
    for(int i = 0; i < 7; i++){
        printf("%d: %s\n", valid_keys[i], bst_search(bst, valid_keys[i]) ? "true": "false");
    }
    /*
    for(int i = 0; i < 3; i++){
        printf("%d: %s\n", invalid_keys[i], bst_search(bst, invalid_keys[i]) ? "true": "false");
    }*/

    printTree(bst);
    bst_destroy(bst);

    return 0;
}