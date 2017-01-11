#ifndef RemoveNode_H
#define RemoveNode_H

#include "Node.h"

#define isAnyOneDoubleBlack(currNode, removedNode)  ((((currNode) != NULL)&&((currNode)->colour == DOUBLE_BLACK)) || \
                                                     (((currNode) == NULL)&&((removedNode)->colour == DOUBLE_BLACK)) )
#define leftChildRightLeft(x) (x)->right->left->left
#define rightChildRightLeft(x) (x)->right->left->right

void caseLeftOneAOne(Node **nodePtr, Node *returnedObject);
void caseLeftOneATwo(Node **nodePtr, Node *returnedObject);
void caseLeftOneBOne(Node **nodePtr, Node *returnedObject);
void caseLeftOneBTwo(Node **nodePtr, Node *returnedObject);
void caseLeftTwoAOne(Node **nodePtr, Node *returnedObject);
void caseLeftTwoATwo(Node **nodePtr, Node *returnedObject);
void caseLeftTwoBOne(Node **nodePtr, Node *returnedObject);
void caseLeftTwoBTwo(Node **nodePtr, Node *returnedObject);
void caseLeftThree(Node **nodePtr, Node *returnedObject);
void caseLeftDoubleBlack(Node **nodePtr, Node *returnedObject);
void caseRightOneAOne(Node **nodePtr, Node *returnedObject);
void caseRightOneATwo(Node **nodePtr, Node *returnedObject);
void caseRightOneBOne(Node **nodePtr, Node *returnedObject);
void caseRightOneBTwo(Node **nodePtr, Node *returnedObject);
void caseRightTwoAOne(Node **nodePtr, Node *returnedObject);
void caseRightTwoATwo(Node **nodePtr, Node *returnedObject);
void caseRightTwoBOne(Node **nodePtr, Node *returnedObject);
void caseRightTwoBTwo(Node **nodePtr, Node *returnedObject);
void caseRightThree(Node **nodePtr, Node *returnedObject);
void caseRightDoubleBlack(Node **nodePtr, Node *returnedObject);
Node *findReplacingNode(Node *node);
Node *rbtRemoveNode(Node **nodePtr, Node *node);
void rbtRemove(Node **nodePtr, Node *node);

#endif // RemoveNode_H
