#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height; // Delcare value of height int
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // Make sure height is not less than 1 or greater than 8

    for (int row = 0; row < height; row++) // print row
    {
        for (int space = height - row - 1; space > 0; space--) // print space
        {
            printf(" ");
        }
        for (int column = 0; column < row + 1; column++) // print columns or hash symbols
        {
            printf("#");
        }
        printf("  ");
        for (int right_column = 0; right_column < row + 1; right_column++) // print right alinged columns or hash symbols
        {
            printf("#");
        }
        printf("\n");
    }
}