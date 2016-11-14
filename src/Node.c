#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

Node *initNode(Node *root, Node *left, Node *right, int colour){
  root->left = left;
  root->right = right;
  root->colour = colour;
  return root;
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