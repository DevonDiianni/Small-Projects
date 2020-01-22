/** 
 * Devon Diianni
 * December 15th, 2019
 * node.h 
 */

#ifndef NODE_H_
#define NODE_H_

typedef struct Node{
    int node;
    struct Node *next;
} Node;

typedef struct Node Node;

Node* addNode(int node);

#endif /* NODE_H_ */