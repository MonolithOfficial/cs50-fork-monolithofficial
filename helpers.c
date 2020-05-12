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

            int sepiaRed = round(0.393 * (*redPtr) + 0.769 * (*greenPtr) + 0.189 * (*bluePtr));
            int sepiaGreen = round(0.349 * (*redPtr) + 0.686 * (*greenPtr) + 0.168 * (*bluePtr));
            int sepiaBlue = round(0.272 * (*redPtr) + 0.534 * (*greenPtr) + 0.131 * (*bluePtr));

            // int filterArray[3] = {sepiaBlue, sepiaGreen, sepiaRed};
            // for (int k = 0; k < 3; k++)
            // {
            //     if (filterArray[k] > 255)
            //     {
            //         filterArray[k] = 255;
            //     }
            // }
            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;


            *bluePtr = sepiaBlue;
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
    BYTE *bluePtr = NULL;
    BYTE *greenPtr = NULL;
    BYTE *redPtr = NULL;
    int blur_blue;
    int blur_green;
    int blur_red;
    for (int i = 0; i <= height - 1; i++)
    {
        for (int j = 0; j <= width - 1; j++)
        {
            bluePtr = &image[i][j].rgbtBlue;
            greenPtr = &image[i][j].rgbtGreen;
            redPtr = &image[i][j].rgbtRed;

            int top = i + 1;
            int right = j + 1;
            int bottom = i - 1;
            int left = j - 1;

            if (j != 0 && i != 0 && i != height - 1 && j != width - 1)
            {
                    blur_blue = round((*bluePtr
                + *&image[top][j].rgbtBlue +
                + *&image[top][right].rgbtBlue
                + *&image[i][right].rgbtBlue
                + *&image[bottom][right].rgbtBlue
                + *&image[bottom][j].rgbtBlue
                + *&image[bottom][left].rgbtBlue
                + *&image[i][left].rgbtBlue
                + *&image[top][left].rgbtBlue) / 10.6);

                blur_green = round((*greenPtr
                + *&image[top][j].rgbtGreen +
                + *&image[top][right].rgbtGreen
                + *&image[i][right].rgbtGreen
                + *&image[bottom][right].rgbtGreen
                + *&image[bottom][j].rgbtGreen
                + *&image[bottom][left].rgbtGreen
                + *&image[i][left].rgbtGreen
                + *&image[top][left].rgbtGreen) / 10.6);

                blur_red = round((*redPtr
                + *&image[top][j].rgbtRed +
                + *&image[top][right].rgbtRed
                + *&image[i][right].rgbtRed
                + *&image[bottom][right].rgbtRed
                + *&image[bottom][j].rgbtRed
                + *&image[bottom][left].rgbtRed
                + *&image[i][left].rgbtRed
                + *&image[top][left].rgbtRed) / 10.6);
            }
            else if (i == 0 && j != 0 && i != height - 1 && j != width - 1)
            {
                blur_blue = round((*bluePtr
                + *&image[top][j].rgbtBlue +
                + *&image[top][right].rgbtBlue
                + *&image[i][right].rgbtBlue
                // + *&image[bottom][right].rgbtBlue
                // + *&image[bottom][j].rgbtBlue
                // + *&image[bottom][left].rgbtBlue
                + *&image[i][left].rgbtBlue
                + *&image[top][left].rgbtBlue) / 6.0);

                blur_green = round((*greenPtr
                + *&image[top][j].rgbtGreen +
                + *&image[top][right].rgbtGreen
                + *&image[i][right].rgbtGreen
                // + *&image[bottom][right].rgbtGreen
                // + *&image[bottom][j].rgbtGreen
                // + *&image[bottom][left].rgbtGreen
                + *&image[i][left].rgbtGreen
                + *&image[top][left].rgbtGreen) / 6.0);

                blur_red = round((*redPtr
                + *&image[top][j].rgbtRed +
                + *&image[top][right].rgbtRed
                + *&image[i][right].rgbtRed
                // + *&image[bottom][right].rgbtRed
                // + *&image[bottom][j].rgbtRed
                // + *&image[bottom][left].rgbtRed
                + *&image[i][left].rgbtRed
                + *&image[top][left].rgbtRed) / 6.0);
            }
            else if (j == 0 && i != 0 && i != height - 1 && j != width - 1)
            {
                blur_blue = round((*bluePtr
                + *&image[top][j].rgbtBlue +
                + *&image[top][right].rgbtBlue
                + *&image[i][right].rgbtBlue
                + *&image[bottom][right].rgbtBlue
                + *&image[bottom][j].rgbtBlue)
                // + *&image[bottom][left].rgbtBlue
                // + *&image[i][left].rgbtBlue
                // + *&image[top][left].rgbtBlue)
                / 6.0);

                blur_green = round((*greenPtr
                + *&image[top][j].rgbtGreen +
                + *&image[top][right].rgbtGreen
                + *&image[i][right].rgbtGreen
                + *&image[bottom][right].rgbtGreen
                + *&image[bottom][j].rgbtGreen)
                // + *&image[bottom][left].rgbtGreen
                // + *&image[i][left].rgbtGreen
                // + *&image[top][left].rgbtGreen)
                / 6.0);

                blur_red = round((*redPtr
                + *&image[top][j].rgbtRed +
                + *&image[top][right].rgbtRed
                + *&image[i][right].rgbtRed
                + *&image[bottom][right].rgbtRed
                + *&image[bottom][j].rgbtRed)
                // + *&image[bottom][left].rgbtRed
                // + *&image[i][left].rgbtRed
                // + *&image[top][left].rgbtRed)
                / 6.0);
            }
            else if (i == 0 && j == 0 && i != height - 1 && j != width - 1)
            {
                blur_blue = round((*bluePtr
                + *&image[top][j].rgbtBlue +
                + *&image[top][right].rgbtBlue
                + *&image[i][right].rgbtBlue)
                // + *&image[bottom][right].rgbtBlue
                // + *&image[bottom][j].rgbtBlue
                // + *&image[bottom][left].rgbtBlue
                // + *&image[i][left].rgbtBlue
                // + *&image[top][left].rgbtBlue)
                / 4.0);

                blur_green = round((*greenPtr
                + *&image[top][j].rgbtGreen +
                + *&image[top][right].rgbtGreen
                + *&image[i][right].rgbtGreen)
                // + *&image[bottom][right].rgbtGreen
                // + *&image[bottom][j].rgbtGreen
                // + *&image[bottom][left].rgbtGreen
                // + *&image[i][left].rgbtGreen
                // + *&image[top][left].rgbtGreen)
                / 4.0);

                blur_red = round((*redPtr
                + *&image[top][j].rgbtRed +
                + *&image[top][right].rgbtRed
                + *&image[i][right].rgbtRed)
                // + *&image[bottom][right].rgbtRed
                // + *&image[bottom][j].rgbtRed
                // + *&image[bottom][left].rgbtRed
                // + *&image[i][left].rgbtRed
                // + *&image[top][left].rgbtRed)
                / 4.0);
            }
            else if (i == height - 1 && j != width - 1 && i != 0 && j != 0)
            {
                blur_blue = round((*bluePtr
                // + *&image[top][j].rgbtBlue +
                // + *&image[top][right].rgbtBlue
                + *&image[i][right].rgbtBlue
                + *&image[bottom][right].rgbtBlue
                + *&image[bottom][j].rgbtBlue
                + *&image[bottom][left].rgbtBlue
                + *&image[i][left].rgbtBlue)
                // + *&image[top][left].rgbtBlue)
                / 6.0);

                blur_green = round((*greenPtr
                // + *&image[top][j].rgbtGreen +
                // + *&image[top][right].rgbtGreen
                + *&image[i][right].rgbtGreen
                + *&image[bottom][right].rgbtGreen
                + *&image[bottom][j].rgbtGreen
                + *&image[bottom][left].rgbtGreen
                + *&image[i][left].rgbtGreen)
                // + *&image[top][left].rgbtGreen)
                / 6.0);

                blur_red = round((*redPtr
                // + *&image[top][j].rgbtRed +
                // + *&image[top][right].rgbtRed
                + *&image[i][right].rgbtRed
                + *&image[bottom][right].rgbtRed
                + *&image[bottom][j].rgbtRed
                + *&image[bottom][left].rgbtRed
                + *&image[i][left].rgbtRed)
                // + *&image[top][left].rgbtRed)
                / 6.0);

            }
            else if (j == width - 1 && i != height - 1 && i != 0 && j != 0)
            {
                blur_blue = round((*bluePtr
                + *&image[top][j].rgbtBlue +
                // + *&image[top][right].rgbtBlue
                // + *&image[i][right].rgbtBlue
                // + *&image[bottom][right].rgbtBlue
                + *&image[bottom][j].rgbtBlue
                + *&image[bottom][left].rgbtBlue
                + *&image[i][left].rgbtBlue
                + *&image[top][left].rgbtBlue) / 6.0);

                blur_green = round((*greenPtr
                + *&image[top][j].rgbtGreen +
                // + *&image[top][right].rgbtGreen
                // + *&image[i][right].rgbtGreen
                // + *&image[bottom][right].rgbtGreen
                + *&image[bottom][j].rgbtGreen
                + *&image[bottom][left].rgbtGreen
                + *&image[i][left].rgbtGreen
                + *&image[top][left].rgbtGreen) / 6.0);

                blur_red = round((*redPtr
                + *&image[top][j].rgbtRed +
                // + *&image[top][right].rgbtRed
                // + *&image[i][right].rgbtRed
                // + *&image[bottom][right].rgbtRed
                + *&image[bottom][j].rgbtRed
                + *&image[bottom][left].rgbtRed
                + *&image[i][left].rgbtRed
                + *&image[top][left].rgbtRed) / 6.0);
            }

            else if (j == width - 1 && i == height - 1 && i != 0 && j != 0)
            {
                blur_blue = round((*bluePtr
                // + *&image[top][j].rgbtBlue +
                // + *&image[top][right].rgbtBlue
                // + *&image[i][right].rgbtBlue
                // + *&image[bottom][right].rgbtBlue
                + *&image[bottom][j].rgbtBlue
                + *&image[bottom][left].rgbtBlue
                + *&image[i][left].rgbtBlue)
                // + *&image[top][left].rgbtBlue)
                / 4.0);

                blur_green = round((*greenPtr
                // + *&image[top][j].rgbtGreen +
                // + *&image[top][right].rgbtGreen
                // + *&image[i][right].rgbtGreen
                // + *&image[bottom][right].rgbtGreen
                + *&image[bottom][j].rgbtGreen
                + *&image[bottom][left].rgbtGreen
                + *&image[i][left].rgbtGreen)
                // + *&image[top][left].rgbtGreen)
                / 4.0);

                blur_red = round((*redPtr
                // + *&image[top][j].rgbtRed +
                // + *&image[top][right].rgbtRed
                // + *&image[i][right].rgbtRed
                // + *&image[bottom][right].rgbtRed
                + *&image[bottom][j].rgbtRed
                + *&image[bottom][left].rgbtRed
                + *&image[i][left].rgbtRed)
                // + *&image[top][left].rgbtRed)
                / 4.0);
            }
            // printf("Blue value: %i\n", *bluePtr);
            // printf("Green value: %i\n", *greenPtr);
            // printf("Red value: %i\n", *redPtr);

            *bluePtr = blur_blue;
            *greenPtr = blur_green;
            *redPtr = blur_red;

        }
    }
    // printf("Blue blur value: %i\n", blur_blue);
    // printf("Green blur value: %i\n", blur_green);
    // printf("Red blur value: %i\n", blur_red);
    return;
}
