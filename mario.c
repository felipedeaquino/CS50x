#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height; /* global variable for future uses outside of the do-while loop */
    do
    {
        height = get_int("Height: "); /* get user's input for making Mario's pyramid */
    }
    while (height <= 0 || height > 8); /* loop to guarantee desirable input */
    for (int loop = height; loop >= 1; loop--) /* loop to make the pyramid instructions */
    {
        for (int space = 1; space < loop; space++) /* first set of spaces */
        {
            printf(" ");
        }
        for (int bricks = loop; bricks <= height; bricks++) /* first set of hashes */
        {
            printf("#");
        }
        printf("  "); /* gap between hashes */
        for (int bricks2 = loop; bricks2 <= height; bricks2++) /* second set of hashes */
        {
            printf("#");
        }
        printf("\n"); /* new line */
    }
}