#include"interface.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


int interfaceMain(void)
{
    char choice  = 0;
    bool flag    = true; 
    int  status  = 0;
    
    while (flag)
    {
        puts("\n----------------------------------\n"
             "Please choose a data structure: \n"
             "To choose Linked List------------ press 'A' \n"
             "To choose Double Linked List      press 'B' \n"
             "To choose Stack ----------------- press 'C' \n"
             "To choose Queue                   press 'D' \n"
             "To choose Hash Table ------------ press 'E' \n"
             "To quit the program               press 'Q'");

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

            case 'E':
                puts("You chose a Hash Table");
                status = chainedHashTableInterface();
                if(!status)
                {   
                    quitContinue();
                    break;
                }
                else
                {
                    exit(-1);
                } 

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
    while (true)
    {
        if(ch == EOF || ch == '\n')
            return;
        
        ch = getchar();
    }     
}