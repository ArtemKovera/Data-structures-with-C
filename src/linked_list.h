#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdio.h>

//structure for list elements
typedef struct Node_
{
    char * data;
    struct Node_ * next;
} Node;

//structure for a linked list
typedef struct list_
{
    size_t size;

    Node * head;
    Node * tail;
} List;

//size of a single Node
const size_t NODE_SIZE = sizeof(Node); 

//initialize an empty linked list
//returns pointer to the list
List* init(void);

//to remove all nodes
//returns 0 if the call is successful
int removeNodes(List* list);

//returns the size of the linked list
size_t size(const List* list);

//inserts a head element at the very beginning of the list
//returns 0 if the call is successful
//returns -1 or -2 otherwise
int insertHead(List* list, const char* str, size_t strSize);

//inserts a new element after the element in the second parameter
//returns 0 if the call is successful
//returns -1 or -2 otherwise
int insertNext(List* list, Node* node, const char* str, size_t strSize);

//inserts a new element with a specific index 
//returns 0 if the call is successful
//returns -1, -2, or -3 otherwise
int insertIndex(List* list, size_t index, const char* str, size_t strSize);

//removes the next node from the list given a node address as the second parameter
//returns 0 if the call is successful
//returns -1 or -2 otherwise
int removeNodeAfterAddress(List* list, Node* address);

//removes head from the list
//returns 0 if the call is successful
//returns -1 otherwise
int removeHead(List* list);

//traverses the list
//prints data components to the console
void traverse(const List* list);

//returns the data of a particular list element
//returns NULL if the call is not successful 
char* data(const List* list, const Node* node);

//returns the data of a particular list element given the index of this element as the second parameter
//returns NULL if the call is not successful 
char* dataIndex(const List* list, const size_t index);

#endif