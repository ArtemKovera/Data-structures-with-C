
CC=gcc
CFLAGS= -Wall

program: main.o interface.o linked_list_interface.o linked_list.o doubly_linked_list_interface.o doubly_linked_list.o stack_interface.o queue_interface.o hash_table_interface.o hash_table.o
	$(CC) $(CFLAGS) main.o interface.o linked_list_interface.o linked_list.o doubly_linked_list_interface.o doubly_linked_list.o stack_interface.o queue_interface.o hash_table_interface.o hash_table.o -o $@

main.o: ./src/main.c ./src/interface.h
	$(CC) $(CFLAGS) ./src/main.c -c

interface.o: ./src/interface.c ./src/interface.h
	$(CC) $(CFLAGS) ./src/interface.c -c

linked_list_interface.o: ./src/linked_list_interface.c ./src/linked_list.h ./src/interface.h
	$(CC) $(CFLAGS) ./src/linked_list_interface.c -c

linked_list.o: ./src/linked_list.c ./src/linked_list.h
	$(CC) $(CFLAGS) ./src/linked_list.c -c

doubly_linked_list_interface.o: ./src/doubly_linked_list_interface.c ./src/doubly_linked_list.h ./src/interface.h
	$(CC) $(CFLAGS) ./src/doubly_linked_list_interface.c -c

doubly_linked_list.o: ./src/doubly_linked_list.c ./src/doubly_linked_list.h
	$(CC) $(CFLAGS) ./src/doubly_linked_list.c -c

stack_interface.o: ./src/stack_interface.c ./src/linked_list.h ./src/interface.h
	$(CC) $(CFLAGS) ./src/stack_interface.c -c

queue_interface.o: ./src/queue_interface.c ./src/doubly_linked_list.h ./src/interface.h
	$(CC) $(CFLAGS) ./src/queue_interface.c -c

hash_table.o: ./src/hash_table.c ./src/hash_table.h 
	$(CC) $(CFLAGS) ./src/hash_table.c -c 

hash_table_interface.o: ./src/hash_table_interface.c ./src/hash_table.h ./src/interface.h 
	$(CC) $(CFLAGS) ./src/hash_table_interface.c -c

clean:
	rm *.o program


