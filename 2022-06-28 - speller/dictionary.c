// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];

// Global variables

unsigned int wordcounter = 0;
unsigned int hashvalue = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // returns a hash value for the given word, uses that hashvalue as the tables index for a traversal pointer

    hashvalue = hash(word);
    node *travpointer = table[hashvalue];

    /* as long as the pointer isn't null, it compares the given word to the traversal pointers word case insensitively
       if the word matches the pointers word ( ==0 ) then return true, else return false*/
    while (travpointer != NULL)
    {
        if (strcasecmp(word, travpointer->word) == 0)
        {
            return true;
        }
        else
        {
            travpointer = travpointer->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hashtotal = 0;

    /* used given information (short on hash tables & the provided basic hash function) as inspiration.
       i tried a few different more complex methods that just didn't work out as they should have and i couldn't
       figure out how to work through them to get the results i was looking for.
       this iterates the length of the word, adds the ASCII values of each letter (forced to lowercase) to hashvalue
       returns the hashvalue modulo the number of buckets(N) to ensure the words stay within
       the boundary of the amount of buckets
       */
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        hashtotal += tolower(word[i]);
    }
    return hashtotal % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // char array size of LENGTH + 1 for storing words
    char word[LENGTH + 1];

    // open dictionary with safety check
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Not enough memory to open %s\n", dictionary);
        return false;
    }

    /* loops through every single word in the dictionary until EOF
       creates a node with safety check, copies the value at n->word into word array
       iterates word counter, gets hashvalue of word, uses hashvalue to assign placement of node
       update table[hashvalue] to point to new node*/
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Not enough memory to allocate node");
            return false;
        }

        strcpy(n->word, word);
        wordcounter++;
        hashvalue = hash(word);
        n->next = table[hashvalue];
        table[hashvalue] = n;
    }

    // frees dictionary from memory

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (wordcounter > 0)
    {
        return wordcounter;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterates buckets one at a time

    for (int i = 0; i < N; i++)
    {
        // create indexpointer for keeping track of files in linked list, with i being the current bucket

        node *indexpointer = table[i];

        /* while the indexpointer isn't null : create a traversal pointer pointed at the same value as indexpointer,
            move to the next node in the linked list, free the current traversal pointer*/
        while (indexpointer != NULL)
        {
            node *travpointer = indexpointer;

            indexpointer = indexpointer->next;

            free(travpointer);
        }

        // if the indexpointer is NULL and you've reached the end of the last bucket

        if (indexpointer == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
