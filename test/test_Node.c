#include "unity.h"
#include "Node.h"
#include "CustomAssertion.h"

Node node10, node20, node30, node40, node50;
Node node60, node70, node80, node90, node100;
Node node110, node120, node130, node140, node150; 

void defineNode(Node *node, int colour, int value){
  node->left = NULL;
  node->right = NULL;
  node->colour = colour;
  node->value = value;
}

void setUp(void){
  defineNode(&node10, BLACK, 10);
  defineNode(&node20, BLACK, 20);
  defineNode(&node30, BLACK, 30);
  defineNode(&node40, BLACK, 40);
  defineNode(&node50, BLACK, 50);
  defineNode(&node60, BLACK, 60);
  defineNode(&node70, BLACK, 70);
  defineNode(&node80, BLACK, 80);
  defineNode(&node90, BLACK, 90);
  defineNode(&node100, BLACK, 100);
  defineNode(&node110, BLACK, 110);
  defineNode(&node120, BLACK, 120);
  defineNode(&node130, BLACK, 130);
  defineNode(&node140, BLACK, 140);
  defineNode(&node150, BLACK, 150);
}

void tearDown(void){}

/******************************
 *
 *          10
 *         /  \
 *      NULL  NULL
 *
 ******************************/
void test_a_new_node_is_initialized(void){
  int colour=BLACK;
  
  initNode(&node10, NULL, NULL, colour);
  
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, colour, 10);
}

/******************************
 *
 *          20
 *         /  \
 *       10  NULL
 *
 ******************************/
void test_a_new_node_is_added_as_left_child_of_a_root_node(void){
  int rootColour=BLACK;
  int leftChildColour=RED;
  
  initNode(&node20, &node10, NULL, rootColour);
  initNode(&node10, NULL, NULL, leftChildColour);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, NULL, rootColour, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, leftChildColour, 10);
}

/**************************
 *
 *          30
 *         /  \
 *      NULL  50
 *
 **************************/
void test_a_new_node_is_added_as_right_child_of_a_root_node(void){
  int rootColour=BLACK;
  int rightChildColour=RED;
  
  initNode(&node30, NULL, &node50, rootColour);
  initNode(&node50, NULL, NULL, rightChildColour);
  
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, &node50, rootColour, 30);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, rightChildColour, 50);
}

/**************************
 *
 *          50
 *         /  \
 *       30   70
 *
 **************************/
void test_two_new_node_is_added_as_left_and_right_child_of_a_root_node(void){
  int rootColour=BLACK;
  int leftChildColour=RED;
  int rightChildColour=RED;
  
  initNode(&node50, &node30, &node70, rootColour);
  initNode(&node30, NULL, NULL, leftChildColour);
  initNode(&node70, NULL, NULL, rightChildColour);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, rootColour, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, leftChildColour, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, rightChildColour, 70);
}


