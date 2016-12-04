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
void caseOneA(Node **nodePtr);

#endif // DeleteNode_H