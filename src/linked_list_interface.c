#include"interface.h"
#include"linked_list.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//returns 0 if call is successful 
//returns -1 otherwise
int linkedListInterface(void)
{   
    char choice           = 0;
    int status            = 0;
    size_t sizeEntered    = 0;   
    size_t size           = 0; 
    size_t index          = 0;
    char* bufferString    = NULL;
    char filename [64]    = {0};

    
    List* list = init();
    puts("An empty linked list has been created");

    while(true)
    {
        puts("Please specify the maximum size of the strings in the list - it must be from 1 to 100");
        flushInput();
        status = scanf("%zu", &sizeEntered);
        if(sizeEntered < 1 || sizeEntered > 100 || status == 0)
        {
            puts("Error: wrong number");
            continue;
        }
        printf("Great! The maximum string size in your list is %zu\n", sizeEntered);   
        break;
    }
    size = sizeEntered + 1;
    bufferString = (char*) malloc(size);
    
    while(true)
    {
        flushInput();
        puts("\nPlease choose what you want to do with your list: \n"
             "To insert a new string at the head of the list ------------------- press 'A' \n"
             "To insert a new string after a given index                         press 'B' \n"
             "To remove the string at the head of the list --------------------- press 'C' \n"
             "To remove the string at a given index                              press 'D' \n"
             "To display all strings in the list ------------------------------- press 'E' \n"
             "To display all strings, node indexes and addresses in the list     press 'F' \n"
             "To display the string at a given index --------------------------- press 'G' \n"
             "To find the string in the list                                     press 'H' \n"
             "To display the number of the strings stored in the list ---------- press 'I' \n"
             "To save the content of the list to a file                          press 'S' \n"
             "To finish working with your list and clean up all its resources -- press 'Q'");
        
        choice = getchar();

        switch(choice)
        {
            case'A': //To insert a new string at the head of the list
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin);
                status = insertHead(list, bufferString, size);
                if(!status)
                    puts("Great! You successfully inserted the element at the head of the list");
                else
                {
                    puts("Some problems with this operation occured...");
                    return -1;
                }
                break;
            
            case'B': //To insert a new string after a given index
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin); 
                
                while(true)
                {
                    flushInput();
                    puts("\nPlease enter the index: ");
                    status = scanf("%zu", &index);
                    if(status == 1)
                    {
                        status = insertAfterIndex(list, index, bufferString, size);
                        break;
                    }
                    puts("Wrong number, please try again");
                }
                
                if(!status)
                {
                    printf("Great! You successfully inserted the element after the index %zu\n", index);
                    break;
                }
                else if(status==-4)
                {
                    puts("Error: There is no element with this index in the list");
                    break;
                }
                else
                {
                    puts("Memory allocation problem with this operation occured...");
                    return -1;                    
                }

            case'C': //To remove the string at the head of the list
                status = removeHead(list);
                if(!status)
                {
                    puts("The string at the head of the list has been removed");
                    break;
                }
                else if(status == -1)
                {
                    puts("Error: there are no elements in the list");
                    break;
                }
                break;
            
            case'D':  //To remove the string at a given index 
                puts("Please, enter the index:");
                flushInput();
                scanf("%zu", &index);
                status = removeNodeAtIndex(list, index);
                if(status == 0)
                {
                    puts("Great the string has been removed");
                }
                else if(status == -1)
                {
                    puts("Your list is empty. You cannot remove any element from it");
                }
                else if(status == -4)
                {
                    puts("Error: wrong index. Next time please provide another one.");
                }
                else
                {
                    puts("Something wrong with this operation happened");
                }
                break;

            case'E': //To display all strings in the list
                puts("\nStrings in your list: \n");
                traverseData(list);
                break;

            case'F': //To display all strings, node indexes and addresses in the list
                puts("\nElement indexes, strings, and element addresses in your list:\n");
                traverse(list);
                break;

            case'G': //To display the string at a given index 
                while(true)
                {
                    puts("Please enter the index of the string you want to display");
                    flushInput();
                    status = scanf("%zu", &index);
                    if(status == 1)
                    {
                        if(dataAtIndex(list, index))
                        {
                            printf("%s\n", dataAtIndex(list, index));
                        }
                        break;   
                    }
                    puts("Wrong number, please try again");                                     
                }
                break;

            case'H': //To find the string in the list
                puts("Please enter the string you want to find");
                printf("(Only first %zu characters will be compared)\n", sizeEntered); 
                flushInput();
                fgets(bufferString, size, stdin);
                status = findData(list, bufferString);
                if(status == -1)
                    puts("The string is not in the list");
                else  
                    printf("The string is found at index %d\n", status);
                break;

            case'I': //To display the number of the strings stored in the list 
                printf("There are %zu strings in the list\n", getSize(list));
                break;
            
            case'S': //To store the content of the list to a file
                puts("Please enter the file name:");
                flushInput();
                fgets(filename, 64, stdin);
                status = saveToFileLL(list, filename);
                if(!status)
                    printf("Great! The content of your list has been saved to the file %s\n", filename);
                else
                    puts("Some problem has occured with saving to a file");
                break;            

            case'Q': //To finish working with this list and cleaning up all its resources
                free(bufferString);
                bufferString = NULL;
                status = removeList(list);
                if(!status)
                {
                    puts("Your linked list has been removed");
                    return 0;
                }   
                else
                {
                    puts("Problems with removing the list");
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