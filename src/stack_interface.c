#include"interface.h"
#include"linked_list.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//returns 0 if call is successful 
//returns -1 otherwise

int stackInterface(void)
{   
    char choice           = 0;
    int status            = 0;
    size_t sizeEntered    = 0;   
    size_t size           = 0; 
    char* bufferString    = NULL;
    char* pointer         = NULL;
    
    List* list = init();
    puts("An empty stack data structure has been created");

    while(true)
    {
        puts("Please specify the maximum size of the strings in the stack - it must be from 1 to 100");
        flushInput();
        status = scanf("%zu", &sizeEntered);
        if(sizeEntered < 1 || sizeEntered > 100 || status == 0)
        {
            puts("Error: wrong number");
            continue;
        }
        printf("Great! The maximum string size in your stack is %zu\n", sizeEntered);   
        break;
    }
    size = sizeEntered + 1;
    bufferString = (char*) malloc(size);
    
    while(true)
    {
        flushInput();
        puts("\nPlease choose what you want to do with your stack: \n"
             "Push (to insert a new string at the top) ------------------------  press 'A' \n"
             "Pop (to remove the string at the top)                              press 'B' \n"
             "Top (to display the string at the top) --------------------------- press 'C' \n"
             "To display the number of the strings stored in the stack           press 'D' \n"
             "To finish working with your stack and clean up all its resources - press 'Q'");
        
        choice = getchar();

        switch(choice)
        {
            case'A': //Push
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin);
                status = insertHead(list, bufferString, size);
                if(!status)
                    puts("Great! You successfully pushed the element to the stack");
                else
                {
                    puts("Some problems with this operation occured...");
                    return -1;
                }
                break;

            case'B': //Pop
                status = removeHead(list);
                if(!status)
                {
                    puts("The string at the top of the stack has been removed");
                    break;
                }
                else if(status == -1)
                {
                    puts("Error: there are no elements in the stack");
                    break;
                }
                break;

            case'C': //Top
                if((pointer = dataAtIndex(list, 0)) != NULL)
                {
                    printf("%s\n", pointer);
                }
                else
                {
                    puts("Some problems with this operation occured...");
                }
                break;   

            case'D': //To display the number of the strings stored in the stack
                printf("There are %zu strings in the stack\n", SIZE_L(list));
                break;
            
            case'Q': //To finish working with this stack and cleaning up all its resources
                free(bufferString);
                bufferString = NULL;
                status = removeList(list);
                if(!status)
                {
                    puts("Your stack has been removed");
                    return 0;
                }   
                else
                {
                    puts("Problems with removing the stack");
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