#include <stdlib.h>
#include <stdio.h>
#include "RemoveNode.h"
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
ReturnedObject rbtRemovedNode(Node *nodePtr){
  ReturnedObject retObj;
  
  retObj.removedNode = nodePtr;
  retObj.returnedColour = nodePtr->colour;
  
  return retObj;
}

/**
 * caseLeft 1a(1) - Double black node can be a node or null.
 *                - Parent is red and the siblingRight's right child are red.
 *                - SiblingRight is black.
 *                - Double black node become null.
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
void caseLeftOneAOne(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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
 *                - Parent and siblingRight are black.
 *                - Right child of siblingRight is red.
 *                - Double black node will become null.
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
void caseLeftOneATwo(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
        if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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
 *                - Parent and the left child of siblingRight are red.
 *                - SiblingRight is black.
 *                - Double black node will become null.
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
void caseLeftOneBOne(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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
 *                - Parent and siblingRight are black.
 *                - Left child of siblingRight is red.
 *                - Double black node become null.
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
void caseLeftOneBTwo(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
        if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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
 *                   - Parent, siblingRight and the children of siblingRight are black.
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
void caseLeftTwoAOne(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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
 *                   - Both child of siblingRight are null.
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    10(B) 50(B)              10(B)  50(R)
 *         /   \                     /   \ 
 *        -    -                    -    -
 *
 */
void caseLeftTwoATwo(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
        if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
          (*nodePtr)->colour = DOUBLE_BLACK;
          (*nodePtr)->right->colour = RED;
        }
      }
    }
  }
}

/**
 *    caseLeft 2b(1) - Double black node can be a node or null.
 *                   - SiblingRight and its children are black with the parent is red.
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
void caseLeftTwoBOne(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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
 *                   - Parent is red and siblingRight is black.
 *                   - Children of siblingRight are null.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               NULL  50(R)
 *
 *
 *
 */
void caseLeftTwoBTwo(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
        if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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
 *       20(B)     rotate left     50(B)     case 2    50(B)  
 *      //  \      ----------->   /   \     ------->  /   \
 *    10(B) 50(R)  at node20   20(R)  70(B)         20(B) 70(B)
 *          /  \               //  \                /   \
 *       30(B)70(B)          10(B) 30(B)           -   30(R)
 *
 *
 *
 */
void caseLeftThree(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
            caseLeftTwoATwo(&((*nodePtr)->left), retObj, nodeValue);
            caseLeftTwoBTwo(&((*nodePtr)->left), retObj, nodeValue);
          }
          else if(((*nodePtr)->left->right->left != NULL) && ((*nodePtr)->left->right->right != NULL)){
            caseLeftTwoAOne(&((*nodePtr)->left), retObj, nodeValue);
            caseLeftTwoBOne(&((*nodePtr)->left), retObj, nodeValue);
          }
        }
        else if((siblingLeft == NULL) && (retObj.returnedColour == DOUBLE_BLACK)){
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = RED;
          if(((*nodePtr)->left->right->left == NULL) && ((*nodePtr)->left->right->right == NULL)){
            caseLeftTwoATwo(&((*nodePtr)->left), retObj, nodeValue);
            caseLeftTwoBTwo(&((*nodePtr)->left), retObj, nodeValue);
          }
          else if(((*nodePtr)->left->right->left != NULL) && ((*nodePtr)->left->right->right != NULL)){
            caseLeftTwoAOne(&((*nodePtr)->left), retObj, nodeValue);
            caseLeftTwoBOne(&((*nodePtr)->left), retObj, nodeValue);
          }
        }
      }
    }
  }
}

void caseLeftDoubleBlack(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  caseLeftOneAOne(nodePtr, retObj, nodeValue);
  caseLeftOneATwo(nodePtr, retObj, nodeValue);
  caseLeftOneBOne(nodePtr, retObj, nodeValue);
  caseLeftOneBTwo(nodePtr, retObj, nodeValue);
  caseLeftTwoAOne(nodePtr, retObj, nodeValue);
  caseLeftTwoATwo(nodePtr, retObj, nodeValue);
  caseLeftTwoBOne(nodePtr, retObj, nodeValue);
  caseLeftTwoBTwo(nodePtr, retObj, nodeValue);
  caseLeftThree(nodePtr, retObj, nodeValue);
}

