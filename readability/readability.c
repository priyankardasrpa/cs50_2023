#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get the input text
    string text = get_string("Text: ");

    // Print the number of letters
    // printf("%d letters\n", count_letters(text));

    // Print the number of words
    // printf("%d words\n", count_words(text));

    // Print the number of sentences
    // printf("%d sentences\n", count_sentences(text));

    // Average number of letters per 100 words
    float L = ((float) count_letters(text) / (float) count_words(text)) * 100;

    // Average number of sentences per 100 words
    float S = ((float) count_sentences(text) / (float) count_words(text)) * 100;

    // Calculate the grade
    int index = (int) round(((0.0588 * L) - (0.296 * S) - 15.8));

    // If the index >= 16
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

// Count the number of letters in the text
int count_letters(string text)
{
    int index = 0;
    int count = 0;

    // Loop till the end of the string
    while (text[index] != '\0')
    {
        // Is the current character a letter
        if (isalpha(text[index]))
        {
            count += 1;
        }
        index += 1;
    }
    return count;
}

// Returns the number of words in the text
int count_words(string text)
{
    int count = 0;
    int index = 0;

    // Loop till the end of the string
    while (text[index] != '\0')
    {

        // If the current character is a space
        if (text[index] == ' ')
        {
            count += 1;
        }
        index += 1;
    }

    // There will be 1 more word than there are spaces
    return count + 1;
}

// Return the number of sentences
int count_sentences(string text)
{
    int index = 0;
    int count = 0;

    // Loop till the end of the string
    while (text[index] != '\0')
    {
        // Is the current character represents end of a sentence ?
        if (text[index] == '.')
        {
            count += 1;
        }
        else if (text[index] == '!')
        {
            count += 1;
        }
        else if (text[index] == '?')
        {
            count += 1;
        }

        index += 1;
    }

    return count;
}