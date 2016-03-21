/**
 * This program evaluates face values. Released under the Vegas Public License.
 *
 * Lol. Whatever.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char card_name[3];
    int val = 0;
    int count = 0;

    puts("Enter the card name: ");
    scanf("%2s", card_name);

    if(card_name[0] == 'K' || card_name[0] == 'Q' || card_name[0] == 'J')
        val = 10;

    else if(card_name[0] == 'A')
        val = 11;

    else
        val = atoi(card_name);

    printf("The card value is: %i\n", val);

    if(val >= 3 && val <= 6)
        puts('count goes up!');

    else if(val == 10)
        puts('count goes down!');

    return 0;
}
