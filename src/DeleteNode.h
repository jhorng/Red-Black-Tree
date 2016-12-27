#ifndef DeleteNode_H
#define DeleteNode_H

#include "Node.h"

typedef struct ReturnedObject ReturnedObject;
struct ReturnedObject{
  Node *removedNode;
  Colour returnedColour;
};

ReturnedObject rbtRemoveNode(Node *nodePtr);
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
void intRbtDelete(Node **nodePtr, Node *node);
void rbtDelete(Node **nodePtr, Node *node);

#endif // DeleteNode_H
