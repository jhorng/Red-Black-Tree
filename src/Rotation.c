#include <stdlib.h>
#include <stdio.h>
#include "Rotation.h"

void rotateLeft(Node **nodePtr){
  Node *temp1, *temp2;
  
  if((*nodePtr)->right == NULL){
    printf("Right node does not exist!\n");
    nodePtr = nodePtr;
    return;
  }
  
  temp1 = *nodePtr;
  temp2 = (*nodePtr)->right;
  
  *nodePtr = temp2;
  (*nodePtr)->left = temp1;
}

void rotateRight(Node **nodePtr){
  Node *temp1, *temp2;
  
  if((*nodePtr)->left == NULL){
    printf("Left node does not exist!\n");
    nodePtr = nodePtr;
    return;
  }
  
  temp1 = *nodePtr;
  temp2 = (*nodePtr)->left;
  
  *nodePtr = temp2;
  (*nodePtr)->right = temp1;
}

void rotateLeftRight(Node **nodePtr){
  
}

void rotateRightLeft(Node **nodePtr){
  
}