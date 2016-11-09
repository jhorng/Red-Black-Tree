#include "unity.h"
#include "Rotation.h"
#include "Node.h"

//Creating global variables
Node *node10, *node20, *node30, *node40, *node50;
Node *node60, *node70, *node80, *node90, *node100;
Node *node110, *node120, *node130, *node140, *node150;

// Reset the global variable nodes

void refreshNode(Node *node, int value){
  node->left = NULL;
  node->right = NULL;
  node->colour = 0;
  node->value = value;
}

void setUp(void){
  node10 = initializeNode(NULL, NULL, BLACK, 10);
  node20 = initializeNode(NULL, NULL, BLACK, 20);
  node30 = initializeNode(NULL, NULL, BLACK, 30);
  node40 = initializeNode(NULL, NULL, BLACK, 40);
  node50 = initializeNode(NULL, NULL, BLACK, 50);
  node60 = initializeNode(NULL, NULL, BLACK, 60);
  node70 = initializeNode(NULL, NULL, BLACK, 70);
  node80 = initializeNode(NULL, NULL, BLACK, 80);
  node90 = initializeNode(NULL, NULL, BLACK, 90);
  node100 = initializeNode(NULL, NULL, BLACK, 100);
  node110 = initializeNode(NULL, NULL, BLACK, 110);
  node120 = initializeNode(NULL, NULL, BLACK, 120);
  node130 = initializeNode(NULL, NULL, BLACK, 130);
  node140 = initializeNode(NULL, NULL, BLACK, 140);
  node150 = initializeNode(NULL, NULL, BLACK, 150);
  
}

void tearDown(void){}

/*
 *   Left rotation->fail rotated due to absence of nodes.
 *
 *        10                  10
 *       /  \      --->      /  \
 *     NULL NULL           NULL NULL
 */
void test_left_rotation_with_root_only_should_do_nothing(void){
  Node *root = node10;
  rotateLeft(&root);
  
  TEST_ASSERT_EQUAL(10, root->value);
}

/*
 *   Left rotation->fail rotated due to absence of right node.
 *
 *        20                20
 *       /  \     --->     /  \
 *     10  NULL          10  NULL
 */
void test_left_rotation_with_a_left_node_linked_to_the_root_should_do_nothing(void){
  Node *root = node20;
  Node *left = node10;
  
  addNode(root, left);
  rotateLeft(&root);
  
  TEST_ASSERT_EQUAL(20, root->value);
  TEST_ASSERT_EQUAL(10, root->left->value);
  
}

/* *   Left rotation->success
 *
 *        10                  20
 *       /  \      --->      /  \
 *    NULL  20             10  NULL   
 */
void test_left_rotation_with_right_node_linked_to_the_root_should_rotate(void){
  Node *root = node10;
  Node *right = node20;
  
  addNode(root, right);
  rotateLeft(&root);
  
  TEST_ASSERT_EQUAL(20, root->value);
  TEST_ASSERT_EQUAL(10, root->left->value);
}

/*
 *   Right rotation->fail rotated due to absence of left
 *
 *        10                  10
 *       /  \      --->      /  \
 *    NULL  20             NULL  20   
 */
void test_right_rotation_with_a_right_node_linked_to_the_root_should_do_nothing(void){
  Node *root = node10;
  Node *right = node20;
  
  addNode(root, right);
  rotateRight(&root);
  
  TEST_ASSERT_EQUAL(10, root->value);
  TEST_ASSERT_EQUAL(20, root->right->value);
  
}

/*
 *   Right rotation->success
 *
 *        20                10
 *       /  \     --->     /  \
 *     10  NULL         NULL  20
 */
void test_right_rotation_with_a_left_node_linked_to_the_root_should_rotate(void){
  Node *root = node20;
  Node *left = node10;
  
  addNode(root, left);
  rotateRight(&root);
  
  TEST_ASSERT_EQUAL(10, root->value);
  TEST_ASSERT_EQUAL(20, root->right->value);
  
}
