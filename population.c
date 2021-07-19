#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startsize;
    int endsize;
    int years = 0;
    do
    {
        // TODO: Prompt for start size
        startsize = get_int("What is the llamas population start size?\n");

    }
    while(startsize < 9);

    do
    {
    // TODO: Prompt for end size
        endsize = get_int("What is the llamas population end size?\n");
    }
    while(endsize < startsize);

    if(startsize == endsize)
    {
        printf("Years: %d\n", years);
    }
    else
    {
        while(startsize < endsize)
        {
            // TODO: Calculate number of years until we reach threshold
            startsize = startsize + (startsize / 3) - (startsize / 4);
            years++;
        }
    // TODO: Print number of years
    printf("Years: %d\n", years);
    }
}