SHELL = /bin/sh
CC = gcc
CFLAGS = -Wall
SOURCES = $(wildcard *.c)

.SUFFIXES:
.SUFFIXES: .c
.PHONY: clean all

all: $(subst .c,,$(SOURCES))

%:
	$(CC) $(CFLAGS) $@.c -o bin/$@

clean:
	rm -f bin/*
