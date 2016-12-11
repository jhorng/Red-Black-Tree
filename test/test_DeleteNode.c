#include "unity.h"
#include "DeleteNode.h"
#include "CustomAssertion.h"
#include "Node.h"
#include "Rotation.h"

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

/*
 *    60(B)   add 80(R)   60(B)    remove 80    60(B)
 *    /  \   --------->   /  \    --------->    /  \\
 * NULL NULL           NULL 80(R)             NULL 80(B)
 *
 *
 */
void test_remove_node80_after_added_to_node60(void){
  ReturnedObject ro;
  
  Node *root = &node60;
  
  initNode(&node60, NULL, NULL, BLACK);
  
  rbtAdd(&root, &node80);
  
  CTEST_ASSERT_EQUAL_NODE(&node60, NULL, &node80, BLACK, 60);
  CTEST_ASSERT_EQUAL_NODE(&node80, NULL, NULL, RED, 80);
  
  ro = rbtRemoveNode(&node80);
  
  TEST_ASSERT_EQUAL_PTR(&node80, ro.removedNode);
  TEST_ASSERT_EQUAL(DOUBLE_BLACK, ro.returnedColour);
  CTEST_ASSERT_EQUAL_NODE(&node60, NULL, &node80, BLACK, 60);
  CTEST_ASSERT_EQUAL_NODE(&node80, NULL, NULL, DOUBLE_BLACK, 80);
}

/*
 * case 1a.1 - node40 will be removed and rotate left at node70.
 *
 *
 *         120(B)                       120(B)
 *        /     \       rotate left    /    \
 *     70(R)    130(R)  ---------->  90(R) 130(R)
 *    //   \                        /   \
 *  40(B)  90(B)                  70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void test_remove_node40_will_perform_caseOneAOne_with_parent_is_red(void){
  Node *root = &node120;
  ReturnedObject ro;
  
  initNode(&node120, &node70, &node130, BLACK);
  initNode(&node70, &node40, &node90, RED);
  initNode(&node130, NULL, NULL, RED);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  ro = rbtRemoveNode(&node40);
  caseOneAOne(&(root->left));
  
  CTEST_ASSERT_EQUAL_NODE(&node120, &node90, &node130, BLACK, 120);
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, RED, 90);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, RED, 130);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/*
 * case 1a.2 - node40 will be removed and rotate left at node70.
 *
 *
 *         120(B)                       120(B)
 *        /     \       rotate left    /    \
 *     70(B)    130(R)  ---------->  90(B) 130(R)
 *    //   \                        /   \
 *  40(B)  90(B)                  70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void test_remove_node40_will_perform_caseOneATwo_with_left_parent_is_black(void){
  Node *root = &node120;
  ReturnedObject ro;
  
  initNode(&node120, &node70, &node130, BLACK);
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node130, NULL, NULL, RED);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  ro = rbtRemoveNode(&node40);
  caseOneA(&(root->left));
  
  CTEST_ASSERT_EQUAL_NODE(&node120, &node90, &node130, BLACK, 120);
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, RED, 130);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/*
 * case 1b.1 - node40 will be removed and rotate right at node90
 *             then rotate left at node70.
 *
 *
 *         120(B)                        120(B)                       120(B)
 *        /     \       rotate right    /    \      rotate left      /    \
 *     70(R)    130(R)  -----------> 70(R) 130(R)  ----------->    80(R) 130(R)
 *    //   \             at node90   //  \          at node70     /   \
 *  40(B)  90(B)                   40(B) 80(R)                 70(B) 90(B)
 *         /                              \
 *       80(R)                            90(B)
 *
 */
