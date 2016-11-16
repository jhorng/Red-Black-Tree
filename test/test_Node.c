#include "unity.h"
#include "Node.h"
#include "CustomAssertion.h"
#include "Rotation.h"

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
 *          10(B)
 *         /    \
 *      NULL(B) NULL(B)
 *
 ******************************/
void test_a_new_node_is_initialized(void){
  initNode(&node10, NULL, NULL, BLACK);
  
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
}

/****************************************************
 *
 *          20(B)        add 30(R)        20(B)
 *         /    \       --------->       /    \
 *       10(R) NULL(B)                10(R)  30(R)
 *
 ****************************************************/
void test_a_new_node_is_added_as_left_child_of_a_root_node(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, NULL, BLACK);
  initNode(&node10, NULL, NULL, RED);
  
  addNode(&node20, &node30);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node30, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/*
 *   case 1
 *
 *         50(B)         add 40(R)        50(R)
 *       /     \       ----------->      /    \
 *     30(R)   70(R)                  30(B)  70(B)
 *                                       \
 *                                       40(R) 
 *
 */
void test_caseOne_with_a_node_added_to_the_tree_will_recolour_the_nodes(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, RED);
  initNode(&node70, NULL, NULL, RED);
  
  addNode(root->left, &node40);
  caseOne(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, &node40, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, RED, 40);
}

/*    case 2
 *
 *          20(B)   add 30(R)     20(B)   left-rotate       20(B)
 *         /       --------->     /      ------------>      /
 *      10(R)                   10(R)                     30(R)
 *                                \                       /
 *                                30(R)                 10(R)
 *
 */
void test_caseTwo_with_a_node_added_to_the_tree_will_rotate_left(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, NULL, BLACK);
  initNode(&node10, NULL, NULL, RED);
  
  addNode(&node10, &node30);
  caseTwo(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node30, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node10, NULL, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
}
