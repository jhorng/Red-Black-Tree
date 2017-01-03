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
void caseLeftOneAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftOneATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftOneBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftOneBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftTwoAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftTwoATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftTwoBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftTwoBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftThree(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseLeftDoubleBlack(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightOneAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightOneATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightOneBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightOneBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightTwoAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightTwoATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightTwoBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightTwoBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseRightThree(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void swapNode(Node **node1, Node *node2);
void intRbtRemove(Node **nodePtr, Node *node);
void rbtRemove(Node **nodePtr, Node *node);

#endif // RemoveNode_H
