#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "CustomAssertion.h"
#include "Node.h"

char *nodeColour(Colour colour){
  switch(colour){
    case BLACK:
      return "black";
      break;
    case RED:
      return "red";
      break;      
    case DOUBLE_BLACK:
      return "double black";
      break;
    default:
      return "undefined color";
      break;   
  }
}

void customTestAssertion(Node *root, Node *left, Node *right, Colour colour, int value, int lineNo){
  char buffer[256];
  
  if(root == NULL){
    UNITY_TEST_FAIL(lineNo, "Expect node not NULL.");
  }
  
  if(root->left != left){
    if(root->left == NULL){
      sprintf(buffer, "Expect left node is NULL, but it is %d.", left->value);
      UNITY_TEST_FAIL(lineNo, buffer);
    }
    else if(left == NULL){
      sprintf(buffer,"Expect left node is %d(0x%p), but it is NULL",   \
              root->left->value, root->left);
      UNITY_TEST_FAIL(lineNo, buffer);
    }
    else{
      sprintf(buffer,"Expect left node is %d(0x%p), but it is %d",     \
              root->left->value, root->left, left->value);
      UNITY_TEST_FAIL(lineNo, buffer);
    }
  }
  
  if(root->right != right){
    if(root->right == NULL){
      sprintf(buffer,"Expect right node is NULL, but it is %d", right->value);
      UNITY_TEST_FAIL(lineNo, buffer);
    }
    else if(right == NULL){
      sprintf(buffer,"Expect right node is %d(0x%p), but it is NULL",   \
              root->right->value, root->right);
      UNITY_TEST_FAIL(lineNo, buffer);
    }
    else{
      sprintf(buffer,"Expect right node is %d(0x%p), but it is %d",     \
              root->right->value, root->right, right->value);
      UNITY_TEST_FAIL(lineNo, buffer);
    }
  }
  
  if(root->value != value){
    sprintf(buffer, "Expect node %d's value is %d, but it is %d",     \
            root->value, value, root->value);
    UNITY_TEST_FAIL(lineNo, buffer);
  }
  
  if(root->colour != colour){
    sprintf(buffer, "Expect node %d is %s colour, but it is %s",    \
            root->value, nodeColour(root->colour), nodeColour(colour));
    UNITY_TEST_FAIL(lineNo, buffer);
  }
}