#include "interface.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int setInterface(void)
{
    return 0;
}

int chainedHashTableInterface(void)
{
    return 0;
}

int binaryTreeInterface(void)
{
    return 0;
}

int priorityQueueInterface(void)
{
    return 0;
}

int interfaceMain(void)
{
    char choice  = 0;
    bool flag    = true; 
    int  status  = 0;
    
    while (flag)
    {
        puts("\n----------------------------------\n"
             "Please choose a data structure: \n"
             "To choose Linked List          - press 'A' \n"
             "To choose Double Linked List   - press 'B' \n"
             "To choose Stack                - press 'C' \n"
             "To choose Queue                - press 'D' \n"
             "To choose Set                  - press 'F' \n"
             "To choose Chained Hash Table   - press 'G' \n"
             "To choose Binary Tree          - press 'H' \n"
             "To choose Priority Queue       - press 'I' \n"
             "To quit the program            - press 'Q'");

        choice = getchar();

        switch(choice)
        {
            case 'A':
                puts("\nYou chose a Linked List");
                status = linkedListInterface();
                if(!status)
                {   
                    quitContinue();
                    break;
                }
                else
                {
                    exit(-1);
                }

            case 'B':
                puts("You chose a Doubly Linked List");
                status = doublyLinkedListInterface(); 
                if(!status)
                {   
                    quitContinue();
                    break;
                }
                else
                {
                    exit(-1);
                }                               

            case 'C':
                puts("You chose a Stack");
                status = stackInterface(); 
                if(!status)
                {   
                    quitContinue();
                    break;
                }
                else
                {
                    exit(-1);
                }   

            case 'D':
                puts("You chose a Queue");
                status = queueInterface(); 
                if(!status)
                {   
                    quitContinue();
                    break;
                }
                else
                {
                    exit(-1);
                }   

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

            case 'Q':
                exit(0);

            default:
                puts("\nYou've entered an inappropriate character \n"
                     "Make your choice again");                            
        }
    }
    
    return 0;
}

void quitContinue (void)
{
    while(true)
    {
        puts ("To continue         - press 'Y'\n"
              "To quit the program - press 'Q'");
        
        flushInput();
        char choice2 = getchar();
        flushInput();

        switch(choice2)
        {
            case 'Y':
                return;
                break;
            case 'Q':
                exit(0);
            default:
                puts("You've entered an inappropriate character \n"
                    "Please make your choice again");          
        }

    }
}

void flushInput(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        continue;
}