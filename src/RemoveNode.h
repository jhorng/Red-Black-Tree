#ifndef RemoveNode_H
#define RemoveNode_H

#include "Node.h"

#define leftChildRightLeft(x) (x)->right->left->left
#define rightChildRightLeft(x) (x)->right->left->right

typedef struct ReturnedObject ReturnedObject;
struct ReturnedObject{
  Node *removedNode;
  Colour returnedColour;
};

ReturnedObject rbtRemovedNode(Node *nodePtr);
void caseLeftOneAOne(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftOneATwo(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftOneBOne(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftOneBTwo(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftTwoAOne(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftTwoATwo(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftTwoBOne(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftTwoBTwo(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftThree(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseLeftDoubleBlack(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightOneAOne(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightOneATwo(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightOneBOne(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightOneBTwo(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightTwoAOne(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightTwoATwo(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightTwoBOne(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightTwoBTwo(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightThree(Node **nodePtr, ReturnedObject retObj, int nodeValue);
void caseRightDoubleBlack(Node **nodePtr, ReturnedObject retObj, int nodeValue);
Node *findReplacingNode(Node *node);
void swapNode(Node *node1, Node *node2);
void intRbtRemove(Node **nodePtr, Node *node);
void rbtRemove(Node **nodePtr, Node *node);

#endif // RemoveNode_H
