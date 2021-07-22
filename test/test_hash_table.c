//use     "gcc -g  test_hash_table.c ../src/hash_table.c ../src/linked_list.c"   when compiling
//use     "valgrind --leak-check=yes ./a.out"                to check errors with memory
/* 

   it is supposed that all functions for the hash table must be tested here in various situations.
   
   *** but the main test will be in the main program ***

*/
#include"./../src/hash_table.h"
#include<stdio.h>


int main()
{
    int status = 0;
    
    //testing initHT()

    //initializing hash table which works with 1-character strings
    HashTable *ht1 = initHT(1);

    //initializing hash table which works with 10-character strings
    HashTable *ht10 = initHT(10);

    //initializing hash table which works with 50-character strings
    HashTable *ht50 = initHT(50); 

    //initializing hash table which works with 50-character strings
    HashTable *ht100 = initHT(100);


    //testing addStringHT()
    status = addStringHT(ht10, "aa", 10);
    if(status == 0)
    {
       puts("The string aa has been added successfully to ht10"); 
    }
    else
    {   
        puts("Some problem has occured with string insertion");
        printf("the status is %d\n", status);
    }

    status = addStringHT(ht10, "cccccccc", 10);
    if(status == 0)
    {
       puts("The string ccccccccc has been added successfully"); 
    }
    else
    {   
        puts("Some problem has occured with string insertion");
        printf("the status is %d\n", status);
    }

    status = addStringHT(ht10, "cccccccbd", 10);
    if(status == 0)
    {
       puts("The string ccccccccbd has been added successfully"); 
    }
    else
    {   
        puts("Some problem has occured with string insertion");
        printf("the status is %d\n", status);
    }  

    printf("The total number of strings in the hash table = %lu\n", STRING_TOTAL_HT(ht10)); 


    //testing removeElementHt()
    status = removeElementHt(ht10, "cccccccbd", 10);
        if(status == 0)
    {
       puts("The string ccccccccbd has been removed successfully"); 
    }
    else
    {   
        puts("Some problem has occured with string removal");
        printf("the status is %d\n", status);
    }  

    status = removeElementHt(ht10, "cccccccc", 10);
    if(status == 0)
    {
       puts("The string cccccccc has been removed successfully"); 
    }
    else
    {   
        puts("Some problem has occured with string removal");
        printf("the status is %d\n", status);
    }  


    
    //testing findStringHT()
    if(findStringHT(ht10, "aa", 10))
    {
        puts("\"aa\" is in the hash table");
    }
    else
    {
        puts("\"aa\" is not in the hash table");        
    }
    

    if(findStringHT(ht10, "bb", 10))
    {
        puts("\"bb\" is in the hash table");
    }
    else
    {
        puts("\"bb\" is not in the hash table");        
    }

    if(findStringHT(ht10, "Zh", 10))
    {
        puts("\"Zh\" is in the hash table");
    }
    else
    {
        puts("\"Zh\" is not in the hash table");        
    }  

    if(findStringHT(ht10, "cccccccc", 10))
    {
        puts("\"cccccccccc\" is in the hash table");
    }
    else
    {
        puts("\"cccccccccc\" is not in the hash table");        
    }       

    if(findStringHT(ht10, "cccccccbd", 10))
    {
        puts("\"cccccccbd\" is in the hash table");
    }
    else
    {
        puts("\"cccccccbd\" is not in the hash table");        
    }    

    printf("The total number of strings in the hash table = %lu\n", STRING_TOTAL_HT(ht10)); 


    //testing removeHT()
    status = removeHT(ht10);
    if(status == 0)
    {
       puts("ht10 has been deleted successfully"); 
    }  
    
    status = removeHT(ht1);
    if(status == 0)
    {
       puts("ht1 has been deleted successfully"); 
    }   
    
    status = removeHT(ht50);
    if(status == 0)
    {
       puts("ht50 has been deleted successfully"); 
    }

    status = removeHT(ht100);
    if(status == 0)
    {
       puts("ht100 has been deleted successfully"); 
    }


    return 0;
}