/**
 * caseRight 1a(1) - Double black node can be a node or null.
 *                 - Parent is red and the siblingLeft's right child are red.
 *                 - siblingLeft is black.
 *                 - Double black node become null.
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
void caseRightOneAOne(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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
 *                 - Double black node will become null.
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
void caseRightOneATwo(Node **nodePtr, ReturnedObject retObj, int nodeValue){
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
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
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

/**
 * caseRight 1b(1) - Double black node can be a node or null.
 *                - Parent and the right child of siblingLeft are red.
 *                - SiblingLeft is black.
 *                - Double black node will become null.
 *
 *
 *        /       rotate left      /       rotate right     / 
 *     70(R)     ------------>   70(R)    ------------>   50(R)
 *    /   \\      at node40     /   \\     at node70     /   \
 *  40(B) 90(B)               50(R)  90(B)            40(B) 70(B)
 *    \                       /     
 *   50(R)                  40(B)     
 *
 */
void caseRightOneBOne(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == RED){
    if((rightChildLeft != NULL) && (rightChildLeft->colour == RED)){
      if(siblingLeft->colour == BLACK){
        if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
          (*nodePtr)->right = NULL;
          rotateLeftRight(&(*nodePtr));
          (*nodePtr)->colour = RED;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
        else if(siblingRight == NULL){
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
            rotateLeftRight(&(*nodePtr));
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
 * caseRight 1b(2) - Double black node can a node or null.
 *                - Parent and siblingLeft are black.
 *                - Right child of siblingLeft is red.
 *                - Double black node will become null.
 *
 *
 *        /       rotate left      /       rotate right     / 
 *     70(B)     ------------>   70(R)    ------------>   50(B)
 *    /   \\      at node40     /   \\     at node70     /   \
 *  40(B) 90(B)               50(R)  90(B)            40(B) 70(B)
 *    \                       /     
 *   50(R)                  40(B)     
 *
 */
void caseRightOneBTwo(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((rightChildLeft != NULL) && (rightChildLeft->colour == RED)){
        if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
          (*nodePtr)->right = NULL;
          rotateLeftRight(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
        }
        else if(siblingRight == NULL){
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
            rotateLeftRight(&(*nodePtr));
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->left->colour = BLACK;
            (*nodePtr)->right->colour = BLACK;
          }
        }
      }
    }
  }
}

/**
 *    caseRight 2a(1) - Double black node can be a node or null.
 *                   - Parent, siblingRight and the children of siblingRight are black.
 *    
 *           /                         //   
 *         50(B)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 *
 *
 */
void caseRightTwoAOne(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft != NULL) && (leftChildLeft->colour == BLACK)){
        if((rightChildLeft != NULL) && (rightChildLeft->colour == BLACK)){
          if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
            (*nodePtr)->right = NULL;
            (*nodePtr)->colour = DOUBLE_BLACK;
            (*nodePtr)->left->colour = RED;
          }
          else if(siblingRight == NULL){
            if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
              (*nodePtr)->colour = DOUBLE_BLACK;
              (*nodePtr)->left->colour = RED;
            }
          }
        }
      }
    }
  }
}

/**
 *    caseRight 2a(2) - Double black node can be either a node or null.
 *                   - Parent and siblingLeft are black.
 *                   - Both child of siblingRight are null.
 *    
 *           /                         //   
 *         50(B)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \                      /  \
 *    -    -                     -   -
 *
 *
 *
 */
void caseRightTwoATwo(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft == NULL) && (rightChildLeft == NULL)){
        if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
          (*nodePtr)->right = NULL;
          (*nodePtr)->colour = DOUBLE_BLACK;
          (*nodePtr)->left->colour = RED;
        }
        else if(siblingRight == NULL){
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
            (*nodePtr)->colour = DOUBLE_BLACK;
            (*nodePtr)->left->colour = RED;
          }
        }
      }
    }
  }
}

/**
 *   caseRight 2b(1) - Double black node can be a node or null.
 *                   - SiblingLeft and its children are black with the parent is red.
 *    
 *           /                         /   
 *         50(R)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 *
 *
 */
void caseRightTwoBOne(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == RED){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft != NULL) && (leftChildLeft->colour == BLACK)){
        if((rightChildLeft != NULL) && (rightChildLeft->colour == BLACK)){
          if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
            (*nodePtr)->right = NULL;
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->left->colour = RED;
          }
          else if(siblingRight == NULL){
            if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
              (*nodePtr)->colour = BLACK;
              (*nodePtr)->left->colour = RED;
            }
          }
        }
      }
    }
  }
}

/**
 *   caseRight 2b(2) - Double black node can be a node or null.
 *                   - Parent is red and siblingLeft is black.
 *                   - Children of siblingLeft are null.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      /   \\     ----------->    /   \
 *    10(B) 50(B)               10(R)  -
 *    /  \                      /  \
 *   -   -                     -   -
 *
 */
