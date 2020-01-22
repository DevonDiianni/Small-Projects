/* SList.h 
Devon DiIanni
October 4th, 2019
*/


#ifndef SLIST_H
#define SLIST_H
 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct SList SList;
 
typedef void (*SList_forfn)(void *);
 
SList * slistCreate();  // Creates an empty list
int     slistGetSize(const SList * list);  // return the size of list (number of elements in the list)
void    slistPrint(const SList * list, char* (*formatter)(void *));  // print the contents of the list

bool    slistInsertFirst(SList * list, const void * value, size_t valueSize); // insert a Node with the specified info at the front of list
void *  slistGetFirst(const SList * list);  // get the value part of the first element
bool    slistRemoveFirst(SList * list);   // remove (delete) the first element in list

bool    slistInsertNth(SList * list, int n, const void * value, size_t valueSize);   // insert element into the Nth position (zero based)
void *  slistGetNth(const SList * list, int n);   // get the Nth element, where the list is zero based
bool    slistRemoveNth(SList * list, int n);  // remove (delete) the Nth element in list

bool    slistInsertLast(SList * list, const void * value, size_t valueSize);   // insert element into the last position
void *  slistGetLast(const SList * list);   // get the last element
bool    slistRemoveLast(SList * list);  // remove (delete) the last element in list
 
#endif /* SLIST_H */
