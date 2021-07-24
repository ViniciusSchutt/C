#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //Declaring variables
    int height, i, k, w;
    do
    {
        //Get the height of the right-alygned pyramid
        height = get_int("Height: ");
    }
    //while this condition is met, repeat asking for a valid value of the height
    while (height < 1 || height > 8);

    for (k = 0; k < height; k++)
    {
        for (w = k + 1; w < height; w++)
        {
            printf(" ");
        }
        for (i = height + k + 1; i > height; i--)
        {
            printf("#");
        }
        printf("\n");

    }
}