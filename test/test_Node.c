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

/**
 *
 *          30(B)           node10        30(B)
 *         /    \         --------->     /    \
 *      NULL(B) NULL(B)               10(R)  NULL(B)
 *
 */
void test_node10_is_added_to_the_left_of_the_tree_when_left_is_null(void){
  Node *root = &node30;
  
  initNode(&node30, NULL, NULL, BLACK);
  
  rbtAdd(&root, &node10);
  
  CTEST_ASSERT_EQUAL_NODE(&node30, &node10, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
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
  
  rbtAdd(&root, &node30);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node30, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/*
 *   case 1.1
 *
 *         50(B)         add 40(R)        50(R)
 *       /     \       ----------->      /    \
 *     30(R)   70(R)                  30(B)  70(B)
 *                                       \
 *                                       40(R) 
 *
 */
void test_caseOnePointOne_with_a_node_added_to_the_tree_as_leftGrandRightChild_will_recolour_the_nodes(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, RED);
  initNode(&node70, NULL, NULL, RED);
  
  rbtAdd(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, &node40, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, RED, 40);
}

/*
 *   case 1.1
 *
 *         50(B)         add 20(R)        50(R)
 *       /     \       ----------->      /    \
 *     30(R)   70(R)    recolour       30(B)  70(B)
 *                                     /
 *                                  20(R) 
 *
 */
void test_caseOnePointOne_with_a_node_added_to_the_tree_as_leftGrandLeftChild_will_recolour_the_nodes(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, RED);
  initNode(&node70, NULL, NULL, RED);
  
  rbtAdd(&root, &node20);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, RED, 20);
}

/*
 *   case 1.2
 *
 *         60(B)         add 70(R)        60(R)
 *       /     \       ----------->      /    \
 *     40(R)   80(R)     recolour     40(B)  80(B)
 *                                           /
 *                                         70(R) 
 *
 */
void test_caseOnePointTwo_with_a_node_added_to_the_tree_at_right_of_rightGrandLeftChild_will_recolour_the_nodes(void){
  Node *root = &node60;
  
  initNode(&node60, &node40, &node80, BLACK);
  initNode(&node40, NULL, NULL, RED);
  initNode(&node80, NULL, NULL, RED);
  
  rbtAdd(&root, &node70);
  
  CTEST_ASSERT_EQUAL_NODE(&node60, &node40, &node80, RED, 60);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, NULL, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, RED, 70);
}

/*
 *   case 1.2
 *
 *         60(B)         add 90(R)        60(R)
 *       /     \       ----------->      /    \
 *     40(R)   80(R)     recolour     40(B)  80(B)
 *                                             \
 *                                             90(R) 
 *
 */
void test_caseOnePointTwo_with_a_node_added_to_the_tree_at_right_of_rightGrandRightChild_will_recolour_the_nodes(void){
  Node *root = &node60;
  
  initNode(&node60, &node40, &node80, BLACK);
  initNode(&node40, NULL, NULL, RED);
  initNode(&node80, NULL, NULL, RED);
  
  rbtAdd(&root, &node90);
  
  CTEST_ASSERT_EQUAL_NODE(&node60, &node40, &node80, RED, 60);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node80, NULL, &node90, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, RED, 90);
}

/*
 *   case 1 - non-stop recolour
 *
 *              90(B)            add 10(R)                90(B)
 *            /      \          -----------> ...        /     \
 *          50(R)    120(R)      recolour            50(B)    120(B)
 *         /   \    /     \                         /   \    /     \
 *      30(B) 70(B)110(B) 130(B)                30(R) 70(B)110(B) 130(B)
 *      /   \                                  /   \
 *    20(R)40(R)                            20(B)40(B)
 *                                           /
 *                                        10(R)
 *
 */
void test_node10_added_at_the_left_most_as_red_will_recolour_again_and_again_till_the_main_root_but_the_colour_of_root_unchange(void){
  Node *root = &node90;
  
  initNode(&node90, &node50, &node120, BLACK);
  initNode(&node50, &node30, &node70, RED);
  initNode(&node120, &node110, &node130, RED);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  initNode(&node110, NULL, NULL, BLACK);
  initNode(&node130, NULL, NULL, BLACK);
  initNode(&node20, NULL, NULL, RED);
  initNode(&node40, NULL, NULL, RED);
  
  rbtAdd(&root, &node10);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node50, &node120, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node120, &node110, &node130, BLACK, 120);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node110, NULL, NULL, BLACK, 110);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, BLACK, 130);
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
}

/*    case 2.1
 *
 *          30(B)   left-rotate   30(B)
 *         /       --------->     / 
 *      10(R)                   20(R)
 *        \                     /
 *       20(R)               10(R)
 *
 */
void test_caseTwoPointOne_with_a_node_added_to_the_tree_as_leftGrandRightChild_will_rotate_left_with_uncle_is_null(void){
  Node *root = &node30;
  
  initNode(&node30, &node10, NULL, BLACK);
  initNode(&node10, NULL, &node20, RED);
  initNode(&node20, NULL, NULL, RED);
  
  caseTwoPointOne(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, NULL, RED, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
}

/*    case 2.1
 *
 *          30(B)     left-rotate     30(B)
 *         /    \    ------------>    /   \
 *      10(R) 40(B)               20(R) 40(B)
 *        \                        /
 *       20(R)                 10(R)
 *
 */
void test_caseTwoPointOne_with_a_node_added_to_the_tree_as_leftGrandRightChild_will_rotate_left_will_uncle_is_node40(void){
  Node *root = &node30;
  
  initNode(&node30, &node10, &node40, BLACK);
  initNode(&node10, NULL, &node20, RED);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  caseTwoPointOne(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, NULL, RED, 20);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
}

/*    case 2.2
 *
 *      100(B)     right-rotate   100(B)
 *          \      ------------>      \
 *         130(R)                   110(R)
 *          /                          \
 *        110(R)                        130(R)
 *
 */
void test_caseTwoPointTwo_with_a_node_added_to_the_tree_as_rightGrandLeftChild_will_rotate_right_with_uncle_is_null(void){
  Node *root = &node100;
  
  initNode(&node100, NULL, &node130, BLACK);
  initNode(&node130, &node110, NULL, RED);
  initNode(&node110, NULL, NULL, RED);
  
  caseTwoPointTwo(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, &node110, BLACK, 100);
  CTEST_ASSERT_EQUAL_NODE(&node110, NULL, &node130, RED, 110);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, RED, 130);
}

