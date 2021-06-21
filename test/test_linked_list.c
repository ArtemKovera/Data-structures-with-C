//use     "gcc -g -idirafter ../src/ test_linked_list.c ../src/linked_list.c"   when compiling
//use     "valgrind --leak-check=yes ./a.out"                to check errors with memory
//it is supposed that all functions for a linked list must be tested here in various situations.
#include<linked_list.h>


int main(void)
{
    //initializing new list
    puts("Initializing first list"); 
    List* list = init(); 
    printf("Now list has %zu nodes\n", size(list));

    //testing insertHead 
    insertHead(list, "my string", 10);
    printf("Now list has %zu nodes\n", size(list));
    
    traverse(list);        
    traverseData(list);
    
    //testing insertHead
    insertHead(list, "my new head string", 19);
    puts(" ");
    traverse(list);
    
    //testing insertNext
    insertNext(list, list->head, "Some words to store", 20);

    puts(" ");
    printf("Now list has %zu nodes\n", size(list));
    traverse(list);

    //testing nextNode
    Node* ptr = nextNode(list->head); //pointer pointing to the next node after the head

    //testing insertNext
    insertNext(list, ptr, "Some more words to store", 26);

    puts(" ");
    printf("Now list has %zu nodes\n", size(list));
    traverse(list);
    traverseData(list);

    puts(" ");

    //testing insertAfterIndex
    insertAfterIndex(list, 1, "Insert with index", 18);
    printf("Now list has %zu nodes\n", size(list));
    traverseData(list);

    //testing removing elements
    removeHead(list);
    puts(" ");
    printf("Now list has %zu nodes\n", size(list));
    traverseData(list);

    removeNodeAfterAddress(list, list->head);
    puts(" ");
    printf("Now list has %zu nodes\n", size(list));
    traverseData(list);

    removeNodeAfterAddress(list, list->head);
    puts(" ");
    printf("Now list has %zu nodes\n", size(list));
    traverseData(list);

    //testing data and dataAtIndex
    printf("testing data() - %s\n", data(list, list->head));    
    printf("testing dataAtIndex() - %s\n", dataAtIndex(list, 1));    
    puts(" ");

    //testing getHead and getTail 
    printf("Now list has %zu nodes\n", size(list));
    printf("List head at - %p\n", getHead(list));
    printf("List tail at - %p\n", getTail(list));
    traverse(list);

    puts(" ");
    int rem = removeList(list);
    if(!rem)
        puts("removeList works for the first list");

    puts("----------------------------------------\n");

    //initializing new list
    puts("Initializing second list"); 
    List* list2 = init(); 
    printf("Now list has %zu nodes\n", size(list2));

    //testing removing an empty list
    int rem2 = removeList(list2);
    if(!rem2)
        puts("removeList works for the second list");

    puts("----------------------------------------\n");

    //initializing new list
    puts("Initializing third list"); 
    List* list3 = init(); 
    printf("Now list has %zu nodes\n", size(list3));

    //testing traversing an empty list 
    traverse(list3);
    traverseData(list3);
    
    //testing insertNext in a wrong situation
    insertNext(list3, list3->head, "Some words to store", 20);
    traverseData(list3);

    //testing insertAfterIndex in a wrong situation
    insertAfterIndex(list3, 0, "Some string1", 13);
    insertAfterIndex(list3, 1, "Some string2", 13);
    traverseData(list3);

    //testing removeNodeAfterAddress in a wrong situation
    removeNodeAfterAddress(list3, list3->head);
    removeNodeAfterAddress(list3, list3->tail);

    //testing removeHead in a wrong situation
    removeHead(list3);

    //testing data and dataAtIndex in a wrong situation
    if(data(list3, list3->head))
        printf("testing data() - %s\n", data(list3, list3->head));  

    if(dataAtIndex(list3, 1))  
        printf("testing dataAtIndex() - %s\n", dataAtIndex(list3, 1)); 

    int rem3 = removeList(list3);
    if(!rem3)
        puts("removeList works for the third list");

    puts("----------------------------------------\n");

    //initializing forth list
    //testing node addresses in various situations
    puts("Initializing forth list"); 
    List* list4 = init(); 

    insertHead(list4, "head1", 6);
    insertHead(list4, "head2", 6);
    insertHead(list4, "head3", 6);
    printf("Now list has %zu nodes\n", size(list4));
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4));  

    puts("\n");
    removeHead(list4); 
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4));  

    puts("\n");
    removeHead(list4); 
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4));   

    puts("\n");
    insertAfterIndex(list4, 0, "tail", 5); 
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4));    

    puts("\n");
    removeNodeAfterAddress(list4, list4->head);   
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4)); 

    puts("\n");
    insertNext(list4, list4->head, "tail", 5);
    insertNext(list4, list4->head, "middle", 7);
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4));    

    puts("\n");
    insertNext(list4, list4->head->next, "middle2", 8);
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4));    

    puts("\n");
    removeNodeAfterAddress(list4, list4->head->next);
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4)); 

    puts("\n");
    insertNext(list4, list4->tail, "tail2", 6);
    traverse(list4);
    printf("List4 head at - %p\n", getHead(list4));
    printf("List4 tail at - %p\n", getTail(list4));                    
    
    puts("\n");
    int rem4 = removeList(list4);
    if(!rem4)
        puts("removeList works for the forth list");
    
    return 0;
}