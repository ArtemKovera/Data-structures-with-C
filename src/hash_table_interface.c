#include"interface.h"
#include"hash_table.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//returns 0 if call is successful 
//returns -1 otherwise
int chainedHashTableInterface(void)
{   
    char choice           = 0;
    int status            = 0;
    size_t sizeEntered    = 0;   
    size_t size           = 0; 
    size_t index          = 0;
    char* bufferString    = NULL;
    bool flag = false;
    


    while(true)
    {
        puts("Please specify the maximum string size in the hash table - it must be from 1 to 100");
        flushInput();
        status = scanf("%zu", &sizeEntered);
        if(sizeEntered < 1 || sizeEntered > 100 || status == 0)
        {
            puts("Error: wrong number");
            continue;
        }
        printf("Great! The maximum string size in your hash table is %zu\n", sizeEntered);   
        break;
    }

    size = sizeEntered + 1;
    bufferString = (char*) malloc(size);

    HashTable *ht = initHT(size);
    puts("An empty hash table has been created");
    
    while(true)
    {
        flushInput();
        puts("\nPlease choose what you want to do with your hash table: \n"
             "To insert a new string to the hash table  ----------------------------- press 'A' \n"
             "To find a string in the hash table                                      press 'B' \n"
             "To remove a string from the hash table  ------------------------------- press 'C' \n"
             "To display the number of strings stored in the hash table               press 'D' \n"
             "To finish working with your hash table and clean up all its resources - press 'Q'");
        
        choice = getchar();

        switch(choice)
        {
            case'A': //To insert a new string to the hash table
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin);
                status = addStringHT(ht, bufferString, sizeEntered);
                if(!status)
                    puts("Great! You successfully inserted this string to the hash table");
                else
                {
                    puts("Some problems with this operation occured...");
                    return -1;
                }
                break;
            
            case'B': //To find a string in the hash table 
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin);
                flag = findStringHT (ht, bufferString, sizeEntered);
                
                if(flag)
                    puts("This string is in the hash table");
                else
                    puts("This string is NOT in the hash table");
                    
                break;            
            
            case'C': //To remove a string from the hash table
                flushInput();
                puts("\nPlease enter the string: ");
                fgets(bufferString, size, stdin); 
                
                status = removeElementHt(ht, bufferString, sizeEntered);
                
                if(!status)
                {
                    puts("This string has been removed from the hash table");
                }
                else if(status==-1)
                {
                    puts("Error: this string is not in the hash table");
                }
                else
                {
                    puts("Error: some problems occured during this operation");
                }
                break;

            case'D': //To display the number of strings stored in the hash table
                printf("There are %zu strings in the hash table\n", STRING_TOTAL_HT(ht));
                break;

            case'Q': //To finish working with your hash table and clean up all its resources
                free(bufferString);
                bufferString = NULL;
                status = removeHT(ht);

                if(!status)
                {
                    puts("Your hash table has been removed");
                    return 0;
                }   
                else
                {
                    puts("Problems with removing the hash table");
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