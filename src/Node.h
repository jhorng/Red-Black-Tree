#ifndef Node_H
#define Node_H

#define isNoLeftChild(x)  (x)->left==0?1:0
#define isNoRightChild(x)  (x)->right==0?1:0

#define leftChildColour(x)  (x)->left->colour
#define rightChildColour(x)  (x)->right->colour

typedef enum{
  BLACK,        // 0
  RED,          // 1
  DOUBLE_BLACK  // 2
}Colour;

typedef struct Node Node;
struct Node{
  Node *left;
  Node *right;
  int colour;
  int value;
};

Node *initNode(Node *root, Node *left, Node *right, int colour);
void caseOneLeftA(Node **root);
void caseOneLeftB(Node **root);
void caseOneRightA(Node **root);
void caseOneRightB(Node **root);
void caseOnePointOne(Node **root);
void caseOnePointTwo(Node **root);
void caseTwoPointOne(Node **root);
void caseTwoPointTwo(Node **root);
void caseThreePointOne(Node **root);
void caseThreePointTwo(Node **root);
void intRbtAdd(Node **root, Node *child);
void rbtAdd(Node **root, Node *child);

#endif // Node_H
