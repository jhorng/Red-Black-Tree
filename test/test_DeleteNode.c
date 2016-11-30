#include "unity.h"
#include "DeleteNode.h"
#include "Node.h"

Node node10, node20, node25, node30, node40, node50;
Node node60, node70, node80, node90, node95, node100, node105;
Node node110, node120, node130, node140, node150, node160; 

void defineNode(Node *node, int colour, int value){
  node->left = NULL;
  node->right = NULL;
  node->colour = colour;
  node->value = value;
}

void setUp(void){
  defineNode(&node10, BLACK, 10);
  defineNode(&node20, BLACK, 20);
  defineNode(&node25, BLACK, 25);
  defineNode(&node30, BLACK, 30);
  defineNode(&node40, BLACK, 40);
  defineNode(&node50, BLACK, 50);
  defineNode(&node60, BLACK, 60);
  defineNode(&node70, BLACK, 70);
  defineNode(&node80, BLACK, 80);
  defineNode(&node90, BLACK, 90);
  defineNode(&node95, BLACK, 95);
  defineNode(&node100, BLACK, 100);
  defineNode(&node105, BLACK, 105);
  defineNode(&node110, BLACK, 110);
  defineNode(&node120, BLACK, 120);
  defineNode(&node130, BLACK, 130);
  defineNode(&node140, BLACK, 140);
  defineNode(&node150, BLACK, 150);
  defineNode(&node160, BLACK, 160);
}

void tearDown(void){}

void test_dummy_func(void){
  Node *root = &node60;
  
  initNode(&node60, NULL, NULL, BLACK);
  
  rbtAdd(&root, &node80);
  
  CTEST_ASSERT_EQUAL(&node60, NULL, &node80, BLACK, 60);
  CTEST_ASSERT_EQUAL(&node80, NULL, NULL, RED, 80);
}
