#ifndef Rotation_H
#define Rotation_H

typedef struct Node Node;
struct Node{
  Node *left;
  Node *right;
  int colour;
  int value;
};

void rotateLeft(Node **nodePtr);
void rotateRight(Node **nodePtr);
void rotateLeftRight(Node **nodePtr);
void rotateRightLeft(Node **nodePtr);

#endif // Rotation_H
