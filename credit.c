#include <stdio.h>
#include <cs50.h>

/* based on Luhn’s Algorithm */

int firstDigit(long n)  /* "slice" long numbers to get first digits */
{
    while (n >= 10)
    {
        n /= 10;
    }
    return n;
}

int secondFirstDigit(long n) /* "slice" long numbers to get first and second digits */
{
    while (n >= 100)
    {
        n /= 10;
    }
    return n;
}

int main(void)
{
    long input = get_long("Number: ");
    long loop = input;
    int counterOne = 0; /* stores the sum of products' digits */
    int counterTwo = 0; /* stores the sum of digits that weren't multiplied by 2 */
    long factorOne = 10; /* remove digits that weren't multiplied by 2 */
    long factorTwo = 100; /* "scrape" of digits of interest */
    while (loop != 0)
    {
        counterTwo += (loop % factorOne) / (factorOne / 10); /* get digits not multiplied by 2 */
        loop = loop - (loop % factorOne);
        int i = ((loop % factorTwo) / factorOne) * 2; /* check for products >= 10 */
        if (10 <= i)
        {
            int ones = i % 10; /* first digit of product >= 10 */
            int tens = (i - ones) / 10; /* second digit of product >= 10 */
            counterOne += ones + tens; /* sum of the digits of the product */
        }
        else
        {
            counterOne += i; /* one-digit products */
        }
        loop = loop - (loop % factorTwo);
        factorOne *= 100; /* step */
        factorTwo *= 100; /* step */
    }
    int legit = counterOne + counterTwo;
    if (legit % 10 == 0) /* test for invalid numbers */
    {
        if (input >= 100000000000000 && input < 1000000000000000) /* AMEX test */
        {
            int test = secondFirstDigit(input);
            if (test == 34 || test == 37) /* AMEX cards properties */
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (input >= 1000000000000000 && input < 10000000000000000) /* MASTERCARD or VISA test */
        {
            int testMaster = secondFirstDigit(input);
            int testVisa = firstDigit(input);
            if (testMaster == 51 || testMaster == 52 || testMaster == 53 || testMaster == 54
                || testMaster == 55)  /* MASTERCARD cards properties */
            {
                printf("MASTERCARD\n");
            }
            else if (testVisa == 4) /* VISA cards property */
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (input >= 1000000000000 && input < 10000000000000) /* VISA test two */
        {
            int test = firstDigit(input);
            if (test == 4) /* VISA cards property */
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}