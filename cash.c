#include <stdio.h>
#include <cs50.h>
#include <math.h> /* importing math library to use round */

int main(void)
{
    float change; /* global variable for future uses outside of the do-while loop */
    do
    {
        change  = get_float("Change owed: "); /* get user's input */
    }
    while (change < 0); /* prevents negative values */
    int cents = round(change * 100); /* rounding input */
    int coins = 0; /* keeps track of how many coins we need */
    while (cents > 0) /* loop */
    {
        if (cents - 25 >= 0) /* try a quarter */
        {
            cents = cents - 25; /* subtracts a quarter */
            coins++; /* count plus one coin */
        }
        else if (cents - 10 >= 0) /* try a dime */
        {
            cents = cents - 10;
            coins ++;
        }
        else if (cents - 5 >= 0) /* try a nickel */
        {
            cents = cents - 5;
            coins++;
        }
        else if (cents - 1 >= 0) /* try a penny */
        {
            cents = cents - 1;
            coins++;
        }
    }
    printf("%i\n", coins); /* prints result */
}