// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <stdlib.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Declare variables
unsigned int word_count;
unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    node *cursor = table[hash_value];

    // Traverse linked list for word
    // cursor must point to next element
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Simple hash function, should be fast, parces through and divides to find answer
    // Credit - https://joseph28robinson.medium.com/cs50-pset-5-speller-f9c89d08237e
    unsigned long answer = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        answer += tolower(word[i]);
    }
    return answer % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open file
    FILE *file = fopen(dictionary, "r");

    //return NULL if file cannot be opened
    if (file == NULL)
    {
        printf("unable to open %s\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];

    //scan dictionary for strings until EOF
    while (fscanf(file, "%s", word) != EOF)
    {
        //Allocate memory for new node
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        //copy word to node
        strcpy(n->word, word);
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            // assign temp variable so not to lose access to the rest of the elements in bucket
            node *temp = cursor;
            cursor = cursor->next;
            // free temp without losing access to bucket elements
            free(temp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
