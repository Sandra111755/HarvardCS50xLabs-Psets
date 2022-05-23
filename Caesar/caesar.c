#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string odns);
char rotate(char ptext, int key);

int main(int argc, string argv[])
{
    // ensures a key is entered on the command line, and that key is only digits 0-9
    if (argc == 2 && only_digits(argv[1]))
    {
        // passes the value of argv[1] to the key variable as an integer
        int key = atoi(argv[1]);

        string ptext = get_string("plaintext:  ");
        printf("ciphertext: ");

        /* iterates the length of the user entered plain text character by character,
        calls rotate function on each character of the plain text then prints out the key shifted value*/
        for (int i = 0, len = strlen(ptext); i < len; i++)
        {
            char pchar = rotate(ptext[i], key);
            printf("%c", pchar);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

/*  iterates through the inputted string from argv[1].
    passed the i-th letter of the ods string to c and
    uses !isdigit to return false as soon as it detects an
    input that is not 0-9. */

bool only_digits(string ods)
{
    for (int i = 0, len = strlen(ods); i < len; i++)
    {
        char c = ods[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}
/* rotate character values based on the key entered,
ensures case sensitivity and passes through special characters.*/
char rotate(char pchar, int key)
{
    if (isalpha(pchar))
    {
        if (islower(pchar))
        {
            char c = (pchar + key - 97) % 26 + 97;
            return c;
        }
        else
        {
            char c = (pchar + key - 65) % 26 + 65;
            return c;
        }
    }
    else
    {
        return pchar;
    }
}