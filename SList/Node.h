/* Node.h
Devon DiIanni 
October 4th, 2019
 */

#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>
struct Node {
    void * value;
    size_t valueSize;
    struct Node * next;
    
};

//typedef struct Node Node;
 
typedef struct Node Node;

Node * createNode  (const void * value, const size_t valueSize);
void   releaseNode (Node * node);
void * getNodeValue(const Node *); // get the value pointer from the node
void   setNodeNext (Node * node, Node * next);  // set the link to the next node in our list
Node * getNodeNext (const Node * node);     // retrieve the next element linked to by this node

#endif /* NODE_H_ */
