#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdio.h>

//structure for list elements
typedef struct listElement_
{
    const char * data;
    struct listElement_ * next;
} ListElement;

//structure for a linked list
typedef struct list_
{
   size_t size;

   ListElement * head;
   ListElement * tail;
} List;

//initialize an empty linked list
List* init(void);

//to remove the linked list and free the memory
//returns 0 if the call is successful
//returns -1 otherwise
int remove(List*);

//returns the size of the linked list
size_t size(const List*);

//inserts a new element after the element in second parameter
//returns 0 if the call is successful
//returns -1 otherwise
int insertNext(List*, ListElement*, const char*);

//removes an element from the list
//returns 0 if the call is successful
//returns -1 otherwise
int removeElement(List*, ListElement*);

//traverses the list
//prints data components to the console
void traverse(const List*);

//returns the data of a particular list element
//returns NULL if the call is not successful 
const char* data(const ListElement*);

//returns the data of a particular list element given the index of this element as the second parameter
//returns NULL if the call is not successful 
const char* dataIndex(const List*, const size_t);

#endif