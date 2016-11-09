#ifndef Node_H
#define Node_H

typedef struct Node Node;
struct Node{
  Node *left;
  Node *right;
  int colour;
  int value;
};

Node *initializeNode(int colour, int value);
void addNode(Node *root, Node *child);

#endif // Node_H
