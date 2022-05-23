#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    //Do loop while h value is less than 1 and more than 8.
    //Sanitizes user input.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //Main for loop, initiates the rows for printing the spaces and hashes.
    for (int rows = 0; rows < height; rows++)
        //First nested for loop, prints the spaces for the first pyramid.
    {
        for (int spaces = rows + 1; spaces < height; spaces++)
        {
            printf(" ");
            //Second nested for loop, prints the hashes for the first pyramid.
        }
        for (int hashes = rows + height + 1; hashes > height; hashes--)
        {
            printf("#");
        }
        //Third nested for loop, prints the hashes for the second pyamid.
        printf("  ");
        for (int hashes = rows + height + 1; hashes > height; hashes--)
        {
            printf("#");
        }
        //Adds new line after each iteration of the three nested for loops.
        printf("\n");
    }
}