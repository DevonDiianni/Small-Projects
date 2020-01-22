/* SList.c 
Devon DiIanni
October 4th, 2019
*/

#include "Node.h"
#include "SList.h"
//#include "stdbool.h"
//#include "stdiop"

struct SList {
    Node * head;
    Node * tail;
    unsigned int count;
};

typedef struct SList SList;
 
typedef void (*SList_forfn)(void *);

//Big-O Notation: O(n)
SList * slistCreate()  // Creates an empty list
{
    // create a new list
    SList * newList = (SList *)malloc(sizeof(SList));
    // set the count to 0
    newList->count = 0;
    // set head and tail to null
    newList->head = NULL;
    newList->tail = NULL;
    // return this list
    return newList;
}

//Big-O Notation: O(n)
int   slistGetSize(const SList * list)  // return the size of list (number of elements in the list)
{
    return list->count;
}

//Big-O Notation: O(n)
void    slistPrint(const SList * list, char* (*formatter)(void *))  // print the contents of the list
{
    // print the list
    
    // print the start of the list
    printf("[");
    // the head node
    Node * curr = list->head;
    // as long as the current is not nulls
    while( curr )
    {
        // print this using the formatter
        printf("%s",formatter(curr->value));
        // if this is not the tail, add a space
        if( curr->next != NULL )
            printf(", ");
        // move to the next node
        curr = curr->next;
    }
    // print the closing bracket
    printf("]\n");
}

//Big-O Notation: O(1)
bool    slistInsertFirst(SList * list, const void * value, size_t valueSize) // insert a Node with the specified info at the front of list
{
    // get a new node
    Node * newNode = createNode(value, valueSize);
    // set the next of this node to the head of the list
    newNode->next = list->head;
    // set the head to this node
    list->head = newNode;
    // increment the count by 1
    list->count++;
    // return true
    return true;
}

// Big-O Notation: O(1)
void *  slistGetFirst(const SList * list)  // get the value part of the first element
{
    // if the list is empty, return NULL
    if( list->count == 0 )
        return NULL;
    //else return head value
    return list->head->value;
}

//Big-O Notation: O(1)
bool    slistRemoveFirst(SList * list)   // remove (delete) the first element in list
{
    // if the list is empty, return false
    if( list->count == 0 )
        return false;
    // store the reference to the head
    Node * oldHead = list->head;
    // move the head to the next position
    list->head = list->head->next;
    // reduce the count by 1
    list->count--;
    // if count becomes 0, set head and tail to null
    if( list->count == 0 )
    {
        list->head = NULL;
        list->tail = NULL;
    }
    // free the old head
    releaseNode(oldHead);
    // return true
    return true;
}

//Big-O Notation: O(n)
bool    slistInsertNth(SList * list, int n, const void * value, size_t valueSize)   // insert element into the Nth position (zero based)
{
    // if n is less tha 0 or greater than equal to size, return null
    if( n<0 || n>list->count )
        return false;
    // if index is 0
    if( n == 0 )
        return slistInsertFirst(list, value, valueSize);
    // else if it is to insert at last
    else if( n == list->count )
        return slistInsertLast(list, value, valueSize);
    else
    {
        // insert somewhere in between
        // the index
        int index = 1;
        
        // insert in middle
        Node * curr = list->head->next;
        Node * prev = list->head;
        // iterate
        while( curr )
        {
            // if this is place to insert node
            if (index == n)
            {
                // create a new node
                Node * newNode = createNode(value, valueSize);
                // set the next of prev to this
                prev->next = newNode;
                // set next of new node to curr
                newNode->next = curr;
                // increment count by 1
                list->count++;
                // return true
                return true;
            }
            // move forward
            index++;
            
            prev = curr;
            curr = curr->next;
        }
        
        // insert here
        // create a new node
        Node * newNode = createNode(value, valueSize);
        // set next of tail to this
        list->tail->next = newNode;
        // set tail to new node
        list->tail = newNode;
        // increment count by 1
        list->count++;
        return true;
    }
    
}

//Big-O Notation: O(n)
void *  slistGetNth(const SList * list, int n)   // get the Nth element, where the list is zero based
{
    // if n is less tha 0 or greater than equal to size, return null
    if( n<0 || n>=list->count )
        return NULL;
    
    // the index
    int index = 0;
    // the head node
    Node * curr = list->head;
    // as long as the current is not nulls
    while( curr )
    {
        // if this is the index to get
        if( index == n )
            return curr->value;
        // move to the next node
        curr = curr->next;
        // increment the index
        index++;
    }
    return NULL;
}

//Big-O Notation: O(n)
bool    slistRemoveNth(SList * list, int n)  // remove (delete) the Nth element in list
{
    // if n is less tha 0 or greater than equal to size, return false
    if( n<0 || n>=list->count )
    return false;
    
    // if n is 0, remove the first
    if( n == 0 )
        return slistRemoveFirst(list);
    // else if this is the last
    else if( n == list->count  -1 )
        return slistRemoveLast(list);
    else
    {
        // the index
        int index = 1;
        
        // remove from the middle
        Node * curr = list->head->next;
        Node * prev = list->head;
        // iterate
        while( curr )
        {
            // if this is the node to remove
            if (index == n)
            {
                // store the reference to the next
                Node * next = curr->next;
                // set next of previous to next
                prev->next = next;
                // delete the current
                releaseNode(curr);
                // return true
                return true;
            }
            // move forward
            index++;
            
            prev = curr;
            curr = curr->next;
        }
        return false;
    }
}
//Big-O Notation: O(1)
bool slistInsertLast(SList * list, const void * value, size_t valueSize) // insert element into the last position
{
    // create a new node
    Node * newNode = createNode(value, valueSize);
    // if the list is empty
    if( list->count == 0 )
    {
        // set head and tail to this
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        // set the new node to the next of the tail
        list->tail->next = newNode;
        // set the tail to the new node
        list->tail = newNode;
    }
    // increment the count
    list->count++;
    // return true
    return true;
}
//Big-O Notation: O(1)
void *  slistGetLast(const SList * list)  // get the last element
{
    // if the list is empty
    if( list->count == 0 )
    {
        // return null
        return NULL;
    }
    // else return the last
    else
    {
        return list->tail->value;
    }
}

//Big-O Notation: Big O(n)
bool    slistRemoveLast(SList * list)  // remove (delete) the last element in list
{
    // if the list is empty
    if( list->count == 0 )
    {
        // return false
        return false;
    }
    // else if there is only one node
    else if( list->count == 1 )
    {
        // the reference to the tail
        Node * temp = list->tail;
        // set the tail and head to null
        list->head = NULL;
        list->tail = NULL;
        
        // release this temp node
        releaseNode(temp);
    }
    // else remove the last
    else
    {
        // the reference to the head
        Node * curr = list->head;
        // as long we do not read the second last node
        while( curr->next != list->tail )
        {
            curr = curr->next;
        }
        // store the reference to the tail
        Node * temp = list->tail;
        // set next of current to null
        curr->next = NULL;
        //set tail to curr
        list->tail = curr;
        // release old tail
        releaseNode(temp);
    }
    // reduce count by 1
    list->count--;
    
    // return true
    return true;
}
 
