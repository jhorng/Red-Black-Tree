#include "unity.h"
#include "Rotation.h"
#include "Node.h"

//Creating global variables
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

/*
 *   Left rotation->fail rotated due to absence of nodes.
 *
 *        10                  10
 *       /  \      --->      /  \
 *     NULL NULL           NULL NULL
 */
void test_left_rotation_with_root_only_should_do_nothing(void){
  Node *root = &node10;
  initNode(&node10, NULL, NULL, BLACK);
  
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
  Node *root = &node20;
  Node *left = &node10;
  
  initNode(&node20, &node10, NULL, BLACK);
  initNode(&node10, NULL, NULL, RED);
  
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
  Node *root = &node10;
  Node *right = &node20;
  
  initNode(&node10, NULL, &node20, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
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
  Node *root = &node10;
  Node *right = &node20;
  
  initNode(&node10, NULL, &node20, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
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
  Node *root = &node20;
  Node *left = &node10;
  
  initNode(&node20, &node10, NULL, BLACK);
  initNode(&node10, NULL, NULL, RED);
  
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
  Node *root = &node50;
  Node *childLeft = &node30;
  Node *childRight = &node70;
  Node *grandChildRight = &node40;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, &node40, RED);
  initNode(&node70, NULL, NULL, RED);
  initNode(&node40, NULL, NULL, BLACK);
  
  rotateLeftRight(&root);
  
  TEST_ASSERT_EQUAL(40, root->value);
  TEST_ASSERT_EQUAL(50, root->right->value);
  TEST_ASSERT_EQUAL(30, root->left->value);
  TEST_ASSERT_EQUAL(70, root->right->right->value);
}

/*
 *   Right left rotation->success
 *
 *        50                40
 *       /  \     --->     /  \
 *     30   70           50   70
 *         /            /
 *       40            30
 *
 *
 */
void test_rotateRightLeft_should_rotate_tree_to_correct_position(void){
  Node *root = &node50;
  Node *childLeft = &node30;
  Node *childRight = &node70;
  Node *grandChildRight = &node40;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, RED);
  initNode(&node70, &node40, NULL, RED);
  initNode(&node40, NULL, NULL, BLACK);
  
  rotateRightLeft(&root);
  
  TEST_ASSERT_EQUAL(40, root->value);
  TEST_ASSERT_EQUAL(50, root->left->value);
  TEST_ASSERT_EQUAL(70, root->right->value);
  TEST_ASSERT_EQUAL(30, root->left->left->value);
}