#include "helpers.h"
#include "math.h"
#include "stdlib.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            image[i][j].rgbtBlue = round(sum / 3.0);
            image[i][j].rgbtGreen = round(sum / 3.0);
            image[i][j].rgbtRed = round(sum / 3.0);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int maxColor = 255;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

// ensures that if by the above formulas, you were to get an average > 255 that it would set the color value to 255 instead
            if (sepiaBlue > maxColor)
            {
                image[i][j].rgbtBlue = maxColor;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            if (sepiaGreen > maxColor)
            {
                image[i][j].rgbtGreen = maxColor;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaRed > maxColor)
            {
                image[i][j].rgbtRed = maxColor;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    // iterates every pixel in left half of the image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // passes the left half of the image into the temp file

            temp = image[i][j];

            // passes the right side of the image into the left side

            image[i][j] = image[i][width - (j + 1)];

            // passes left half of the original image, from the temp file, into the right side of the original file

            image[i][width - (j + 1)] = temp;
        }
    }
    return;

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // iterates through every pixel in the image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumblue = 0, sumgreen = 0, sumred = 0;
            float counter = 0.0;

            // iterates every pixel in a 3x3 box around the current[i][j] pixel

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // passes current value of pixels relative position into a variable to check for validity in next step

                    int currentpixelx = x + i;
                    int currentpixely = y + j;

                    // check validity of current pixels and continues if so

                    if (currentpixelx < 0 || currentpixelx > (height - 1) || currentpixely < 0 || currentpixely > (width - 1))
                    {
                        continue;
                    }

                    // adds values of valid pixels found in 3x3 box initialized above

                    sumblue += image[currentpixelx][currentpixely].rgbtBlue;
                    sumgreen += image[currentpixelx][currentpixely].rgbtGreen;
                    sumred += image[currentpixelx][currentpixely].rgbtRed;
                    counter ++;
                }
            }

            /*rounds the average sum value of each color divided by the number of valid pixels counted and
            passes those value(s) into the blue, green and red pixel(s) of the temp file*/

            temp[i][j].rgbtBlue = round(sumblue / counter);
            temp[i][j].rgbtGreen = round(sumgreen / counter);
            temp[i][j].rgbtRed = round(sumred / counter);
        }
    }

    // pass the values of the temp file into the original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}