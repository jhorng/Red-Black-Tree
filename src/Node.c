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

void caseOneLeftA(Node **root){
  if((!isNoLeftChild(*root)) && (!isNoRightChild(*root)) && (!isNoLeftChild((*root)->left))){
    if((leftChildColour(*root)) && (rightChildColour(*root)) && (leftChildColour((*root)->left))){
      if(!isNoRightChild((*root)->left)){
        if(rightChildColour((*root)->left) == BLACK){
          (*root)->colour = RED;
          leftChildColour(*root) = BLACK;
          rightChildColour(*root) = BLACK;
        }
      }
      else{
        (*root)->colour = RED;
        leftChildColour(*root) = BLACK;
        rightChildColour(*root) = BLACK;
      }
    }
  }
}

void caseOneLeftB(Node **root){
  if((!isNoLeftChild(*root)) && (!isNoRightChild(*root)) && (!isNoRightChild((*root)->left))){
    if((leftChildColour(*root)) && (rightChildColour(*root)) && (rightChildColour((*root)->left))){
      if(!isNoLeftChild((*root)->left)){
        if(leftChildColour((*root)->left) == BLACK){
          (*root)->colour = RED;
          leftChildColour(*root) = BLACK;
          rightChildColour(*root) = BLACK;
        }
      }
      else{
        (*root)->colour = RED;
        leftChildColour(*root) = BLACK;
        rightChildColour(*root) = BLACK;
      }
    }
  }
}

void caseOneRightA(Node **root){
  if((!isNoLeftChild(*root)) && (!isNoRightChild(*root)) && (!isNoRightChild((*root)->right))){
    if((leftChildColour(*root)) && (rightChildColour(*root)) && (rightChildColour((*root)->right))){
      if(!isNoLeftChild((*root)->right)){
        if(leftChildColour((*root)->right) == BLACK){
          (*root)->colour = RED;
          leftChildColour(*root) = BLACK;
          rightChildColour(*root) = BLACK;
        }
      }
      else{
        (*root)->colour = RED;
        leftChildColour(*root) = BLACK;
        rightChildColour(*root) = BLACK;
      }
    }
  }
}

void caseOneRightB(Node **root){
  if((!isNoLeftChild(*root)) && (!isNoRightChild(*root)) && (!isNoLeftChild((*root)->right))){
    if((leftChildColour(*root)) && (rightChildColour(*root)) && (leftChildColour((*root)->right))){
      if(!isNoRightChild((*root)->right)){
        if(rightChildColour((*root)->right) == BLACK){
          (*root)->colour = RED;
          leftChildColour(*root) = BLACK;
          rightChildColour(*root) = BLACK;
        }
      }
      else{
        (*root)->colour = RED;
        leftChildColour(*root) = BLACK;
        rightChildColour(*root) = BLACK;
      }
    }
  }
}

void caseOnePointOne(Node **root){
  caseOneLeftA(root);
  caseOneLeftB(root);
}

void caseOnePointTwo(Node **root){
  caseOneRightA(root);
  caseOneRightB(root);
}

void caseTwoPointOne(Node **root){
  if(isNoRightChild(*root)){
    if(!isNoLeftChild(*root)){
      if(!isNoRightChild((*root)->left)){
        if(leftChildColour(*root) && rightChildColour((*root)->left) == RED){
          rotateLeft(&((*root)->left));
        }
      }
    }
  }
  else{
    if(rightChildColour(*root) == BLACK){
      if(!isNoLeftChild(*root)){
        if(!isNoRightChild((*root)->left)){
          if((leftChildColour(*root)) && (rightChildColour((*root)->left)) == RED){
            rotateLeft(&((*root)->left));
          }
        }
      }
    }
  }
}

void caseTwoPointTwo(Node **root){
  if(isNoLeftChild(*root)){
    if(!isNoRightChild(*root)){
      if(!isNoLeftChild((*root)->right)){
        if((rightChildColour(*root)) && (leftChildColour((*root)->right)) == RED){
          rotateRight(&((*root)->right));
        }
      }
    }
  }
  else{
    if(leftChildColour(*root) == BLACK){
      if(!isNoRightChild(*root)){
        if(!isNoLeftChild((*root)->right)){
          if((rightChildColour(*root)) && (leftChildColour((*root)->right)) == RED){
            rotateRight(&((*root)->right));
          }
        }
      }
    }
  }
}

void caseThreePointOne(Node **root){
  if(isNoRightChild(*root)){
    if(!isNoLeftChild((*root)->left)){
      if((leftChildColour(*root)) && (leftChildColour((*root)->left)) == RED){
        rotateRight(&((*root)));
        (*root)->colour = BLACK;
        leftChildColour(*root) = RED;
        rightChildColour(*root) = RED;
      }
    }
  }
  else{
    if(rightChildColour(*root) == BLACK){
      if(!isNoLeftChild((*root)->left)){
        if((leftChildColour(*root)) && (leftChildColour((*root)->left)) == RED){
          rotateRight(&((*root)));
          (*root)->colour = BLACK;
          leftChildColour(*root) = RED;
          rightChildColour(*root) = RED;
        }
      }
    }
  }
}

void caseThreePointTwo(Node **root){
  if(isNoLeftChild(*root)){
    if(!isNoRightChild((*root)->right)){
      if((rightChildColour(*root)) && (rightChildColour((*root)->right)) == RED){
        rotateLeft(&((*root)));
        (*root)->colour = BLACK;
        leftChildColour(*root) = RED;
        rightChildColour(*root) = RED;
      }
    }
  }
  else{ 
    if(leftChildColour(*root) == BLACK){
      if(!isNoRightChild((*root)->right)){
        if((rightChildColour(*root)) && (rightChildColour((*root)->right)) == RED){
          rotateLeft(&((*root)));
          (*root)->colour = BLACK;
          leftChildColour(*root) = RED;
          rightChildColour(*root) = RED;
        }
      }
    }
  }
}

void intRbtAdd(Node **root, Node *child){
  if(*root == NULL){
    (*root) = child;
    (*root)->colour = RED;
    return;
  }
  
  if(child->value < (*root)->value){
    intRbtAdd(&((*root)->left), child);
    caseOnePointOne(root);
    caseTwoPointOne(root);
    caseThreePointOne(root);
  }
  else if(child->value > (*root)->value){
    intRbtAdd(&((*root)->right), child);
    caseOnePointTwo(root);
    caseTwoPointTwo(root);
    caseThreePointTwo(root);
  }
}

void rbtAdd(Node **root, Node *child){
  intRbtAdd(root, child);
  if((*root)->colour == RED){
    (*root)->colour = BLACK;
  }
}
