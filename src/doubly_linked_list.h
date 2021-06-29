#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include<stdio.h>

typedef struct NodeDL_
{
    char * data;
    struct NodeDL_ * next;
    struct NodeDL_ * previous;
} NodeDL;

typedef struct dlist_
{
    size_t size;
    NodeDL* head;
    NodeDL* tail;
} DList;

//initialize an empty doubly linked list
//returns pointer to the list
DList* initDL(void);

size_t getSizeDL(const DList list);

//to remove a doubly linked list
//returns 0 if the call is successful
int removeDL(DList * list);

//inserts a head element at the very beginning of the doubly linked list
//returns 0 if the call is successful
//returns -1 or -2 otherwise
int insertHeadDL(DList* list, const char* str, size_t strSize);

//inserts a tail element in a doubly linked list
//returns 0 if the call is successful
//returns -1 or -2 otherwise
int insertTailDL(DList* list, const char* str, size_t strSize);

//inserts node after index
//returns 0 if the call is successful
//returns -1 otherwise
int insertAfterIndexDL(DList* list, size_t index, const char* str, size_t strSize);

//inserts node before index
//returns 0 if the call is successful
//returns -1 otherwise
int insertBeforeIndexDL(DList* list, size_t index, const char* str, size_t strSize);

//removes node at index
//returns 0 if the call is successful
//returns -1 otherwise
int removeAtIndexDL(DList* list, size_t index);

//removes the head from the doubly linked list
//returns 0 if the call is successful
//returns -1 otherwise
int removeHeadDL(DList* list);

//removes the tail from the doubly linked list
//returns 0 if the call is successful
//returns -1 otherwise
int removeTailDL(DList* list);

//traverses the doubly linked list from head to tail
//prints data components to the console
void traverseDL(DList* list);

//traverses the doubly linked list from tail to head
//prints data components to the console
void traverseBackwordDL(DList* list);

//returns the pointer to a data of a particular list element given the index of this element as the second parameter
//returns NULL if the call is not successful 
char* dataAtIndexDL(DList* list, size_t index);

//returns the node index where the string is found in the list
//the list is searched from the head
//the function stops when first occurrence is found
//returns -1 if the string is not found
int findDataFromHeadDL(DList* list, const char* data);

//returns the node index where the string is found in the list
//the list is searched from the tail
//the function stops when first occurrence is found
//returns -1 if the string is not found
int findDataFromTailDL(DList* list, const char* data);

#endif