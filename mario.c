#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declaring an integer variable for our dear user.
    int input;

    // forcing our dear user to conform to our standards.
    do
    {
        input = get_int("For Mario's sake, insert a positive integer: ");
    }
    while (input > 8 || input < 1);

    // mapping our dear user's input to the pyramid's height.
    for (int i = 0; i < input; i++)
    {
        // drawing out left blanks.
        for (int j = 0; j < input - i; j++)
        {
            printf(" ");
        }
        // drawing out left blocks.
        for (int h = 0; h < i + 1; h++)
        {
            printf("#");
        }
        // defining the pillar of fate.
        printf("  ");
        // drawing out right blocks
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // our trusty line-break.
        printf("\n");
    }
    printf("Look! There's the princess!\n");
}
