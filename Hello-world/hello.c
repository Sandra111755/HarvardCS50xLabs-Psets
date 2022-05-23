#include <cs50.h>
#include <stdio.h>

int main(void)

{
    //Asks user for name
    string name = get_string("What is your name?\n");
    //Prints users name
    printf("Hello, %s\n", name);
}