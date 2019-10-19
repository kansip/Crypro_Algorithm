# -*- coding: utf-8 -*-
def __main__():
    password = input()
    string = input()

    sorted_password = sorted(password)

    digits = []

    for char in password:
        i = sorted_password.index(char)
        digits.append(i)
        sorted_password[i] = "-"

    height = len(string) // len(password)

    decoded_string = ""

    for i in range(height):
        for digit in digits:
            index = digit * height + i
            decoded_string += string[index]

    print(decoded_string)


if __name__ == "__main__":
    __main__()