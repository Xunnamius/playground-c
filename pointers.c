#include <stdio.h>
#include <stdlib.h>

void incrementByOne(int * x)
{
    *x = *x + 1;
}

int main()
{
    int count = 0;

    puts("Enter a digit: ");
    
    scanf("%i", &count);

    printf("You entered: %i\n", count);
    incrementByOne(&count);
    printf("Count is now: %i\n", count);

    printf("Size of int (8?): %lu\n", sizeof(int));

    char chars[] = "This is my character array";
    char * cp = chars;
    char c = *chars;

    printf("These four should be equal: %p %p %p %p\n", chars, &chars, &chars[0], &*cp);
    printf("But this should be different because dereferenced value is not a reference: %p", &c);
    puts("\n");

    return 0;
}
