#include"interface.h"
#include"doubly_linked_list.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//returns 0 if call is successful 
//returns -1 otherwise
int queueInterface(void)
{   
    char choice           = 0;
    int status            = 0;
    size_t sizeEntered    = 0;   
    size_t size           = 0; 
    char* bufferString    = NULL;
    char* pointer         = NULL;

    DList* list = initDL();
    puts("An empty queue data structure has been created");

    while(true)
    {
        puts("Please specify the maximum size of the strings in the queue - it must be from 1 to 100");
        flushInput();
        status = scanf("%zu", &sizeEntered);
        if(sizeEntered < 1 || sizeEntered > 100 || status == 0)
        {
            puts("Error: wrong number");
            continue;
        }
        printf("Great! The maximum string size in your queue is %zu\n", sizeEntered);   
        break;
    }
    size = sizeEntered + 1;
    bufferString = (char*) malloc(size);
    
    while(true)
    {
        flushInput();
        puts("\nPlease choose what you want to do with your list: \n"
             "Enqueue (to add a new string at the head of the queue) ----------- press 'A' \n"
             "Dequeue (To remove the string at the tail of the queue)            press 'B' \n"
             "To display the string at the tail -------------------------------- press 'C' \n"
             "To display the number of the strings stored in the queue           press 'D' \n"
             "To finish working with the queue and clean up all its resources -- press 'Q'");
        
        choice = getchar();

        switch(choice)
        {
            case'A': //Enqueue
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin);
                status = insertHeadDL(list, bufferString, size);
                if(!status)
                    puts("Great! You successfully added the element to the queue");
                else
                {
                    puts("Some problems with this operation occured...");
                    return -1;
                }
                break;          

            case'B': //Dequeue
                status = removeTailDL(list);
                if(!status)
                {
                    puts("The string at the tail of the queue has been removed");
                    break;
                }
                else if(status == -1)
                {
                    puts("Error: there are no elements in the queue");
                    break;
                }
                break;            

            case'C': //To display the string at the tail

                if((pointer = dataAtIndexDL(list, list->size - 1)) != NULL)
                {
                    printf("%s\n", pointer);
                }
                else
                {
                    puts("Some problems with this operation occured...");
                }
                break; 

            case'D': //To display the number of the strings stored in the queue
                printf("There are %zu strings in the queue\n", SIZE_DL(list));
                break;
            
            case'Q': //To finish working with this queue and cleaning up all its resources
                free(bufferString);
                bufferString = NULL;
                status = removeDL(list);
                if(!status)
                {
                    puts("Your queue has been removed");
                    return 0;
                }   
                else
                {
                    puts("Problems with removing the queue");
                    return -1;
                }
                break;
            default: 
                puts("\nYou've entered an inappropriate character \n"
                     "Make your choice again");   
        }
    }    

    return 0;
}