void test_remove_node40_will_perform_caseOneBOne_with_left_parent_is_red(void){
  Node *root = &node120;
  ReturnedObject ro;
  
  initNode(&node120, &node70, &node130, BLACK);
  initNode(&node70, &node40, &node90, RED);
  initNode(&node130, NULL, NULL, RED);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  ro = rbtRemoveNode(&node40);
  caseOneBOne(&(root->left));
  
  CTEST_ASSERT_EQUAL_NODE(&node120, &node80, &node130, BLACK, 120);
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, RED, 130);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/*
 * case 1b.2 - node40 will be removed and rotate right at node90
 *             then rotate left at node70.
 *
 *
 *         120(B)                        120(B)                       120(B)
 *        /     \       rotate right    /    \      rotate left      /    \
 *     70(B)    130(R)  -----------> 70(B) 130(R)  ----------->    80(B) 130(R)
 *    //   \             at node90   //  \          at node70     /   \
 *  40(B)  90(B)                   40(B) 80(R)                 70(B) 90(B)
 *         /                              \
 *       80(R)                            90(B)
 *
 */
void test_remove_node40_will_perform_caseOneBTwo_with_left_parent_is_black(void){
  Node *root = &node120;
  ReturnedObject ro;
  
  initNode(&node120, &node70, &node130, BLACK);
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node130, NULL, NULL, RED);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  ro = rbtRemoveNode(&node40);
  caseOneBTwo(&(root->left));
  
  CTEST_ASSERT_EQUAL_NODE(&node120, &node80, &node130, BLACK, 120);
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, RED, 130);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 *    case 2a(1)
 *    
 *          80(B)                      80(B)
 *         /    \                     //   \
 *       20(B)   -  flip colour     20(B)   -
 *      //  \      ----------->    /    \
 *    10(B) 50(B)               10(B)  50(R)
 *          /  \                       /  \
 *       30(B)70(B)                 30(B) 70(B)
 *
 *
 *
 */
void test_case2A1_given_parent_siblingRight_leftChildLeft_and_leftChildRight_are_black_with_siblingLeft_is_double_black_will_flip_colour(void){
  Node *root = &node80;
  ReturnedObject ro;
  
  initNode(&node80, &node20, NULL, BLACK);
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  ro = rbtRemoveNode(&node10);
  caseTwoAOne(&(root->left));
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node20, NULL, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    case 2a(2)
 *    
 *          80(B)                      80(B)
 *         /    \                     //   \
 *       20(B)   -  flip colour     20(B)   -
 *      //  \      ----------->    /    \
 *    10(B) 50(B)               10(B)  50(R)
 *
 *
 *
 */
void test_case2A2_given_siblingRight_is_black_and_both_siblingRight_children_are_null_with_the_parent_being_black(void){
  Node *root = &node80;
  ReturnedObject ro;
  
  initNode(&node80, &node20, NULL, BLACK);
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  ro = rbtRemoveNode(&node10);
  caseTwoATwo(&(root->left));
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node20, NULL, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    case 2b(1)
 *    
 *          80(B)                      80(B)
 *         /    \                     /    \
 *       20(R)   -  flip colour     20(B)   -
 *      //  \      ----------->    /    \
 *    10(B) 50(B)               10(B)  50(R)
 *          /  \                       /  \
 *       30(B)70(B)                 30(B) 70(B)
 *
 *
 *
 */
void test_case2B1_given_the_sblingRight_is_black_and_both_children_of_siblingRight_are_black(void){
  Node *root = &node80;
  ReturnedObject ro;
  
  initNode(&node80, &node20, NULL, BLACK);
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  ro = rbtRemoveNode(&node10);
  caseTwoBOne(&(root->left));
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node20, NULL, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    case 2b(2)
 *    
 *          80(B)                      80(B)
 *         /    \                     /    \
 *       20(R)   -  flip colour     20(B)   -
 *      //  \      ----------->    /    \
 *    10(B) 50(B)               10(B)  50(R)
 *
 *
 *
 */
void test_case2B2_given_siblingRight_is_black_and_both_siblingRight_children_are_null_with_the_parent_being_red(void){
  Node *root = &node80;
  ReturnedObject ro;
  
  initNode(&node80, &node20, NULL, BLACK);
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  ro = rbtRemoveNode(&node10);
  caseTwoBTwo(&(root->left));
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node20, NULL, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}