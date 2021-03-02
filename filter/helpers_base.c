#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            int limit = 255;

            if(sepiaRed > limit)
            {
                image[i][j].rgbtRed = limit;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if(sepiaGreen > limit)
            {
                image[i][j].rgbtGreen = limit;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if(sepiaBlue > limit)
            {
                image[i][j].rgbtBlue = limit;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {
            int tmpRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed;
            image[i][width-1-j].rgbtRed = tmpRed;

            int tmpGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][width-1-j].rgbtGreen = tmpGreen;

            int tmpBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;
            image[i][width-1-j].rgbtBlue = tmpBlue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float redarr[height][width];
    float greenarr[height][width];
    float bluearr[height][width];

    //Iterate over middle pixels:

    for(int i = 1; i < height - 1; i++)
    {
        for(int j = 1; j > 0 && j < width - 1; j++)
        {
            int cumR = 0;
            int cumG = 0;
            int cumB = 0;
            int count =0;

            for(int k = i - 1; count < 3; k++)
            {
                int count2 = 0;
                for(int f = j - 1; count2 < 3; f++)
                {
                    int red = image[k][f].rgbtRed;
                    cumR += red;

                    int green = image[k][f].rgbtGreen;
                    cumG += green;

                    int blue = image[k][f].rgbtBlue;
                    cumB += blue;

                    count2++;
                    //printf("%i \n", cum);
                }
                count++;
            }
            redarr[i][j] = round(cumR / 9.0);
            greenarr[i][j] = round(cumG / 9.0);
            bluearr[i][j] = round(cumB / 9.0);
        }
    }

    //Iterate through first row

    for(int j = 1; j < width - 1; j++)
    {
        int cumR = 0;
        int cumG = 0;
        int cumB = 0;
        int count =0;

        for(int k = 0; count < 2; k++)
        {
            int count2 = 0;
            for(int f = j - 1; count2 < 3; f++)
            {
                int red = image[k][f].rgbtRed;
                cumR += red;

                int green = image[k][f].rgbtGreen;
                cumG += green;

                int blue = image[k][f].rgbtBlue;
                cumB += blue;

                count2++;
                    //printf("%i \n", cum);
            }
            count++;
        }
            redarr[0][j] = round(cumR / 6.0);
            greenarr[0][j] = round(cumG / 6.0);
            bluearr[0][j] = round(cumB / 6.0);
    }

    //Iterate through last row

    for(int j = 1; j < width - 1; j++)
    {
        int cumR = 0;
        int cumG = 0;
        int cumB = 0;
        int count =0;

        for(int k = height - 2; count < 2; k++)
        {
            int count2 = 0;
            for(int f = j - 1; count2 < 3; f++)
            {
                int red = image[k][f].rgbtRed;
                cumR += red;

                int green = image[k][f].rgbtGreen;
                cumG += green;

                int blue = image[k][f].rgbtBlue;
                cumB += blue;

                count2++;
                    //printf("%i \n", cum);
            }
            count++;
        }
            redarr[height - 1][j] = round(cumR / 6.0);
            greenarr[height - 1][j] = round(cumG / 6.0);
            bluearr[height - 1][j] = round(cumB / 6.0);
    }

    //Iterate through left column

    for(int i = 1; i < height - 1; i++)
    {
        int cumR = 0;
        int cumG = 0;
        int cumB = 0;
        int count =0;

        for(int k = i - 1; count < 3; k++)
        {
            int count2 = 0;
            for(int f = 0; count2 < 2; f++)
            {
                int red = image[k][f].rgbtRed;
                cumR += red;

                int green = image[k][f].rgbtGreen;
                cumG += green;

                int blue = image[k][f].rgbtBlue;
                cumB += blue;

                count2++;
                    //printf("%i \n", cum);
            }
            count++;
        }
            redarr[i][0] = round(cumR / 6.0);
            greenarr[i][0] = round(cumG / 6.0);
            bluearr[i][0] = round(cumB / 6.0);
    }

    //Iterate through right column

    for(int i = 1; i < height - 1; i++)
    {
        int cumR = 0;
        int cumG = 0;
        int cumB = 0;
        int count =0;

        for(int k = i - 1; count < 3; k++)
        {
            int count2 = 0;
            for(int f = width - 2; count2 < 2; f++)
            {
                int red = image[k][f].rgbtRed;
                cumR += red;

                int green = image[k][f].rgbtGreen;
                cumG += green;

                int blue = image[k][f].rgbtBlue;
                cumB += blue;

                count2++;
                    //printf("%i \n", cum);
            }
            count++;
        }
            redarr[i][width - 1] = round(cumR / 6.0);
            greenarr[i][width - 1] = round(cumG / 6.0);
            bluearr[i][width - 1] = round(cumB / 6.0);
    }

    //int cumR = 0;
    //int cumG = 0;
    //int cumB = 0;
    //int count =0;

    //Corners upper left

    int k, count, cumR, cumG, cumB;

    for(k = 0, count = 0, cumR = 0, cumG = 0, cumB = 0; count < 2; k++)
    {
        int count2 = 0;
        for(int f = 0; count2 < 2; f++)
        {
            int red = image[k][f].rgbtRed;
            cumR += red;

            int green = image[k][f].rgbtGreen;
            cumG += green;

            int blue = image[k][f].rgbtBlue;
            cumB += blue;

            count2++;
                    //printf("%i \n", cum);
        }
        count++;
        redarr[0][0] = round(cumR / 4.0);
        greenarr[0][0] = round(cumG / 4.0);
        bluearr[0][0] = round(cumB / 4.0);
    }


    //Corners upper right


    for(k = 0, count = 0, cumR = 0, cumG = 0, cumB = 0; count < 2; k++)
    {
        int count2 = 0;
        for(int f = width - 2; count2 < 2; f++)
        {
            int red = image[k][f].rgbtRed;
            cumR += red;

            int green = image[k][f].rgbtGreen;
            cumG += green;

            int blue = image[k][f].rgbtBlue;
            cumB += blue;

            count2++;
                    //printf("%i \n", cum);
        }
        count++;
        redarr[0][width - 1] = round(cumR / 4.0);
        greenarr[0][width - 1] = round(cumG / 4.0);
        bluearr[0][width - 1] = round(cumB / 4.0);
    }

    //Corners lower right
    for(k = height - 2, count = 0, cumR = 0, cumG = 0, cumB = 0; count < 2; k++)
    {
            int count2 = 0;
            for(int f = width - 2; count2 < 2; f++)
            {
                int red = image[k][f].rgbtRed;
                cumR += red;

                int green = image[k][f].rgbtGreen;
                cumG += green;

                int blue = image[k][f].rgbtBlue;
                cumB += blue;

                count2++;
                    //printf("%i \n", cum);
            }
            count++;
            redarr[height - 1][width - 1] = round(cumR / 4.0);
            greenarr[height - 1][width - 1] = round(cumG / 4.0);
            bluearr[height - 1][width - 1] = round(cumB / 4.0);
    }


    //Corners lower left
    for(k = height - 2, count = 0, cumR = 0, cumG = 0, cumB = 0; count < 2; k++)
        {
            int count2 = 0;
            for(int f = 0; count2 < 2; f++)
            {
                int red = image[k][f].rgbtRed;
                cumR += red;

                int green = image[k][f].rgbtGreen;
                cumG += green;

                int blue = image[k][f].rgbtBlue;
                cumB += blue;

                count2++;
                    //printf("%i \n", cum);
            }
            count++;
            redarr[height - 1][0] = round(cumR / 4.0);
            greenarr[height - 1][0] = round(cumG / 4.0);
            bluearr[height - 1][0] = round(cumB / 4.0);
        }


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = redarr[i][j];
            image[i][j].rgbtGreen = greenarr[i][j];
            image[i][j].rgbtBlue = bluearr[i][j];
        }
    }
    return;
}
