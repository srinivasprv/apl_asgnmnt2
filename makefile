CC = g++
CFLAGS = -c
all: dict
dict: main.o  dict.o bst.o rbt.o
	$(CC) main.o dict.o bst.o rbt.o -o dict

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

dict.o: dict.cpp
	$(CC) $(CFLAGS) dict.cpp -o dict.o

bst.o: bst.cpp
	$(CC) $(CFLAGS) bst.cpp -o bst.o

rbt.o: rbt.cpp
	$(CC) $(CFLAGS) rbt.cpp -o rbt.o

clean:
	rm *.o dict
