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
 * caseLeft 1a(1) - Double black node can be a node or null.
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
void caseLeftOneAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChildRight = siblingRight->right;
  
  if(parent->colour == RED){
    if((rightChildRight != NULL) && (rightChildRight->colour == RED)){
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
 * caseLeft 1a(2) - Double black node can a node or null.
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
void caseLeftOneATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
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
 * caseLeft 1b(1) - Double black node can be a node or null.
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
void caseLeftOneBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
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
 * caseLeft 1b(2) - Double black node can a node or null.
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
void caseLeftOneBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
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
 *    caseLeft 2a(1) - Double black node can be a node or null.
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
void caseLeftTwoAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
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
 *    caseLeft 2a(2) - Double black node can be either a node or null.
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
void caseLeftTwoATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
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
 *    caseLeft 2b(1) - Double black node can be a node or null.
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
void caseLeftTwoBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
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
 *    caseLeft 2b(2) - Double black node can be a node or null.
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
void caseLeftTwoBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
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
 *    caseLeft 3 - double black node can be either a node or null.
 *    
 *         /                         /                   /    
 *       20(B)     rotate left     50(B)     caseLeft 2    50(B)  
 *      //  \      ----------->   /   \     ------->  /   \
 *    10(B) 50(R)  at node20   20(R)  70(B)         20(B) 70(B)
 *          /  \               //  \                /   \
 *       30(B)70(B)          10(B) 30(B)           -   30(R)
 *
 *
 *
 */
void caseLeftThree(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
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
            caseLeftTwoATwo(&((*nodePtr)->left), deletedNode, nodeValue);
            caseLeftTwoBTwo(&((*nodePtr)->left), deletedNode, nodeValue);
          }
          else if(((*nodePtr)->left->right->left != NULL) && ((*nodePtr)->left->right->right != NULL)){
            caseLeftTwoAOne(&((*nodePtr)->left), deletedNode, nodeValue);
            caseLeftTwoBOne(&((*nodePtr)->left), deletedNode, nodeValue);
          }
        }
        else if((siblingLeft == NULL) && (deletedNode.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = RED;
          if(((*nodePtr)->left->right->left == NULL) && ((*nodePtr)->left->right->right == NULL)){
            caseLeftTwoATwo(&((*nodePtr)->left), deletedNode, nodeValue);
            caseLeftTwoBTwo(&((*nodePtr)->left), deletedNode, nodeValue);
          }
          else if(((*nodePtr)->left->right->left != NULL) && ((*nodePtr)->left->right->right != NULL)){
            caseLeftTwoAOne(&((*nodePtr)->left), deletedNode, nodeValue);
            caseLeftTwoBOne(&((*nodePtr)->left), deletedNode, nodeValue);
          }
        }
      }
    }
  }
}

void caseLeftDoubleBlack(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  caseLeftOneAOne(nodePtr, deletedNode, nodeValue);
  caseLeftOneATwo(nodePtr, deletedNode, nodeValue);
  caseLeftOneBOne(nodePtr, deletedNode, nodeValue);
  caseLeftOneBTwo(nodePtr, deletedNode, nodeValue);
  caseLeftTwoAOne(nodePtr, deletedNode, nodeValue);
  caseLeftTwoATwo(nodePtr, deletedNode, nodeValue);
  caseLeftTwoBOne(nodePtr, deletedNode, nodeValue);
  caseLeftTwoBTwo(nodePtr, deletedNode, nodeValue);
  caseLeftThree(nodePtr, deletedNode, nodeValue);
}

/**
 * caseRight 1a(1) - Double black node can be a node or null.
 *                 - Parent is red and the siblingLeft's right child are red.
 *                 - siblingLeft is black.
 *                 - Double black node become null before rotation.
 *
 *
 *         /     rotate Right    /
 *      70(R)    ----------->  40(R)
 *     /   \\                 /   \
 *   40(B) 90(B)            20(B)70(B)
 *   /                   
 * 20(R)                      
 *
 */
void caseRightOneAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  
  if(parent->colour == RED){
    if((leftChildLeft != NULL) && (leftChildLeft->colour == RED)){
      if(siblingLeft->colour == BLACK){
        if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
          (*nodePtr)->right = NULL;
          rotateRight(&(*nodePtr));
          (*nodePtr)->colour = RED;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
        else if(siblingRight == NULL){
          if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
            rotateRight(&(*nodePtr));
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
 * caseRight 1a(2) - Double black node can a node or null.
 *                 - Parent and siblingLeft are black.
 *                 - Left child of siblingLeft is red.
 *                 - Double black node will become null before rotation.
 *
 *
 *         /     rotate Right    /
 *      70(B)    ----------->  40(B)
 *     /   \\                 /   \
 *   40(B) 90(B)            20(B)70(B)
 *   /                   
 * 20(R)                       
 *
 */
void caseRightOneATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft != NULL) && (leftChildLeft->colour == RED)){
        if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
          (*nodePtr)->right = NULL;
          rotateRight(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
        else if(siblingRight == NULL){
          if((deletedNode.removedNode->value == nodeValue) && (deletedNode.returnedColour == DOUBLE_BLACK)){
            rotateRight(&(*nodePtr));
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->left->colour = BLACK;
            (*nodePtr)->right->colour = BLACK;
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
    caseLeftDoubleBlack(nodePtr, retObj, (*nodePtr)->value);
  }
  else if(node->value > (*nodePtr)->value){
    intRbtDelete(&((*nodePtr)->right), node);
  }
}

void rbtDelete(Node **nodePtr, Node *node){
  intRbtDelete(nodePtr, node);
}