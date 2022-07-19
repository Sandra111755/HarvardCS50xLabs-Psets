from cs50 import get_string
import re

# main function gets a string from the user and calls the print_answer function, passing the string value to it.


def main():

    string = get_string("Text: ")

    print_answer(string)

# function takes the string, processes it with the Coleman-Liau formula, and returns the index to be used in the print function.


def coleman_liau_formula(string):

    letters = count_letters(string)
    words = count_words(string)
    sentences = count_sentences(string)

    index = round(0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8)

    return index

# Counts the number of letters using regex and returns them


def count_letters(string):

    search_string = string
    letters = 0

    pattern = re.compile(r'[a-zA-Z]')
    matches = pattern.finditer(search_string)

    for match in matches:
        letters += 1

    return letters

# Counts the number of words using regex and returns them


def count_words(string):

    search_string = string
    words = 0

    pattern = re.compile(r' ')
    matches = pattern.finditer(search_string)

    for match in matches:
        words += 1

    words += 1

    return words

# Counts the number of sentences using regex and returns them


def count_sentences(string):

    search_string = string
    sentences = 0

    pattern = re.compile(r'[.!?]')
    matches = pattern.finditer(search_string)

    for match in matches:
        sentences += 1

    return sentences

# prints the grade level of the entered string as per the objectives.


def print_answer(string):

    index = coleman_liau_formula(string)

    if (index < 1):
        print("Before Grade 1")

    elif (index > 1 and index < 16):
        print(f"Grade {index}")

    else:
        print("Grade 16+")


main()