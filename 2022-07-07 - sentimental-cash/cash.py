# Imports get_float from cs50 module

from cs50 import get_float

# Gets float dollar value from user.
# Passes dollar value(modified to (rounded)pennies) into minimum coins function.
# Prints minimum amount of coins.


def main():
    dollars = getdollarsfloat()
    coins = minimumcoins(round(dollars * 100))
    print(coins)

# Enforces user entered float of positive value only


def getdollarsfloat():
    while True:
        dollarfloat = get_float("Change owed: ")
        if dollarfloat <= 0:
            continue
        else:
            break
    return dollarfloat

# Calculate the minimum amount of coins from modified user entered float value


def minimumcoins(dollars):

    # Variables needed for adding the number of coins to return
    quarters = 0
    dimes = 0
    nickels = 0
    pennies = 0

    # Keeps an ordered running tally of amount of quarters, dimes, nickels and pennies and subtracting after each iteration
    while dollars >= 25:
        dollars -= 25
        quarters += 1

    while dollars >= 10:
        dollars -= 10
        dimes += 1

    while dollars >= 5:
        dollars -= 5
        nickels += 1

    while dollars >= 1:
        dollars -= 1
        pennies += 1

    # Adds minimum amount of coins needed together and returns them to be used in the print function
    coinsum = pennies + nickels + dimes + quarters
    return coinsum


main()