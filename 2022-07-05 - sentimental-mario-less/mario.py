# Imported get_int function from cs50 library
from cs50 import get_int

# Defined main to print out a left-aligned pyramid using the height variable as input


def main():
    height = getheight()

    # Uses a combination of the reversed range function with a for loop and
    # print concatenation to print out the spaces and hashes appropriately

    for spaces in reversed(range(height)):
        print(" " * spaces, end="")
        print("#" * (height - spaces))

# gets height with enforced limits on user entered numbers


def getheight():
    while True:
        height = get_int("Height: ")
        if height < 1 or height > 8:
            continue
        else:
            break

    return height


main()