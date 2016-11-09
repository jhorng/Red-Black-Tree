#include "unity.h"
#include "Rotation.h"
#include "Node.h"

//Creating global variables
Node *node10, *node20, *node30, *node40, *node50;
Node *node60, *node70, *node80, *node90, *node100;
Node *node110, *node120, *node130, *node140, *node150;

void setUp(void){
  node10 = initializeNode(BLACK, 10);
  node20 = initializeNode(BLACK, 20);
  node30 = initializeNode(BLACK, 30);
  node40 = initializeNode(BLACK, 40);
  node50 = initializeNode(BLACK, 50);
  node60 = initializeNode(BLACK, 60);
  node70 = initializeNode(BLACK, 70);
  node80 = initializeNode(BLACK, 80);
  node90 = initializeNode(BLACK, 90);
  node100 = initializeNode(BLACK, 100);
  node110 = initializeNode(BLACK, 110);
  node120 = initializeNode(BLACK, 120);
  node130 = initializeNode(BLACK, 130);
  node140 = initializeNode(BLACK, 140);
  node150 = initializeNode(BLACK, 150);
  
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

/*
 *   Left right rotation->success
 *
 *        50                40
 *       /  \     --->     /  \
 *     30   70           30   50
 *       \                     \
 *       40                    70 
 */
void test_rotateLeftRight_should_rotate_tree_to_correct_position(void){
  Node *root = node50;
  Node *childLeft = node30;
  Node *childRight = node70;
  Node *grandChildRight = node40;
  
  addNode(root, childLeft);
  addNode(root, childRight);
  addNode(childLeft, grandChildRight);
  
  rotateLeftRight(&root);
  
  TEST_ASSERT_EQUAL(40, root->value);
  TEST_ASSERT_EQUAL(50, root->right->value);
  TEST_ASSERT_EQUAL(30, root->left->value);
  TEST_ASSERT_EQUAL(70, root->right->right->value);
}

/*
 *   Right left rotation->success
 *
 *        50                70
 *       /  \     --->     /
 *     30   70           50
 *       \               /
 *       40            30 
 *                      \
 *                      40
 */
void test_rotateRightLeft_should_rotate_tree_to_correct_position(void){
  Node *root = node50;
  Node *childLeft = node30;
  Node *childRight = node70;
  Node *grandChildRight = node40;
  
  addNode(root, childLeft);
  addNode(root, childRight);
  addNode(childLeft, grandChildRight);
  
  rotateRightLeft(&root);
  
  TEST_ASSERT_EQUAL(70, root->value);
  TEST_ASSERT_EQUAL(50, root->left->value);
  TEST_ASSERT_EQUAL(30, root->left->left->value);
  TEST_ASSERT_EQUAL(40, root->left->left->right->value);
}