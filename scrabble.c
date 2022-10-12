#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Compares scores
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

// Computes score based on previous mapping of points
int compute_score(string word)
{
    // Array of letters from the alphabet
    char ALPHABET[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // Starts score with 0 points
    int score = 0;

    // loop through all letters from given word
    for (int i = 0; i < strlen(word); i++)
    {
        // takes one character per loop, making sure that it's uppercase to compare if it's within uppercase letters range in ASCII
        char ch = toupper(word[i]);
        if (64 < (int)ch && (int)ch < 91)
        {
            // equalizes the value of A in ASCII with 0, i.e., first index of POINTS
            int letterIndex = (int)ch - 65;
            score += POINTS[letterIndex];
        }
    }
    return score;
}
