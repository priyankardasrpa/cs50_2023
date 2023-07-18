#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // TODO: Render the pyramid
    for (int row = 1; row <= height; row++)
    {
        int hashes = row;
        int spaces = height - hashes;

        // TODO: Print the spaces first
        while (spaces > 0)
        {
            printf(" ");
            spaces = spaces - 1;
        }

        // TODO: Print the hashes after spaces
        while (hashes > 0)
        {
            printf("#");
            hashes = hashes - 1;
        }
        printf("\n");
    }
}