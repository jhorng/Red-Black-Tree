#include "unity.h"
#include "RemoveNode.h"
#include "CustomAssertion.h"
#include "Node.h"
#include "Rotation.h"

Node node5, node10, node20, node25, node30, node40, node50;
Node node60, node70, node80, node90, node95, node100, node105;
Node node110, node120, node130, node140, node150, node160; 

void defineNode(Node *node, int colour, int value){
  node->left = NULL;
  node->right = NULL;
  node->colour = colour;
  node->value = value;
}

void setUp(void){
  defineNode(&node5, BLACK, 5);
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
 *           \          /              
 *          100(R)    40(B)            
 *
 */
void test_remove_node40_will_perform_caseLeftOneAOne_with_parent_is_red(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, NULL, NULL, DOUBLE_BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  caseLeftOneAOne(&root, &node50);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, RED, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, &node40, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
}

/**
 * caseLeft 1a(1) - siblingLeft is a double black null.
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
  Node *retObj = &node40;
  
  initNode(&node70, NULL, &node90, RED);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftOneAOne(&root, retObj);
  
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
 *           \              /          
 *          100(R)        40(B)        
 *
 */
void test_remove_node40_will_perform_caseLeftOneATwo_with_left_parent_is_black(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, NULL, DOUBLE_BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  caseLeftOneATwo(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node90, &node70, &node100, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node70, &node40, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
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
  Node *retObj = &node40;
  
  initNode(&node70, NULL, &node90, BLACK);
  initNode(&node90, NULL, &node100, BLACK);
  initNode(&node100, NULL, NULL, RED);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftOneATwo(&root, retObj);
  
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
 *         /                      \              /
 *       80(R)                    90(B)        40(B)
 *
 */
void test_remove_node40_will_perform_caseLeftOneBOne_with_left_parent_is_red(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, NULL, NULL, DOUBLE_BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  caseLeftOneBOne(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, RED, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, &node40, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
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
 *        /                     \
 *      80(R)                  90(B)
 *
 */
void test_left_double_black_child_of_red_node70_is_null_will_do_double_rotation(void){
  Node *root = &node70;
  Node *retObj = &node40;
  
  initNode(&node70, NULL, &node90, RED);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftOneBOne(&root, retObj);
  
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
 *         /                     \                /
 *       80(R)                   90(B)          40(B)
 *
 */
void test_remove_node40_will_perform_caseLeftOneBTwo_with_left_parent_is_black(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, NULL, DOUBLE_BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  caseLeftOneBTwo(&root, &node40);
  
  CTEST_ASSERT_EQUAL_NODE(&node80, &node70, &node90, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node70, &node40, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
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
  Node *retObj = &node40;
  
  initNode(&node70, NULL, &node90, BLACK);
  initNode(&node90, &node80, NULL, BLACK);
  initNode(&node80, NULL, NULL, RED);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftOneBTwo(&root, retObj);
  
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
 *    10(B) 50(B)                10(B)  50(R)
 *          /  \                       /  \
 *       30(B)70(B)                 30(B) 70(B)
 *
 */
void test_caseLeft2A1_given_parent_siblingRight_leftChildLeft_and_leftChildRight_are_black_with_siblingLeft_is_double_black_will_flip_colour(void){
  Node *root = &node20;
  Node *retObj = &node5;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  caseLeftTwoAOne(&root, retObj);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
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
 *    NULL 50(B)                NULL  50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 */
void test_siblingLeft_is_null_and_double_black_will_flip_colour_when_parent_siblingRight_leftChildLeft_and_leftChildRight_are_black(void){
  Node *root = &node20;
  Node *retObj = &node10;
  
  initNode(&node20, NULL, &node50, BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftTwoAOne(&root, retObj);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    caseLeft 2a(2) - siblingLeft(node10) is double black.
 *                   - Both child of siblingRight are null.
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    10(B) 50(B)              10(B)  50(R)
 *
 */
void test_caseLeft2A2_given_siblingRight_is_black_and_both_siblingRight_children_are_null_with_the_parent_being_black(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  caseLeftTwoATwo(&root, &node5);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    caseLeft 2a(2) - siblingLeft(node10) is null and double black.
 *                   - both child in siblingRight are null.
 *    
 *         /                         //   
 *       20(B)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *      -   50(B)                -   50(R)
 *
 */
void test_caseLeft2A2_given_siblingLeft_is_null_and_double_black(void){
  Node *root = &node20;
  Node *retObj = &node10;
  
  initNode(&node20, NULL, &node50, BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftTwoATwo(&root, retObj);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, DOUBLE_BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    caseLeft 2b(1) - siblingLeft(node10) is double black.
 *    
 *         /                         /    
 *       20(R)     flip colour     20(B)   
 *      //  \     ----------->    /    \
 *    10(B) 50(B)               10(B) 50(R)
 *          /  \                      /  \
 *       30(B)70(B)                30(B) 70(B)
 *
 */
void test_caseLeft2B1_given_the_sblingRight_is_black_and_both_children_of_siblingRight_are_black(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  caseLeftTwoBOne(&root, &node5);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
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
 *      -  50(B)                 -   50(R)
 *         /   \                     /   \
 *       30(B)70(B)               30(B) 70(B)
 *
 */
void test_caseLeft2B1_given_siblingLeft_is_null_and_double_black_sblingRight_is_black_and_both_children_of_siblingRight_are_black(void){
  Node *root = &node20;
  Node *retObj = &node10;
  
  initNode(&node20, NULL, &node50, RED);
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftTwoBOne(&root, retObj);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
}

/**
 *    caseLeft 2b(2) - siblingLeft(node10) is double black.
 *                   - Children of siblingRight are null.
 *    
 *         /                         /   
 *       20(R)     flip colour     20(B)  
 *      //  \     ----------->    /   \
 *    10(B) 50(B)              10(B) 50(R)
 *
 */
void test_caseLeft2B2_given_siblingRight_is_black_and_both_siblingRight_children_are_null_with_the_parent_being_red(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, NULL, NULL, BLACK);
  
  caseLeftTwoBTwo(&root, &node5);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    caseLeft 2b(2) - siblingLeft(node10) is null and double black.
 *               - Children of siblingRight are null.
 *    
 *         /                         /   
 *       20(R)     flip colour     20(B)  
 *      //  \     ----------->    /    \
 *      -  50(B)                 -   50(R)
 *
 */
void test_caseLeft2B2_given_siblingLeft_is_null_and_double_black_and_siblingRight_is_black_and_both_siblingRight_children_are_null_with_the_parent_being_red(void){
  Node *root = &node20;
  Node *retObj = &node10;
  
  initNode(&node20, NULL, &node50, RED);
  initNode(&node50, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftTwoBTwo(&root, retObj);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, RED, 50);
}

/**
 *    caseLeft 3 - siblingLeft(node10) is double black
 *    
 *         /                         /                       /    
 *       20(B)     rotate left     50(B)     caseLeft 2    50(B)  
 *      //  \     ----------->    /   \     ----------->  /   \
 *    10(B) 50(R)  at node20   20(R)  70(B)             20(B) 70(B)
 *          /  \              //  \                    /   \
 *       30(B)70(B)         10(B) 30(B)              10(B) 30(R)
 *
 */
void test_caseLeft3_given_the_sblingRight_is_red_and_siblingLeft_is_double_black(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, BLACK);
  initNode(&node10, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, &node30, &node70, RED);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  caseLeftThree(&root, &node5);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node20, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node30, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, BLACK, 10);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
}

/**
 *    caseLeft 3 - siblingLeft(node10) is null and double black
 *    
 *         /                        /                   /    
 *       20(B)     rotate left    50(B)     case 2    50(B)  
 *      //  \     ----------->   /   \     ------->  /   \
 *      - 50(R)    at node20   20(R)  70(B)         20(B) 70(B)
 *          /  \              //  \                /   \
 *       30(B)70(B)           - 30(B)           -   30(R)
 *
 */
void test_caseLeft3_given_siblingLeft_is_null_and_double_black_and_the_sblingRight_is_red_and_siblingLeft_is_double_black(void){
  Node *root = &node20;
  Node *retObj = &node10;
  
  initNode(&node20, NULL, &node50, BLACK);
  initNode(&node50, &node30, &node70, RED);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseLeftThree(&root, retObj);
  
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
 *   /                             \
 * 20(R)                          90(B)
 *
 */
void test_remove_node90_will_perform_caseRightOneAOne_with_parent_is_red(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node90, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  caseRightOneAOne(&root, &node100);
  
  CTEST_ASSERT_EQUAL_NODE(&node40, &node20, &node70, RED, 40);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, &node90, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
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
  Node *retObj = &node90;
  
  initNode(&node70, &node40, NULL, RED);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightOneAOne(&parent, retObj);
  
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
 *   /                             \
 * 20(R)                          90(B)
 *
 */
void test_remove_node90_will_perform_caseRightOneATwo_with_left_parent_is_black(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node90, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  caseRightOneATwo(&root, &node120);
  
  CTEST_ASSERT_EQUAL_NODE(&node40, &node20, &node70, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, &node90, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
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
  Node *root = &node70;
  Node *retObj = &node90;
  
  initNode(&node70, &node40, NULL, BLACK);
  initNode(&node40, &node20, NULL, BLACK);
  initNode(&node20, NULL, NULL, RED);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightOneATwo(&root, retObj);
  
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
 *    \                       /                               \
 *   50(R)                  40(B)                            90(B)
 *
 *
 */
void test_remove_node90_as_double_black_node_will_perform_caseRightOneBOne_with_parent_is_red(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, RED);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node90, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  caseRightOneBOne(&root, NULL);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, RED, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, &node90, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
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
  Node *retObj = &node90;
  
  initNode(&node70, &node40, NULL, RED);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightOneBOne(&root, retObj);
  
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
 *  40(B) 90(B)               50(R) 90(B)              40(B) 70(B)
 *    \                       /                               \
 *   50(R)                  40(B)                             90(B)
 * 
 */
void test_node90_as_double_black_node_with_parent_and_siblingLeft_are_black_and_rightChildLeft_is_red(void){
  Node *root = &node70;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node90, NULL, NULL, DOUBLE_BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  caseRightOneBTwo(&root, &node100);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, BLACK, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, &node90, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node90, NULL, NULL, BLACK, 90);
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
  Node *retObj = &node100;
  
  initNode(&node70, &node40, NULL, BLACK);
  initNode(&node40, NULL, &node50, BLACK);
  initNode(&node50, NULL, NULL, RED);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightOneBTwo(&root, retObj);
  
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
 *     30(B)  70(B)               30(R) 70(B)
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_caseRight2A1_given_parent_siblingRight_children_of_siblingLeft_are_black_with_siblingRight_is_double_black_will_flip_colour(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node70, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  caseRightTwoAOne(&root, &node90);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, DOUBLE_BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
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
  Node *retObj = &node70;
  
  initNode(&node50, &node30, NULL, BLACK);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightTwoAOne(&root, retObj);
  
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
 *     30(B)  70(B)               30(R) 70(B)
 *     /   \  /  \                /  \  /  \
 *    -    - -    -              -   - -    - 
 *
 */
void test_caseRight2A2_given_parent_and_siblingLeft_are_black_and_both_children_of_siblingLeft_are_null(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node70, NULL, NULL, DOUBLE_BLACK);
  
  caseRightTwoATwo(&root, &node80);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, DOUBLE_BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
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
  Node *retObj = &node70;
  
  initNode(&node50, &node30, NULL, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightTwoATwo(&root, retObj);
  
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
 *     30(B)  70(B)               30(R) 70(B)
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_caseRight2B1_given_siblingLeft_and_its_children_are_black_with_the_parent_is_red(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, RED);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node70, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  caseRightTwoBOne(&root, &node80);
  
  CTEST_ASSERT_EQUAL_NODE(&node50, &node30, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node40, RED, 30);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
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
 *     30(B)   -                  30(R)   -
 *     /   \                      /  \
 *  20(B) 40(B)                20(B) 40(B)
 *
 */
void test_caseRight2B1_given_siblingRight_is_null_but_double_black_siblingLeft_and_its_children_are_black_with_the_parent_is_red(void){
  Node *root = &node50;
  Node *retObj = &node70;
  
  initNode(&node50, &node30, NULL, RED);
  initNode(&node30, &node20, &node40, BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightTwoBOne(&root, retObj);
  
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
 *    10(B) 50(B)               10(R) 50(B)
 *    /  \                      /  \
 *   -   -                     -   -
 *
 */
void test_caseRight2B2_given_parent_is_red_and_siblingLeft_is_black_and_children_of_siblingLeft_are_null(void){
  Node *root = &node20;
  
  initNode(&node20, &node10, &node50, RED);
  initNode(&node10, NULL, NULL, BLACK);
  initNode(&node50, NULL, NULL, DOUBLE_BLACK);
  
  caseRightTwoBTwo(&root, NULL);
  
  CTEST_ASSERT_EQUAL_NODE(&node20, &node10, &node50, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node10, NULL, NULL, RED, 10);
  CTEST_ASSERT_EQUAL_NODE(&node50, NULL, NULL, BLACK, 50);
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
  Node *retObj = &node50;
  
  initNode(&node20, &node10, NULL, RED);
  initNode(&node10, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightTwoBTwo(&root, retObj);
  
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
 *  20(B) 40(B)                       40(B) 70(B)             40(R) 70(B)
 *
 */
void test_caseRight3_given_the_sblingRight_is_red_and_siblingLeft_is_double_black(void){
  Node *root = &node50;
  
  initNode(&node50, &node30, &node70, BLACK);
  initNode(&node30, &node20, &node40, RED);
  initNode(&node70, NULL, NULL, DOUBLE_BLACK);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  caseRightThree(&root, &node90);
  
  CTEST_ASSERT_EQUAL_NODE(&node30, &node20, &node50, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node20, NULL, NULL, BLACK, 20);
  CTEST_ASSERT_EQUAL_NODE(&node50, &node40, &node70, BLACK, 50);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, NULL, RED, 40);
  CTEST_ASSERT_EQUAL_NODE(&node70, NULL, NULL, BLACK, 70);
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
  Node *retObj = &node70;
  
  initNode(&node50, &node30, NULL, BLACK);
  initNode(&node30, &node20, &node40, RED);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node40, NULL, NULL, BLACK);
  
  retObj->colour = DOUBLE_BLACK;
  caseRightThree(&root, retObj);
  
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

/**
 *    "rbtRemoveNode"
 * 
 *          70(B)                         70(B)
 *         /    \         remove         /    \
 *      40(R)   90(R)    -------->    40(R)   90(R)
 *     /   \    /   \     node20     //  \    /   \
 *  20(B)30(B)80(B)100(B)            - 30(B)80(B)100(B)
 *
 */
void test_rbtRemove_for_caseLeft1a1(void){
  Node *root = &node70;
  Node *returnedObject;
  
  initNode(&node70, &node40, &node90, BLACK);
  initNode(&node40, &node20, &node30, RED);
  initNode(&node90, &node80, &node100, RED);
  initNode(&node20, NULL, NULL, BLACK);
  initNode(&node30, NULL, NULL, BLACK);
  initNode(&node80, NULL, NULL, BLACK);
  initNode(&node100, NULL, NULL, BLACK);
  
  returnedObject=rbtRemoveNode(&root, &node20);
  
  TEST_ASSERT_EQUAL_PTR(&node20, returnedObject);
  CTEST_ASSERT_EQUAL_NODE(&node70, &node40, &node90, BLACK, 70);
  CTEST_ASSERT_EQUAL_NODE(&node40, NULL, &node30, RED, 40);
  CTEST_ASSERT_EQUAL_NODE(&node90, &node80, &node100, RED, 90);
  CTEST_ASSERT_EQUAL_NODE(&node30, NULL, NULL, BLACK, 30);
  CTEST_ASSERT_EQUAL_NODE(&node80, NULL, NULL, BLACK, 80);
  CTEST_ASSERT_EQUAL_NODE(&node100, NULL, NULL, BLACK, 100);
}