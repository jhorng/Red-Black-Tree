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

void caseOnePointOne(Node *root){
  if(root->right != NULL){
    if(root->left->right != NULL){
      if((root->right->colour) && (root->left->right->colour) == RED){
        root->colour = RED;
        root->left->colour = BLACK;
        root->right->colour = BLACK;
      }
    }
    else if(root->left->left != NULL){
      if((root->right->colour) && (root->left->left->colour) == RED){
        root->colour = RED;
        root->left->colour = BLACK;
        root->right->colour = BLACK;
      }
    }
  }
}

void caseOnePointTwo(Node *root){
  if(root->left != NULL){
    if(root->right->left != NULL){
      if((root->left->colour) && (root->right->left->colour) == RED){
        root->colour = RED;
        root->left->colour = BLACK;
        root->right->colour = BLACK;
      }
    }
    else if(root->right->right != NULL){
      if((root->left->colour) && (root->right->right->colour) == RED){
        root->colour = RED;
        root->left->colour = BLACK;
        root->right->colour = BLACK;
      }
    }
  }
}

void caseTwoPointOne(Node *root){
  if(root->right == NULL){
    if(root->left != NULL){
      if(root->left->right != NULL){
        if((root->left->colour) && (root->left->right->colour) == RED){
          rotateLeft(&(root->left));
        }
      }
    }
  }
  else{
    if(root->right->colour == BLACK){
      if(root->left != NULL){
        if(root->left->right != NULL){
          if((root->left->colour) && (root->left->right->colour) == RED){
            rotateLeft(&(root->left));
          }
        }
      }
    }
  }
}

void caseTwoPointTwo(Node *root){
  if(root->left == NULL){
    if(root->right != NULL){
      if(root->right->left != NULL){
        if((root->right->colour) && (root->right->left->colour) == RED){
          rotateRight(&(root->right));
        }
      }
    }
  }
  else{
    if(root->left->colour == BLACK){
      if(root->right != NULL){
        if(root->right->left != NULL){
          if((root->right->colour) && (root->right->left->colour) == RED){
            rotateRight(&(root->right));
          }
        }
      }
    }
  }
}

void caseThreePointOne(Node *root){
  if(root->right == NULL){
    if(root->left->left != NULL){
      if((root->left->colour) && (root->left->left->colour) == RED){
        rotateRight(&(root));
        root->colour = BLACK;
        root->left->colour = RED;
        root->right->colour = RED;
      }
    }
  }
  else{
    if(root->right->colour == BLACK){
      if(root->left->left != NULL){
        if((root->left->colour) && (root->left->left->colour) == RED){
          rotateRight(&(root));
          root->colour = BLACK;
          root->left->colour = RED;
          root->right->colour = RED;
        }
      }
    }
  }
}

void caseThreePointTwo(Node *root){
  if(root->left == NULL){
    if(root->right->right != NULL){
      if((root->right->colour) && (root->right->right->colour) == RED){
        rotateLeft(&(root));
        root->colour = BLACK;
        root->left->colour = RED;
        root->right->colour = RED;
      }
    }
  }
  else{ 
    if(root->left->colour == BLACK){
      if(root->right->right != NULL){
        if((root->right->colour) && (root->right->right->colour) == RED){
          rotateLeft(&(root));
          root->colour = BLACK;
          root->left->colour = RED;
          root->right->colour = RED;
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
    caseOnePointOne(*root);
    caseTwoPointOne(*root);
    caseThreePointOne(*root);
  }
  else if(child->value > (*root)->value){
    intRbtAdd(&((*root)->right), child);
    caseOnePointTwo(*root);
    caseTwoPointTwo(*root);
    caseThreePointTwo(*root);
  }
}

void rbtAdd(Node **root, Node *child){
  intRbtAdd(root, child);
}

// void addNode(Node *root, Node *child){
  // if(root->value < child->value){  
    // if (root->right == NULL){
      // root->right = child;
      // root->right->colour = RED;
    // }
    // else{
      // addNode(root->right, child);
    // }
  // }
  // else if (root->value > child->value){
    // if (root->left == NULL){
      // root->left = child;
      // root->left->colour = RED;
    // }
    // else{
      // addNode(root->left, child);
    // }
  // }
// }
