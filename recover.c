#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2 || strcmp(argv[1], "card.raw") != 0)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("failed to open %s", argv[1]);
        return 2;
    }
    FILE *output_file = NULL;
    char name[8];
    BYTE buffer[512];
    int count = 0;
    while (&free)
    {
        unsigned char byter = fread(buffer, sizeof(BYTE), 512, file);
        if (byter == 0 && feof(file))
        {
            break;
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        && output_file != NULL)
        {
            fclose(output_file);
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            sprintf(name, "%03i.jpeg", count);
            output_file = fopen(name, "w");
            count++;
        }

        if (output_file != NULL)
        {
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
