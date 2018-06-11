IDIR=src/
CC=g++
FLAGS=-std=c++14 -I$(IDIR)

all: src/main.cc src/_unity.cc
	$(CC) $(FLAGS) -o bin/AddressBook src/main.cc src/_unity.cc


clear:
	rm bin/*