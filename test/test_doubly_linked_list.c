//use     "gcc -g  test_doubly_linked_list.c ../src/doubly_linked_list.c"   when compiling
//use     "valgrind --leak-check=yes ./a.out"                to check errors with memory
//it is supposed that all functions for a linked list must be tested here in various situations.
#include"./../src/doubly_linked_list.h"

int main()
{   
    int status = 0;
    DList * list = initDL();
    puts("A Doubly linked list has been created");
    printf("The size of the list is %lu\n", getSizeDL(list));
    

    //Testing insertHeadDL(), insertTailDL(), insertAfterIndexDL(), insertBeforeIndexDL()
    puts(" ");
    puts("Inserting head...");
    status = insertHeadDL(list, "First words", 12);
    if(!status)
        puts("Head has been inserted to the list");
    
    printf("The size of the list is %lu\n", getSizeDL(list));
    puts(" ");

    puts("Inserting new head...");
    status = insertHeadDL(list, "New head", 10);
    if(!status)
        puts("A new head has been inserted to the list");
    
    printf("The size of the list is %lu\n", getSizeDL(list));
    puts(" ");

    puts("Inserting tail...");
    status = insertTailDL(list, "First tail", 12);
    if(!status)
        puts("A tail has been inserted to the list");
    printf("The size of the list is %lu\n", getSizeDL(list));
    puts(" ");  

    puts("Inserting a new tail...");
    status = insertTailDL(list, "A new tail", 11);
    if(!status)
        puts("A new tail has been inserted to the list");
    printf("The size of the list is %lu\n", getSizeDL(list));
    puts(" ");  

    puts("Inserting after index 1...");
    status = insertAfterIndexDL(list, 1, "after index 1", 14);
    if(!status)
        puts("A new string has been inserted after index 1");
    printf("The size of the list is %lu\n", getSizeDL(list));
    puts(" ");  

    puts("Inserting before index 3...");
    status = insertBeforeIndexDL(list, 3, "This string is at index 3 now", 30);
    if(!status)
        puts("A new string has been inserted before index 3");
    printf("The size of the list is %lu\n", getSizeDL(list));
    puts(" "); 


    //Testing traverseDL(), traverseBackwordDL(), dataAndIndexies()
    puts("Traversing the list: ");
    traverseDL(list);

    puts(" ");
    puts("Traversing the list backword: ");    
    traverseBackwordDL(list);
    
    puts(" ");
    puts("Data and indexies: "); 
    dataAndIndexies(list);

  
    // testing findDataFromHeadDL() and findDataFromTailDL()
    puts("Finding strings in the list: \n");

    puts("Finding the string 'This string is at index 3 now' starting from head");
    status = findDataFromHeadDL(list, "This string is at index 3 now");
    if(status >= 0)
        printf("This string is found at index %d\n", status);
    else if(status == -1)
        printf("This string is not found\n");  
    puts(" ");   

    puts("Finding the string 'This string is at index 3 now' starting from tail");
    status = findDataFromTailDL(list, "This string is at index 3 now");
    if(status >= 0)
        printf("This string is found at index %d\n", status);
    else if(status == -1)
        printf("This string is not found\n");  
    puts(" ");

    puts("Finding the string 'Some random string' starting from head");
    status = findDataFromHeadDL(list, "Some random string");
    if(status >= 0)
        printf("This string is found at index %d\n", status);
    else if(status == -1)
        printf("This string is not found\n");  
    puts(" ");   

    puts("Finding the string 'Some random string' starting from tail");
    status = findDataFromTailDL(list, "Some random string");
    if(status >= 0)
        printf("This string is found at index %d\n", status);
    else if(status == -1)
        printf("This string is not found\n");  
    puts(" "); 
    
    //Testing dataAtIndexDL()
    puts("Testing dataAtIndexDL()");
    printf("The string at index 2 is \"%s\" \n", dataAtIndexDL(list, 2));
    printf("The string at index 3 is \"%s\" \n", dataAtIndexDL(list, 3));
    puts(" ");

    //Testing removeAtIndexDL(), removeHeadDL(), removeTailDL()
    puts("Deleting the node at index 3");
    status = removeAtIndexDL(list, 3);     
    if(!status)
        puts("The element has been deleted");
    puts(" ");
    puts("Deleting the node at index 2");
    status = removeAtIndexDL(list, 2);     
    if(!status)
        puts("The element has been deleted");
    puts(" ");
    

    puts("Deleting the head");
    status = removeHeadDL(list);     
    if(!status)
        puts("The head has been deleted");
    puts(" ");
    puts("Deleting the tail");
    status = removeTailDL(list);     
    if(!status)
        puts("The tail has been deleted");
    puts(" ");  
    

    puts("Traversing the list again:");
    dataAndIndexies(list);       

    //Testing saveToFile()
    puts("Saving the list to a file");
    status = saveToFile(list, "text.txt");
    if(!status)
        puts("The list has been saved to file");
    puts(" ");
    
    status = removeDL(list);
    if(!status)
        puts("The list has been deleted");

    puts("Everything works");
    return 0;
}