#include <stdlib.h>
#include <stdio.h>
#include "Node.h"
#include "Rotation.h"

Node *initNode(Node *root, Node *left, Node *right, int colour){
  root->left = left;
  root->right = right;
  root->colour = colour;
  return root;
}

void caseOne(Node *root){
  if(root->right != NULL){
    if(((root->right->colour) && (root->left->right->colour))== RED){
      root->colour = RED;
      root->left->colour = BLACK;
      root->right->colour = BLACK;
    }
  }
}

void caseTwo(Node *root){
  if(root->right == NULL){
    if(root->left->right->colour == RED){
      rotateLeft(&(root->left));
    }
  }
  else if(root->right->colour == BLACK){
    if(root->left->right->colour == RED){
      rotateLeft(&(root->left));
    }
  }
}

void addNode(Node *root, Node *child){
  if(root->value < child->value){  
    if (root->right == NULL){
      root->right = child;
      root->right->colour = RED;
    }
    else{
      addNode(root->right, child);
    }
  }
  else if (root->value > child->value){
    if (root->left == NULL){
      root->left = child;
      root->left->colour = RED;
    }
    else{
      addNode(root->left, child);
    }
  }
}