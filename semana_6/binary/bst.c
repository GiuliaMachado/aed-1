#include "bst.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    Element key;
    struct Node* left;
    struct Node* right;
}Node;

struct BST{
    Node* root;
};

Node* create_Node(Element key){
    Node* node = malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

BST* bst_create(){
    BST* bst = malloc(sizeof(BST));

    bst->root = NULL;

    return bst;
}

void bst_destroyNode(Node* node){
    if(node == NULL){
        return;
    }
    bst_destroyNode(node->left);
    bst_destroyNode(node->right);
    free(node);
}
void bst_destroy(BST* bst){
   bst_destroyNode(bst->root);
   free(bst);
}

//versão iterativa
bool bst_searchIter(BST* bst, Element key){
    Node* cur = bst->root;
    while(cur != NULL){
        if(key == cur->key){
            return true;
        }
        else if(key < cur->key){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
    return false;
}

//versao recursiva
bool bst_searchRecur(BST* bst, Element key){
    Node* cur = bst->root;
    //caso base 1: arvore vazia
    if(bst->root == NULL){
        return false;
    }
    //caso base 2: achou o valor
    if(key == cur->key){
        return true;
    }
    //caso recursivo 1: valor menor
    if(key < cur->key){
        return bst_searchRecur(cur->left, key);
    }
    //caso recursivo 2: valor maior
    return bst_searchRecur(cur->right, key);
}
bool bst_search(BST* bst, Element key){
    //escolho se quero versao iterativa ou recursiva
    return bst_searchRecur(bst->root, key);
}
//Percurso em Ordem - Recursivo
void bst_printNodeInOrder(Node* node){
    if(node == NULL){
        return;
    }
    bst_printNodeInOrder(node->left);
    element_print(node->key);
    printf(" ");
    bst_printNodeInOrder(node->right);
}
//garante encapsulamento sem acessar o nó
void bst_printInOrder(BST* bst){
    bst_printNodeInOrder(bst->root);
    printf("\n");
}

//Percurso Pré-Ordem
void bst_printNodePreOrder(Node* node){
    if(node == NULL){
        return;
    }
    element_print(node->key);
    printf(" ");
    bst_printPreOrder(node->left);
    bst_printNodePreOrder(node->right);
}
void bst_printPreOrder(BST* bst){
    bst_printNodePreOrder(bst->root);
    printf("\n");
}
//Percurso Pós-Ordem
void bst_printNodePosOrder(Node* node){
    if(node == NULL){
        return;
    }
    bst_printNodePosOrder(node->left);
    bst_printNodePosOrder(node->right);
    element_print(node->key);
    printf(" ");
}