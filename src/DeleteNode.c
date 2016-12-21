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

/**
 * case 1a(1) - Double black node can be a node or null.
 *            - Parent is red and the siblingRight's right child are red.
 *            - SiblingRight is black.
 *            - Double black node become null before rotation.
 *
 *
 *        /     rotate left    /
 *     70(R)    ---------->  90(R)
 *    //   \                /   \
 *  40(B)  90(B)          70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void caseOneAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if(parent->colour == RED){
    if((rightChild != NULL) && (rightChild->colour == RED)){
      if(siblingRight->colour == BLACK){
        if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
          (*nodePtr)->left = NULL;
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = RED;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
        else if(siblingLeft == NULL){
          if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
            rotateLeft(&(*nodePtr));
            (*nodePtr)->colour = RED;
            (*nodePtr)->left->colour = BLACK;
            (*nodePtr)->right->colour = BLACK;
          }
        }
      }
    }
  }
}

/**
 * case 1a(2) - Double black node can a node or null.
 *            - Parent and siblingRight are black.
 *            - Right child of siblingRight is red.
 *            - Double black node will become null before rotation.
 *
 *
 *        /   rotate left    /   
 *     70(B)  ---------->  90(B)
 *    //   \              /   \
 *  40(B)  90(B)        70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void caseOneATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((rightChild != NULL) && (rightChild->colour == RED)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left = NULL;
        rotateLeft(&(*nodePtr));
        (*nodePtr)->colour = BLACK;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->right->colour = BLACK;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
      }
    }
  }
}

/**
 * case 1b(1) - Double black node can be a node or null.
 *            - Parent and the left child of siblingRight are red.
 *            - SiblingRight is black.
 *            - Double black node will become null before rotation.
 *
 *
 *        /       rotate right      /    rotate left       / 
 *     70(R)      ----------->   70(R)   ----------->   80(R)
 *    //   \      at node90     //  \    at node70     /   \
 *  40(B)  90(B)             null  80(R)            70(B) 90(B)
 *         /                         \
 *       80(R)                      90(B)
 *
 */
void caseOneBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  
  if(parent->colour == RED){
    if((leftChildRight != NULL) && (leftChildRight->colour == RED)){
      if(siblingRight->colour == BLACK){
        if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
          (*nodePtr)->left = NULL;
          rotateRightLeft(&(*nodePtr));
          (*nodePtr)->colour = RED;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
        else if(siblingLeft == NULL){
          if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
            rotateRightLeft(&(*nodePtr));
            (*nodePtr)->colour = RED;
            (*nodePtr)->left->colour = BLACK;
            (*nodePtr)->right->colour = BLACK;
          }
        }
      }
    }
  }
}

/**
 * case 1b(2) - Double black node can a node or null.
 *            - Parent and siblingRight are black.
 *            - Left child of siblingRight is red.
 *            - Double black node become null before rotation.
 *
 *
 *        /     rotate right    /      rotate left      /   
 *     70(B)   ------------>  70(B)   ----------->    80(B) 
 *    //   \    at node90    //  \     at node70     /   \
 *  40(B)  90(B)           null  80(R)             70(B) 90(B)
 *         /                      \
 *       80(R)                    90(B)
 *
 */
void caseOneBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((leftChildRight != NULL) && (leftChildRight->colour == RED)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left = NULL;
        rotateRightLeft(&(*nodePtr));
        (*nodePtr)->colour = BLACK;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->right->colour = BLACK;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
      }
    }
  }
}

/**
 *    case 2a(1) - Double black node can be a node or null.
 *               - Parent, siblingRight and the children of siblingRight are black.
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)  
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               NULL  50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 *
 *
 */
void caseTwoAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((leftChildRight != NULL) && (leftChildRight->colour == BLACK)){
      if((rightChildRight != NULL) && (rightChildRight->colour == BLACK)){
        if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
          (*nodePtr)->left = NULL;
          (*nodePtr)->colour = DOUBLE_BLACK;
          (*nodePtr)->right->colour = RED;
        }
        else if(siblingLeft == NULL){
          if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
            (*nodePtr)->colour = DOUBLE_BLACK;
            (*nodePtr)->right->colour = RED;
          }
        }
      }
    }
  }
}

/**
 *    case 2a(2) - Double black node can be either a node or null.
 *               - Both child of siblingRight are null.
 *    
 *          80(B)                      80(B)
 *         /    \                     //   \
 *       20(B)   -  flip colour     20(B)   -
 *      //  \      ----------->    /    \
 *    10(B) 50(B)               10(B)  50(R)
 *
 *
 *
 */
void caseTwoATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((leftChildRight == NULL) && (rightChildRight == NULL)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left = NULL;
        (*nodePtr)->colour = DOUBLE_BLACK;
        (*nodePtr)->right->colour = RED;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          (*nodePtr)->colour = DOUBLE_BLACK;
          (*nodePtr)->right->colour = RED;
        }
      }
    }
  }
}

/**
 *    case 2b(1) - Double black node can be a node or null.
 *               - SiblingRight and its children are black with the parent is red.
 *    
 *         /                         /   
 *       20(R)     flip colour     20(B)  
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               NULL  50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 *
 *
 */
void caseTwoBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == RED) && (siblingRight->colour == BLACK)){
    if((leftChildRight != NULL) && (leftChildRight->colour == BLACK)){
      if((rightChildRight != NULL) && (rightChildRight->colour == BLACK)){
        if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
          (*nodePtr)->left = NULL;
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->right->colour = RED;
        }
        else if(siblingLeft == NULL){
          if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->right->colour = RED;
          }
        }
      }
    }
  }
}

/**
 *    case 2b(2) - Double black node can be a node or null.
 *               - Parent is red and siblingRight is black.
 *               - Children of siblingRight are null.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               NULL  50(R)
 *
 *
 *
 */
void caseTwoBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == RED) && (siblingRight->colour == BLACK)){
    if((leftChildRight == NULL) && (rightChildRight == NULL)){
      if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
        (*nodePtr)->left = NULL;
        (*nodePtr)->colour = BLACK;
        (*nodePtr)->right->colour = RED;
      }
      else if(siblingLeft == NULL){
        if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->right->colour = RED;
        }
      }
    }
  }
}

/**
 *    case 3 - double black node can be either a node or null.
 *    
 *         /                         /                   /    
 *       20(B)     rotate left     50(B)     case 2    50(B)  
 *      //  \      ----------->   /   \     ------->  /   \
 *    10(B) 50(R)  at node20   20(R)  70(B)         20(B) 70(B)
 *          /  \               //  \                /   \
 *       30(B)70(B)          10(B) 30(B)           -   30(R)
 *
 *
 *
 */
void caseThree(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == RED)){
    if((leftChildRight != NULL) && (leftChildRight->colour == BLACK)){
      if((rightChildRight != NULL) && (rightChildRight->colour == BLACK)){
        if((siblingLeft != NULL) && (siblingLeft->colour == DOUBLE_BLACK)){
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = RED;
          if(((*nodePtr)->left->right->left == NULL) && ((*nodePtr)->left->right->right == NULL)){
            caseTwoATwo(&((*nodePtr)->left), deletedNode, nodeValue);
            caseTwoBTwo(&((*nodePtr)->left), deletedNode, nodeValue);
          }
          else if(((*nodePtr)->left->right->left != NULL) && ((*nodePtr)->left->right->right != NULL)){
            caseTwoAOne(&((*nodePtr)->left), deletedNode, nodeValue);
            caseTwoBOne(&((*nodePtr)->left), deletedNode, nodeValue);
          }
        }
        else if((siblingLeft == NULL) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = RED;
          if(((*nodePtr)->left->right->left == NULL) && ((*nodePtr)->left->right->right == NULL)){
            caseTwoATwo(&((*nodePtr)->left), deletedNode, nodeValue);
            caseTwoBTwo(&((*nodePtr)->left), deletedNode, nodeValue);
          }
          else if(((*nodePtr)->left->right->left != NULL) && ((*nodePtr)->left->right->right != NULL)){
            caseTwoAOne(&((*nodePtr)->left), deletedNode, nodeValue);
            caseTwoBOne(&((*nodePtr)->left), deletedNode, nodeValue);
          }
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
    caseOneAOne(nodePtr, retObj, (*nodePtr)->value);
    caseOneATwo(nodePtr, retObj, (*nodePtr)->value);
    caseOneBOne(nodePtr, retObj, (*nodePtr)->value);
    caseOneBTwo(nodePtr, retObj, (*nodePtr)->value);
    caseTwoAOne(nodePtr, retObj, (*nodePtr)->value);
    caseTwoATwo(nodePtr, retObj, (*nodePtr)->value);
    caseTwoBOne(nodePtr, retObj, (*nodePtr)->value);
    caseTwoBTwo(nodePtr, retObj, (*nodePtr)->value);
    caseThree(nodePtr, retObj, (*nodePtr)->value);
  }
  else if(node->value > (*nodePtr)->value){
    intRbtDelete(&((*nodePtr)->right), node);
  }
}

void rbtDelete(Node **nodePtr, Node *node){
  intRbtDelete(nodePtr, node);
}