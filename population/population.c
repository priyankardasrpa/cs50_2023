#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int born = 0;
    int died = 0;
    int years = 0;
    int currentSize = startSize + born - died;
    while (currentSize < endSize)
    {
        currentSize = currentSize + (int)(currentSize / 3) - (int)(currentSize / 4);
        years = years + 1;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
