#ifndef DeleteNode_H
#define DeleteNode_H

#include "Node.h"

typedef struct ReturnedObject ReturnedObject;
struct ReturnedObject{
  Node *removedNode;
  Colour returnedColour;
};

ReturnedObject rbtRemoveInt(Node *nodePtr);

#endif // DeleteNode_H
