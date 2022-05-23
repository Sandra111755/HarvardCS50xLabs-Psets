#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{

    // Get input words from both players.
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Checks values of scores and outputs the winner or if it's a tie.
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

/*  Initializes variable to keep track of score

    Iterates the length of the entered word.

    Uses islower to determine if the characters in the word array are lower case.

    If they are lowercase, the score is then updated using
    the ASCII values of the characters in the word array minus 97
    as the index number of the POINTS array.

    Else they are uppercase and the score is updated using
    the ASCII values of the characters in the word string minus 65
    as the index number of the POINTS array.

    All special characters pass through and are not counted.

    Returns the value of score1 and score2 */
int compute_score(string word)
{
    int score = 0;

    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (islower(word[i]))
        {
            score = score + POINTS[word[i] - 97];
        }
        else
        {
            score = score + POINTS[word[i] - 65];
        }
    }
    return score;
}
