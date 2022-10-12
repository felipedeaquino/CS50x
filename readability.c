#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get input text
    string text = get_string("Text: ");

    // Get the number of letters found in text
    int letters = count_letters(text);

    // Get the number of words found in text
    int words = count_words(text);

    // Get the number of sentences found in text
    int sentences = count_sentences(text);

    // Coleman-Liau index of a text
    int index = round(0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8);

    // Print evaluated grade of a text
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

// Count the total number of letters of a given text
int count_letters(string text)
{
    int counter = 0;
    // Loop through all char to count if is a letter
    for (int i = 0; i < strlen(text); i++)
    {
        // Takes one character per loop
        char ch = text[i];
        // Checks if character is a letter. Non-alphabetic character returns 0 by definition
        if (isalpha(ch) != 0)
        {
            counter += 1;
        }
    }
    return counter;
}

// Count the total number of words of a given text
int count_words(string text)
{
    int words = 0;
    // Loop through all char to count words
    for (int i = 0; i < strlen(text); i++)
    {
        // Takes one character per loop
        char ch = text[i];
        // Checks if character is a letter. Non-alphabetic character returns 0 by definition
        if (ch == ' ')
        {
            words += 1;
        }
    }
    // Add last word
    words += 1;
    return words;
}

// Count the total number of sentences* of a given text
int count_sentences(string text)
{
    int sentences = 0;
    // Loop through all char to count sentences
    for (int i = 0; i < strlen(text); i++)
    {
        // Takes one character per loop
        char ch = text[i];
        // Checks if character is a letter. Non-alphabetic character returns 0 by definition
        if (ch == '.' || ch == '!' || ch == '?')
        {
            sentences += 1;
        }
    }
    return sentences;
}