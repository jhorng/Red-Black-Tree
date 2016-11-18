#ifndef Node_H
#define Node_H

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
void caseOnePointOne(Node *root);
void caseOnePointTwo(Node *root);
void caseTwoPointOne(Node *root);
void caseThreePointOne(Node *root);
void addNode(Node *root, Node *child);

#endif // Node_H