/*    case 2.2
 *
 *      100(B)     right-rotate   100(B)
 *      /    \    ------------>   /    \
 *   80(B)  130(R)              80(B) 110(R)
 *          /                            \
 *       110(R)                         130(R)
 *
 */
void test_caseTwoPointTwo_with_a_node_added_to_the_tree_as_rightGrandLeftChild_will_rotate_right_with_uncle_is_node80(void){
  Node *root = &node100;
  
  initNode(&node100, &node80, &node130, BLACK);
  initNode(&node80, NULL, NULL, BLACK);
  initNode(&node130, &node110, NULL, RED);
  initNode(&node110, NULL, NULL, RED);
  
  caseTwoPointTwo(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node100, &node80, &node110, BLACK, 100);
  CTEST_ASSERT_EQUAL_NODE(&node80, NULL, NULL, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node110, NULL, &node130, RED, 110);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, RED, 130);
}

/*    case 3.1
 *
 *          80(B)   right-rotate       50(B)
 *         /      ------------>      /    \
 *      50(R)                     30(R)  80(R)
 *      /                     
 *   30(R)              
 *
 */
void test_caseThreePointOne_with_a_node_added_to_the_tree_as_leftGrandLeftChild_will_rotate_right_with_uncle_as_null(void){
  Node *root = &node80;
  
  initNode(&node80, &node50, NULL, BLACK);
  initNode(&node50, &node30, NULL, RED);
  initNode(&node30, NULL, NULL, RED);
  
  caseThreePointOne(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node80, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node80, NULL, NULL, RED, 80);
}

/*    case 3.1
 *
 *          80(B)      right-rotate     50(B)
 *         /    \     ------------>    /    \
 *      50(R) 100(B)                30(R)  80(R)
 *       /                                    \
 *    30(R)                                  100(B)
 *
 */
void test_caseThreePointOne_with_a_node_added_to_the_tree_as_leftGrandLeftChild_will_rotate_right_with_uncle_is_node100(void){
  Node *root = &node80;
  
  initNode(&node80, &node50, &node100, BLACK);
  initNode(&node50, &node30, NULL, RED);
  initNode(&node100, NULL, NULL, BLACK);
  initNode(&node30, NULL, NULL, RED);
  
  caseThreePointOne(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node80, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node80, NULL, &node100, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/*    case 3.2
 *
 *       80(B)    left-rotate       100(B)
 *          \     ------------>    /    \ 
 *         100(R)                80(R)  120(R)
 *            \                     
 *            120(R)              
 *
 */
void test_caseThreePointTwo_with_a_node_added_to_the_tree_as_rightGrandRightChild_will_rotate_left_with_uncle_as_null(void){
  Node *root = &node80;
  
  initNode(&node80, NULL, &node100, BLACK);
  initNode(&node100, NULL, &node120, RED);
  initNode(&node120, NULL, NULL, RED);
  
  caseThreePointTwo(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node100, &node80, &node120, BLACK, 100);
  CTEST_ASSERT_EQUAL_NODE(&node80, NULL, NULL, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node120, NULL, NULL, RED, 120);
}

/*    case 3.2
 *
 *          80(B)      left-rotate      100(B)
 *         /    \     ------------>    /    \
 *      50(B) 100(R)                80(R)  130(R)
 *               \                  /
 *              130(R)            50(B)
 *
 */
 void test_caseThreePointTwo_with_a_node_added_to_the_tree_as_rightGrandRightChild_will_rotate_left_with_uncle_as_node(void){
  Node *root = &node80;
  
  initNode(&node80, &node50, &node100, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  initNode(&node100, NULL, &node130, RED);
  initNode(&node130, NULL, NULL, RED);
  
  caseThreePointTwo(root);
  
  CTEST_ASSERT_EQUAL_NODE(&node100, &node80, &node130, BLACK, 100);
  CTEST_ASSERT_EQUAL_NODE(&node80, &node50, NULL, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, RED, 130);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, BLACK, 50);
}

/*  case 2 + case 3
 *  
 *        90(B)                      90(B)                          70(B)
 *       /    \       add 70(R)     /    \    1. right-rotate      /    \
 *    50(R) 120(B)   -------->   50(R) 120(B) --------------->  50(R)  90(R)
 *                                 \          2. left-rotate             \
 *                                70(R)                                 120(B)
 *
 */
void test_node70_as_leftGrandRightChild_with_uncle_is_black_will_perform_case2_and_case3(void){
  Node *root = &node90;
  
  initNode(&node90, &node50, &node120, BLACK);
  initNode(&node50, NULL, NULL, RED);
  initNode(&node120, NULL, NULL, BLACK);
  
  rbtAdd(&root, &node70);
  
  CTEST_ASSERT_EQUAL_NODE(&node70, &node50, &node90, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, &node120, RED, 90);
  CTEST_ASSERT_EQUAL_NODE(&node120, NULL, NULL, BLACK, 120);
}