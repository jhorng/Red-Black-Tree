#ifndef DeleteNode_H
#define DeleteNode_H

#include "Node.h"

typedef struct ReturnedObject ReturnedObject;
struct ReturnedObject{
  Node *removedNode;
  Colour returnedColour;
};

ReturnedObject rbtRemoveNode(Node *nodePtr);
void caseOneAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseOneATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseOneBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseOneBTwo(Node **nodePtr);
void caseTwoAOne(Node **nodePtr);
void caseTwoATwo(Node **nodePtr);
void caseTwoBOne(Node **nodePtr);
void caseTwoBTwo(Node **nodePtr);
void caseThree(Node **nodePtr);
void intRbtDelete(Node **nodePtr, Node *node);
void rbtDelete(Node **nodePtr, Node *node);

#endif // DeleteNode_H
