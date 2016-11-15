#ifndef Node_H
#define Node_H

typedef enum{
  BLACK,
  RED,
  DOUBLE_BLACK
}Colour;

typedef struct Node Node;
struct Node{
  Node *left;
  Node *right;
  int colour;
  int value;
};

Node *initNode(Node *root, Node *left, Node *right, int colour);
void addNode(Node *root, Node *child);

#endif // Node_H
