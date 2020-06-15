#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is yout name?\n"); /* getting name of the user */
    printf("hello, %s\n", name); /* prints hello plus user name */
}