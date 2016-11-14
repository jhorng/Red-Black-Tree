#include "unity.h"
#include "Node.h"

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

void test_a_new_node_is_initialized(void){
  int colour=BLACK;
  
  initNode(&node10, NULL, NULL, colour);
  
  TEST_ASSERT_EQUAL(NULL, node10.left);
  TEST_ASSERT_EQUAL(NULL, node10.right);
  TEST_ASSERT_EQUAL(BLACK, node10.colour);
  TEST_ASSERT_EQUAL(10, node10.value);
}

void test_a_new_node_is_added_as_left_child_of_a_root_node(void){
  int rootColour=BLACK;
  int leftChildColour=RED;
  
  initNode(&node20, &node10, NULL, rootColour);
  initNode(&node10, NULL, NULL, leftChildColour);
  
  TEST_ASSERT_EQUAL(&node10, node20.left);
  TEST_ASSERT_EQUAL(NULL, node20.right);
  TEST_ASSERT_EQUAL(rootColour, node20.colour);
  TEST_ASSERT_EQUAL(20, node20.value);
  TEST_ASSERT_EQUAL(NULL, node20.left->left);
  TEST_ASSERT_EQUAL(NULL, node20.left->right);
  TEST_ASSERT_EQUAL(leftChildColour, node20.left->colour);
  TEST_ASSERT_EQUAL(10, node20.left->value);
}

void test_a_new_node_is_added_as_right_child_of_a_root_node(void){
  int rootColour=BLACK;
  int rightChildColour=RED;
  
  initNode(&node30, NULL, &node50, rootColour);
  initNode(&node50, NULL, NULL, rightChildColour);
  
  TEST_ASSERT_EQUAL(NULL, node30.left);
  TEST_ASSERT_EQUAL(&node50, node30.right);
  TEST_ASSERT_EQUAL(rootColour, node30.colour);
  TEST_ASSERT_EQUAL(30, node30.value);
  TEST_ASSERT_EQUAL(NULL, node30.right->left);
  TEST_ASSERT_EQUAL(NULL, node30.right->right);
  TEST_ASSERT_EQUAL(rightChildColour, node30.right->colour);
  TEST_ASSERT_EQUAL(50, node30.right->value);
}

void test_two_new_node_is_added_as_left_and_right_child_of_a_root_node(void){
  int rootColour=BLACK;
  int leftChildColour=RED;
  int rightChildColour=RED;
  
  initNode(&node50, &node30, &node70, rootColour);
  initNode(&node30, NULL, NULL, leftChildColour);
  initNode(&node70, NULL, NULL, rightChildColour);
  
  TEST_ASSERT_EQUAL(&node30, node50.left);
  TEST_ASSERT_EQUAL(&node70, node50.right);
  TEST_ASSERT_EQUAL(rootColour, node50.colour);
  TEST_ASSERT_EQUAL(50, node50.value);
  TEST_ASSERT_EQUAL(NULL, node50.left->left);
  TEST_ASSERT_EQUAL(NULL, node50.left->right);
  TEST_ASSERT_EQUAL(leftChildColour, node50.left->colour);
  TEST_ASSERT_EQUAL(30, node50.left->value);
  TEST_ASSERT_EQUAL(NULL, node50.right->left);
  TEST_ASSERT_EQUAL(NULL, node50.right->right);
  TEST_ASSERT_EQUAL(rightChildColour, node50.right->colour);
  TEST_ASSERT_EQUAL(70, node50.right->value);
}


