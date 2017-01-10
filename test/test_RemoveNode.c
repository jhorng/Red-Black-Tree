#include "unity.h"
#include "RemoveNode.h"
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

/**
 * caseLeft 1a(1) - node40 will be removed and rotate left at node70.
 *
 *
 *        /    rotate left    /  
 *     70(R)   ---------->  90(R)
 *    //   \               /   \
 *  40(B)  90(B)        70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void test_remove_node40_will_perform_caseLeftOneAOne_with_parent_is_red(void){
  Node *root = &node70;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, NULL, NULL, DOUBLE_BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  caseLeftOneAOne(&root, retObj, 40);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, RED, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/**
 * caseLeft 1a(1) - node40 will be removed and rotate left at node70.
 *
 *
 *        /   rotate left    /
 *     70(R)  ---------->  90(R)
 *    //   \              /   \
 *    -  90(B)          70(B)100(B)
 *          \                         
 *         100(R)                   
 *
 */
void test_removed_node40_as_null_will_perform_caseLeftOneAOne_with_parent_is_red(void){
  Node *root = &node70;
  Node *removedNode = &node40;
  ReturnedObject retObj;
  
  initNode(&node70, NULL, &node90, RED);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(removedNode);
  caseLeftOneAOne(&root, retObj, 40);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, RED, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/**
 * caseLeft 1a(2) - node40 will be removed and rotate left at node70.
 *
 *
 *        /       rotate left    /
 *     70(B)      ---------->  90(B)
 *    //   \                  /   \
 *  40(B)  90(B)            70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void test_remove_node40_will_perform_caseLeftOneATwo_with_left_parent_is_black(void){
  Node *root = &node70;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, NULL, DOUBLE_BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  caseLeftOneATwo(&root, retObj, 40);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/**
 * caseLeft 1a(2) - double black null at left node70 and rotate left at node70.
 *
 *
 *        /     rotate left    / 
 *     70(B)    ---------->  90(B)
 *    //   \                /   \
 *    -  90(B)            70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void test_double_black_is_null_at_left_black_node70_with_rotate_left_at_node70(void){
  Node *root = &node70;
  Node *removedNode = &node40;
  ReturnedObject retObj;
  
  initNode(&node70, NULL, &node90, BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node40);
  caseLeftOneATwo(&root, retObj, 40);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/**
 * caseLeft 1b(1) - node40 will be removed and rotate right at node90
 *             then rotate left at node70.
 *
 *
 *        /      rotate right    /    rotate left     /   
 *     70(R)     -----------> 70(R)   ----------->  80(R) 
 *    //   \     at node90   //  \    at node70    /   \
 *  40(B)  90(B)           40(B) 80(R)           70(B) 90(B)
 *         /                      \
 *       80(R)                    90(B)
 *
 */
void test_remove_node40_will_perform_caseLeftOneBOne_with_left_parent_is_red(void){
  Node *root = &node70;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, NULL, NULL, DOUBLE_BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  caseLeftOneBOne(&root, retObj, 40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 * caseLeft 1b(1) - node40 will be removed and rotate right at node90
 *             then rotate left at node70.
 *
 *
 *        /    rotate right    /    rotate left      /  
 *     70(R)   -----------> 70(R)   ----------->   80(R)
 *    //   \   at node90   //  \    at node70     /   \
 *    -  90(B)             -  80(R)             70(B) 90(B)
 *         /                    \
 *       80(R)                 90(B)
 *
 */
void test_left_double_black_child_of_red_node70_is_null_will_do_double_rotation(void){
  Node *root = &node70;
  Node *removedNode = &node40;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node40);
  caseLeftOneBOne(&root, retObj, 40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 * caseLeft 1b(2) - node40 will be removed and rotate right at node90
 *             then rotate left at node70.
 *
 *
 *        /     rotate right    /     rotate left      / 
 *     70(B)    -----------> 70(B)    ----------->   80(B)
 *    //   \    at node90   //  \     at node70     /   \
 *  40(B)  90(B)          40(B) 80(R)             70(B) 90(B)
 *         /                     \
 *       80(R)                   90(B)
 *
 */
void test_remove_node40_will_perform_caseLeftOneBTwo_with_left_parent_is_black(void){
  Node *root = &node70;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, NULL, DOUBLE_BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  caseLeftOneBTwo(&root, retObj, 40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 * caseLeft 1b(2) - node40 changes to null and rotate right at node90
 *             then rotate left at node70.
 *
 *
 *        /     rotate right   /     rotate left      /  
 *     70(B)    -----------> 70(B)   ----------->   80(B) 
 *    //   \    at node90   //  \     at node70     /   \
 *    -  90(B)              -  80(R)              70(B) 90(B)
 *         /                     \
 *       80(R)                   90(B)
 *
 */
void test_double_black_null_will_perform_caseLeftOneBTwo_with_left_parent_is_black(void){
  Node *root = &node70;
  Node *removedNode = &node40;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node40);
  caseLeftOneBTwo(&root, retObj, 40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 *    caseLeft 2a(1) node10 is double black node.
 *    
 *         /                          //   
 *       20(B)      flip colour     20(B)  
 *      //  \      ----------->    /    \
 *    10(B) 50(B)                NULL  50(R)
 *          /  \                       /  \
 *       30(B)70(B)                 30(B) 70(B)
 *
 */
void test_caseLeft2A1_given_parent_siblingRight_leftChildLeft_and_leftChildRight_are_black_with_siblingLeft_is_double_black_will_flip_colour(void){
  Node *root = &node20;
  ReturnedObject retObj;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  caseLeftTwoAOne(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    caseLeft 2a(1) siblingLeft is null and double black. 
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *     NULL 50(B)               NULL  50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 */
void test_siblingLeft_is_null_and_double_black_will_flip_colour_when_parent_siblingRight_leftChildLeft_and_leftChildRight_are_black(void){
  Node *root = &node20;
  Node *removedNode = &node10;
  ReturnedObject retObj;
  
  initNode(&node20, NULL, &node50, BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node10);
  caseLeftTwoAOne(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    caseLeft 2a(2) - siblingLeft(node10) is double black.
 *               - Both child of siblingRight are null.
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    10(B) 50(B)              10(B)  50(R)
 *
 */
void test_caseLeft2A2_given_siblingRight_is_black_and_both_siblingRight_children_are_null_with_the_parent_being_black(void){
  Node *root = &node20;
  ReturnedObject retObj;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  caseLeftTwoATwo(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    caseLeft 2a(2) - siblingLeft(node10) is null and double black.
 *               - both child in siblingRight are null.
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *     null 50(B)               null  50(R)
 *
 */
void test_caseLeft2A2_given_siblingLeft_is_null_and_double_black(void){
  Node *root = &node20;
  Node *removedNode = &node10;
  ReturnedObject retObj;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node10);
  caseLeftTwoATwo(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    caseLeft 2b(1) - siblingLeft(node10) is double black.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               NULL  50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 */
void test_caseLeft2B1_given_the_sblingRight_is_black_and_both_children_of_siblingRight_are_black(void){
  Node *root = &node20;
  ReturnedObject retObj;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  caseLeftTwoBOne(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    caseLeft 2b(1) - siblingLeft(node10) is null and double black.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    null 50(B)                null  50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 */
void test_caseLeft2B1_given_siblingLeft_is_null_and_double_black_sblingRight_is_black_and_both_children_of_siblingRight_are_black(void){
  Node *root = &node20;
  Node *removedNode = &node10;
  ReturnedObject retObj;
  
  initNode(&node20, NULL, &node50, RED);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node10);
  caseLeftTwoBOne(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    caseLeft 2b(2) - siblingLeft(node10) is double black.
 *               - Children of siblingRight are null.
 *    
 *         /                         /   
 *       20(R)     flip colour     20(B)  
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               NULL  50(R)
 *
 */
void test_caseLeft2B2_given_siblingRight_is_black_and_both_siblingRight_children_are_null_with_the_parent_being_red(void){
  Node *root = &node20;
  ReturnedObject retObj;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  caseLeftTwoBTwo(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    caseLeft 2b(2) - siblingLeft(node10) is null and double black.
 *               - Children of siblingRight are null.
 *    
 *         /                         /   
 *       20(R)     flip colour     20(B)  
 *      //  \     ----------->    /    \
 *     null 50(B)               NULL  50(R)
 *
 */
void test_caseLeft2B2_given_siblingLeft_is_null_and_double_black_and_siblingRight_is_black_and_both_siblingRight_children_are_null_with_the_parent_being_red(void){
  Node *root = &node20;
  Node *removedNode = &node10;
  ReturnedObject retObj;
  
  initNode(&node20, NULL, &node50, RED);
  initNode(&node50, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node10);
  caseLeftTwoBTwo(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    caseLeft 3 - siblingLeft(node10) is double black
 *    
 *         /                         /                   /    
 *       20(B)     rotate left     50(B)     caseLeft 2    50(B)  
 *      //  \     ----------->    /   \     ------->  /   \
 *    10(B) 50(R)  at node20   20(R)  70(B)         20(B) 70(B)
 *          /  \              //  \                /   \
 *       30(B)70(B)         10(B) 30(B)           -   30(R)
 *
 */
void test_caseLeft3_given_the_sblingRight_is_red_and_siblingLeft_is_double_black(void){
  Node *root = &node20;
  ReturnedObject retObj;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, &node30, &node70, RED);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  caseLeftThree(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node20, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node30, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/**
 *    caseLeft 3 - siblingLeft(node10) is null and double black
 *    
 *         /                        /                   /    
 *       20(B)     rotate left    50(B)     case 2    50(B)  
 *      //  \     ----------->   /   \     ------->  /   \
 *    null 50(R)  at node20   20(R)  70(B)         20(B) 70(B)
 *          /  \              //  \                /   \
 *       30(B)70(B)         null 30(B)           -   30(R)
 *
 */
void test_caseLeft3_given_siblingLeft_is_null_and_double_black_and_the_sblingRight_is_red_and_siblingLeft_is_double_black(void){
  Node *root = &node20;
  Node *removedNode = &node10;
  ReturnedObject retObj;
  
  initNode(&node20, NULL, &node50, BLACK);
  initNode(&node50, &node30, &node70, RED);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node10);
  caseLeftThree(&root, retObj, 10);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node20, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node30, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/**
 *    "rbtRemove"
 *    caseLeft 1a(1) - node40 will be removed and rotate left at node70.
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
void test_rbtRemove_for_caseLeft1a1(void){
  Node *root = &node120;
  
  initNode(&node120, &node70, &node130, BLACK);
  initNode(&node70, &node40, &node90, RED);
  initNode(&node130, NULL, NULL, RED);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  rbtRemove(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node120, &node90, &node130, BLACK, 120);
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, RED, 90);
  CTEST_ASSERT_EQUAL_NODE(&node130, NULL, NULL, RED, 130);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/**
 *    "rbtRemove"
 *    caseLeft 1a(1) - SiblingLeft(node40) becomes double black null and returns to its parent.
 *                   - ReturnedObject stored node40.
 *
 *
 *        /    rotate left    /    
 *     70(R)   ---------->  90(R)
 *    //   \               /   \
 *    -   90(B)          70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void test_rbtRemove_for_caseLeft1a1_given_the_target_node_has_removed_and_returned(void){
  Node *root = &node70;
  
  initNode(&node70, NULL, &node90, RED);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  rbtRemove(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, RED, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/**
 *    "rbtRemove"
 *    caseLeft 1a(2) - node40 will be removed and rotate left at node70.
 *
 *
 *        /       rotate left    /
 *     70(B)      ---------->  90(B)
 *    //   \                  /   \
 *  40(B)  90(B)            70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void test_rbtRemove_for_caseLeft1a2(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  rbtRemove(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/**
 *    "rbtRemove"
 *    caseLeft 1a(2) - node40 becomes double black null and returns to its parent.
 *                   - ReturnedObject stored node40.
 *
 *
 *        /       rotate left    /
 *     70(B)      ---------->  90(B)
 *    //   \                  /   \
 *    -   90(B)            70(B)100(B)
 *           \                         
 *          100(R)                   
 *
 */
void test_rbtRemove_for_caseLeft1a2_given_the_target_node_has_removed_and_returned(void){
  Node *root = &node70;
  
  initNode(&node70, NULL, &node90, BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  rbtRemove(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}

/**
 *    "rbtRemove"
 *    caseLeft 1b(1) - node40 will be removed.
 *                   - Rotate right at node90, then rotate left at node70.
 *
 *
 *        /       rotate right    /       rotate left      /    
 *     70(R)      -----------> 70(R)      ----------->   80(R) 
 *    //   \      at node90   //  \       at node70     /   \
 *  40(B)  90(B)            40(B) 80(R)               70(B) 90(B)
 *         /                        \
 *       80(R)                      90(B)
 *
 */
void test_rbtRemove_for_caseLeft1b1(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  rbtRemove(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 *    "rbtRemove"
 *    caseLeft 1b(1) - node40 becomes double black null and returns to its parent.
 *                   - Rotate right at node90, then rotate left at node70.
 *
 *
 *        /     rotate right    /      rotate left      /   
 *     70(R)    -----------> 70(R)     ----------->   80(R)
 *    //   \    at node90   //  \      at node70      /   \
 *    -   90(B)             -  80(R)               70(B) 90(B)
 *         /                      \
 *       80(R)                    90(B)
 *
 */
void test_rbtRemove_for_caseLeft1b1_given_the_target_node_has_removed_and_returned(void){
  Node *root = &node70;
  
  initNode(&node70, NULL, &node90, RED);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  rbtRemove(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 *    "rbtRemove"
 *    caseLeft 1b(2) - node40 will be removed.
 *                   - Rotate right at node90, then rotate left at node70.
 *
 *
 *        /     rotate right    /     rotate left      / 
 *     70(B)    -----------> 70(B)    ----------->   80(B)
 *    //   \    at node90   //  \     at node70     /   \
 *  40(B)  90(B)          40(B) 80(R)             70(B) 90(B)
 *         /                     \
 *       80(R)                   90(B)
 *
 */
void test_rbtRemove_for_caseLeft1b2(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  rbtRemove(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 *    "rbtRemove"
 *    caseLeft 1b(2) - node40 becomes double black null and returns to its parent.
 *                   - Rotate right at node90, then rotate left at node70.
 *
 *
 *        /     rotate right    /     rotate left      / 
 *     70(B)    -----------> 70(B)    ----------->   80(B)
 *    //   \    at node90   //  \     at node70     /   \
 *    -   90(B)             -  80(R)             70(B) 90(B)
 *         /                     \
 *       80(R)                   90(B)
 *
 */
void test_rbtRemove_for_caseLeft1b2_given_the_target_node_has_removed_and_returned(void){
  Node *root = &node70;
  
  initNode(&node70, NULL, &node90, BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  rbtRemove(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
}

/**
 *    "rbtRemove"
 *    caseLeft 2a(1) node10 is double black node.
 *    
 *         /                        //  
 *       20(B)     flip colour     20(B)  
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               NULL  50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 */
void test_rbtRemove_for_caseLeft2a1(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    "rbtRemove"
 *    caseLeft 2a(1) node10 becomes double black null and returns to its parent.
 *    
 *         /                        //  
 *       20(B)     flip colour     20(B)  
 *      //  \     ----------->    /    \
 *      -  50(B)               NULL  50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 */
void test_rbtRemove_for_caseLeft2a1_given_the_target_node_has_removed_and_returned(void){
  Node *root = &node20;
  
  initNode(&node20, NULL, &node50, BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    "rbtRemove"
 *    caseLeft 2a(2) - siblingLeft(node10) is double black.
 *                   - Both child of siblingRight are null.
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    10(B) 50(B)              10(B)  50(R)
 *
 */
void test_rbtRemove_for_caseLeft2a2(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    "rbtRemove"
 *    caseLeft 2a(2) - siblingLeft(node10) becomes double black null and returns to its parent.
 *                   - Both child of siblingRight are null.
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *      -   50(B)                -   50(R)
 *
 */
void test_rbtRemove_for_caseLeft2a2_given_the_target_node_has_removed_and_returned(void){
  Node *root = &node20;
  
  initNode(&node20, NULL, &node50, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    "rbtRemove"
 *    1. caseLeft 2b(1) - siblingLeft(node10) is double black.
 *    
 *         /                         /          
 *       20(R)     flip colour     20(B)        
 *      //  \     ----------->    /   \     
 *    10(B) 50(B)                -   50(R)    
 *          /  \                     /   \      
 *       30(B)70(B)                30(B) 70(B)   
 *  
 */
void test_rbtRemove_for_caseLeft2b1(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node10); // Violation becomes stable.
                             // However, error in having caseLeft3 activated. 
                             // Need ATTENTION. 
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    "rbtRemove"
 *    caseLeft 2b(2) - siblingLeft(node10) is double black.
 *               - Children of siblingRight are null.
 *    
 *         /                         /   
 *       20(R)     flip colour     20(B)  
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               NULL  50(R)
 *
 */
void test_rbtRemove_for_caseLeft2b2(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node10);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    "rbtRemove"
 *    caseLeft 3 - siblingLeft(node10) is double black
 *    
 *         /                         /                   /    
 *       20(B)     rotate left     50(B)     caseLeft 2    50(B)  
 *      //  \     ----------->    /   \     ------->  /   \
 *    10(B) 50(R)  at node20   20(R)  70(B)         20(B) 70(B)
 *          /  \              //  \                /   \
 *       30(B)70(B)         10(B) 30(B)           -   30(R)
 *
 */
void test_rbtRemove_for_caseLeft3(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, &node30, &node70, RED);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node10);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node20, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node30, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/**
 * caseRight 1a(1) - node90 will be removed and rotate right at node70.
 *
 *
 *         /     rotate Right    /
 *      70(R)    ----------->  40(R)
 *     /   \\                 /   \
 *   40(B) 90(B)            20(B)70(B)
 *   /                   
 * 20(R)                      
 *
 */
void test_remove_node90_will_perform_caseRightOneAOne_with_parent_is_red(void){
  Node *parent = &node70;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node90, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  caseRightOneAOne(&parent, retObj, 90);
  
  CTEST_ASSERT_EQUAL_NODE(&node40, &node20, &node70, RED, 40);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 * caseRight 1a(1) - node90 is a double black node and has returned to parent(ndoe70).
 *
 *
 *         /     rotate Right    /
 *      70(R)    ----------->  40(R)
 *     /   \\                 /   \
 *   40(B)  -               20(B)70(B)
 *   /                   
 * 20(R)               
 *
 */
void test_node90_as_double_black_null_will_perform_caseRightOneAOne_with_parent_is_red(void){
  Node *parent = &node70;
  Node *removedNode = &node90;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, NULL, RED);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node90);
  caseRightOneAOne(&parent, retObj, 90);
  
  CTEST_ASSERT_EQUAL_NODE(&node40, &node20, &node70, RED, 40);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 * caseRight 1a(2) - node90 will be removed and rotate right at node70.
 *
 *
 *         /     rotate Right    /
 *      70(B)    ----------->  40(B)
 *     /   \\                 /   \
 *   40(B) 90(B)            20(B)70(B)
 *   /                   
 * 20(R)                 
 *
 */
void test_remove_node90_will_perform_caseRightOneATwo_with_left_parent_is_black(void){
  Node *parent = &node70;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node90, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  caseRightOneATwo(&parent, retObj, 90);
  
  CTEST_ASSERT_EQUAL_NODE(&node40, &node20, &node70, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 * caseRight 1a(2) - double black null at left node70 and rotate left at node70.
 *
 *
 *         /     rotate Right    /
 *      70(B)    ----------->  40(B)
 *     /   \\                 /   \
 *   40(B)  -               20(B)70(B)
 *   /                   
 * 20(R)                   
 *
 */
void test_node90_as_double_black_node_is_null_and_rotate_right_at_parent_given_parent_is_black(void){
  Node *parent = &node70;
  Node *removedNode = &node90;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, NULL, BLACK);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node90);
  caseRightOneATwo(&parent, retObj, 90);
  
  CTEST_ASSERT_EQUAL_NODE(&node40, &node20, &node70, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 * caseRight 1b(1) - node90 will be removed.
 *                 - Rotate left at node40, then rotate right at node70.
 *
 *
 *        /       rotate left      /       rotate right     / 
 *     70(R)     ------------>   70(R)    ------------>   50(R)
 *    /   \\      at node40     /   \\     at node70     /   \
 *  40(B) 90(B)               50(R)  90(B)            40(B) 70(B)
 *    \                       /     
 *   50(R)                  40(B)   
 *
 *
 */
void test_remove_node90_as_double_black_node_will_perform_caseRightOneBOne_with_parent_is_red(void){
  Node *root = &node70;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node90, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  caseRightOneBOne(&root, retObj, 90);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 * caseRight 1b(1) - node90 as double black null.
 *                 - Rotate left at node40 then rotate right at node70.
 *
 *
 *        /       rotate left      /       rotate right     / 
 *     70(R)     ------------>   70(R)    ------------>   50(R)
 *    /   \\      at node40     /   \\     at node70     /   \
 *  40(B)  -                  50(R)  -                40(B) 70(B)
 *    \                       /     
 *   50(R)                  40(B)   
 *
 */
void test_caseRightOneBOne_with_parent_and_rightChildLeft_are_red_and_siblingLeft_is_black_given_siblingRight_is_double_black_null(void){
  Node *root = &node70;
  Node *removedNode = &node90;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, NULL, RED);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node90);
  caseRightOneBOne(&root, retObj, 90);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 * caseRight 1b(2) - node90 will be removed due to double black node.
 *                 - Rotate left at node40 then rotate right at node70.
 *
 *
 *        /       rotate left      /       rotate right     / 
 *     70(B)     ------------>   70(R)    ------------>   50(B)
 *    /   \\      at node40     /   \\     at node70     /   \
 *  40(B) 90(B)               50(R)  90(B)            40(B) 70(B)
 *    \                       /     
 *   50(R)                  40(B)     
 *
 */
void test_node90_as_double_black_node_with_parent_and_siblingLeft_are_black_and_rightChildLeft_is_red(void){
  Node *root = &node70;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node90, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  caseRightOneBTwo(&root, retObj, 90);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 * caseRight 1b(2) - node90 as double black null.
 *                 - Rotate left at node40 then rotate right at node70.
 *
 *
 *        /       rotate left      /       rotate right     / 
 *     70(B)     ------------>   70(R)    ------------>   50(B)
 *    /   \\      at node40     /   \\     at node70     /   \
 *  40(B)  -                  50(R)  -                40(B) 70(B)
 *    \                       /     
 *   50(R)                  40(B)     
 *
 */
void test_caseRightOneBTwo_with_parent_and_siblingLeft_are_black_and_rightChildLeft_is_red_given_siblingRight_is_double_black_null(void){
  Node *root = &node70;
  Node *removedNode = &node90;
  ReturnedObject retObj;
  
  initNode(&node70, &node40, NULL, BLACK);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node90);
  caseRightOneBTwo(&root, retObj, 90);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    caseRight 2a(1) - node70 is double black node.
 *                    - Parent, siblingLeft, and children of siblingLeft are black.
 *                    - Colour flipped for parent and siblingRight to be double black and red respectively.
 *    
 *           /                         //   
 *         50(B)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_caseRight2A1_given_parent_siblingRight_children_of_siblingLeft_are_black_with_siblingRight_is_double_black_will_flip_colour(void){
  Node *root = &node50;
  ReturnedObject retObj;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node70, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  caseRightTwoAOne(&root, retObj, 70);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, DOUBLE_BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
}

/**
 *    caseRight 2a(1) - SiblingRight is double black node but null.
 *                    - Parent, siblingLeft, and children of siblingLeft are black.
 *                    - Colour flipped for parent and siblingRight to be double black and red respectively.
 *    
 *           /                         //   
 *         50(B)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)   -                  30(R)  -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_siblingRight_is_null_but_double_black_will_flip_colour_when_parent_siblingLeft_and_children_of_siblingLeft_are_black(void){
  Node *root = &node50;
  Node *removedNode = &node70;
  ReturnedObject retObj;
  
  initNode(&node50, &node30, NULL, BLACK);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node70);
  caseRightTwoAOne(&root, retObj, 70);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, DOUBLE_BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
}

/**
 *    caseRight 2a(2) - SiblingRight(node70) is double black.
 *                    - Parent and siblingLeft are black.
 *                    - Both child of siblingLeft are null.
 *    
 *           /                         //   
 *         50(B)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \  /   \               /  \
 *    -    - -    -              -   -
 *
 */
void test_caseRight2A2_given_parent_and_siblingLeft_are_black_and_both_children_of_siblingLeft_are_null(void){
  Node *root = &node50;
  ReturnedObject retObj;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, DOUBLE_BLACK);
  
  caseRightTwoATwo(&root, retObj, 70);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, DOUBLE_BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/**
 *    caseRight 2a(2) - SiblingRight is double black but null.
 *                    - Parent and siblingLeft are black.
 *                    - Both child of siblingLeft are null.
 *    
 *           /                         //   
 *         50(B)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)   -                  30(R)  -
 *     /   \                      /  \
 *    -    -                     -   - 
 *
 */
void test_caseRight2A2_given_parent_and_siblingLeft_are_black_and_the_children_of_siblingLeft_are_null(void){
  Node *root = &node50;
  Node *removedNode = &node70;
  ReturnedObject retObj;
  
  initNode(&node50, &node30, NULL, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node70);
  caseRightTwoATwo(&root, retObj, 70);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, DOUBLE_BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/**
 *   caseRight 2b(1) - SiblingRight is a double black node.
 *                   - SiblingLeft and its children are black with the parent is red.
 *    
 *           /                         /   
 *         50(R)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_caseRight2B1_given_siblingLeft_and_its_children_are_black_with_the_parent_is_red(void){
  Node *root = &node50;
  ReturnedObject retObj;
  
  initNode(&node50, &node30, &node70, RED);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node70, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  caseRightTwoBOne(&root, retObj, 50);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
}

/**
 *   caseRight 2b(1) - SiblingRight is double black but null.
 *                   - SiblingLeft and its children are black with the parent is red.
 *    
 *           /                         /   
 *         50(R)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)   -                  30(R)  -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_caseRight2B1_given_siblingRight_is_null_but_double_black_siblingLeft_and_its_children_are_black_with_the_parent_is_red(void){
  Node *root = &node50;
  Node *removedNode = &node70;
  ReturnedObject retObj;
  
  initNode(&node50, &node30, NULL, RED);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node70);
  caseRightTwoBOne(&root, retObj, 70);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
}

/**
 *   caseRight 2b(2) - Double black node can be a node or null.
 *                   - Parent is red and siblingLeft is black.
 *                   - Children of siblingLeft are null.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      /   \\     ----------->    /   \
 *    10(B) 50(B)               10(R)  -
 *    /  \                      /  \
 *   -   -                     -   -
 *
 */
void test_caseRight2B2_given_parent_is_red_and_siblingLeft_is_black_and_children_of_siblingLeft_are_null(void){
  Node *root = &node20;
  ReturnedObject retObj;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, DOUBLE_BLACK);
  
  caseRightTwoBTwo(&root, retObj, 50);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
}

/**
 *  caseRight 2b(2) - Double black node can be a node or null.
 *                  - Parent is red and siblingLeft is black.
 *                  - Children of siblingLeft are null.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      /   \\     ----------->    /   \
 *    10(B)  -                  10(R)  -
 *    /  \                      /  \
 *   -   -                     -   -
 *
 */
void test_caseRight2B2_given_siblingRight_is_null_and_double_black_and_parent_is_red_and_siblingLeft_is_black_and_children_of_siblingLeft_are_null(void){
  Node *root = &node20;
  Node *removedNode = &node50;
  ReturnedObject retObj;
  
  initNode(&node20, &node10, NULL, RED);
  initNode(&node10, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node50);
  caseRightTwoBTwo(&root, retObj, 50);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
}

/**
 *    caseRight 3 - SiblingRight is double black.
 *                - Parent, siblingLeft and children of siblingLeft are black.
 *                - Right rotation and case 2 are used to balance the tree.
 *    
 *           /                          /                       /
 *         50(B)     rotate right     30(B)      case 2       30(B)
 *        /   \\     ----------->    /    \      ------>     /    \
 *     30(R)  70(B)                20(B) 50(R)             20(B) 50(B)
 *     /   \                            /   \\                   /   \
 *  20(B) 40(B)                       40(B) 70(B)             40(R)  -
 *
 */
void test_caseRight3_given_the_sblingRight_is_red_and_siblingLeft_is_double_black(void){
  Node *root = &node50;
  ReturnedObject retObj;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, &node20, &node40, RED);
  initNode(&node70, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  caseRightThree(&root, retObj, 70);
  
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node50, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, NULL, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, RED, 40);
}

/**
 *    caseRight 3 - SiblingRight is double black but null.
 *                - Parent, siblingLeft and children of siblingLeft are black.
 *                - Right rotation and case 2 are used to balance the tree.
 *     
 *           /                          /                       /
 *         50(B)     rotate right     30(B)      case 2       30(B)
 *        /   \\     ----------->    /    \      ------>     /    \
 *     30(R)   -                   20(B) 50(R)             20(B) 50(B)
 *     /   \                            /   \\                   /   \
 *  20(B) 40(B)                       40(B)  -                40(R)  -
 *
 */
void test_caseRight3_given_parent_siblingLeft_and_children_of_siblingLeft_are_black_while_siblingRight_is_double_black_null(void){
  Node *root = &node50;
  Node *removedNode = &node70;
  ReturnedObject retObj;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, &node20, &node40, RED);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  removedNode->colour = DOUBLE_BLACK;
  retObj = rbtRemovedNode(&node70);
  caseRightThree(&root, retObj, 70);
  
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node50, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, NULL, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, RED, 40);
}

/**
 *    "rbtRemove"
 *    caseRight 1a(1) - node90 will be removed and rotate right at node70.
 *
 *
 *         /     rotate Right    /
 *      70(R)    ----------->  40(R)
 *     /   \\                 /   \
 *   40(B) 90(B)            20(B)70(B)
 *   /                   
 * 20(R)                      
 *
 */
void test_rbtRemove_for_caseRightOneAOne(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node90, NULL, NULL, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  rbtRemove(&root, &node90);
  
  CTEST_ASSERT_EQUAL_NODE(&node40, &node20, &node70, RED, 40);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    "rbtRemove"
 *    caseRight 1a(2) - node90 will be removed and rotate right at node70.
 *
 *
 *         /     rotate Right    /
 *      70(B)    ----------->  40(B)
 *     /   \\                 /   \
 *   40(B) 90(B)            20(B)70(B)
 *   /                   
 * 20(R)                 
 *
 */
void test_rbtRemove_for_caseRightOneATwo(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node90, NULL, NULL, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  rbtRemove(&root, &node90);
  
  CTEST_ASSERT_EQUAL_NODE(&node40, &node20, &node70, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    "rbtRemove"
 *    caseRight 1b(1) - node90 will be removed.
 *                    - Rotate left at node40, then rotate right at node70.
 *
 *
 *        /       rotate left      /       rotate right     / 
 *     70(R)     ------------>   70(R)    ------------>   50(R)
 *    /   \\      at node40     /   \\     at node70     /   \
 *  40(B) 90(B)               50(R)  90(B)            40(B) 70(B)
 *    \                       /     
 *   50(R)                  40(B)   
 *
 *
 */
void test_rbtRemove_caseRightOneBOne(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node90, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  rbtRemove(&root, &node90);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    "rbtRemove"
 *    caseRight 1b(2) - node90 will be removed due to double black node.
 *                    - Rotate left at node40 then rotate right at node70.
 *
 *
 *        /       rotate left      /       rotate right     / 
 *     70(B)     ------------>   70(R)    ------------>   50(B)
 *    /   \\      at node40     /   \\     at node70     /   \
 *  40(B) 90(B)               50(R)  90(B)            40(B) 70(B)
 *    \                       /     
 *   50(R)                  40(B)     
 *
 */
void test_rbtRemove_caseRightOneBTwo(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node90, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  rbtRemove(&root, &node90);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    "rbtRemove"
 *    caseRight 2a(1) - node70 is double black node.
 *                    - Parent, siblingLeft, and children of siblingLeft are black.
 *                    - Colour flipped for parent and siblingRight to be double black and red respectively.
 *    
 *           /                         //   
 *         50(B)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_rbtRemove_caseRight2A1(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node70);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, DOUBLE_BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
}

/**
 *    "rbtRemove"
 *    caseRight 2a(2) - SiblingRight(node70) is double black.
 *                    - Parent and siblingLeft are black.
 *                    - Both child of siblingLeft are null.
 *    
 *           /                         //   
 *         50(B)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \  /   \               /  \
 *    -    - -    -              -   -
 *
 */
void test_rbtRemove_for_caseRight2A2(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node70);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, DOUBLE_BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/**
 *    "rbtRemove"
 *    caseRight 2b(1) - SiblingRight is a double black node.
 *                    - SiblingLeft and its children are black with the parent is red.
 *    
 *           /                         /   
 *         50(R)     flip colour     50(B)  
 *        /   \\     ----------->   /    \
 *     30(B)  70(B)               30(R)  -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_rbtRemove_for_caseRight2B1(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, RED);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node70);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, NULL, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
}

/**
 *    "rbtRemove"
 *    caseRight 2b(2) - Double black node can be a node or null.
 *                    - Parent is red and siblingLeft is black.
 *                    - Children of siblingLeft are null.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      /   \\     ----------->    /   \
 *    10(B) 50(B)               10(R)  -
 *    /  \                      /  \
 *   -   -                     -   -
 *
 */
void test_rbtRemove_for_caseRight2B2(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node50);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
}

/**
 *    "rbtRemove"
 *    caseRight 3 - SiblingRight is double black.
 *                - Parent, siblingLeft and children of siblingLeft are black.
 *                - Right rotation and case 2 are used to balance the tree.
 *    
 *           /                          /                       /
 *         50(B)     rotate right     30(B)      case 2       30(B)
 *        /   \\     ----------->    /    \      ------>     /    \
 *     30(R)  70(B)                20(B) 50(R)             20(B) 50(B)
 *     /   \                            /   \\                   /   \
 *  20(B) 40(B)                       40(B) 70(B)             40(R)  -
 *
 */
void test_rbtRemove_caseRight3(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, &node20, &node40, RED);
  initNode(&node70, NULL, NULL, BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  rbtRemove(&root, &node70);
  
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node50, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, NULL, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, RED, 40);
}

/**
 *    Find node60 as the replacing node given node50 is the target.      
 *
 *       50(B)    replacing node     
 *      /   \    --------------> 60(B)
 *   20(R) 80(R)           
 *   /     /   \           
 * 10(B) 60(B) 90(B)       
 *
 */
void test_findReplacingNode_node60_given_node50_is_the_target(void){
  Node *root = &node50;
  Node *replaceNode;
  
  initNode(&node50, &node20, &node80, BLACK);
  initNode(&node20, &node10, NULL, RED);
  initNode(&node80, &node60, &node90, RED);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node60, NULL, NULL, BLACK);
  initNode(&node90, NULL, NULL, BLACK);
  
  replaceNode=findReplacingNode(root->right);
  
  TEST_ASSERT_EQUAL_PTR(&node60, replaceNode);
  TEST_ASSERT_EQUAL(NULL, replaceNode->left);
  TEST_ASSERT_EQUAL(NULL, replaceNode->right);
  TEST_ASSERT_EQUAL(BLACK, replaceNode->colour);
  TEST_ASSERT_EQUAL(60, replaceNode->value);
}