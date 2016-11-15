#include <stdlib.h>
#include <stdio.h>
#include "Rotation.h"

void colourChange(Node **nodePtr){
  if((*nodePtr)->colour != BLACK){
    (*nodePtr)->colour = BLACK;
    colourChange(nodePtr);
  }
  
  else if((*nodePtr)->left != NULL){
    if((*nodePtr)->left->colour != RED){
      (*nodePtr)->left->colour = RED;
      colourChange(nodePtr);
    }
  }
  
  else if((*nodePtr)->right != NULL){
    if((*nodePtr)->right->colour != RED){
      (*nodePtr)->right->colour = RED;
      colourChange(nodePtr);
    }
  }
  
  else
    return;
}

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
  
  colourChange(nodePtr);
}

void rotateRight(Node **nodePtr){
  Node *root, *child, *leftGrandChild, *rightGrandChild;
  
  if((*nodePtr)->left == NULL){
    printf("Left node does not exist!\n");
    nodePtr = nodePtr;
    return;
  }
  
  root = *nodePtr;
  child = root->left;
  rightGrandChild = child->right;
  leftGrandChild = child->left;
  
  *nodePtr = child;
  (*nodePtr)->right = root;
  (*nodePtr)->right->left = rightGrandChild;
  
  colourChange(nodePtr);
}

void rotateLeftRight(Node **nodePtr){
  rotateLeft(&((*nodePtr)->left));
  rotateRight(&(*nodePtr));
}

void rotateRightLeft(Node **nodePtr){
  rotateRight(&((*nodePtr)->right));
  rotateLeft(&(*nodePtr));
}






