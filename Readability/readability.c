#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

/*  main function takes an argument as a string.
    uses Coleman-Liau formula to find the grade level of the text and prints out accordingly
*/

int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);

    int lcount = count_letters(text);
    int wcount = count_words(text);
    int scount = count_sentences(text);

    int index = round(0.0588 * lcount / wcount * 100 - 0.296 * scount / wcount * 100 - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

/*  iterates through the entered string, if the characters are
    alphanumeric it adds to the counter
    then returns that letter count to main
*/

int count_letters(string text)
{
    int lcount = 0;

    for (int i = 0, letters = strlen(text); i < letters; i++)
    {
        if (isalnum(text[i]))
        {
            lcount++;
        }
    }
    return lcount;
}

/*  iterates through the entered string and counts each space as applied to the word before it
    count++ added at the end because i was to assume that there would be no trailing spaces.
    returns the spaces +1 count to main
*/

int count_words(string text)
{
    int wcount = 0;

    for (int i = 0, words = strlen(text); i < words; i++)
    {
        if (isspace(text[i]))
        {
            wcount++;
        }
    }
    wcount++;
    return wcount;
}

/*  iterates through the entered string and
    counts each period, exclamation, and question mark
    returns that number count to main
*/

int count_sentences(string text)
{
    int scount = 0;

    for (int i = 0, sents = strlen(text); i < sents; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            scount++;
        }
    }
    return scount;
}