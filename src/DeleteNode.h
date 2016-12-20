#ifndef DeleteNode_H
#define DeleteNode_H

#include "Node.h"

#define leftTwo(x)  (x)->left->left
#define leftThree(x)  (x)->left->left->left

typedef struct ReturnedObject ReturnedObject;
struct ReturnedObject{
  Node *removedNode;
  Colour returnedColour;
};

ReturnedObject rbtRemoveNode(Node *nodePtr);
void caseOneAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseOneATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseOneBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseOneBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseTwoAOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseTwoATwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseTwoBOne(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseTwoBTwo(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void caseThree(Node **nodePtr, ReturnedObject deletedNode, int nodeValue);
void intRbtDelete(Node **nodePtr, Node *node);
void rbtDelete(Node **nodePtr, Node *node);

#endif // DeleteNode_H
