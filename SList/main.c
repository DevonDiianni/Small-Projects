#define MAIN_C_
#include "SList.h"

int main(void){
    /* Test Run */
    
    SList* myList = slistCreate();
    /* Printing empty list */
    slistPrint(myList);
    
    slistInsertFirst(myList, "this", 4);
    slistInsertFirst(myList, "hello", 5);
    slistGetLast(myList);
    slistInsertLast(myList,"sorta",5);
    slistInsertLast(myList, "works", 5);
    printf("Size of the list is: %d \n",slistGetSize(myList));
    slistPrint(myList);
    return 0;
}