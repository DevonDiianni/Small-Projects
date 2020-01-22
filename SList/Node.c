/* Node.c 
Devon DiIanni
October 4th, 2019
*/
#include <stdlib.h>
#include "Node.h"
#include <string.h>

//Big-O Notation: O(1)
//create the node
Node * createNode  (const void * value1, const size_t valueSize1)
{
    // create a new node
    Node * newNode; 
    newNode = (Node *)malloc(sizeof(Node));

    newNode->value = (void *)malloc(valueSize1);
    memcpy(newNode->value, value1, valueSize1);
   
    return newNode;

}

//Big-O Notation: O(1)
// release the node
void  releaseNode (Node * node)
{
    if (node != NULL){
        free(node->value);
        free(node);
    }   
    else
    {
        return;
    }
    
}

//Big-O Notation: O(1)
// get the value pointer from the node
void * getNodeValue(const Node * node)
{
    if (node == NULL){
        return NULL;
    }
    else{
    return node->value;
    };
}

//Big-O Notation: O(1)
// set the link to the next node in our list
void setNodeNext (Node * node, Node * next)
{
    node->next = next;
}

//Big-O Notation: O(1)
// retrieve the next element linked to by this node
Node * getNodeNext (const Node * node)
{
    return node->next;
}
