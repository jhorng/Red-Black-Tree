#ifndef Node_H
#define Node_H

#define BLACK 1
#define RED   2

typedef struct Node Node;
struct Node{
  Node *left;
  Node *right;
  int colour;
  int value;
};

Node *initializeNode(Node *left, Node *right, int colour, int value);
void addNode(Node *root, Node *child);

#endif // Node_H
