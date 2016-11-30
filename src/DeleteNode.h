#ifndef DeleteNode_H
#define DeleteNode_H

#include "Node.h"

typedef struct ReturnedObject ReturnedObject;
struct ReturnedObject{
  Node *removedNode;
  Colour returnedColour;
};

#endif // DeleteNode_H
