from cs50 import get_string
from sys import exit
import re


# Gets card number from user as a string, processes it, and prints out the type (or invalid)


def main():

    card_number = get_string("Number: ")

    validate_card(card_number)

    print_answer(card_number)

# Validates user entered card using regular expressions and luhns algorithm


def validate_card(card_number):

    digit_amount(card_number)
    luhns_algorithm(card_number)
    card_type(card_number)


# Checks the amount of digits in the entered string


def digit_amount(card_number):
    """Uses regex to search for the pattern of 13, 15, or 16 digits"""

    pattern = re.compile(r'\d{16}|\d{15}|\d{13}')

    matches = pattern.match(card_number)

    if matches == None:
        print("INVALID")
        exit()

# Runs luhns algorithm on the entered card number if the user entered a valid amount of digits


def luhns_algorithm(card_number):

    even_sum = 0
    odd_sum = 0

    """Iterates through the odd and even numbers in the entered string using string slicing
     and typecasts the results to perform the proper arithmetic on them."""

    for odd_numbers in card_number[-2::-2]:
        if (int(odd_numbers) * 2) >= 10:
            odd_sum += (int(odd_numbers) * 2 % 10)
            odd_sum += (int(odd_numbers) * 2 // 10)
        else:
            odd_sum += (int(odd_numbers) * 2)

    for even_numbers in card_number[-1::-2]:
        even_sum += int(even_numbers)

    if (odd_sum + even_sum) % 10 != 0:
        print("INVALID")
        exit()

# Returns the card type if the two previous functions were sucessfully run on the user entered numbers


def card_type(card_number):
    """Uses regex to search for the specific starting pattern of each card and returns that card to be printed"""

    pattern = re.compile(r'(55|54|53|52|51|37|34|4)(\d+)')

    number_id = int(pattern.sub(r'\1', card_number))

    if number_id == 4:
        return "VISA"

    if number_id == 34 or number_id == 37:
        return "AMEX"

    if number_id == 51 or number_id == 52 or number_id == 53 or number_id == 54 or number_id == 55:
        return "MASTERCARD"

    else:
        print("INVALID")
        exit()

# Prints out the type of card as long as the previous functions were successful


def print_answer(card_number):

    answer = card_type(card_number)
    print(answer)


main()