#include"interface.h"
#include"linked_list.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//returns 0 if call is successful 
//returns -1 otherwise
int linkedListInterface(void)
{   
    char choice = 0;
    int status  = 0;


    List* list = init();
    puts("An empty linked list has been created");

    
    while(true)
    {
        
        puts("Please choose what you want to do with your list: \n"
             "To insert a new string at the head of the list                   - press 'A' \n"
             "To insert a new string after a given address                     - press 'B' \n"
             "To insert a new string after a given index                       - press 'C' \n"
             "To remove the string after a given address                       - press 'D' \n"
             "To remove the string at the head of the list                     - press 'E' \n"
             "To display all strings in the list                               - press 'F' \n"
             "To display all strings, node indexes and addresses in the list   - press 'G' \n"
             "To display the sting at a given address                          - press 'H' \n"
             "To display the string at a given index                           - press 'I' \n"
             "To display the address of the next element                       - press 'J' \n"
             "To display the address of the head of the list                   - press 'K' \n"
             "To display the address of the tail of the list                   - press 'L' \n"
             "To display the number of the strings stored in the list          - press 'M' \n"
             "To finish working with your list and clean up all its resources  - press 'N'");
        
        flushInput();
        choice = getchar();

        switch(choice)
        {

        }
    }

  

    int removeStatus = removeList(list);
    if(!removeStatus)
        puts("Your linked list has been removed");
    else
    {
        puts("Problems with removing the list");
        return -1;
    }
    
    return 0;
}