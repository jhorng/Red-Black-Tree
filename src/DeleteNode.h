#ifndef DeleteNode_H
#define DeleteNode_H

#include "Node.h"

typedef struct ReturnedObject ReturnedObject;
struct ReturnedObject{
  Node *removedNode;
  Colour returnedColour;
};

ReturnedObject rbtRemoveNode(Node *nodePtr);
void caseOneAOne(Node **nodePtr);
void caseOneATwo(Node **nodePtr);
void caseOneBOne(Node **nodePtr);
void caseOneBTwo(Node **nodePtr);
void caseTwoAOne(Node **nodePtr);
void caseTwoATwo(Node **nodePtr);
void caseTwoBOne(Node **nodePtr);
void caseTwoBTwo(Node **nodePtr);
void caseOneA(Node **nodePtr);
void caseOneB(Node **nodePtr);
void caseTwoA(Node **nodePtr);
void caseTwoB(Node **nodePtr);
void caseThree(Node **nodePtr);

#endif // DeleteNode_H
