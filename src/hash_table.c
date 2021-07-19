#include"hash_table.h"
#include"linked_list.h"
#include"stdlib.h"


HashTable* initHT(const size_t numberOfCharacters)
{
    HashTable *ht = malloc(sizeof(HashTable));
    
    ht->numberOfElements = numberOfCharacters * 127;

    ht->size = 0;
    ht->array = (List**) calloc(sizeof(List*), ht->numberOfElements);
      
    return ht;
}


unsigned int hashFunction(const char *str, const size_t strSize)
{
    unsigned int result = 0;
    size_t count = 0;

    while(count < strSize)
    {
        result += *str;
        str++;

        if(*str == '\0')
            break;
    }

    return result;
}

int addStringHT(HashTable *ht, const char *str, const size_t strSize)
{
    
    if(!ht)
        return -4;
    
    unsigned int index = hashFunction(str, strSize);
    int status = 0;
    if(index > ht->numberOfElements)
        return -3;
    
    
    if(ht->array[index] == NULL)
    {
        ht->array[index] = init();
    } 


    status = insertHead(ht->array[index], str, strSize);
    ht->size++;
    

    return status;
}

bool findStringHT(const HashTable *ht, const char *str, const size_t strSize)
{
    if(!ht)
        return false;
    
    unsigned int index = hashFunction(str, strSize);
    int status = 0;

    if(index > ht->numberOfElements)
        return false;
    
    List *list = ht->array[index]; 

    if(list == NULL)
    {
        return false;
    }   

    status = findData(list, str);

    if(status == -1)
        return false;
        
    return true;
}

int removeElementHt(HashTable *ht, const char *str, const size_t strSize)
{   
    if(!ht)
        return -5;
    
    unsigned int index = hashFunction(str, strSize);
    int status = 0;

    if(index > ht->numberOfElements)
        return -1;    

    List *list = ht->array[index]; 

    if(list == NULL)
    {
        return -1;
    }       

    status = findData(list, str);

    if(status == -1)
        return -1;
    
    ht->size--;
    return removeNodeAtIndex(list, status);
}

int removeHT(HashTable *ht)
{
    if(!ht)
        return -1;
    
    if(ht->size == 0)
    {
        free(ht->array);
        ht->array = NULL;
        free(ht);
        ht = NULL;
        return 0;
    }

    for(size_t index = 0; index < ht->numberOfElements; index++)
    {
        List *tmp = ht->array[index];
        
        if(tmp)
            removeList(tmp);
    }

    free(ht->array);
    ht->array = NULL;
    free(ht);
    ht = NULL;
    return 0;
}

size_t getNumberOfElements(const HashTable *ht)
{
    return ht->numberOfElements;
}