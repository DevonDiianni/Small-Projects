/**
 * Devon Diianni
 * main.c
 * December 15th, 2019
 * 
 */ 

#include "graph.h"
#include "node.h"
#include "list.h"
#include "readFile.h"

/* Driver Function */
void main(void) {


        FILE *fp=fopen("smalltest.txt", "r");
        int value[ROW][COL];
        printf("Contents read from the file:\n");
        readresultsSmall(fp, value);

        FILE *fp_2=fopen("largetest.txt", "r");
        int value_2[ROW_2][COL];
        printf("Contents read from the file:\n");
        readresultsLarge(fp_2, value_2);


}


