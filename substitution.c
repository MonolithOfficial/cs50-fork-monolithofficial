#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    int count = 0;
    int duplicateCount = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isalpha(argv[1][i]))
        {
            count++;
        }
        for (int j = i + 1; argv[1][j] != '\0'; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                duplicateCount++;
            }
        }
    }
    printf("%i\n", duplicateCount);
    if (count != strlen(argv[1]) || duplicateCount != 0)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("Plaintext: ");
        string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string lowerAlphabet = "abcdefghigklmnopqrstuvwxyz";
        int index = 0;
        // int arrayOfIndexes[strlen(plaintext)];
        // int matchCount = 0;
        for (int i = 0; plaintext[i] != '\0'; i++)
        {
            if (plaintext[i] >= 65 && plaintext[i] <= 90){
                for (int j = 0; upperAlphabet[j] != '\0'; j++)
                {
                    if (plaintext[i] == upperAlphabet[j])
                    {
                        // printf("%c", plaintext[i]);
                        char *wantedChar = strchr(upperAlphabet, plaintext[i]);
                        index = (int)(wantedChar - upperAlphabet);

                        // printf("%i\n", index);
                        // arrayOfIndexes[matchCount] = index;
                        argv[1][index] = toupper(argv[1][index]);
                        printf("%c", argv[1][index]);
                    }


                }
            }
            if (plaintext[i] >= 97 && plaintext[i] <= 122)
            {
                for (int j = 0; lowerAlphabet[j] != '\0'; j++)
                {
                    if (plaintext[i] == lowerAlphabet[j])
                    {
                        // printf("%c", plaintext[i]);
                        char *wantedChar = strchr(lowerAlphabet, plaintext[i]);
                        index = (int)(wantedChar - lowerAlphabet);

                        // printf("%i\n", index);
                        // arrayOfIndexes[matchCount] = index;
                        argv[1][index] = tolower(argv[1][index]);
                        printf("%c", argv[1][index]);
                    }


                }
            }
            if (!isalpha(plaintext[i]))
                {
                    printf("%c", plaintext[i]);
                    continue;
                }

        }
        printf("\n");


    }

}
