#include"hash_table.h"
#include"linked_list.h"
#include"stdlib.h"


HashTable* initHT(const size_t numberOfCharacters)
{
    HashTable *ht = malloc(sizeof(HashTable));
    
    ht->numberOfElements = numberOfCharacters * 127;

    ht->size = 0;
    ht->array = (List*) calloc(sizeof(List*), ht->numberOfElements);
      
    return ht;
}


unsigned int hashFunction(const char *str)
{
    unsigned int result = 0;

    while(*str != '\0')
    {
        result += *str;
        str++;
    }

    return result;
}

int addStringHT(HashTable *ht, const char *str, const size_t strSize)
{
    unsigned int index = hashFunction(str);
    int status = 0;
    if(index > ht->numberOfElements)
        return -3;
    
    List *list = (ht->array)+index;
    

    if(list == NULL)
    {
        list = init();
    } 


    status = insertHead(list, str, strSize);
    ht->size++;
    return status;
}

bool findStringHT(const HashTable *ht, const char *str)
{
    unsigned int index = hashFunction(str);
    int status = 0;

    if(index > ht->numberOfElements)
        return false;
    
    List *list = (ht->array)+index; 

    if(list == NULL)
    {
        return false;
    }   

    status = findData(list, str);

    if(status == -1)
        return false;
        
    return true;
}

int removeElement(HashTable *ht, const char *str)
{
    unsigned int index = hashFunction(str);
    int status = 0;

    if(index > ht->numberOfElements)
        return -1;    

    List *list = (ht->array)+index; 

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
    if(ht->size == 0)
    {
        free(ht->array);
        ht->array = NULL;
        free(ht);
        ht = NULL;
        return 0;
    }

    for(size_t count = 0; count < ht->numberOfElements; count++)
    {
        List *tmp = (ht->array) + count;
        
        if(tmp)
            removeList(tmp);
    }

    free(ht->array);
    ht->array = NULL;
    free(ht);
    ht = NULL;
    return 0;
}
