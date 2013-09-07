all: dict
dict: main.o bst.o rbt.o
	g++ main.o bst.o rbt.o -o dict

main.o: main.cpp
	g++ -c main.cpp -o main.o

bst.o: bst.cpp
	g++ -c bst.cpp -o bst.o

rbt.o: rbt.cpp
	g++ -c rbt.cpp -o rbt.o

clean:
	rm *.o
