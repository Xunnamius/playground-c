SHELL = /bin/sh
CC = gcc
CFLAGS = -Wall -g
SOURCES = $(wildcard *.c)

.SUFFIXES:
.SUFFIXES: .c
.PHONY: clean all

all: $(subst .c,,$(SOURCES))

%:
	$(CC) $(CFLAGS) $@.c -o bin/$@

clean:
	rm -rf bin/*
