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

    //Main for loop, initiates the rows.
    for (int rows = 0; rows < height; rows++)
        //First nested for loop, prints spaces in pyramid.
    {
        for (int spaces = rows + 1; spaces < height; spaces++)
        {
            printf(" ");
        }
        //Second nested for loop, prints the hash tags in the pyramid.
        for (int hashes = rows + height + 1; hashes > height; hashes--)
        {
            printf("#");
        }
        //Prints a new line after each interation of the nested for loops.
        printf("\n");
    }
}