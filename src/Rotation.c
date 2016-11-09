#include <stdlib.h>
#include <stdio.h>
#include "Rotation.h"

void rotateLeft(Node **nodePtr){
  Node *temp1, *temp2, *temp3;
  
  if((*nodePtr)->right == NULL){
    printf("Right node does not exist!\n");
    nodePtr = nodePtr;
    return;
  }
  
  temp1 = *nodePtr;
  temp2 = temp1->right;
  temp3 = temp2->left;
  
  *nodePtr = temp2;
  (*nodePtr)->left = temp1;
  (*nodePtr)->left->right = temp3;
}

void rotateRight(Node **nodePtr){
  Node *temp1, *temp2, *temp3;
  
  if((*nodePtr)->left == NULL){
    printf("Left node does not exist!\n");
    nodePtr = nodePtr;
    return;
  }
  
  temp1 = *nodePtr;
  temp2 = temp1->left;
  temp3 = temp2->right;
  
  *nodePtr = temp2;
  (*nodePtr)->right = temp1;
  (*nodePtr)->right->left = temp3;
}

void rotateLeftRight(Node **nodePtr){
  rotateLeft(&((*nodePtr)->left));
  rotateRight(&(*nodePtr));
}

void rotateRightLeft(Node **nodePtr){
  rotateRight(&((*nodePtr)->right));
  rotateLeft(&(*nodePtr));
}






