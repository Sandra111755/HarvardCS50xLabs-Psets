# Importing get_int from cs50 library
from cs50 import get_int

# Defined main to print out a left then right aligned pyramid with two spaces in between them


def main():
    height = get_height()

    # For loop for spaces using reversed(range) function to invert the pyramid and set the spacing.
    # secondary print function handles printing out the all the hashes appropriately using concatenation

    for spaces in reversed(range(height)):
        print(" " * spaces, end="")
        print("#" * (height - spaces) + "  " + "#" * (height - spaces))

# returns height range between 1 and 8 using mock do-while loop


def get_height():
    while True:
        height = get_int("Height: ")
        if height < 1 or height > 8:
            continue
        else:
            break

    return height


main()