#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<stdio.h>
#include<stdbool.h>
#include"linked_list.h"

#define STRING_TOTAL_HT(x) (x->size)

typedef struct 
{
    List *array;
    size_t size;
    size_t numberOfElements;
}HashTable;

//initializes a new hash table
//returns the pointer to the array in the hash table 
//the size of the array depends upon the number of characters
//the larger the number of characters, the larger the size of the array 
HashTable* initHT(const size_t numberOfCharacters); 

//addes a new string to the hash table
//returns 0 if the call successful
//returns -1, -2, -3 if some error in this function occurs
int addStringHT(HashTable *ht, const char *str, const size_t strSize);

//returns true if the string is found in the hash table
//feturns false otherwise
bool findStringHT(const HashTable *ht, const char *str);

//returns the output of the hash function on a given input
//the hash function is simple, it just sums up the char values in the string
unsigned int hashFunction(const char *str);

//deletes a hash table
//frees up all the resourses
//returns 0 if the call is successful  
int removeHT(HashTable *ht);

//deletes an element from a hash table
//returns 0 if call is successful
//returns -1 if there is no such element in the hash table
//returns -2, -3, -4 if some error occurs
int removeElement(HashTable *ht, const char *str);

#endif