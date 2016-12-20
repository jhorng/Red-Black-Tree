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
void caseOneAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if((parent->colour == RED) && (rightChild->colour == RED)){
    if(siblingRight->colour == BLACK){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left->left = NULL;
        rotateLeft(&((*nodePtr)->left));
        (*nodePtr)->left->colour = RED;
        (*nodePtr)->left->left->colour = BLACK;
        (*nodePtr)->left->right->colour = BLACK;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&((*nodePtr)->left));
          (*nodePtr)->left->colour = RED;
          (*nodePtr)->left->left->colour = BLACK;
          (*nodePtr)->left->right->colour = BLACK;
        }
      }
    }
  }
}

void caseOneATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if(rightChild->colour == RED){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left->left = NULL;
        rotateLeft(&((*nodePtr)->left));
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->left->left->colour = BLACK;
        (*nodePtr)->left->right->colour = BLACK;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&((*nodePtr)->left));
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->left->left->colour = BLACK;
          (*nodePtr)->left->right->colour = BLACK;
        }
      }
    }
  }
}

// Case one B
void caseOneBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  
  if((parent->colour == RED) && (leftChildRight->colour == RED)){
    if(siblingRight->colour == BLACK){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left->left = NULL;
        rotateRightLeft(&(*nodePtr)->left);
        (*nodePtr)->left->colour = RED;
        (*nodePtr)->left->left->colour = BLACK;
        (*nodePtr)->left->right->colour = BLACK;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&((*nodePtr)->left));
          (*nodePtr)->left->colour = RED;
          (*nodePtr)->left->left->colour = BLACK;
          (*nodePtr)->left->right->colour = BLACK;
        }
      }
    }
  }
}

void caseOneBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if(leftChildRight->colour == RED){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left->left = NULL;
        rotateRightLeft(&((*nodePtr)->left));
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->left->left->colour = BLACK;
        (*nodePtr)->left->right->colour = BLACK;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&((*nodePtr)->left));
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->left->left->colour = BLACK;
          (*nodePtr)->left->right->colour = BLACK;
        }
      }
    }
  }
}

// Case two A
void caseTwoAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((leftChildRight->colour == BLACK) && (rightChildRight->colour == BLACK)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left->left = NULL;
        (*nodePtr)->left->colour = DOUBLE_BLACK;
        (*nodePtr)->left->right->colour = RED;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          (*nodePtr)->left->colour = DOUBLE_BLACK;
          (*nodePtr)->left->right->colour = RED;
        }
      }
    }
  }
}

void caseTwoATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((leftChildRight == NULL) && (rightChildRight == NULL)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left->left = NULL;
        (*nodePtr)->left->colour = DOUBLE_BLACK;
        (*nodePtr)->left->right->colour = RED;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          (*nodePtr)->left->colour = DOUBLE_BLACK;
          (*nodePtr)->left->right->colour = RED;
        }
      }
    }
  }
}

// Case two B
void caseTwoBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == RED) && (siblingRight->colour == BLACK)){
    if((leftChildRight->colour == BLACK) && (rightChildRight->colour == BLACK)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left->left = NULL;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->left->right->colour = RED;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->left->right->colour = RED;
        }
      }
    }
  }
}

void caseTwoBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == RED) && (siblingRight->colour == BLACK)){
    if((leftChildRight == NULL) && (rightChildRight == NULL)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left->left = NULL;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->left->right->colour = RED;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->left->right->colour = RED;
        }
      }
    }
  }
}

/**
 *    case 3
 *    
 *          80(B)                      80(B)                80(B)
 *         /    \                     /    \               /    \
 *       20(B)   -  rotate left     50(B)   -  case 2    50(B)  -
 *      //  \      ----------->    /   \      ------->  /   \
 *    10(B) 50(R)   at node20   20(R)  70(B)          20(B) 70(B)
 *          /  \               //  \                 /   \
 *       30(B)70(B)          10(B) 30(B)            -   30(R)
 *
 *
 *
 */
void caseThree(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = (*nodePtr)->left;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == RED)){
    if((leftChildRight->colour == BLACK) && (rightChildRight->colour == BLACK)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        rotateLeft(&((*nodePtr)->left));
        (*nodePtr)->left->colour = BLACK;
        leftTwo(*nodePtr)->colour = RED;
        if((leftTwo(*nodePtr)->right->left == NULL) && (leftTwo(*nodePtr)->right->right == NULL)){
          caseTwoATwo(&((*nodePtr)->left), deletedNode, nodeValue);
          caseTwoBTwo(&((*nodePtr)->left), deletedNode, nodeValue);
        }
        else{
          caseTwoAOne(&((*nodePtr)->left), deletedNode, nodeValue);
          caseTwoBOne(&((*nodePtr)->left), deletedNode, nodeValue);
        }
      }
      else if(siblingLeft == NULL){
        rotateLeft(&((*nodePtr)->left));
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->left->left->colour = RED;
        if((leftTwo(*nodePtr)->right->left == NULL) && (leftTwo(*nodePtr)->right->right == NULL)){
          caseTwoATwo(&((*nodePtr)->left), deletedNode, nodeValue);
          caseTwoBTwo(&((*nodePtr)->left), deletedNode, nodeValue);
        }
        else{
          caseTwoAOne(&((*nodePtr)->left), deletedNode, nodeValue);
          caseTwoBOne(&((*nodePtr)->left), deletedNode, nodeValue);
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