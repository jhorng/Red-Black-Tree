#ifndef CustomAssertion_H
#define CustomAssertion_H

#include "unity.h"
#include "Node.h"

#define CTEST_ASSERT_EQUAL_NODE(root, left, right, colour, value)   \
        customTestAssertion(root, left, right, colour, value, __LINE__)
        
void customTestAssertion(Node *root, Node *left, Node *right, Colour colour, int value, int lineNo);
char *nodeColour(Colour colour);

#endif // CustomAssertion_H
