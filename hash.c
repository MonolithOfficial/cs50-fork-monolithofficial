#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define LENGTH 45
const unsigned int N = 6000;

unsigned long hash(char *word)
    {
        // int sum = 0;
        // // char lowerBuffer[LENGTH + 1];
        // // for (int i = 0; word[i] != '\0'; i++)
        // // {
        // //     lowerBuffer[i] = tolower(word[i]);
        // // }
        // for (int j = 0; word[j] != '\0'; j++)
        // {
        //     if (word[j] != '\n')
        //     {
        //         sum += tolower(word[j]);
        //     }
        // }
        // return (sum) % N;
        unsigned long hash = 5381;
        int c;

        while ((0 != (c = *word++)))
            hash = ((hash << 4) + hash) + c; /* hash * 33 + c */

        return hash % N;
    }
int main (void)
{
    printf("%lu", hash("foraged"));
}