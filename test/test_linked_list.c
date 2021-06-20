//use     "gcc -g test_linked_list.c ../src/linked_list.c"   when compiling
//use     "valgrind --leak-check=yes ./a.out"                to check errors with memory
#include<linked_list.h>


int main(void)
{
    List* list = init();

    printf("Now list has %zu nodes\n", size(list));

    int inhead = insertHead(list, "my string", 10);

    printf("Now list has %zu nodes\n", size(list));

    traverse(list);

    puts(" ");

    traverseData(list);

    int rem = removeList(list);
    if(!rem)
        puts("removeList works");

    return 0;
}