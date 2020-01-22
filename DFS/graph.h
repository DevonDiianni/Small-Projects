/**
 * Devon Diianni 
 * graph.h
 * December 15th, 2019
 *
 */
#include "list.h"
#include "node.h"


#ifndef GRAPH_H_
#define GRAPH_H_


typedef struct Graph{
    int numHead;
    struct List *array;
} Graph;

typedef struct Graph Graph;

Graph* createGraph(int size);
void addEdge(Graph* graph, int head, int node);
void printGraph(Graph* graph);

/* Add sorts here */
void topologicalSort(Graph *graph);

#endif /* GRAPH_H_ */