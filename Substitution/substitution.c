#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // ensures you can only enter 1 key on the command line
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // ensures the length of the entered key is 26
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    /* ensures key is only alphabetic characters by
       iterating through the length of the key character by character. */
    for (int i = 0, alen = strlen(argv[1]); i < alen ; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    /* ensures key has no repeating characters by iterating
       through the length of the key character by character and
       checking each character against every other chracter.
       ensures case insensitivity.*/
    for (int i = 0, rxlen = strlen(argv[1]); i < rxlen; i++)
    {
        for (int j = i + 1, rylen = strlen(argv[1]); j < rylen; j++)
        {
            if ((toupper(argv[1][i])) == (toupper(argv[1][j])))
            {
                printf("Key must not contain repeating characters.\n");
                return 1;
            }
        }
    }
    string ptext = get_string("plaintext:  ");

    printf("ciphertext: ");

    /* iterates through the plain text character by character.
       ensures case of plaintext is enciphered and printed as written regardless of key case.
       prints value of plaintext using the key as an alphabet. */
    for (int i = 0, clen = strlen(ptext); i < clen ; i++)
    {
        if (isupper(ptext[i]))
        {
            printf("%c", toupper(argv[1][ptext[i] - 65]));
        }
        else if (islower(ptext[i]))
        {
            printf("%c", tolower(argv[1][ptext[i] - 97]));
        }
        else
        {
            printf("%c", ptext[i]);
        }
    }
    printf("\n");
    return 0;
}