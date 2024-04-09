#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 Element key;
 struct Node* left;
 struct Node* right;
 int height;
} Node;

Node* createNode(Element key) {

    Node* newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

 int maximum(int a, int b) {
 return (a > b) ? a : b;
 }

 int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
 }
void updateHeight(Node* node){
    if(node != NULL){
        node->height = 1 + maximum(height(node->left), height(node->right));
    }
}
int balanceFactor(Node* node){
    if(node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

int maximum(int a, int b){
    return (a > b) ? a : b;
}

//desbalanceamentos: Left-Left LL
Node* rotateRight(Node* node){
    Node* pivot = node->left;

    node->left = pivot->right;
    pivot->right = node;

    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}
//caso: Right-Right RR 
Node* rotateLeft(Node* node){
    Node* pivot = node->right;

    node->right = pivot->left;
    pivot->left = node;

    updateHeight(node);
    updateHeight(pivot);

    return pivot;
}

//Caso Right-Left RL  
/*Node* rotateRightLeft(Node* node){
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}
*/
//Caso Right-Left RL
/*Node* rotateLeftRight(Node* node){
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}
*/
Node* rebalance(Node* node){
    updateHeight(node);
    //no critico
    if(balanceFactor(node) < -1){
        if(balanceFactor(node->right)> 0){
            node->right = rotateRight(node->left);
        }
        return rotateLeft(node);
    }
    //nó critico
    else if(balanceFactor(node) > 1){
        if(balanceFactor(node->left) < 0){
            node->left = rotateLeft(node->right);
        }
        return rotateRight(node);
    }
}