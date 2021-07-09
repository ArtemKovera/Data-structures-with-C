#include"interface.h"
#include"doubly_linked_list.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//returns 0 if call is successful 
//returns -1 otherwise
int doublyLinkedListInterface(void)
{   
    char choice           = 0;
    int status            = 0;
    size_t sizeEntered    = 0;   
    size_t size           = 0; 
    size_t index          = 0;
    char* bufferString    = NULL;
    char* pointer         = NULL;
    char filename [FILE_NAME_SIZE]    = {0};
    
    DList* list = initDL();
    puts("An empty doubly linked list has been created");

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
             "To insert a new string at the tail of the list                     press 'B' \n"
             "To insert a new string after a given index ----------------------- press 'C' \n"
             "To insert a new string before a given index                        press 'D' \n"
             "To remove the string at the head of the list --------------------- press 'E' \n"
             "To remove the string at the tail of the list                       press 'F' \n"
             "To remove the string at a given index ---------------------------- press 'G' \n"
             "To display all strings in the list from head to tail               press 'H' \n"
             "To display all strings in the list from tail to head ------------- press 'I' \n"
             "To display all strings and their corresponding indexes             press 'J' \n"
             "To display the string at a given index --------------------------- press 'K' \n"
             "To find the string in the list from head to tail                   press 'L' \n"
             "To find the string in the list from tail to head ----------------- press 'M' \n"
             "To display the number of the strings stored in the list            press 'N' \n"
             "To save the content of the list to a file ------------------------ press 'S' \n"
             "To finish working with your list and clean up all its resources    press 'Q'");
        
        choice = getchar();

        switch(choice)
        {
            case'A': //To insert a new string at the head of the list
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin);
                status = insertHeadDL(list, bufferString, size);
                if(!status)
                    puts("Great! You successfully inserted the element at the head of the list");
                else
                {
                    puts("Some problems with this operation occured...");
                    return -1;
                }
                break;
            
            case'B': //To insert a new string at the tail of the list
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin);
                status = insertTailDL(list, bufferString, size);
                if(!status)
                    puts("Great! You successfully inserted the element at the tail of the list");
                else
                {
                    puts("Some problems with this operation occured...");
                    return -1;
                }
                break;            
            
            case'C': //To insert a new string after a given index
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
                        status = insertAfterIndexDL(list, index, bufferString, size);
                        break;
                    }
                    puts("Wrong number, please try again");
                }
                
                if(!status)
                {
                    printf("Great! You successfully inserted the element after the index %zu\n", index);
                    break;
                }
                else if(status==-2 || status==-1)
                {
                    puts("Error: There is no element with this index in the list");
                    break;
                }
                else
                {
                    puts("Memory allocation problem with this operation occured...");
                    return -1;                    
                }

            case'D': //To insert a new string before a given index
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
                        status = insertBeforeIndexDL(list, index, bufferString, size);
                        break;
                    }
                    puts("Wrong number, please try again");
                }
                
                if(!status)
                {
                    printf("Great! You successfully inserted the element before the index %zu\n", index);
                    break;
                }
                else if(status==-2 || status==-1)
                {
                    puts("Error: There is no element with this index in the list");
                    break;
                }
                else
                {
                    puts("Memory allocation problem with this operation occured...");
                    return -1;                    
                }            

            case'E': //To remove the string at the head of the list
                status = removeHeadDL(list);
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

            case'F': //To remove the string at the tail of the list
                status = removeTailDL(list);
                if(!status)
                {
                    puts("The string at the tail of the list has been removed");
                    break;
                }
                else if(status == -1)
                {
                    puts("Error: there are no elements in the list");
                    break;
                }
                break;            
            
            case'G':  //To remove the string at a given index 
                puts("Please, enter the index:");
                flushInput();
                scanf("%zu", &index);
                status = removeAtIndexDL(list, index);
                if(status == 0)
                {
                    puts("Great the string has been removed");
                }
                else if(status == -1)
                {
                    puts("Your list is empty. You cannot remove any element from it");
                }
                else if(status == -2)
                {
                    puts("Error: wrong index. Next time please provide another one.");
                }
                else
                {
                    puts("Something wrong with this operation happened");
                }
                break;

            case'H': //To display all strings in the list from head to tail
                puts("\nStrings in your list from head to tail: \n");
                traverseDL(list);
                break;

            case'I': //To display all strings in the list from tail to head
                puts("\nStrings in your list from tail to head: \n");
                traverseBackwordDL(list);
                break;            

            case'J': //To display all strings and their corresponding indexes 
                puts("\nElement indexes and corresponding strings in your list:\n");
                dataAndIndexies(list);
                break;

            case'K': //To display the string at a given index 
                while(true)
                {
                    puts("Please enter the index of the string you want to display");
                    flushInput();
                    status = scanf("%zu", &index);
                    if(status == 1)
                    {
                        if((pointer = dataAtIndexDL(list, index)) != NULL)
                        {
                            printf("%s\n", pointer);
                        }
                        break;   
                    }
                    puts("Wrong number, please try again");                                     
                }
                break;

            case'L': //To find the string in the list from head to tail
                puts("Please enter the string you want to find");
                printf("(Only first %zu characters will be compared)\n", sizeEntered); 
                flushInput();
                fgets(bufferString, size, stdin);
                status = findDataFromHeadDL(list, bufferString);
                if(status == -1)
                    puts("The string is not in the list");
                else  
                    printf("The string is found at index %d\n", status);
                break;

            case'M': //To find the string in the list from tail to head
                puts("Please enter the string you want to find");
                printf("(Only first %zu characters will be compared)\n", sizeEntered); 
                flushInput();
                fgets(bufferString, size, stdin);
                status = findDataFromTailDL(list, bufferString);
                if(status == -1)
                    puts("The string is not in the list");
                else  
                    printf("The string is found at index %d\n", status);
                break;            

            case'N': //To display the number of the strings stored in the list 
                printf("There are %zu strings in the list\n", SIZE_DL(list));
                break;
            
            case'S': //To store the content of the list to a file
                puts("Please enter the file name:");
                flushInput();
                fgets(filename, FILE_NAME_SIZE, stdin);
                status = saveToFile(list, filename);
                if(!status)
                    printf("Great! The content of your list has been saved to the file %s\n", filename);
                else
                    puts("Some problem has occured with saving to a file");
                break;

            case'Q': //To finish working with this list and cleaning up all its resources
                free(bufferString);
                bufferString = NULL;
                status = removeDL(list);
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