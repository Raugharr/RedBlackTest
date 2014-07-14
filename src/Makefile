CC=gcc
CFLAGS=-Wall
OBJFLD=obj/
NAME=RBTree

RBTree.o: RBTree.c RBTree.h
	$(CC) -c -o $(OBJFLD)RBTree.o RBTree.c $(CFLAGS)
	
all: main.c RBTree.o
	$(CC) -o ../$(NAME) main.c $(OBJFLD)*

.PHONY: clean all

clean:
	rm $(OBJFLD)*.o
