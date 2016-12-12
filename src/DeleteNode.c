#include <stdlib.h>
#include <stdio.h>
#include "DeleteNode.h"
#include "Rotation.h"

/**
 * Brief: A particular node's info will be stored in this structure 
 *        and the colour of it will be changed to double black.
 *
 * Aug: Node *nodePtr 
 *
 * Return: retObj (structure of the particular stored node)
 *
 */ 
ReturnedObject rbtRemoveNode(Node *nodePtr){
  ReturnedObject retObj;
  
  retObj.removedNode = nodePtr;
  retObj.returnedColour = DOUBLE_BLACK;
  
  retObj.removedNode->colour = retObj.returnedColour;
  
  return retObj;
}

// Case one A
void caseOneAOne(Node **nodePtr){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if((parent->colour) && (rightChild->colour) == RED){
      if(siblingRight->colour == BLACK){
        (*nodePtr)->left->left = NULL;
        rotateLeft(&((*nodePtr)->left));
        (*nodePtr)->left->colour = RED;
        (*nodePtr)->left->left->colour = BLACK;
        (*nodePtr)->left->right->colour = BLACK;
      }
    }
  }
}

void caseOneATwo(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == BLACK){
        if(rightChild->colour == RED){
          (*nodePtr)->left = NULL;
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
      }
    }
  }
}

// Case one B
void caseOneBOne(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour && leftChildRight->colour == RED){
      if(siblingRight->colour == BLACK){
        (*nodePtr)->left = NULL;
        rotateRightLeft(&(*nodePtr));
        (*nodePtr)->colour = RED;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->right->colour = BLACK;
      }
    }
  }
}

void caseOneBTwo(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == BLACK){
        if(leftChildRight->colour == RED){
          (*nodePtr)->left = NULL;
          rotateRightLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
      }
    }
  }
}

// Case two A
void caseTwoAOne(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == BLACK){
        if(leftChildRight->colour == BLACK){
          if(rightChildRight->colour == BLACK){
            (*nodePtr)->colour = DOUBLE_BLACK;
            (*nodePtr)->right->colour = RED;
            (*nodePtr)->left = NULL;
          }
        }
      }
    }
  }
}

void caseTwoATwo(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == BLACK){
        if(leftChildRight == NULL){
          if(rightChildRight == NULL){
            (*nodePtr)->colour = DOUBLE_BLACK;
            (*nodePtr)->right->colour = RED;
            (*nodePtr)->left = NULL;
          }
        }
      }
    }
  }
}

void caseTwoBOne(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == RED){
      if(siblingRight->colour == BLACK){
        if(leftChildRight->colour == BLACK){
          if(rightChildRight->colour == BLACK){
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->right->colour = RED;
            (*nodePtr)->left = NULL;
          }
        }
      }
    }
  }
}

void caseTwoBTwo(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == RED){
      if(siblingRight->colour == BLACK){
        if(leftChildRight == NULL){
          if(rightChildRight == NULL){
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->right->colour = RED;
            (*nodePtr)->left = NULL;
          }
        }
      }
    }
  }
}

void caseOneA(Node **nodePtr){
  caseOneAOne(nodePtr);
  caseOneATwo(nodePtr);
}

void caseOneB(Node **nodePtr){
  caseOneBOne(nodePtr);
  caseOneBTwo(nodePtr);
}

void caseTwoA(Node **nodePtr){
  caseTwoAOne(nodePtr);
  caseTwoATwo(nodePtr);
}

void caseTwoB(Node **nodePtr){
  caseTwoBOne(nodePtr);
  caseTwoBTwo(nodePtr);
}

void caseThree(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == RED){
        rotateLeft(&(*nodePtr));
        (*nodePtr)->colour = BLACK;
        (*nodePtr)->left->colour = RED;
        if((*nodePtr)->left->right->left == NULL){
          if((*nodePtr)->left->right->right == NULL){
            caseTwoATwo(&((*nodePtr)->left));
            caseTwoBTwo(&((*nodePtr)->left));
          }
        }
        else{
          caseTwoAOne(&((*nodePtr)->left));
          caseTwoBOne(&((*nodePtr)->left));
        }
      }
    }
  }
}

void intRbtDelete(Node **nodePtr, Node *node){
  ReturnedObject retObj;
  if(*nodePtr == node){
    retObj = rbtRemoveNode(*nodePtr);
    return;
  }
  
  if(node->value < (*nodePtr)->value){
    intRbtDelete(&((*nodePtr)->left), node);
  }
  else if(node->value > (*nodePtr)->value){
    intRbtDelete(&((*nodePtr)->right), node);
  }
}

void rbtDelete(Node **nodePtr, Node *node){
  intRbtDelete(nodePtr, node);
}