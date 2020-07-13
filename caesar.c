#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // ci = (pi + k) % 26
    int k;
    int i;
    // checks number of parameters
    if (argc == 2)
    {
        //in case that is a negative number input
        if (argv[1][0] ==  '-')
        {
            //i = 1;
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
        //for positive input
        else
        {
            i = 0;
        }
        //check if it's a valid key
        for (int n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }
        //finally turns key into integer
        k = atoi(argv[1]);
        string input = get_string("plaintext: ");
        //iterates over any char of the given plaintext
        for (int j = 0; j < strlen(input); j++)
        {
            if (isupper(input[j]))
            {
                //usage of "ci = (pi + k) % 26" for upper letters
                input[j] = (input[j] - 'A' + k) % 26 + 'A';
            }
            else if (islower(input[j]))
            {
                //usage of "ci = (pi + k) % 26" for lower letters
                input[j] = (input[j] - 'a' + k) % 26 + 'a';
            }
        }
        //printing the result
        printf("ciphertext: %s\n", input);
        return 0;
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}