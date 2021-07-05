#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdio.h>

#define NODE_SIZE sizeof(Node)

//structure for list elements
typedef struct Node_
{
    char * data;
    struct Node_ * next;
} Node;

//structure for a linked list
typedef struct
{
    size_t size;

    Node * head;
    Node * tail;
} List;

//size of a single Node
//const size_t NODE_SIZE = sizeof(Node); 

//initialize an empty linked list
//returns pointer to the list
List* init(void);

//to remove a linked list
//returns 0 if the call is successful
int removeList(List* list);

//returns the size of the linked list
size_t getSize(const List* list);

//inserts a head element at the very beginning of the list
//returns 0 if the call is successful
//returns -1 or -2 otherwise
int insertHead(List* list, const char* str, const size_t strSize);

//inserts a new element after the element in the second parameter
//returns 0 if the call is successful
//returns -1, -2, or -3 otherwise
//time complexity for this function is 1
int insertNext(List* list, Node* node, const char* str, const size_t strSize);

//inserts a new element with a specific index 
//returns 0 if the call is successful
//returns -1, -2, -3, or -4 otherwise
//time complexity for this function is N
int insertAfterIndex(List* list, const size_t index, const char* str, const size_t strSize);

//removes the next node from the list given a node address as the second parameter
//returns 0 if the call is successful
//returns -1, -2, or -3 otherwise
int removeNodeAfterAddress(List* list, Node* address);

//removes node at the index specified as the second parameter
//returns 0 if the call is successful
//returns -1, -2, -3, or -4 otherwise 
int removeNodeAtIndex(List* list, const size_t index);

//removes head from the list
//returns 0 if the call is successful
//returns -1 otherwise
int removeHead(List* list);

//traverses the list
//prints element indexies, data components, and element addresses to the console
void traverse(const List* list);

//traverses the list
//prints data components to the console
void traverseData(const List* list);

//returns the pointer to the data of a particular list element
//returns NULL if the call is not successful 
char* data(const List* list, const Node* node);

//returns the pointer to a data of a particular list element given the index of this element as the second parameter
//returns NULL if the call is not successful 
char* dataAtIndex(const List* list, const size_t index);

//returns the address of the next node in the list
Node* nextNode(const Node* node);

//returns the address of the head in the list
Node* getHead(const List* list);

//returns the address of the tail in the list
Node* getTail(const List* list);

//returns the node index where the string is found in the list
//the list is searched from the head
//the function stops when first occurrence is found
//returns -1 if the string is not found
int findData(const List* list, const char* str);

//saves the content of a linked list to file
//returns 0 if the call is successful
//returns -1 otherwise
int saveToFileLL(const List* list, const char* file);

#endif