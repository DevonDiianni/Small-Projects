/** 
 * Devon Diianni
 * readFile.h
 * December 15th, 2019
 *
 */

#include "list.h"
#include "node.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/* Define row size here*/
#define ROW 4
#define ROW_2 17

/* Define column sizes here*/
#define COL 1

#ifndef READFILE_H_
#define READFILE_H_


/* Helper methods to read in files, sort, and print the graph */
void readresultsSmall(FILE *fp, int value[][COL]);
void readresultsLarge(FILE *fp, int value_2[][COL]);




#endif /* READFILE_H_ */