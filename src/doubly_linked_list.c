#include"doubly_linked_list.h"
#include<stdlib.h>
#include<stdbool.h>

DList * initDL(void)
{
    DList * list = malloc(sizeof(DList));

    if(!list)
    {
        fprintf(stderr, "Error with doubly linked list creation.\n");
        exit(1);
    }

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

size_t getSizeDL(const DList* list)
{
    return list->size;
}

int removeDL(DList * list)
{   
    if(list->size == 0)
    {
        free(list);
        list=NULL;
        return 0;
    }
    
    NodeDL *tmp1 = list->head;
    NodeDL *tmp2 = NULL;

    while(tmp1)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
        free(tmp2->data);
        tmp2->data = NULL;
        free(tmp2);
        tmp2 = NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    free(list);

    return 0;
}

int insertHeadDL(DList* list, const char* str, size_t strSize)
{
    NodeDL * node = malloc(sizeof(NodeDL));

    if(!node)
    {
        fprintf(stderr, "Error with allocating memory for a head node in a doubly linked list\n");
        return -3;
    }
    
    NodeDL *tmp = list->head;
    list->head = node;
    node->previous = NULL;
    
    if(list->size == 0)
    {
        list->tail = node;
        node->next = NULL;
    }
    else
    {
        node->next = tmp;
        tmp->previous = node;
    }

    list->size++;

    node->data = malloc(strSize);

    if(node->data)
    {
        for (size_t i = 0; i < strSize-1; i++)
        {
            node->data[i] = str[i];
            if(str[i] == '\n')
            {
                node->data[i] = '\0';
                break;
            }
        }
        node->data[strSize-1] = '\0'; // the string in the node always ends with '\0' 
    }
    else // if node->data==NULL
    {
        fprintf(stderr, "Error with allocating memory for a data element in a doubly linked list\n");
        return -4;
    }

    return 0;
}

int insertTailDL(DList* list, const char* str, size_t strSize)
{
    NodeDL * node = malloc(sizeof(NodeDL));

    if(!node)
    {
        fprintf(stderr, "Error with allocating memory for a tail node\n");
        return -3;
    } 
    
    NodeDL *tmp = list->tail;
    list->tail = node;
    node->next = NULL;
    
    if(list->size == 0)
    {
        list->head = node;
        node->previous = NULL;
    }
    else
    {
        node->previous = tmp;
        tmp->next = node;
    }

    list->size++;

    node->data = malloc(strSize);

    if(node->data)
    {
        for (size_t i = 0; i < strSize-1; i++)
        {
            node->data[i] = str[i];
            if(str[i] == '\n')
            {
                node->data[i] = '\0';
                break;
            }
        }
        node->data[strSize-1] = '\0'; // the string in the node always ends with '\0' 
    }
    else // if node->data==NULL
    {
        fprintf(stderr, "Error with allocating memory for a data element\n");
        return -4;
    }

    return 0;       
}

int insertAfterIndexDL(DList* list, size_t index, const char* str, size_t strSize)
{
    if(list->size == 0)
        return -1;
    
    if(index+1 > list->size)
        return -2;
    
    if(list->size == 1)
    {
        return insertTailDL(list, str, strSize);
    }

    NodeDL * node = malloc(sizeof(NodeDL));

    if(!node)  // if node == NULL
    {   
        fprintf(stderr, "Error with allocating memory for a node\n");
        return -3;
    }

    if(node->data)
    {
        for (size_t i = 0; i < strSize-1; i++)
        {
            node->data[i] = str[i];
            if(str[i] == '\n')
            {
                node->data[i] = '\0';
                break;
            }
        }
        node->data[strSize-1] = '\0'; // the string in the node always ends with '\0' 
    }
    else // if node->data==NULL
    {
        fprintf(stderr, "Error with allocating memory for a data element\n");
        return -4;
    } 

    size_t half = list->size/2;

    if(half >= index)
    {
        NodeDL * tmp = list->head;
        size_t count = 0;

        while(tmp)
        {   
            if(count == index)
            {
                node->previous = tmp;
                node->next = tmp->next;
                tmp->next->previous = node;
                tmp->next  = node;
                list->size++;
                break;
            }
            count++;
            tmp = tmp->next;
        }

        return 0;
    }
    else
    {
        NodeDL * tmp = list->tail;
        size_t count = list->size-1;

        while(tmp)
        {
            if(count == index)
            {
                node->previous = tmp;
                node->next = tmp->next;
                tmp->next->previous = node;
                tmp->next = node;
                list->size++;
                break;
            }

            count--;
            tmp = tmp->previous;
        }

        return 0;
    }
        
}

int insertBeforeIndexDL(DList* list, size_t index, const char* str, size_t strSize)
{
    if(list->size == 0)
        return -1;
    
    if(index+1 > list->size)
        return -2;

    if(list->size == 1)
    {
        return insertHeadDL(list, str, strSize);
    }
    
    NodeDL * node = malloc(sizeof(NodeDL));

    if(!node)  // if node == NULL
    {   
        fprintf(stderr, "Error with allocating memory for a node\n");
        return -3;
    }

    if(node->data)
    {
        for (size_t i = 0; i < strSize-1; i++)
        {
            node->data[i] = str[i];
            if(str[i] == '\n')
            {
                node->data[i] = '\0';
                break;
            }
        }
        node->data[strSize-1] = '\0'; // the string in the node always ends with '\0' 
    }
    else // if node->data==NULL
    {
        fprintf(stderr, "Error with allocating memory for a data element\n");
        return -4;
    } 

    size_t half = list->size/2;

    if(half >= index)
    {
        NodeDL * tmp = list->head;
        size_t count = 0;

        while(tmp)
        {   
            if(count == index)
            {
                node->previous = tmp->previous;
                node->next = tmp;
                tmp->previous->next = node;
                tmp->previous  = node;
                list->size++;
                break;
            }
            count++;
            tmp = tmp->next;
        }

        return 0;
    }
    else
    {
        NodeDL * tmp = list->tail;
        size_t count = list->size-1;

        while(tmp)
        {
            if(count == index)
            {
                node->previous = tmp->previous;
                node->next = tmp;
                tmp->previous->next = node;
                tmp->previous = node;
                list->size++;
                break;
            }

            count--;
            tmp = tmp->previous;
        }

        return 0;
    }    
}

int removeAtIndexDL(DList* list, size_t index)
{
    if(index+1 > list->size)
        return -1;
    
    if(index == 0)
        return removeHeadDL(list);
    
    if(index == list->size-1)
        return removeTailDL(list);
    
    size_t half = list->size/2;

    if(half >= index)
    {
        
        NodeDL * tmp = list->head;
        size_t count = 0;
        while(tmp)
        {
            if(count == index)
            {
                free(tmp->data);
                tmp->next->previous = tmp->previous;
                tmp->previous = tmp->next;
                free(tmp);
                list->size--;
                break;
            }
            count++;
            tmp = tmp->next;
        }

        return 0;
    }
    else
    {
        NodeDL * tmp = list->tail;
        size_t count = list->size - 1;

        while(tmp)
        {
            
            if(count == index)
            {
                free(tmp->data);
                tmp->next->previous = tmp->previous;
                tmp->previous = tmp->next;
                free(tmp);
                list->size--;
                break;
            }

            count--;
            tmp = tmp->previous;
        }

        return 0;
    }
}

int removeHeadDL(DList* list)
{
    if(list->size == 0)
        return -1;

    if(list->size == 1)
    {
        free(list->head->data);
        free(list->head);
        list->tail = NULL;
        list->head = NULL;
        list->size = 0;
        return 0;
    }

    NodeDL * tmp = list->head;
    list->head->next->previous = NULL;
    free(list->head->data);
    list->head = list->head->next;
    free(tmp);
    list->size--;
    return 0;
}

int removeTailDL(DList* list)
{
    if(list->size == 0)
        return -1;
    
    if(list->size == 1)
    {
        free(list->tail->data);
        free(list->tail);
        list->tail = NULL;
        list->head = NULL;
        list->size = 0;
        return 0;        
    }

    NodeDL * tmp = list->tail;
    list->tail->previous->next = NULL;
    free(list->tail->data);
    list->tail = list->tail->previous;
    free(tmp);
    list->size--;
    return 0;    
}

void traverseDL(DList* list)
{
    NodeDL * tmp = list->head;

    while(tmp)
    {
        puts(tmp->data);
        tmp = tmp->next;
    }
}

void traverseBackwordDL(DList* list)
{
    NodeDL * tmp = list->tail;

    while(tmp)
    {
        puts(tmp->data);
        tmp = tmp->previous;
    }
}

void dataAndIndexies(DList* list)
{
    NodeDL * tmp = list->head;
    size_t count = 0;

    while(tmp)
    {
        printf("%lu\n", count);
        puts(tmp->data);
        puts("\n-------------------\n");

        tmp = tmp->next;
        count++;
    }
}

char* dataAtIndexDL(DList* list, size_t index)
{
    if (list->size == 0 || index > list->size-1)
        return NULL;
    
    size_t half = list->size/2;

    if(half >= index)
    {
        
        NodeDL * tmp = list->head;
        size_t count = 0;
        while(tmp)
        {
            if(count == index)
            {
                return tmp->data;
            }
            count++;
            tmp = tmp->next;
        }

    }
    else
    {
        NodeDL * tmp = list->tail;
        size_t count = list->size - 1;

        while(tmp)
        {
            
            if(count == index)
            {
                return tmp->data;
            }

            count--;
            tmp = tmp->previous;
        }

    }
}

int findDataFromHeadDL(DList* list, const char* data)
{
    NodeDL * tmp = list->head;
    int index    = 0;
    size_t i     = 0;

    while(tmp)
    {   
        while(data[i] == tmp->data[i])
            i++;
        i++;

        if(tmp->data[i] == '\0')
            return index;
        
        i = 0;
        index++;
        tmp = tmp->next;
    }

    return -1;
}

int findDataFromTailDL(DList* list, const char* data)
{
    NodeDL * tmp = list->tail;
    int index    = list->size - 1;
    size_t i     = 0;

    while(tmp)
    {   
        while(data[i] == tmp->data[i])
            i++;
        i++;

        if(tmp->data[i] == '\0')
            return index;
        
        i = 0;
        index--;
        tmp = tmp->previous;
    }

    return -1;
}

int saveToFile(DList* list, const char* file)
{
    FILE * fp = fopen(file, "a");
    
    if(fp==NULL)
        return -1;

    NodeDL* tmp = list->head;

    while(tmp)
    {
        fprintf(fp, "%s\n", tmp->data);
        tmp = tmp->next;
    }

    fclose(fp);
    return 0;
}
