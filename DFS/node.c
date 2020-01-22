/** 
 * Devon Diianni
 * December 15th, 2019
 * node.c 
 */

#include "node.h"
#include <stdlib.h>


/**
 * Creates a new Node struct and returns the new node.
 * 
 * @param value the value of the node for the Node struct
 * @return returns the newNode
 */
Node* addNode(int value)
{
 
    Node* newNode = (Node*) malloc(sizeof(struct Node));
    newNode->node = value;
    newNode->next = NULL;

    return newNode;
};
