#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc != 2) // Checking if there are precisely 2 command line arguments.
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26) // Checking if there are precisely 26 characters in the second cl argument.
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    int count = 0; // Variable used to count alpabetic characters in the received argument.
    int duplicateCount = 0; // variable used to store the number of duplicates inside said argument.
    for (int i = 0; argv[1][i] != '\0'; i++) // Iterating through the argument.
    {
        if (isalpha(argv[1][i]))
        {
            count++;
        }
        for (int j = i + 1; argv[1][j] != '\0'; j++) // Engaging a second loop to single out duplicates.
        {
            if (argv[1][i] == argv[1][j])
            {
                duplicateCount++; // Counting duplicates for a later condition.
            }
        }
    }
    if (count != strlen(argv[1])
        || duplicateCount != 0) // Do not allow further runtime if the number of duplicates is something other than 0.
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("Plaintext: "); // Requesting input.
        string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Reference alphabet for uppercase characters.
        string lowerAlphabet = "abcdefghijklmnopqrstuvwxyz"; // Reference alphabet for lowercase characters.
        int index = 0; // Initializing the index variable.
        printf("ciphertext: "); // Readying first part of the output in advance, before loops do their work.
        for (int i = 0; plaintext[i] != '\0'; i++) // Iterating through plaintext initially.
        {
            if (plaintext[i] >= 65 && plaintext[i] <= 90) // If i-indexed char is uppercase.
            {

                for (int j = 0; upperAlphabet[j] != '\0'; j++) // Finding it in the reference alphabet initialized above.
                {
                    if (plaintext[i] == upperAlphabet[j]) // If a match is detected.
                    {
                        char *wantedChar = strchr(upperAlphabet, plaintext[i]); // Getting index of this char in context of an alphabet.
                        index = (int)(wantedChar - upperAlphabet); // This is where this char stands in an alphabet.


                        argv[1][index] = toupper(argv[1][index]); // We still have to be sure it's an uppercase char when we print it out.

                        printf("%c", argv[1][index]);
                    }


                }
            }
            if (plaintext[i] >= 97 && plaintext[i] <= 122) // If the i-indexed char from plaintext happens to be lowercase.
            {
                // All operations are basically the same, but this time we're looking for a match in a lowercase alphabet defined above.
                for (int j = 0; lowerAlphabet[j] != '\0'; j++)
                {
                    if (plaintext[i] == lowerAlphabet[j])
                    {
                        char *wantedChar = strchr(lowerAlphabet, plaintext[i]);
                        index = (int)(wantedChar - lowerAlphabet);

                        argv[1][index] = tolower(argv[1][index]); // Still making sure the char comes out lowercase.

                        printf("%c", argv[1][index]);
                    }


                }
            }
            if (!isalpha(plaintext[i])) // If the i-indexed char in plaintext happens to not be alphabetic at all.
            {
                printf("%c", plaintext[i]); // Print it out as is, unchanged.
                continue; // ...And proceed.
            }

        }
        printf("\n"); // Keeping the terminal nice and clean.


    }

}
