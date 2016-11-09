#include "unity.h"
#include "Node.h"

void setUp(void){}

void tearDown(void){}

void test_a_new_node_is_initialized(void){
  int colour, value;
  
  Node *newNode = initializeNode(NULL, NULL, colour, value);
  
  TEST_ASSERT_EQUAL(NULL, newNode->left);
  TEST_ASSERT_EQUAL(NULL, newNode->right);
  TEST_ASSERT_EQUAL(colour, newNode->colour);
  TEST_ASSERT_EQUAL(value, newNode->value);
}

void test_a_new_node_is_added_as_left_child_of_a_root_node(void){
  int rootColour=1, rootValue=10;
  int leftChildColour=2, leftChildValue=6;
  
  Node *root = initializeNode(NULL, NULL, rootColour, rootValue);
  Node *leftChild = initializeNode(NULL, NULL, leftChildColour, leftChildValue);
  addNode(root, leftChild);
  
  TEST_ASSERT_EQUAL(leftChild, root->left);
  TEST_ASSERT_EQUAL(NULL, root->right);
  TEST_ASSERT_EQUAL(rootColour, root->colour);
  TEST_ASSERT_EQUAL(rootValue, root->value);
  TEST_ASSERT_EQUAL(NULL, root->left->left);
  TEST_ASSERT_EQUAL(NULL, root->left->right);
  TEST_ASSERT_EQUAL(leftChildColour, root->left->colour);
  TEST_ASSERT_EQUAL(leftChildValue, root->left->value);
}

void test_a_new_node_is_added_as_right_child_of_a_root_node(void){
  int rootColour=1, rootValue=10;
  int rightChildColour=2, rightChildValue=12;
  
  Node *root = initializeNode(NULL, NULL, rootColour, rootValue);
  Node *rightChild = initializeNode(NULL, NULL, rightChildColour, rightChildValue);
  addNode(root, rightChild);
  
  TEST_ASSERT_EQUAL(NULL, root->left);
  TEST_ASSERT_EQUAL(rightChild, root->right);
  TEST_ASSERT_EQUAL(rootColour, root->colour);
  TEST_ASSERT_EQUAL(rootValue, root->value);
  TEST_ASSERT_EQUAL(NULL, root->right->left);
  TEST_ASSERT_EQUAL(NULL, root->right->right);
  TEST_ASSERT_EQUAL(rightChildColour, root->right->colour);
  TEST_ASSERT_EQUAL(rightChildValue, root->right->value);
}

void test_two_new_node_is_added_as_left_and_right_child_of_a_root_node(void){
  int rootColour=1, rootValue=50;
  int leftChildColour=2, leftChildValue=25;
  int rightChildColour=2, rightChildValue=75;
  
  Node *root = initializeNode(NULL, NULL, rootColour, rootValue);
  Node *leftChild = initializeNode(NULL, NULL, leftChildColour, leftChildValue);
  Node *rightChild = initializeNode(NULL, NULL, rightChildColour, rightChildValue);
  
  addNode(root, leftChild);
  addNode(root, rightChild);
  
  TEST_ASSERT_EQUAL(leftChild, root->left);
  TEST_ASSERT_EQUAL(rightChild, root->right);
  TEST_ASSERT_EQUAL(rootColour, root->colour);
  TEST_ASSERT_EQUAL(rootValue, root->value);
  TEST_ASSERT_EQUAL(NULL, root->left->left);
  TEST_ASSERT_EQUAL(NULL, root->left->right);
  TEST_ASSERT_EQUAL(leftChildColour, root->left->colour);
  TEST_ASSERT_EQUAL(leftChildValue, root->left->value);
  TEST_ASSERT_EQUAL(NULL, root->right->left);
  TEST_ASSERT_EQUAL(NULL, root->right->right);
  TEST_ASSERT_EQUAL(rightChildColour, root->right->colour);
  TEST_ASSERT_EQUAL(rightChildValue, root->right->value);
}


