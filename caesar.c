#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }
    int counter = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isdigit(argv[1][i]))
        {
            counter++;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
    int key = 0;
    if(counter == strlen(argv[1]))
    {
        key = atoi(argv[1]);
    }

    if (key != 0)
    {
        if (key > 26)
        {
            key %= 26;
        }
        string plaintext = get_string("Plaintext: ");
        for(int i = 0; plaintext[i] != '\0'; i++)
        {
            if(isalpha(plaintext[i]))
            {
                if (plaintext[i] >= 65 && plaintext[i] <= 90)
                {
                    if (plaintext[i] + key > 90)
                    {
                        plaintext[i] = (plaintext[i] + key) - 90 + 64;
                    }
                    else
                    {
                        plaintext[i] += key;
                    }

                }
                else if (plaintext[i] >= 97 && plaintext[i] <= 122)
                {
                    if (plaintext[i] + key > 122)
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
        printf("ciphertext: %s\n", plaintext);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}