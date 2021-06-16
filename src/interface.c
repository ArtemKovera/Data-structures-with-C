#include "interface.h"
#include<stdio.h>
#include<stdbool.h>

int linkedListInterface()
{
    return 0;
}

int doublyLinkedListInterface()
{
    return 0;
}

int circularLinkedListInterface()
{
    return 0;
}

int stackInterface()
{
    return 0;
}

int queueInterface()
{
    return 0;
}

int setInterface()
{
    return 0;
}

int chainedHashTableInterface()
{
    return 0;
}

int binaryTreeInterface()
{
    return 0;
}

int priorityQueueInterface()
{
    return 0;
}

int interfaceMain()
{
    char choice = 'a';
    bool flag = true; 
    
    while (flag)
    {
        puts("Please choose a data structure");
        puts("To choose Linked List          - press 'A' \n"
             "To choose Double Linked List   - press 'B' \n"
             "To choose Circular Linked List - press 'C' \n"
             "To choose Stack                - press 'D' \n"
             "To choose Queue                - press 'E' \n"
             "To choose Set                  - press 'F' \n"
             "To choose Chained Hash Table   - press 'G' \n"
             "To choose Binary Tree          - press 'H' \n"
             "To choose Priority Queue       - press 'I' ");

        choice = getchar();

        switch(choice)
        {
            case 'A':
                puts("You chose a Linked List");
                flag = false;
                linkedListInterface();
                break;
            case 'B':
                puts("You chose a Doubly Linked List");
                flag = false;
                doublyLinkedListInterface();                
                break;
            case 'C':
                puts("You chose a Circular Linked List");
                flag = false;
                circularLinkedListInterface();                
                break;
            case 'D':
                puts("You chose a Stack");
                flag = false;
                stackInterface();
                break;
            case 'E':
                puts("You chose a Queue");
                flag = false;
                queueInterface();
                break;        
            case 'F':
                puts("You chose a Set");
                flag = false;
                setInterface();
                break;
            case 'G':
                puts("You chose a Chained Hash Table");
                flag = false;
                chainedHashTableInterface();
                break;
            case 'H':
                puts("You chose a Binary Tree");
                flag = false;
                binaryTreeInterface();
                break;
            case 'I':
                puts("You chose a Priority Queue");
                flag = false;
                priorityQueueInterface();
                break;  
            default:
                puts("\nYou've entered an inappropriate character \n"
                     "Make your choice again");                            
        }
    }
    
    return 0;
}