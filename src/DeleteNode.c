#include <stdlib.h>
#include <stdio.h>
#include "DeleteNode.h"
#include "Node.h"

ReturnedObject rbtRemoveInt(Node **nodePtr){
  ReturnedObject node;
  
  node.removedNode = (*nodePtr);
  node.returnedColour = DOUBLE_BLACK;
  
  return node;
}