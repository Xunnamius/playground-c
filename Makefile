.PHONY all: cards pointers

cards:
	gcc cards.c -o cards

runcards: cards
	./cards

pointers:
	gcc pointers.c -o pointers

runpointers: pointers
	./pointers
