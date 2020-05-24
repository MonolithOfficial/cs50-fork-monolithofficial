// Implements a dictionary's functionality
#define _OPEN_SYS_ITOA_EXT
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
int w_count = 0;

// Hash table
node *table[N];
FILE *fptr = NULL;

node *createNode(char *wordComponent)
{
    node *newNodePtr = malloc(sizeof(node));
    if (newNodePtr == NULL)
    {
        return NULL;
    }
    strcpy(newNodePtr->word, wordComponent);
    newNodePtr->next = NULL;
    // free(newNodePtr);
    return newNodePtr;
}

void push(node *head_ref, node *newNode)
{
    newNode->next = head_ref;
    head_ref = newNode;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // node *trav = NULL;
    int hashed_word = hash(word);
    // printf("%i", hashed_word);
    // printf("%s", table[hashed_word]->word);
    // if (table[hashed_word] == NULL)
    // {
    //     return true;
    // }
    node *trav = table[hashed_word];
    while (trav->next != NULL)
    {
        // printf("%i", 15);
        // printf("%i", hashed_word);
        if (strcmp(word, trav->word) == 0)
        {
            // break;
            return true;
        }
        else
        {
            trav = trav->next;
            printf("%i", hash((*trav).word));
            printf("%s", trav->word);
        }

    }


    // node *trav = table[5];
    // char *word_hash_5 = trav->word;
    // printf("%s\n", word_hash_5);
    // trav = trav->next;
    // word_hash_5 = trav->word;
    // printf("%s\n", word_hash_5);
    // printf("%s", trav->word);
    // trav = trav->next;
    // printf("%s", trav->word);
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    fptr = fopen(dictionary, "r");

    if (fptr == NULL)
    {
        return false;
    }
    for (int i = 0; i < N; i ++)
    {
        table[i] = NULL;
        printf("%p", table[i]);
    }
    int index = 0;
    char word[LENGTH + 1];
    node *appendingNode = NULL;
    FILE *fptr2 = fopen("sampletextdemo.txt", "w");
    FILE *hashFilePtr = fopen("hashdata.txt", "a");
    for (char *c = fgets(word, sizeof(word), fptr); c != NULL; c = fgets(word, sizeof(word), fptr))
    {
        // if (strcmp(fgets(word, sizeof(word), fptr), "death") == 0)
        // {
        //     return false;
        // }
        for (int k = 0; word[k] != '\0'; k++)
        {
            if (word[k] == '\n')
            {
                word[k] = '\0';
            }
        }
        int hash_code = hash(word);


        // push(table[hash_code], createNode(c));
        appendingNode = createNode(word);
        // strcpy(appendingNode->word, word);
        // printf("%s %i", appendingNode->word, hash_code);
        appendingNode->next = table[hash_code];
        table[hash_code] = appendingNode;

        // table[hash_code] = createNode(word);
        fputs(word, fptr2);
        fputc((char) hash_code, hashFilePtr);
        // printf("%i\n", hash_code);
        w_count++;

        // if (isalpha(c) || (c == '\'' && index > 0))
        // {
        //     word[index] = c;
        //     index++;
        // }
        // else if (index > 0)
        // {
        //     word[index] = '\0';
        //     int hash_code = hash(word);
        //     table[hash_code] = createNode(word);
        //     index = 0;
        // }
    }
    // node *traverse = table[24];
    // while (traverse->next != NULL)
    // {
    //     printf("%s", traverse->word);
    //     traverse = traverse->next;
    // }
    // printf("%s", appendingNode->word);
    return true;
}

// Hashes word to a number
// HASH FUNCTION BY leonbloy from Stackoverflow
unsigned int hash(const char *word)
{
    int sum = 0;
    // char lowerBuffer[LENGTH + 1];
    // for (int i = 0; word[i] != '\0'; i++)
    // {
    //     lowerBuffer[i] = tolower(word[i]);
    // }
    for (int j = 0; word[j] != '\0'; j++)
    {
        if (word[j] != '\n')
        {
            sum += tolower(word[j]);
        }
    }
    return sum % N;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (&load)
    {

        // for (int g = fgetc(fptr); g != EOF; g = fgetc(fptr))
        // {
        //     if (g == '\n')
        //     {
        //         w_count++;
        //     }
        // }
        return w_count - 1;
    }
    else
    {
        return 0;
    }

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    return true;
}