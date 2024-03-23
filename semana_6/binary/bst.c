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
//Algoritmo de inserção recursiva de nós
Node* bst_insertRecur(Node* node, Element key){
    //caso base 1: arvore vazia
    if(node == NULL){
        return create_Node(key);
    }
    //caso recursivo 1: valor a ser inserido menor
    if(key < node->key){
        node->left = bst_insertRecur(node->left, key);
    }
    //caso recursivo 2: valor a ser inserido maior
    else if(key > node->key){
        node->right = bst_insertRecur(node->right, key);
    }
    //caso base 2: valor ja existe na arvore, só retorna o nó
    return node;
}


//Versão iterativa de Inserção de nós
void bst_insertIterative(BST* bst, Element key){
    //caso 1: arvore vazia
    if(bst->root == NULL){
        bst->root = create_Node(key);
        return;
    }
    //2 ponteiros para percorrer a arvore
    Node* parent = NULL;
    Node* cur = bst->root;

    while(cur != NULL){
        //caso 1: achou o nó
        if(cur->key == key){
            return;
        }
        //caso 2: valor a ser inserido menor
        else if(key < cur->key){
            parent = cur;
            cur = cur->left; 
        }
        //caso 3: valor maior
        else{
            parent = cur;
            cur = cur->right;
        }
    }

    //insercao a partir do nó parent
    //caso 1: o valor é menor que o valor de parent
    if(key < parent->key){
        parent->left = create_Node(key);
    }
    //caso 2: o valor é maior do que o valor de parent
    else{
        parent->right = create_Node(key);
    }
}

void bst_insert(BST* bst, Element key){
    bst->root = bst_insertRecur(bst->root, key);
    //bst_insertIterative(bst, key);
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
bool bst_searchRecur(Node* node, Element key){
    //caso base 1: arvore vazia
    if(node == NULL){
        return false;
    }
    //caso base 2: achou o valor
    if(key == node->key){
        return true;
    }
    //caso recursivo 1: valor menor
    if(key < node->key){
        return bst_searchRecur(node->left, key);
    }
    //caso recursivo 2: valor maior
    return bst_searchRecur(node->right, key);
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
    bst_printNodePreOrder(node->left);
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

void bst_printPostOrder(BST* bst){
    bst_printNodePosOrder(bst->root);
    printf(" ");
}