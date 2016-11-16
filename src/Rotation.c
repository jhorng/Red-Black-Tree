#include <stdlib.h>
#include <stdio.h>
#include "Rotation.h"

void rotateLeft(Node **nodePtr){
  Node *root, *child, *grandChild;
  
  if((*nodePtr)->right == NULL){
    printf("Right node does not exist!\n");
    nodePtr = nodePtr;
    return;
  }
  
  root = *nodePtr;
  child = root->right;
  grandChild = child->left;
  
  *nodePtr = child;
  (*nodePtr)->left = root;
  (*nodePtr)->left->right = grandChild;
}

void rotateRight(Node **nodePtr){
  Node *root, *child, *rightGrandChild;
  
  if((*nodePtr)->left == NULL){
    printf("Left node does not exist!\n");
    nodePtr = nodePtr;
    return;
  }
  
  root = *nodePtr;
  child = root->left;
  rightGrandChild = child->right;
  
  *nodePtr = child;
  (*nodePtr)->right = root;
  (*nodePtr)->right->left = rightGrandChild;
}

void rotateLeftRight(Node **nodePtr){
  rotateLeft(&((*nodePtr)->left));
  rotateRight(&(*nodePtr));
}

void rotateRightLeft(Node **nodePtr){
  rotateRight(&((*nodePtr)->right));
  rotateLeft(&(*nodePtr));
}






