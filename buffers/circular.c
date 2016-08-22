/**
 * My implementation of a circular buffer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>

#define BUFFER_SIZE 24

typedef struct CircularBuffer
{
    char buffer[BUFFER_SIZE];
    int writePointer;
    int readPointer;
    int numElements;
} CircularBuffer; 

CircularBuffer * createCircularBuffer();
int writeByteToBuffer(CircularBuffer * circularBuffer, char byte);
char readByteFromBuffer(CircularBuffer * circularBuffer);
void printBuffer(const CircularBuffer * circularBuffer);

int main()
{
    CircularBuffer * circularBuffer = createCircularBuffer();
    char input;

    initscr();
    scrollok(stdscr, true);
    cbreak();
    noecho();

    printw("::Initial state:: ");
    refresh();
    printBuffer(circularBuffer);
    refresh();

    printw("\nType - to exit the program\n");
    printw("Type = to print the buffer\n");
    printw("Press space to read a character\n");
    printw("Type any character to add it to the buffer\n");
    refresh();

    while(input != '-')
    {
        input = getch();

        if(input == ' ')
        {
            char byteRead = readByteFromBuffer(circularBuffer);

            if(byteRead == '\0')
                printw("<the buffer is empty>\n");
            else
                printw("Read byte: %c\n", byteRead);
        }

        else if(input == '=')
            printBuffer(circularBuffer);

        else
        {
            if(writeByteToBuffer(circularBuffer, input))
                printw("Wrote byte: %c\n", input);
            else
                printw("<the buffer is full>\n");
        }

        refresh();
    }

    free(circularBuffer);
    endwin();

    printf("Exited!\n");

    return 0;
}

/**
 * Creates a circular buffer on the heap and returns a pointer to it. This pointer
 * must be free()'d manually.
 *
 * @return a CircularBuffer pointer to a newly initialized circular buffer
 */
CircularBuffer* createCircularBuffer()
{
    CircularBuffer * circularBuffer = malloc(sizeof(CircularBuffer));
    assert(circularBuffer != NULL);

    memset(circularBuffer->buffer, '.', sizeof(circularBuffer->buffer));

    circularBuffer->writePointer = 0;
    circularBuffer->readPointer = 0;
    circularBuffer->numElements = 0;

    return circularBuffer;
}

/**
 * Write a byte to a circular buffer. Returns 0 on failure (buffer full), -1 on
 * success.
 *
 * @param  circularBuffer The buffer to update
 * @param  byte           The byte to write
 *
 * @return                An integer status
 */
int writeByteToBuffer(CircularBuffer * circularBuffer, char byte)
{
    if(circularBuffer->numElements >= BUFFER_SIZE)
        return 0;

    circularBuffer->buffer[circularBuffer->writePointer] = byte;
    circularBuffer->writePointer = (circularBuffer->writePointer + 1) % BUFFER_SIZE;
    circularBuffer->numElements++;
    return -1;
}

/**
 * Read a byte from a circular buffer. Returns a NULL character on failure
 * (buffer empty), or a byte on success.
 *
 * @param  circularBuffer The buffer to read from
 *
 * @return                A byte from the buffer or NULL character on failure
 */
char readByteFromBuffer(CircularBuffer * circularBuffer)
{
    if(circularBuffer->numElements <= 0)
        return '\0';

    char byte = circularBuffer->buffer[circularBuffer->readPointer];
    circularBuffer->readPointer = (circularBuffer->readPointer + 1) % BUFFER_SIZE;
    circularBuffer->numElements--;
    return byte;
}

/**
 * Prints the contents of a circular buffer.
 *
 * @param circularBuffer The buffer to print the contents of
 */
void printBuffer(const CircularBuffer * circularBuffer)
{   
    int size = BUFFER_SIZE * 2 + 6;
    char str[size];

    str[0] = '[';
    str[size - 2] = ']';
    str[size - 1] = '\0';

    int index = 1;

    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        if(i == circularBuffer->readPointer)
        {
            str[index++] = 'R';
            str[index++] = '>';
        }

        if(i == circularBuffer->writePointer)
        {
            str[index++] = 'W';
            str[index++] = '>';
        }

        str[index++] = circularBuffer->buffer[i];

        if(index + 3 < size)
            str[index++] = ' ';
    }

    printw("Buffer contents: %s\n", str);
}
