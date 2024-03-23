#ifndef BST_H
#define BST_H

#include "element.h"

#include <stdbool.h>

typedef struct BST BST;

BST* bst_create();
void bst_destroy(BST* bst);
bool bst_search(BST* bst, Element key);
void bst_insert(BST* bst, Element key);
void bst_remove(BST* bst, Element key);
void bst_printInOrder(BST* bst);
void bst_printPreOrder(BST* bst);
void bst_printPostOrder(BST* bst);
int bst_height(BST* bst);
int bst_count(BST* bst);
#endif