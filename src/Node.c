#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

Node *initializeNode(int colour, int value){
  Node *thisNode = malloc(sizeof(Node));
  thisNode->left = NULL;
  thisNode->right = NULL;
  thisNode->colour = colour;
  thisNode->value = value;
  return thisNode;
}

void addNode(Node *root, Node *child){
  if(root->value < child->value){  
    if (root->right == NULL)
      root->right = child;
    else 
      addNode(root->right, child);
  }
  else if (root->value > child->value){
    if (root->left == NULL)
      root->left = child; 
    else
      addNode(root->left, child);
  }
}