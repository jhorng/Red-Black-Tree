#include <stdlib.h>
#include <stdio.h>
#include "DeleteNode.h"
#include "Rotation.h"

ReturnedObject rbtRemoveNode(Node *nodePtr){
  ReturnedObject retObj;
  
  retObj.removedNode = nodePtr;
  retObj.returnedColour = DOUBLE_BLACK;
  
  retObj.removedNode->colour = retObj.returnedColour;
  
  return retObj;
}

void caseOneAOne(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if(parent == NULL){
    printf("Parent is null!");
    return;
  }

  if(siblingLeft->colour == DOUBLE_BLACK){
    if((parent->colour) && (rightChild->colour) == RED){
      if(siblingRight->colour == BLACK){
        rotateLeft(&(*nodePtr));
        (*nodePtr)->colour = RED;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->right->colour = BLACK;
        (*nodePtr)->left->left = NULL;
      }
    }
  }
}

void caseOneATwo(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if(parent == NULL){
    printf("Parent is null!");
    return;
  }

  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == BLACK){
        if(rightChild->colour == RED){
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
          (*nodePtr)->left->left = NULL;
        }
      }
    }
  }
}

void caseOneA(Node **nodePtr){
  caseOneAOne(nodePtr);
  caseOneATwo(nodePtr);
}

void caseOneBOne(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChild = siblingRight->left;
  
  if(parent == NULL){
    printf("Parent is null!");
    return;
  }
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour && leftChild->colour == RED){
      if(siblingRight->colour == BLACK){
        rotateRightLeft(&(*nodePtr));
        (*nodePtr)->colour = RED;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->right->colour = BLACK;
        (*nodePtr)->left->left = NULL;
      }
    }
  }
}

void caseOneBTwo(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChild = siblingRight->left;
  
  if(parent == NULL){
    printf("Parent is null!");
    return;
  }
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == BLACK){
        if(leftChild->colour == RED){
          rotateRightLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
          (*nodePtr)->left->left = NULL;
        }
      }
    }
  }
}

void caseOneB(Node **nodePtr){
  caseOneBOne(nodePtr);
  caseOneBTwo(nodePtr);
}
