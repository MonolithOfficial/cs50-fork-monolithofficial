#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checking if there, indeed, are only 2 command line arguments.
    if (argc != 2 || strcmp(argv[1], "card.raw") != 0)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        // Null checking the file stream.
        printf("failed to open %s", argv[1]);
        return 2;
    }
    // Initializing output file stream.
    FILE *output_file = NULL;
    // Array of characters to hold file names up to 50.
    char name[8];

    BYTE buffer[512];

    int count = 0;
    while (&free)
    {
        // Byter unsigned char stores the return value of fread(), that being the number of all successfully read characters.
        unsigned char byter = fread(buffer, sizeof(BYTE), 512, file);
        if (byter == 0 && feof(file))
        {
            // Breaking if EOF was reached or there are no successfully read characters.
            break;
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef)
            && output_file != NULL)
        {
            // If JPG has been found, yet the file isn't closed, shall it be so now.
            fclose(output_file);
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            // Naming new files upon JPG discovery.
            sprintf(name, "%03i.jpg", count);
            output_file = fopen(name, "w");
            count++;
        }

        if (output_file != NULL)
        {
            // Keep writing upon discovery.
            fwrite(buffer, 512, 1, output_file);
        }
    }
    fclose(output_file);
    fclose(file);
    // printf("%x", buffer[0]);

    // printf("%i", buffer[500]);
    // for (int i = 0; i < sizeof(buffer); i++)
    // {
    //     printf("%u", buffer[i]);
    // }
    // while ((ch = fgetc(file)) != EOF)
    // {
    //     printf("%c\n", ch);
    // }
}
