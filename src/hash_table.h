#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<stdio.h>
#include<stdbool.h>

#define STRING_TOTAL(x) (x->size)

typedef struct 
{
    unsigned int * array;
    size_t size;
}HashTable;

//initializes a new hash table
//returns the pointer to the array in the hash table 
//the size of the array depends upon the number of characters
//the larger the number of characters, the larger the size of the array 
HashTable* initHT(const size_t numberOfCharacters); 

//addes a new string to the hash table
//returns the index of the array in the hash table
//returns -1 if some error in this function occurs
int addStringHT(HashTable* ht, const char* str);

//returns true if the string is found in the hash table
//feturns false otherwise
bool findStringHT(const HashTable* ht, const char* str);

//returns the output of the hash function on a given input
int hashFunction(const char* str);

#endif