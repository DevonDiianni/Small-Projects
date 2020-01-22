/** 
 * Devon Diianni
 * December 15th, 2019
 * readFile.c
 */

#include "readFile.h"

/**
 * Use hardcoded ROW value to iterate up to. 
 * Read in integer values from both columns, per row.
 * Pass both column values to addEdge() for a given Graph struct.
 * 
 * @param fp The file file pointer to scan for integer values.
 * @param value The value is passed a hardcoded ROW value.
 */
void readresultsSmall(FILE *fp, int value[][COL])
{       int size = 5; /* Number of values for a given Graph  */ 
        Graph* graph = createGraph(size); /* Create graph struct*/
        int row, col, scan;
        
        for(row=0; row<ROW; row++)
        {
                col = 0;
                scan = fscanf(fp, "%d%d", &value[row][col], &value[row][col+1]);
                printf("%d %d\n", value[row][col],  value[row][col+1]);
                addEdge(graph, value[row][col], value[row][col+1]);
              
        }

        printf("\nNodes and their edges: \n");
        printGraph(graph); 
        printf("\nTopological Ordering: ");
        topologicalSort(graph);
        printf("\n\n");
}

/**
 * Use hardcoded ROW value to iterate up to. 
 * Read in integer values from both columns, per row.
 * Pass both column values to addEdge() for a given Graph struct.
 * 
 * @param fp The file file pointer to scan for integer values.
 * @param value The value is passed a hardcoded ROW value.
 */
void readresultsLarge(FILE *fp, int value_2[][COL])
{       int size = 11; /* Number of values for a given Graph  */ 
        Graph* graph_2 = createGraph(size); /* Create graph struct */
        int row, col, scan;
        for(row=0; row<ROW_2; row++)
        {
                col = 0;
                scan = fscanf(fp, "%d%d", &value_2[row][col], &value_2[row][col+1]);
                printf("%d %d\n", value_2[row][col],  value_2[row][col+1]);
                addEdge(graph_2, value_2[row][col], value_2[row][col+1]);
        }

        printf("\nNodes and their edges: \n");
        printGraph(graph_2); 
        printf("\nTopological Ordering: ");
        topologicalSort(graph_2);
        printf("\n\n");
}
