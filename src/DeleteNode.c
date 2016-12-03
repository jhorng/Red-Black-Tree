#include <stdlib.h>
#include <stdio.h>
#include "DeleteNode.h"

ReturnedObject rbtRemoveInt(Node *nodePtr){
  ReturnedObject retObj;
  
  retObj.removedNode = nodePtr;
  retObj.returnedColour = DOUBLE_BLACK;
  
  return retObj;
}