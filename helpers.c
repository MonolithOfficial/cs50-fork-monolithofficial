#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE *bluePtr = NULL;
    BYTE *greenPtr = NULL;
    BYTE *redPtr = NULL;
    int new_filter;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            bluePtr = &image[i][j].rgbtBlue;
            greenPtr = &image[i][j].rgbtGreen;
            redPtr = &image[i][j].rgbtRed;
            new_filter = round((*bluePtr + *greenPtr + *redPtr) / 3.0);
            *bluePtr = new_filter;
            *greenPtr = new_filter;
            *redPtr = new_filter;
            // printf("Blue value: %i\n", *bluePtr);
            // printf("Green value: %i\n", *greenPtr);
            // printf("Red value: %i\n", *redPtr);
        }
    }
    // printf("%i\n", new_filter);
    // printf("%i\n", height);
    // printf("%i\n", width);
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE *bluePtr = NULL;
    BYTE *greenPtr = NULL;
    BYTE *redPtr = NULL;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            bluePtr = &image[i][j].rgbtBlue;
            greenPtr = &image[i][j].rgbtGreen;
            redPtr = &image[i][j].rgbtRed;

            int sepiaBlue = round(0.272 * (*redPtr) + 0.534 * (*greenPtr) + 0.131 * (*bluePtr));
            int sepiaGreen = round(0.349 * (*redPtr) + 0.686 * (*greenPtr) + 0.168 * (*bluePtr));
            int sepiaRed = round(0.393 * (*redPtr) + 0.769 * (*greenPtr) + 0.189 * (*bluePtr));

            int filterArray[3] = {sepiaBlue, sepiaGreen, sepiaRed};
            for (int k = 0; k < 3; k++)
            {
                if (filterArray[k] > 255)
                {
                    filterArray[k] = 255;
                }
            }

            *bluePtr = sepiaGreen;
            *greenPtr = sepiaGreen;
            *redPtr = sepiaRed;
            // printf("Blue value: %i\n", *bluePtr);
            // printf("Green value: %i\n", *greenPtr);
            // printf("Red value: %i\n", *redPtr);
        }
    }
    // printf("%i\n", height);
    // printf("%i\n", width);
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE xTemp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = xTemp;

        }
    }
    // printf("%i\n", height);
    // printf("%i\n", width);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
