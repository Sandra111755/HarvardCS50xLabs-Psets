# Importing the get string function from the cs50 library
from cs50 import get_string

# Calling the get_string function to pass the answer into the name variable.
# Uses the \n line ending to add a new line right after asking the question.
name = get_string("What is your name?\n")

# Format-string prints Hello, userinput here
print(f"Hello, {name}")