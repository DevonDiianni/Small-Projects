/** 
 * Devon Diianni
 * December 15th, 2019
 * graph.c
 */
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Creates a graph struct.
 * 
 * @param size the number of head nodes.
 * @return returns a graph
 */
Graph* createGraph(int size){
    

    Graph* graph = (Graph*) malloc(sizeof(struct Graph)); 
    graph->numHead = size;
    graph->array = (List*) malloc(size * sizeof(List));
    
    int i;
    /* Adds head nodes for the given size */ 
    for (i = 0; i < size; ++i)
    { 
        graph->array[i].head = NULL;
    }

    
    return graph;
};

/**
 * Adds an edge from the head node to a new node of a specified graph.
 * 
 * @param graph the specified graph to add an edge to.
 * @param id the id of the head node to add a edge from.
 * @param node the new node value.
 */
void addEdge(Graph* graph, int id, int node){
    
    //Acyclic graph no need to connect the "tail" node to the head
    //Create new node 
    Node* newNode = addNode(node);
    //make the newNode's next, the curent head for the id given
    newNode->next = graph->array[id].head;
    //make the newNode the head for the given id
    graph->array[id].head = newNode;

};

/**
 * Prints out the head nodes with their corresponding edges.
 * 
 * @param graph the graph to be printed out.
 */ 
void printGraph(Graph* graph){
    int i;
    for (i = 1; i < graph->numHead; ++i) 
    {
        Node* printList = graph->array[i].head;
        printf("\n");
        printf("%d -> ", i); 
        while(printList)
        {
            
            printf("%d ", printList->node);
            printList = printList->next;
            
        }
        printf("\n");
    }
}

/**
 * Recursively call topologicalSortRecurse for all vertices adjacent to a given head node.
 * 
 * @param graph the graph to recurse over.
 * @param v the current node visited.
 * @param visited the pointer to the visited node.
 * @param stack the pointer to the stack.
 * @param stackIndex the pointer to the index of the stack. 
 */ 
void topologicalSortRecurse(Graph *graph, int v, int *visited, int *stack, int *stackIndex)
{
    // Mark the current node as visited.
    visited[v] = 1;

    // Recur for all the vertices adjacent to this vertex
    Node *tmp = graph->array[v].head;
    while(tmp) {
        if (!visited[tmp->node])
            topologicalSortRecurse(graph, tmp->node, visited, stack, stackIndex);

        tmp = tmp->next;
    }

    // Push current vertex to stack which stores result
    stack[(*stackIndex)++] = v;
}

/**
 * Topologically sorts a given graph with a call to topologicalSortRecurse
 * 
 * @param graph the graph to be sorted. 
 */ 
void topologicalSort(Graph *graph)
{
    int *stack = (int*)malloc(graph->numHead * sizeof(int));
    int stackIndex = 0;

    // Mark all the vertices as not visited
    int *visited = (int *)malloc(graph->numHead * sizeof(int));
    bzero(visited, graph->numHead * sizeof(int));

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < graph->numHead; i++) {
        if (visited[i])
            continue;

        topologicalSortRecurse(graph, i, visited, stack, &stackIndex);
    }

    for (int i = graph->numHead - 1; i > 0; i--) {
        printf("%d ", stack[i]);
    }

    free(stack);
    free(visited);
}