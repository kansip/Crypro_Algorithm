# -*- coding: utf-8 -*-

import binascii


def main():
    string = input()

    start_symbol = string[:1]
    string = string[1:].replace(" ", "")

    nulls_count = 0
    next_offset = -1
    new_string = ""

    for i in range(len(string)):
        char = string[i]

        if i > next_offset:
            if char == '0':
                nulls_count += 1

            if char == '1':
                next_offset = i + nulls_count
                nulls_count = 0

        new_string += char

        if i == next_offset:
            new_string += ' '

    segments = new_string[:-1].split()
    counters = []

    for segment in segments:
        counters.append(int(segment, base=2))

    is_nulls = start_symbol == '0'

    string = ""

    for counter in counters:
        for i in range(counter):
            if is_nulls:
                string += "0"
            else:
                string += "1"

        is_nulls = not is_nulls

    binary_string = ""

    for i in range(len(string)):
        binary_string += string[i]

        if (i + 1) % 8 == 0:
            binary_string += " "

        i += 1

    final_string = ""

    for binary_number in binary_string.split():
        final_string += binascii.unhexlify(hex(int(binary_number, 2)).replace("0x", "")).decode('cp1251')

    print(final_string)


if __name__ == "__main__":
    main()
