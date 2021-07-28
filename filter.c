#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float cinzashades;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cinzashades = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/ 3.00);
            image[i][j].rgbtBlue = cinzashades;
            image[i][j].rgbtGreen = cinzashades;
            image[i][j].rgbtRed = cinzashades;
        }
    }
    return;
}

// setting a max value to red, green and blue entries
int valorcores(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // initializing variables for a sepia version of each color
    int azulSep, vermelhoSep, verdeSep;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            azulSep = valorcores(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));
            verdeSep = valorcores(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            vermelhoSep = valorcores(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));

            image[i][j].rgbtBlue = azulSep;
            image[i][j].rgbtGreen = verdeSep;
            image[i][j].rgbtRed = vermelhoSep;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int swt[3];
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // switch the pixels positions to simulate a relfection
            swt[0] = image[i][j].rgbtBlue;
            swt[1] = image[i][j].rgbtGreen;
            swt[2] = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtBlue = swt[0];
            image[i][width - j - 1].rgbtGreen = swt[1];
            image[i][width - j - 1].rgbtRed = swt[2];
        }
    }
    return;
}

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width] , int color_position)
{
    int soma = 0;
    float contador = 0;
    for (int k = i - 1; k <  (i + 2); k++)
    {
        for (int l = j - 1; l < (j + 2); l ++)
        {
            if(k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }
            if (color_position == 0)
            {
                soma += image[k][l].rgbtRed;
            }
            else if (color_position == 1)
            {
                soma += image[k][l].rgbtGreen;
            }
            else
            {
                soma += image[k][l].rgbtBlue;
            }
            contador++;
        }
    }
    return round(soma/contador);
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlur(i, j, height, width, copy, 0);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, copy, 1);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, copy, 2);
        }
    }
    return;
}
