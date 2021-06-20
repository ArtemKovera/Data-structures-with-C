//implementations of functions for a linked list that works with char strings

#include"linked_list.h"
#include<stdlib.h>

List* init(void)
{
    List* ptr = (List*) malloc(sizeof(List));

    ptr->size = 0;
    ptr->head = NULL;
    ptr->tail = NULL;

    return ptr;
}

size_t size(const List* list)
{
    return list->size;
}

int insertHead(List* list, const char* str, size_t strSize)
{
    Node* node = (Node* ) malloc(sizeof(Node));
    
    if(node)
    {
        if(list->size == 0)
        {
            list->tail = node; 
            node->next = NULL;
        } 
        else
        {
            node->next = list->head;
        }
        
        list->head = node;
        list->size++;
    }
    else     // if node==NULL
    {
        return -1;
    }

    node->data = (char*) malloc(strSize);
    if(node->data)
    {
        for (size_t i = 0; i < strSize-1; i++)
        {
            node->data[i] = str[i];
        }
        node->data[strSize] = '\0'; // the string in the node always ends with '\0' 
    }
    else // if node->data==NULL
    {
        return -2;
    }
    
    return 0;
}

int insertNext(List* list, Node* node, const char* str, size_t strSize)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    if(newNode)
    {
        Node* priviousNodeNext = node->next;
        node->next=newNode;
        newNode->next = priviousNodeNext;

        if(list->size==1 || priviousNodeNext->next==NULL)
        {
            list->tail = newNode;
        }

        list->size++;
    }
    else   // if newNode==NULL
    {
        return -1;
    }
    
    newNode->data = (char*) malloc(strSize);

    if(newNode->data)
    {
        for(size_t i = 0; i < strSize-1; i++)
        {
            newNode->data[i] = str[i];
        }

        newNode->data[strSize] = '\0'; //the string in the node always ends with '\0'
    }
    else   // if newNode->data==NULL
    {
        return -2;
    }
    
    return 0;
}

int insertIndex(List* list, size_t index, const char* str, size_t strSize)
{
    if(list->size < index) //if the size of the list is less than index, the element is not allocated
    //and function returns -3
    {
        return -3;
    }
    else if(list->size == 0) //if the size of the list is 0, insertHead function is called
    {
        return insertHead(list, str, strSize);
    }
    else          
    {
        Node* tmp = list->head;
        
        //finding the place of the element in the list
        for(size_t i = 0; i < index; i++)
        {
            tmp = tmp->next;
        }
         
        return insertNext(list, tmp, str, strSize);
    }
    
}

int removeList(List* list)
{
    if(list->size==0)
    {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        free(list);
        list = NULL;
        return 0;
    }
        
    
    Node* tmp1 = list->head;
    Node* tmp2;

    while(tmp1)
    {   
        tmp2 = tmp1;
        tmp1 = tmp1->next;
        free(tmp2->data);
        free(tmp2);
        tmp2->data = NULL;
        tmp2->next = NULL;
        tmp2 = NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    free(list);
    list = NULL;

    return 0;
}

int removeNodeAfterAddress (List* list, Node* address)
{
    if(list->size==0)
        return -1;

    if(address->next==NULL)
        return -2;

    Node* tmp = address->next;
    free(tmp->data);
    tmp->data = NULL;
    address->next = tmp->next;
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;
    
    list->size--;
    
    if(address->next==NULL)
        list->tail = address;
    
    return 0;
}

int removeHead(List* list)
{
    if(list->size==0)
        return -1;
    
    Node* tmp = list->head;

    if(list->size==1)
    {
        free(tmp->data);
        tmp->data = NULL;
        tmp->next = NULL; 

        free(tmp);
        tmp = NULL;

        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = tmp->next;

        free(tmp->data);
        tmp->data = NULL;
        tmp->next = NULL; 
        free(tmp);
        tmp = NULL;
    }
    
    list->size--;
    return 0;
}

void traverse(const List* list)
{
    Node* tmp = list->head;
    size_t count = 0;

    while(tmp)
    {   
        printf("Element - %zu)\n%s \nAddress - %p\n", count, tmp->data, tmp);
        tmp = tmp->next;
    }
}

void traverseData(const List* list)
{
    Node* tmp = list->head;
    size_t count = 0;

    while(tmp)
    {   
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }    
}

char* data(const List* list, const Node* node)
{
    if(list->size==0)
        return NULL;

    return node->data;
}

char* dataIndex(const List* list, const size_t index)
{
    if(list->size==0 || index>list->size)
        return NULL;
    
    size_t count = 0;

    Node* tmp = list->head;
    
    while(count != index)
    {
        tmp = tmp->next;
        count++;
    }

    return tmp->data;
}

Node* nextNode(Node* node)
{
    if(node)
    {
        return node->next;
    }

    return NULL;
}
