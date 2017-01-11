#include <stdlib.h>
#include <stdio.h>
#include "RemoveNode.h"
#include "Rotation.h"

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
void caseLeftOneAOne(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChildRight = siblingRight->right;
  
  if(parent->colour == RED){
    if((rightChildRight != NULL) && (rightChildRight->colour == RED)){
      if(siblingRight->colour == BLACK){
        if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
          if(siblingLeft != NULL){
            (*nodePtr)->left->colour = BLACK;
          }
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = RED;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
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
void caseLeftOneATwo(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChild = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((rightChild != NULL) && (rightChild->colour == RED)){
      if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
        if(siblingLeft != NULL){
          (*nodePtr)->left->colour = BLACK;
        }
        rotateLeft(&(*nodePtr));
        (*nodePtr)->colour = BLACK;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->right->colour = BLACK;
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
 *  40(B)  90(B)              40(B) 80(R)            70(B) 90(B)
 *         /                         \               /
 *       80(R)                      90(B)          40(B)
 *
 */
void caseLeftOneBOne(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  
  if(parent->colour == RED){
    if((leftChildRight != NULL) && (leftChildRight->colour == RED)){
      if(siblingRight->colour == BLACK){
        if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
          if(siblingLeft != NULL){
            (*nodePtr)->left->colour = BLACK;
          }
          rotateRightLeft(&(*nodePtr));
          (*nodePtr)->colour = RED;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
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
 *  40(B)  90(B)           40(B) 80(R)             70(B) 90(B)
 *         /                      \                /
 *       80(R)                    90(B)          40(B)
 *
 */
void caseLeftOneBTwo(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((leftChildRight != NULL) && (leftChildRight->colour == RED)){
      if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
        if(siblingLeft != NULL){
          (*nodePtr)->left->colour = BLACK;
        }
        rotateRightLeft(&(*nodePtr));
        (*nodePtr)->colour = BLACK;
        (*nodePtr)->left->colour = BLACK;
        (*nodePtr)->right->colour = BLACK;
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
void caseLeftTwoAOne(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((leftChildRight != NULL) && (leftChildRight->colour == BLACK)){
      if((rightChildRight != NULL) && (rightChildRight->colour == BLACK)){
        if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
          if(siblingLeft != NULL){
            (*nodePtr)->left->colour = BLACK;
          }
          (*nodePtr)->colour = DOUBLE_BLACK;
          (*nodePtr)->right->colour = RED;
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
void caseLeftTwoATwo(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == BLACK)){
    if((leftChildRight == NULL) && (rightChildRight == NULL)){
      if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
        if(siblingLeft != NULL){
          (*nodePtr)->left->colour = BLACK;
        }
        (*nodePtr)->colour = DOUBLE_BLACK;
        (*nodePtr)->right->colour = RED;
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
void caseLeftTwoBOne(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == RED) && (siblingRight->colour == BLACK)){
    if((leftChildRight != NULL) && (leftChildRight->colour == BLACK)){
      if((rightChildRight != NULL) && (rightChildRight->colour == BLACK)){
        if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
          if(siblingLeft != NULL){
            (*nodePtr)->left->colour = BLACK;
          }
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->right->colour = RED;
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
void caseLeftTwoBTwo(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == RED) && (siblingRight->colour == BLACK)){
    if((leftChildRight == NULL) && (rightChildRight == NULL)){
      if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
        if(siblingLeft != NULL){
          (*nodePtr)->left->colour = BLACK;
        }
        (*nodePtr)->colour = BLACK;
        (*nodePtr)->right->colour = RED;
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
void caseLeftThree(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildRight = siblingRight->left;
  Node *rightChildRight = siblingRight->right;
  
  if((parent->colour == BLACK) && (siblingRight->colour == RED)){
    if((leftChildRight != NULL) && (leftChildRight->colour == BLACK)){
      if((rightChildRight != NULL) && (rightChildRight->colour == BLACK)){
        if(isAnyOneDoubleBlack(siblingLeft, returnedObject)){
          rotateLeft(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = RED;
          caseLeftDoubleBlack(&((*nodePtr)->left), returnedObject);
        }
      }
    }
  }
}

void caseLeftDoubleBlack(Node **nodePtr, Node *returnedObject){
  caseLeftOneAOne(nodePtr, returnedObject);
  caseLeftOneATwo(nodePtr, returnedObject);
  caseLeftOneBOne(nodePtr, returnedObject);
  caseLeftOneBTwo(nodePtr, returnedObject);
  caseLeftTwoAOne(nodePtr, returnedObject);
  caseLeftTwoATwo(nodePtr, returnedObject);
  caseLeftTwoBOne(nodePtr, returnedObject);
  caseLeftTwoBTwo(nodePtr, returnedObject);
  caseLeftThree(nodePtr, returnedObject);
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
void caseRightOneAOne(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  
  if(parent->colour == RED){
    if((leftChildLeft != NULL) && (leftChildLeft->colour == RED)){
      if(siblingLeft->colour == BLACK){
        if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
          if(siblingRight != NULL){
            (*nodePtr)->right->colour = BLACK;
          }
          rotateRight(&(*nodePtr));
          (*nodePtr)->colour = RED;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
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
void caseRightOneATwo(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft != NULL) && (leftChildLeft->colour == RED)){
        if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
          if(siblingRight != NULL){
            (*nodePtr)->right->colour = BLACK;
          }
          rotateRight(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
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
void caseRightOneBOne(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == RED){
    if((rightChildLeft != NULL) && (rightChildLeft->colour == RED)){
      if(siblingLeft->colour == BLACK){
        if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
          if(siblingRight != NULL){
            (*nodePtr)->right->colour = BLACK;
          }
          rotateLeftRight(&(*nodePtr));
          (*nodePtr)->colour = RED;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
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
void caseRightOneBTwo(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((rightChildLeft != NULL) && (rightChildLeft->colour == RED)){
        if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
          if(siblingRight != NULL){
            (*nodePtr)->right->colour = BLACK;
          }
          rotateLeftRight(&(*nodePtr));
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = BLACK;
          (*nodePtr)->right->colour = BLACK;
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
void caseRightTwoAOne(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft != NULL) && (leftChildLeft->colour == BLACK)){
        if((rightChildLeft != NULL) && (rightChildLeft->colour == BLACK)){
          if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
          if(siblingRight != NULL){
            (*nodePtr)->right->colour = BLACK;
          }
            (*nodePtr)->colour = DOUBLE_BLACK;
            (*nodePtr)->left->colour = RED;
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
void caseRightTwoATwo(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft == NULL) && (rightChildLeft == NULL)){
        if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
          if(siblingRight != NULL){
            (*nodePtr)->right->colour = BLACK;
          }
          (*nodePtr)->colour = DOUBLE_BLACK;
          (*nodePtr)->left->colour = RED;
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
void caseRightTwoBOne(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == RED){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft != NULL) && (leftChildLeft->colour == BLACK)){
        if((rightChildLeft != NULL) && (rightChildLeft->colour == BLACK)){
          if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
            if(siblingRight != NULL){
              (*nodePtr)->right->colour = BLACK;
            }
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->left->colour = RED;
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
void caseRightTwoBTwo(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == RED){
    if((siblingLeft != NULL) && (siblingLeft->colour == BLACK)){
      if((leftChildLeft == NULL) && (rightChildLeft == NULL)){
        if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
          if(siblingRight != NULL){
            (*nodePtr)->right->colour = BLACK;
          }
          (*nodePtr)->colour = BLACK;
          (*nodePtr)->left->colour = RED;
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
void caseRightThree(Node **nodePtr, Node *returnedObject){
  Node *parent = *nodePtr;
  Node *siblingLeft = parent->left;
  Node *siblingRight = parent->right;
  Node *leftChildLeft = siblingLeft->left;
  Node *rightChildLeft = siblingLeft->right;
  
  if(parent->colour == BLACK){
    if((siblingLeft != NULL) && (siblingLeft->colour == RED)){
      if((leftChildLeft != NULL) && (leftChildLeft->colour == BLACK)){
        if((rightChildLeft != NULL) && (rightChildLeft->colour == BLACK)){
          if(isAnyOneDoubleBlack(siblingRight, returnedObject)){
            rotateRight(&(*nodePtr));
            (*nodePtr)->colour = BLACK;
            (*nodePtr)->right->colour = RED;
            caseRightDoubleBlack(&((*nodePtr)->right), returnedObject);
          }
        }
      }
    }
  }
}

void caseRightDoubleBlack(Node **nodePtr, Node *returnedObject){
  caseRightOneAOne(nodePtr, returnedObject);
  caseRightOneATwo(nodePtr, returnedObject);
  caseRightOneBOne(nodePtr, returnedObject);
  caseRightOneBTwo(nodePtr, returnedObject);
  caseRightTwoAOne(nodePtr, returnedObject);
  caseRightTwoATwo(nodePtr, returnedObject);
  caseRightTwoBOne(nodePtr, returnedObject);
  caseRightTwoBTwo(nodePtr, returnedObject);
  caseRightThree(nodePtr, returnedObject);
}

Node *findReplacingNode(Node *node){
  Node *replaceNode;
  
  if(node->left == NULL){
    replaceNode=node;
    return replaceNode;
  }
  else{
    findReplacingNode(node->left);
  }  
}

Node *rbtRemoveNode(Node **nodePtr, Node *node){
  Node *returnedObject;
  
  if(*nodePtr == node){
    if(((*nodePtr)->left == NULL) && ((*nodePtr)->right == NULL)){
      returnedObject = *nodePtr;
      returnedObject->colour = DOUBLE_BLACK;
      *nodePtr = NULL;
      return returnedObject;
    }
  }
  
  if(node->value < (*nodePtr)->value){
    rbtRemoveNode(&((*nodePtr)->left), node);
  }
  else if(node->value > (*nodePtr)->value){
    rbtRemoveNode(&((*nodePtr)->right), node);
  }
}

void rbtRemove(Node **nodePtr, Node *node){
  // rbtRemoveNode(nodePtr, node); // not fixed yet
}