CC = g++
CFLAGS = -g -Wall -Wextra


default: bst

bst:Node.o BST.o main.o
	$(CC) $(CFLAGS) -o bst Node.o BST.o main.o

Node.o:	Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp
BST.o:	BST.cpp BST.h Node.h
	$(CC) $(CFLAGS) -c BST.cpp
main.o:	main.cpp BST.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) bst *.o *~
