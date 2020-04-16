#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) // Making sure our dear user not 66 or 33 arguments, but 2 and only 2 of them.
    {
        printf("Usage: ./caesar key\n"); // Yelling at our dear user.
        return 1; // Terminating the program.

    }
    int counter = 0; // This variable is used to count digit chars in our dear user's input (string).
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isdigit(argv[1][i]))
        {
            counter++; // Increments by one as the loop stumbles upon digits.
        }
        else
        {
            printf("Usage: ./caesar key\n"); // I tolerate not letters in here. And so I yell.
            return 1; // And crash the program in the face of misbehavior.
        }

    }
    int key = 0; // Initializing the key variable that'll hold filtered digits as one whole and positive integer.
    if (counter == strlen(argv[1]))
    {
        key = atoi(argv[1]); // Converting second command line argument to string (at last).
    }

    if (key != 0) // A key of 0 when trying to be secretive is quite pointless, amirite?
    {
        if (key > 26)
        {
            key %= 26; // Don't think you can bamboozle my program by entering 666. Checkmate.
        }
        string plaintext = get_string("Plaintext: "); // Prompting our dear user to tell me his secret. I can be trusted.
        for (int i = 0; plaintext[i] != '\0'; i++) // Going through the newly received string.
        {
            if (isalpha(plaintext[i])) // Is it a letter?
            {
                if (plaintext[i] >= 65 && plaintext[i] <= 90) // If it is, indeed, a letter, let me check the ASCII table for a sec.
                {
                    if (plaintext[i] + key > 90) // Ah, so it's one of those Uppercase ones. Those don't go beyond 90 (Z).
                    {
                        plaintext[i] = (plaintext[i] + key) - 90 + 64; // Let's make sure they start over from 65 (A) once 90 is reached..
                    }
                    else
                    {
                        plaintext[i] += key; // It's cool to be normal. Programmers don't gotsta mess with you.
                    }

                }
                else if (plaintext[i] >= 97 && plaintext[i] <= 122) // Ah, lowercase. Nice.
                {
                    if (plaintext[i] + key > 122) // Same operations as above.
                    {
                        plaintext[i] = (plaintext[i] + key) - 122 + 96;
                    }
                    else
                    {
                        plaintext[i] += key;
                    }
                }

            }

        }
        printf("ciphertext: %s\n", plaintext); // Do you smell what the rock is cooking?
    }
    else
    {
        printf("Usage: ./caesar key\n"); // If you did enter 0 like a real gangsta, this is where you get tackled.
        return 1; // Mm ha ha ha.
    }

}