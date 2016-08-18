/**
 * My implementation of a circular buffer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

const int BUFFER_SIZE = 24;

typedef struct CircularBuffer
{
    char buffer[BUFFER_SIZE] = '\0';
    int writePointer = 0;
    int readPointer = 0;
} CircularBuffer;

CircularBuffer* createCircularBuffer();
void writeByteToBuffer(CircularBuffer * circularBuffer, char * byte);
void readByteFromBuffer(CircularBuffer * circularBuffer);
void printBuffer(CircularBuffer * circularBuffer);

int main()
{
    CircularBuffer circularBuffer = createCircularBuffer();
    
    writeByteToBuffer(circularBuffer, 'A');
    printBuffer(circularBuffer);

    writeByteToBuffer(circularBuffer, 'B');
    writeByteToBuffer(circularBuffer, 'C');

    readByteFromBuffer(circularBuffer);
    printBuffer(circularBuffer);

    free(circularBuffer);
}

CircularBuffer* createCircularBuffer()
{
    CircularBuffer * circularBuffer = malloc(sizeof(CircularBuffer));
    assert(circularBuffer != NULL);

    return circularBuffer;
}

void writeByteToBuffer(CircularBuffer * circularBuffer, char byte)
{
    circularBuffer->buffer[circularBuffer->writePointer] = byte;
    circularBuffer->writePointer = (circularBuffer->writePointer + 1) % BUFFER_SIZE;
}

char readByteFromBuffer(CircularBuffer * circularBuffer)
{
    assert(circularBuffer->readPointer <= circularBuffer->writePointer);

    char byte = circularBuffer->buffer[circularBuffer->readPointer];
    circularBuffer->readPointer = (circularBuffer->readPointer + 1) % BUFFER_SIZE;
    return byte;
}

void printBuffer(CircularBuffer * circularBuffer)
{   
    int size = BUFFER_SIZE * 2 + 6;
    char str[size];
    str[0] = '[';
    str[size - 2] = ']';
    str[size - 1] = '\0';

    bool placedReadChars = false;
    bool placedWriteChars = false;

    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        int index = i * 2 + 1;

        if(i == circularBuffer->readPointer)
        {
            str[index] = 'R';
            str[index + 1] = '>';
            placedReadChars = true;
        }

        if(placedReadChars)
            index += 2;

        if(i == circularBuffer->writePointer)
        {
            str[index] = 'W';
            str[index + 1] = '>';
            placedWriteChars = true;
        }

        if(placedWriteChars)
            index += 2;

        str[index] = circularBuffer->buffer[i];

        if(index + 3 < size)
            str[index + 1] = ' ';
    }

    printf("contents: %s\n", str);
}