void caseRightTwoBTwo(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == RED){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft == NULL) && (rightChildLeft == NULL)){
        if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
          (*nodePtr)->right = NULL;
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = RED;
        }
        else if(siblingRight == NULL){
          if((retObj.removedNode->value == nodeValue) && (retObj.returnedColour == DOUBLE_BLACK)){
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->left->colour = RED;
          }
        }
      }
    }
  }
}

/**
 *    caseRight 3 - double black node can be either a node or null.
 *    
 *           /                          /                       /
 *         50(B)     rotate right     30(B)      case 2       30(B)
 *        /   \\     ----------->    /    \      ------>     /    \
 *     30(R)  70(B)                20(B) 50(R)             20(B) 50(B)
 *     /   \                            /   \\                   /   \
 *  20(B) 40(B)                       40(B) 70(B)             40(R)  -
 *
 *
 *
 */
void caseRightThree(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == RED)){
      if((leftChildLeft != NULL) && (leftChildLeft->colour == BLACK)){
        if((rightChildLeft != NULL) && (rightChildLeft->colour == BLACK)){
          if((siblingRight != NULL) && (siblingRight->colour == DOUBLE_BLACK)){
            rotateRight(&(*nodePtr));
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->right->colour = RED;
            if((leftChildRightLeft(*nodePtr) == NULL) && (rightChildRightLeft(*nodePtr) == NULL)){
              caseRightTwoATwo(&((*nodePtr)->right), retObj, nodeValue);
              caseRightTwoBTwo(&((*nodePtr)->right), retObj, nodeValue);
            }
            else if(((*nodePtr)->left->right->left != NULL) && ((*nodePtr)->left->right->right != NULL)){
              caseRightTwoAOne(&((*nodePtr)->right), retObj, nodeValue);
              caseRightTwoBOne(&((*nodePtr)->right), retObj, nodeValue);
            }
          }
          else if((siblingRight == NULL) && (retObj.returnedColour == DOUBLE_BLACK)){
            rotateRight(&(*nodePtr));
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->right->colour = RED;
            if((leftChildRightLeft(*nodePtr) == NULL) && (rightChildRightLeft(*nodePtr) == NULL)){
              caseRightTwoATwo(&((*nodePtr)->right), retObj, nodeValue);
              caseRightTwoBTwo(&((*nodePtr)->right), retObj, nodeValue);
            }
            else if((leftChildRightLeft(*nodePtr)!= NULL) && (rightChildRightLeft(*nodePtr) != NULL)){
              caseRightTwoAOne(&((*nodePtr)->right), retObj, nodeValue);
              caseRightTwoBOne(&((*nodePtr)->right), retObj, nodeValue);
            }
          }
        }
      }
    }
  }
}

void caseRightDoubleBlack(Node **nodePtr, ReturnedObject retObj, int nodeValue){
  caseRightOneAOne(nodePtr, retObj, nodeValue);
  caseRightOneATwo(nodePtr, retObj, nodeValue);
  caseRightOneBOne(nodePtr, retObj, nodeValue);
  caseRightOneBTwo(nodePtr, retObj, nodeValue);
  caseRightTwoAOne(nodePtr, retObj, nodeValue);
  caseRightTwoATwo(nodePtr, retObj, nodeValue);
  caseRightTwoBOne(nodePtr, retObj, nodeValue);
  caseRightTwoBTwo(nodePtr, retObj, nodeValue);
  caseRightThree(nodePtr, retObj, nodeValue);
}

void swapNode(Node **node1, Node *node2){
  Node *tempNode;
  
  tempNode = *node1;
  node1 = &node2;
  node2 = tempNode;
}

void intRbtRemove(Node **nodePtr, Node *node){
  ReturnedObject retObj;
  
  if(*nodePtr == node){
    (*nodePtr)->colour = DOUBLE_BLACK;
    retObj = rbtRemovedNode(*nodePtr);
    return;
  }
  else if(*nodePtr == NULL){
    *nodePtr = node;
    (*nodePtr)->colour = DOUBLE_BLACK;
    retObj = rbtRemovedNode(*nodePtr);
    // node->colour = DOUBLE_BLACK;     // variables cannot pass to
    // retObj = rbtRemovedNode(node);   // the ReturnedObject structure 
    return; // need to take care -> double black null couldn't take care.
  }
  
  if(node->value < (*nodePtr)->value){
    intRbtRemove(&((*nodePtr)->left), node);
    caseLeftDoubleBlack(nodePtr, retObj, node->value);
  }
  else if(node->value > (*nodePtr)->value){
    intRbtRemove(&((*nodePtr)->right), node);
    caseRightDoubleBlack(nodePtr, retObj, node->value);
  }
}

void rbtRemove(Node **nodePtr, Node *node){
  intRbtRemove(nodePtr, node);
}