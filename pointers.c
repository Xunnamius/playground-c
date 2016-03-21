#include <stdio.h>
#include <stdlib.h>

void incrementByOne(int * x)
{
    *x = *x + 1;
}

int main()
{
    int count = 0;
    char rawint[2];

    puts("Enter a digit: ");
    
    scanf("%s", rawint);
    count = (int) atoi(rawint);

    printf("You entered: %i\n", count);
    incrementByOne(&count);
    printf("Count is now: %i\n", count);

    return 0;
}
