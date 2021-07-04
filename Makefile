
CC=gcc
CFLAGS= -Wall

program: main.o interface.o linked_list_interface.o linked_list.o doubly_linked_list_interface.o doubly_linked_list.o
	$(CC) $(CFLAGS) main.o interface.o linked_list_interface.o linked_list.o doubly_linked_list_interface.o doubly_linked_list.o -o program

main.o: ./src/main.c
	$(CC) $(CFLAGS) ./src/main.c -c

interface.o: ./src/interface.c
	$(CC) $(CFLAGS) ./src/interface.c -c

linked_list_interface.o: ./src/linked_list_interface.c
	$(CC) $(CFLAGS) ./src/linked_list_interface.c -c

linked_list.o: ./src/linked_list.c
	$(CC) $(CFLAGS) ./src/linked_list.c -c

doubly_linked_list_interface.o: ./src/doubly_linked_list_interface.c
	$(CC) $(CFLAGS) ./src/doubly_linked_list_interface.c -c

doubly_linked_list.o: ./src/doubly_linked_list.c
	$(CC) $(CFLAGS) ./src/doubly_linked_list.c -c

clean:
	rm *.o program


