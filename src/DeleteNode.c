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

// Case one B
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

// Case two A
void caseTwoAOne(Node **nodePtr){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if(parent == NULL){
    printf("Parent is null!");
    return;
  }
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == BLACK){
        if(leftChildRight->colour == BLACK){
          if(rightChildRight->colour == BLACK){
            (*nodePtr)->colour = DOUBLE_BLACK;
            (*nodePtr)->left->colour = BLACK;
            (*nodePtr)->right->colour = RED;
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
  
  if(parent == NULL){
    printf("Parent is null!");
    return;
  }
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == BLACK){
      if(siblingRight->colour == BLACK){
        if(leftChildRight == NULL){
          if(rightChildRight == NULL){
            (*nodePtr)->colour = DOUBLE_BLACK;
            (*nodePtr)->left->colour = BLACK;
            (*nodePtr)->right->colour = RED;
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
  
  if(parent == NULL){
    printf("Parent is null!");
    return;
  }
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == RED){
      if(siblingRight->colour == BLACK){
        if(leftChildRight->colour == BLACK){
          if(rightChildRight->colour == BLACK){
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->left->colour = BLACK;
            (*nodePtr)->right->colour = RED;
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
  
  if(parent == NULL){
    printf("Parent is null!");
    return;
  }
  
  if(siblingLeft->colour == DOUBLE_BLACK){
    if(parent->colour == RED){
      if(siblingRight->colour == BLACK){
        if(leftChildRight == NULL){
          if(rightChildRight == NULL){
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->left->colour = BLACK;
            (*nodePtr)->right->colour = RED;
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