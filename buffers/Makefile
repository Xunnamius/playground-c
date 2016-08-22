SHELL = /bin/sh
CC = gcc
CFLAGS = -Wall -std=c99
SOURCES = $(wildcard *.c)

.SUFFIXES:
.SUFFIXES: .c
.PHONY: clean all

all: $(subst .c,,$(SOURCES))

%:
	$(CC) $(CFLAGS) $@.c -o ../bin/$@ -lncurses

clean:
	rm -f ../bin/*
